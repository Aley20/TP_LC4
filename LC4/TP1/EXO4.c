#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>

/***************************** Q.1 **********************************/
unsigned retourne(unsigned n){
    unsigned i=0;
    while(n!=0){
        n/=10;
        i++;
    }
    return i;
}

/***************************** Q.2 **********************************/
unsigned sommeChiffre(unsigned n){
    unsigned somme=0;
    unsigned i=0;
    if(n<10){
        return n;
    }
    while(n!=0){ 
        i=n%10;
        somme+=i;
        n/=10;
    }
    return somme;
}

/***************************** Q.3_a **********************************/
bool estNarcissique(unsigned n){
    unsigned p=0;
    bool ok=true;
    unsigned tmp=n;
    while(n!=0){
        unsigned i=n%10;
        p+=i*i*i;
        n/=10;
    }
    if (p!=tmp){
        ok=false;
    }

    return ok;
}

/***************************** Q.3_b **********************************/
void afficheNarcissique(unsigned n){
    for (int i=1;i<=n;i++){
        if(estNarcissique(i)){
            printf("%d\n",i);
        }
    }
}

/***************************** Q.4 **********************************/
unsigned retourne_1(unsigned n){
    int number;
	char text[20];
    char a[20]="";
    while(n!=0){
        number=n%10;
        n/=10;
        sprintf(text, "%d", number);
        strcat(a,text);
    }
    unsigned p=atoi(a);
    return p;
}

int main(){
    //Q.1
     printf("**************************** Q.1 *********************************\n");
    unsigned v;
    printf("Veuillez saisir une valeur :");
    scanf("%u",&v);
    printf("retourne (%u) -> %u\n",v,retourne(v));
    //Q.2
    printf("**************************** Q.2 *********************************\n");
    printf("sommeChiffre(%u) -> %u\n",v,sommeChiffre(v));
    //Q.3_a
    printf("**************************** Q.3_a *********************************\n");
    printf("Veuillez saisir une valeur : ");
    scanf("%u",&v);
    printf("estNarcissique(%u) -> ",v);
    printf(estNarcissique(v) ? "true" : "false");
    printf("\n");
    //Q.3_b
    printf("**************************** Q.3_b *********************************\n");
    afficheNarcissique(v);
     //Q.4
    printf("**************************** Q.4 *********************************\n");
    //printf("retourne(%u) -> %u \n",v,retourne_1(v));
    return EXIT_SUCCESS;

}