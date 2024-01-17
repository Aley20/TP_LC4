#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>


typedef struct polynome{ 
    int coef;
    int degre;
    struct polynome *suiv;
} polynome;


/***************************** Q.1 **********************************/
polynome* creer_polynome_vide() {
    polynome* nouveau=malloc(sizeof(polynome));
    assert(nouveau!=NULL);
    nouveau->coef=0;
    nouveau->degre=-1;
    nouveau->suiv=NULL;
    return nouveau;
}

/***************************** Q.2 **********************************/
polynome* creer_monome(int c, int d){
    polynome *p=(polynome*)malloc(sizeof(polynome));
    assert(p);
    assert(c>0);
    assert(d>=0);
    p->coef=c;
    p->degre=d;
    p->suiv=NULL;
    return p;
}

/***************************** Q.3 **********************************/
void polynome_destroy(polynome* p){
    polynome * tmp=p->suiv,*tmp1;
    while(tmp!=NULL){
        tmp1=tmp;
        tmp=tmp1->suiv;
        free(tmp1);
    }
    p->suiv=NULL;
}

/***************************** Q.4 **********************************/
double evaluer_polynome(polynome* p,double x){
    double res=0;
    polynome* aux = NULL;
	for (aux = p->suiv; aux != NULL; aux = aux->suiv) {
		res += pow(x, aux->degre) * aux->coef;
    }
    return res;
}

/***************************** Q.5 **********************************/
void afficher_polynome(polynome* p){
    polynome * tmp=p->suiv;
    if(tmp==NULL){
        puts("polynome vide \n");
        return;   
    }
    while(tmp!=NULL){
        if ( tmp->coef > 0 && tmp != p->suiv) {
                printf("+");
        }
        if (tmp->degre == 0) {
                printf("%d", tmp->coef);
        }
        if (tmp->degre > 0) {
                printf("%dX", tmp->coef);
                if (tmp->degre>1){
                    printf("^%d",tmp->degre);
                }
                else{
                    printf("");
                }
        } 
        tmp=tmp->suiv;
    } 
    printf("\n");
}

/***************************** Q.6 **********************************/
void ajouter_monome(polynome* p, double c, int d){
    polynome* final=creer_monome(c,d);
   if(p->suiv==NULL) {
       p->suiv=final;
   return;
   }  
       if(p->suiv->degre>final->degre){
           ajouter_monome(p->suiv,c,d);          
       }
       else if(p->suiv->degre<final->degre){
           final->suiv=p->suiv;
           p->suiv=final;
           return;
       }
       else if(p->suiv->degre==final->degre){
           p->suiv->coef+=final->coef;
       }        
   }


/***************************** Q.7 **********************************/
polynome* copie(polynome* p){
    polynome* res = creer_polynome_vide();
	if (p == NULL) {
		return res;
	}
	for (polynome* aux = p->suiv; aux != NULL; aux = aux->suiv) {
		ajouter_monome(res, aux->coef, aux->degre);
	}
	return res;
}

/***************************** Q.8 **********************************/
polynome* somme(polynome* p1, polynome* p2){
    polynome* tmp = copie(p1);
	for (polynome* aux = p2->suiv; aux != NULL; aux = aux->suiv) {
		ajouter_monome(tmp, aux->coef, aux->degre);
	}
	return tmp;
}

/*int main(){
    puts("**************************** Q.1 *********************************\n");
    polynome* p=creer_polynome_vide();
    //afficher_polynome(p);
    puts("**************************** Q.2 *********************************\n");
    p->suiv=creer_monome(3,5);
    p->suiv->suiv=creer_monome(2,2);
    p->suiv->suiv->suiv=creer_monome(1,0);
    afficher_polynome(p);
    puts("**************************** Q.4 *********************************\n");
    printf("%f \n",evaluer_polynome(p,1));
    puts("**************************** Q.3 *********************************\n");
    polynome_destroy(p);
    afficher_polynome(p);
    puts("**************************** Q.6 *********************************\n");
    ajouter_monome(p,3,5);
    ajouter_monome(p,2,2);
    ajouter_monome(p,1,0);
    afficher_polynome(p);
    puts("**************************** Q.7 *********************************\n");
    polynome *cop=copie(p);
    afficher_polynome(cop);
    puts("**************************** Q.8 *********************************\n");
    polynome * som=somme(p,cop);
    afficher_polynome(som);

}
*/
int main(int argc, char* argv[]) {
    int n1, n2, c, d;
    polynome *p1 = creer_polynome_vide();
    polynome *p2 = creer_polynome_vide(); 
    polynome *res;

    printf("Entrez le nombre de monomes du premier polynome : ");
    scanf("%d", &n1);
    for(int i=0; i<n1; i++) {
        printf("Entrez le coefficient et le degre du monome %d : ", i+1);
        scanf("%d%d", &c, &d);
        ajouter_monome(p1, c, d);
    }

    printf("Entrez le nombre de monomes du deuxieme polynome : ");
    scanf("%d", &n2);
    for(int i=0; i<n2; i++) {
        printf("Entrez le coefficient et le degre du monome %d : ", i+1);
        scanf("%d%d", &c, &d);
        ajouter_monome(p2, c, d);
    }

    printf("\nPolynome 1 : ");
    afficher_polynome(p1);
    printf("\nPolynome 2 : ");
    afficher_polynome(p2);

    res = somme(p1, p2);
    printf("\n\nSomme des polynomes : ");
    afficher_polynome(res);

    polynome_destroy(p1);
    polynome_destroy(p2);
    polynome_destroy(res);

    return 0;
}