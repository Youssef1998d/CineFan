#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

typedef struct realisateur{
    int numR;
    char nomR[50];
    char prenomR[50];
    int ageR;
    char natR[50];
    int anC;
    int nbFS;
}Realisateur;

typedef struct acteur{
    char nomAct[50];
    char prenomAct[50];
    int ageAct;
    char paysAct[50];
    char natioAct[50];
    char *bioAct;
    ListeFilm *film;
    int nbAn;
    int nbFS;
    char *prix;
}Acteur;

typedef struct maillonA{
    Acteur A;
    struct maillonA *suiv;
    struct maillonA *prec;
}ListeAct;

typedef struct maillonR{
    Realisateur R;
    struct maillonR *suiv;
    struct maillonR *prec;
}ListeRea;

typedef struct maillonT{
    char type[30];
    struct maillonT *suiv;
    struct maillonT *prec;
}LType;

typedef struct dure{
    int secondes;
    int minutes;
    int heures;
    int enS;
    int enM;
    int enH;
}dure;

typedef struct maillonF{
    Film F;
    struct maillonF *suiv;
    struct maillonF *prec;
}ListeFilm;

typedef struct film{
    int numF;
    char titreF[50];
    ListeRea *realF;
    char *descF;
    int anPF;
    dure dureF;
    LType *typeF;
    ListeAct *actF;
    Lcrit *crit;
}Film;

typedef struct crit{
    int id;
    char *ch;
    struct crit *suiv;
    struct crit *prec;
}Lcrit;

typedef struct date{
    int j;
    int m;
    int a;
}date;

typedef struct bd{
    FILE *f;
    date last;
}bd;

#endif // BIB_H_INCLUDED
