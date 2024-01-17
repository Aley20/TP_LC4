#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

int main(){
    //Q.1
    printf("**************************** Q.1 *********************************\n");
    int n;
    printf("Saisissez une valeur : ");
    scanf("%d",&n);
    int res=n;
    int cpt=0;
    //printf("%d ",res);
    while(res>1){
        if(res%2==0){
            printf("%d ",res);
            res=res/2;
            cpt++;
        } else {
            printf("%d ",res);
            res=res*3+1;
            //res=res+1;
            cpt++;
        
    }
       // printf("%d ",res);
       //printf("%d : %d\n",i,res);


     }
     printf("%d ",res);
     printf("\n");
     //Q.1
     printf("**************************** Q.2 *********************************\n");
     printf("%d : %d\n",n,cpt);

     //Q.3
     printf("**************************** Q.3 *********************************\n");
     int cpt1=0;
     for(int i=1;i<n+1;i++){  

        int res1=i;
        while(res1>1){
            if(res1%2==0){
                 res1=res1/2;
                 cpt1++;
            } else {
                 res1=res1*3;
                 res1++;
                 cpt1++;
  }
}
     printf("%d : %d \n",i,cpt1);
      cpt1=0;
     }

     return EXIT_SUCCESS;
    }

