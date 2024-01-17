#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

/***************************** Q.2-3 **********************************/
unsigned fact (unsigned n){
     int res=1;
     for(int i=1;i<n+1;i++){
       res=res*i;
       printf("%d ! = %d\n",i,res);
     }
     return res;
   }

int main (){
    //Q.1
    printf("**************************** Q.1 *********************************\n");
    int v;
    printf("Veuillez saisir une valeur(Q.1) : ");
    scanf("%i", &v);
     int res=0;
     int cpt=0;

       for(int i=0;i<v+1;i++){
         res=i*i*i;
         cpt+=res;

        }
     printf("Somme des cube de %d = %d\n", v,cpt);
     //Q.2-3
     printf("**************************** Q.2-3 *********************************\n");
     int f;
     printf("Saisissez une valeur(Q.2) : ");
     scanf("%d",&f);
     int f1=fact(f);
     printf("%d\n",f1);
     //Q.4
     printf("**************************** Q.4 *********************************\n");
     /*unsigned somme=0, nombre=0;
     double moyenne;
     for(int i=0;i<INT_MAX;i++){
        printf("Entrez un entier : ");
        scanf("%u",&nombre);
        somme+=nombre;
     if (nombre==0){
        moyenne=(double)somme/(i);
        printf("La moyenne vaut : %f",moyenne);
        break;
     }

     }*/

    double moy=0;
    unsigned u=0;
    unsigned p=0;
    puts("Entrez un entier : ");
    scanf("%u",&p);
    moy+=p;
    u+=1;
    while(p!=0){
      puts("Entrez un entier : ");
      scanf("%u",&p);
      moy+=p;
      u+=1;
    }
    printf("La moyenne vaut %f",moy/(u-1));

    return EXIT_SUCCESS;
}