#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***************************** Q.1 **********************************/
void initialisation(bool T[],size_t n){
    for(size_t i=0;i<n;i++){
        T[i]=true;
    }

}

/***************************** Q.2 **********************************/
#define SUP 10
void remplissage(bool T[],size_t n){
        for (size_t i=2;i<n;i++){
            if(T[i]){
                for(size_t j =i*i;j<n;j+=i){
                    T[j]=false;
                }
            }
        }
    }

/***************************** Q.3 **********************************/
void affichNbPremier(bool T[],size_t n){
    for(size_t i=0;i<n;i++){
        if(T[i]){
            printf("%zu ",i);
        }
    }
    printf("\n");
}


int main(){
//Q.1
    printf("**************************** Q.1 *********************************\n");
    size_t n = 10;
    bool T[n];
    initialisation(T, n);
    printf("initialisation : ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
    //Q.2
    printf("**************************** Q.2 *********************************\n");
    remplissage(T,n);
    printf("Remplissage : ");
     for (size_t i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
    //Q.3
    printf("**************************** Q.3 *********************************\n");
    printf("affichNbPremier : ");
    affichNbPremier(T,n);
    return 0;
}