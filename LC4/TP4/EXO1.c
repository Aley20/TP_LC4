#include <stdio.h>
#include <stdlib.h>

void swap (int *p,int *q){
    int tmp=*p;
    *p=*q;
    *q=tmp;
}

int main(){
    int x, y;
    x = 5;
    y = 6;
    printf ("(avant) x : %d, y : %d\n", x, y); // => (avant) 5 6 
    swap (&x, &y);
    printf ("(apres) x : %d, y : %d\n", x, y); // => (apres) 6 5

    int tab []={1,2,3,4};
    printf("Avant : ");
    for (size_t i=0;i<4;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
    swap (&tab[0], &tab[3]);
    
    printf("Apres : ");
    for (size_t i=0;i<4;i++){
        printf("%d ",tab[i]);
    }
    return 0;
}