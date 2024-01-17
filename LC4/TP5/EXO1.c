#include <stdio.h>
#include <stdlib.h>

int main(){

    int t[]={1,2,3};
    int *pt=t;
    printf("%d \n",*(pt+1));

    int t1[3]={1,2,3};
    int *pt1=t1+1;
    printf("%d \n",*pt1);

    int *pt2=&t[1];
    printf("%d \n",*pt2);

    int *pt3;
    pt3=t;

    int t3[3];
    int *ptt=malloc(5*sizeof(int));
    pt=t3;
    printf("%d \n",*ptt);

    printf("tab u :\n");

    int *u=malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        printf("%d ",u[i]);
    }
    printf("\n");
    u[0]=10;
    u[1]=20;
    u[12]=30;

    for(int i=0;i<5;i++){
        printf("%d ",u[i]);
    }
    printf("\n");

    


    


    return 0;

}
