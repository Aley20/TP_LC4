#include <stdio.h>
#include <stdlib.h>
#include<time.h>

enum etat {
    VALIDEE, ENCOURS, EXPEDIEE
};
typedef enum etat etat;
struct commande{ 
    int num_com;
    int prix_exp;
    int prix_prod;
    etat etat_com;
};
typedef struct commande commande;

/***************************** Q.1 **********************************/
void affiche_com(commande c){
    printf("num_com -> %d\n",c.num_com);
    printf("prix_exp -> %d\n",c.prix_exp);
    printf("prix_prod -> %d\n",c.prix_prod);
    switch(c.etat_com){

        case VALIDEE :
        printf("VALIDEE\n");
        break;

        case ENCOURS :
        printf("EN COURS\n");
        break;

        case EXPEDIEE :
        printf("EXPEDIEE\n");
        break;

        default:
        printf("Etat inconnu\n");

    }
}

/***************************** Q.3 **********************************/
commande com_alea(int num){
    commande c;
    srand(time(NULL));
    c.num_com=num;
    int exp = rand() % 20 + 1;
    int val = rand() % 2000 + 1;
    int etat = rand() % 4;
    c.prix_prod=val; 
    c.prix_exp=exp;
    c.etat_com=etat;
    return c;

}

/***************************** Q.5 **********************************/
void affiche_exp(commande t[], size_t taille){
    for(size_t i=0;i<taille;i++){
        if(t[i].etat_com==EXPEDIEE){
            affiche_com(t[i]);
            printf("\n");
        }
    }
}

/***************************** Q.6 **********************************/
int nbr_en_cours(commande t[], size_t taille){
    int res=0;
    for(size_t i=0;i<taille;i++){
        if(t[i].etat_com==ENCOURS){
            res++;
        }
    }
    return res;
}

/***************************** Q.7 **********************************/
int cout_validees(commande t[],size_t taille){
    int res=0;
    for(size_t i=0;i<taille;i++){
        if(t[i].etat_com==VALIDEE){
            res+=t[i].prix_exp;
        }
    }
    return res;
}

/***************************** Q.8 **********************************/
void change_prix( commande *c, int newprice){
    c->prix_prod=newprice;

}

/***************************** Q.9 **********************************/
void expedie_tout(commande tab[], size_t n) {
    for(size_t i=0;i<n;i++){
        tab[i].etat_com=EXPEDIEE;
    }
}

    int main(){
        //Q.2
        commande c1;
        c1.num_com=5;
        c1.prix_exp=6;
        c1.prix_prod=7;
        c1.etat_com=VALIDEE;
        printf("**************************** Q.2 *********************************\n");
        affiche_com(c1);
        printf("\n");

        commande c2={.num_com=2, .prix_exp=4, .prix_prod=6, .etat_com=ENCOURS};
        affiche_com(c2);
        printf("\n");

        printf("**************************** Q.4 *********************************\n");
        #define NBC 5
        commande N[NBC];
        for(size_t i=0;i<NBC;i++){ //initilisation des commande N
            N[i]=com_alea(i);

        }

        for(size_t i=0;i<NBC;i++){ //affichage des commande N
            printf("------------ N[%zu] ------------\n",i);
            affiche_com(N[i]);
            printf("\n");

        }

        printf("**************************** Q.5 *********************************\n");
        N[0].etat_com=EXPEDIEE;
        N[3].etat_com=EXPEDIEE;
        affiche_exp(N,NBC);
        printf("\n");

        printf("**************************** Q.6 *********************************\n");
        N[0].etat_com=ENCOURS;
        N[3].etat_com=ENCOURS;
        printf("nbr_en_cours(N, %d) -> %d\n",NBC,nbr_en_cours(N,NBC));
        printf("\n");

        printf("**************************** Q.7 *********************************\n");
        N[0].etat_com=VALIDEE;
        N[3].etat_com=VALIDEE;
        printf("cout_validees(N, %d) -> %d\n",NBC,cout_validees(N,NBC));
        printf("\n");

        printf("**************************** Q.8 *********************************\n");
        commande c = {.prix_prod=100};
        change_prix(&c,200);
        printf("%d\n",c.prix_prod);
        printf("\n");

        printf("**************************** Q.9 *********************************\n");
        expedie_tout(N,NBC);
         for(size_t i=0;i<NBC;i++){ //affichage des commande N
            printf("------------ N[%zu] ------------\n",i);
            affiche_com(N[i]);
            printf("\n");

        }

        return 0;
    }
