#ifndef FICHIERS_H_INCLUDED
#define FICHIERS_H_INCLUDED
#include <string.h>

int destroyFileF(){
    FILE* fichier = NULL;
    fichier = fopen("DB/film.txt", "w");
    if (fichier != NULL){
        fprintf(fichier, "");
        fclose(fichier);
    }else{
        return 0;
    }
    return 1;
}
int destroyFileR(){
    FILE* fichier = NULL;
    fichier = fopen("DB/realisateur.txt", "w");
    if (fichier != NULL){
        fprintf(fichier, "");
        fclose(fichier);
    }else{
        return 0;
    }
    return 1;
}
int destroyFileA(){
    FILE* fichier = NULL;
    fichier = fopen("DB/acteur.txt", "w");
    ListeEntier *p = NULL;
    if (fichier != NULL){
        fprintf(fichier, "");
        fclose(fichier);
    }else{
        return 0;
    }
    return 1;
}

void saveF(Film f){
    FILE* fichier = NULL;
    fichier = fopen("DB/film.txt", "a");
    if (fichier != NULL){

        fclose(fichier);
    }
}

void saveR(Realisateur r){
    FILE* fichier = NULL;
    fichier = fopen("DB/realisateur.txt", "a");
    if (fichier != NULL){
        fprintf(fichier, "%d;%s;%s;%d;%s;%d;%d;%d;%s\n", r.numR, r.nomR, r.prenomR, r.anCar, r.NatioR, r.nbF, r.nbS, r.nominationR, r.LF);
        fclose(fichier);
    }
}

void saveRbref(Realisateur r){
    FILE* fichier = NULL;
    fichier = fopen("DB/reaBref.txt", "a");
    if (fichier != NULL){
        fprintf(fichier, "%d;%s;%s;%d;%s;%d;%d;%d\n", r.numR, r.nomR, r.prenomR, r.anCar, r.NatioR, r.nbF, r.nbS, r.nominationR);
        fclose(fichier);
    }
}


void saveA(Acteur a){
    FILE* fichier = NULL;
    fichier = fopen("DB/acteur.txt", "a");
    if (fichier != NULL){
        fprintf(fichier, "%d;%s;%s;%s;%s;%d;%d;%s;%s;%s\n", a.numA, a.nomA, a.prenomA, a.natioA, a.paysA, a.nbF, a.nbS, a.filmA, a.prixA, a.bio);
        fclose(fichier);

    }
}



ListeEntier *movieListGetter(int id){
    FILE* fichier = fopen("DB/realisateur.txt", "r");
    ListeEntier* p=NULL;
    if (fichier!=NULL){
        int i=0;
        while(!feof(fichier)){
            char* s;
            fscanf(fichier, "%s", s);
            printf("%s\n", s);
        }
    }
    return p;
}

ListeChaine *getMovieListAct(int id){
    FILE* fichier;
    fichier = fopen("DB/acteur.txt", "r");
    if (fichier == NULL) {
      printf("Failed\n");
      return 1;
    }

    char buffer[500];
    fgets(buffer, 499, fichier);
    fgets(buffer, 499, fichier);
    buffer[strcspn(buffer, "\n")] = 0;
    int delimiter = 0;
    char p[16]="";
    for (int i=0;i<strlen(buffer);i++){
        if (buffer[i]=='|'){
            delimiter++;
        }
        if (delimiter==7){
            for (int j=0;j<16;j++){
                strncat(p, &buffer[1+i+j], 1);
            }
            break;
        }
    }
    ListeChaine* q;

    struct myStruct s;
    unsigned long ul;
    sscanf(p, "%p", &ul);
    s.adress = (void*) (uintptr_t) ul;
    printf("%p", s.adress);
    fclose(fichier);
    return s.adress;
}

int lastId(char switcher){
    char *s;
    if (switcher=='f'){
        s="DB/film.txt";
    }else if (switcher=='r'){
        s="DB/realisateur.txt";
    }else if (switcher=='a'){
        s="DB/acteur.txt";
    }else if (switcher=='c'){
        s="DB/comments.txt";
    }
    FILE* fichier = fopen(s, "r");
    char buffer[1000];
    if (fichier!=NULL){
        while(fgets(buffer, 999, fichier)!=NULL && !feof(fichier)){
        int active=0;
        Realisateur r;
        int delimiter=0;
        int last=0;
        for (int i=0;i<strlen(buffer);i++){
            if (buffer[i]==';'){
                delimiter++;
                active=1;
            }
            switch(delimiter*active){
                case 1:{ //num
                    char id[8];
                    for(int j=0;j<i;j++){
                        id[j]=buffer[j];
                    }
                    id[i]='\0';
                    last = strlen(id);
                    r.numR = atoi(id);
                    active=0;
                    break;
                }
                case 2:{ //nom
                    int c=0;
                    for (int j=last+1;j<i;j++){
                        r.nomR[j-last-1]=buffer[j];
                        c++;
                    }
                    r.nomR[i-last-1]='\0';
                    last += i-last;
                    active=0;
                    break;
                }
                case 3:{ //prenom
                    for (int j=last+1;j<i;j++){
                        r.prenomR[j-last-1]=buffer[j];
                    }
                    r.prenomR[i-last-1]='\0';
                    last += i-last;
                    active=0;
                    break;
                }
                case 4:{ //anCar
                    char a[3];
                    for(int j=last+1;j<i;j++){
                        a[j-last-1]=buffer[j];
                    }
                    a[i-last-1]='\0';
                    last += i-last;
                    r.anCar = atoi(a);
                    active=0;
                    break;
                }
                case 5:{ //nationalite
                    for (int j=last+1;j<i;j++){
                        r.NatioR[j-last-1]=buffer[j];
                    }
                    r.NatioR[i-last-1]='\0';
                    last += i-last;
                    active=0;
                    break;
                }
                case 6:{ //nbF
                    char n[3];
                    for(int j=last+1;j<i;j++){
                        n[j-last-1]=buffer[j];
                    }
                    n[i-last-1]='\0';
                    last += i-last;
                    r.nbF = atoi(n);
                    active=0;
                    break;
                }
                case 7:{ //nbS
                    char nb[3];
                    for(int j=last+1;j<i;j++){
                        nb[j-last-1]=buffer[j];
                    }
                    nb[i-last-1]='\0';
                    last += i-last;
                    r.nbS = atoi(nb);
                    active=0;
                    break;
                }
                case 8: { //nomination
                    char nbn[3];
                    for(int j=last+1;j<i;j++){
                        nbn[j-last-1]=buffer[j];
                    }
                    nbn[i-last-1]='\0';
                    last += i-last;
                    r.nominationR = atoi(nbn);
                    active=0;
                    break;
                }
                case 9:{ //LF
                    for (int j=last+1;j<i;j++){
                        r.LF[j-last-1]=buffer[j];
                    }
                    r.LF[i-last-1]='\0';
                    last += i-last;
                    active=0;
                    break;
                }
                default : break;
            }
        }
    }
    }else{
        printf("Couldn\'t reach file!!\n");
    }
}

#endif // FICHIERS_H_INCLUDED
