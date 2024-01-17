#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/***************************** Q.1 **********************************/
void somme(int T[], int S[], size_t n){
    S[0]=T[0];
    for(size_t i=1;i<n;i++){
        S[i]=S[i-1]+T[i];
    }
}

/***************************** Q.2 **********************************/
void permute(int T[],size_t n){
    int tmp=T[n-1];
    int *t =(int*) malloc(sizeof(int) * n);;
    for (size_t i=0;i<n;i++){
        t[i]=T[i];
    }
     printf("\n");
    for (size_t i=1;i<n;i++){
        T[i]=t[i-1];
    }
    T[0]=tmp;

}

int main(){
    //Q.1
     printf("**************************** Q.1 *********************************\n");
     int T1 []={1,2,3,4,5};
     size_t n1 = sizeof(T1) / sizeof(T1[0]);
     int S1[n1];
     somme(T1, S1, n1);

     printf("Tableau T1 : ");
     for (size_t i = 0; i < n1; i++) {
     printf("%d ", T1[i]);
     }
     printf("\n");

     printf("Tableau S1 : ");
     for (size_t i = 0; i < n1; i++) {
     printf("%d ", S1[i]);
     }
     printf("\n");

     //Q.2
     printf("**************************** Q.2 *********************************\n");
     int T2 []={2,5,1,6,8,4,9,10,12,7};
     size_t n2=sizeof(T2)/sizeof(T2[0]);
     printf("Tableau 2 (avant permute): ");
     for(size_t i=0;i<n2;i++){
        printf("%d ",T2[i]);
     }
     permute(T2,n2);
      printf("\n");
     printf("Tableau 2 (apres permute): ");
     for(size_t i=0;i<n2;i++){
        printf("%d ",T2[i]);
     }


    return 0;
}