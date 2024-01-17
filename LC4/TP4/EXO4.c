#include <stdio.h>
#include <stdlib.h>

/***************************** Q.1 **********************************/
/*void print_tab (int *t, size_t start, size_t end){
    for(size_t i=start;i<end;i++){
        printf("%p : %d\n",&t[i],t[i]);

    }

}*/

/***************************** Q.2 **********************************/
void print_tab (int *pstart, int *pend){
    for(int *i=pstart;i< pend;i++){
        printf("%p : %d\n",i,*i);

    }
}

int main(){
    int t[]={1,5,2,1,1};
    //size_t start=0;
    size_t end=4;
    printf("**************************** Q.1 *********************************\n");
    /*printf("t={");
    for (size_t i=0;i<5;i++){
        printf("%d ",t[i]);
    }
    printf("}\n");
    print_tab(t,start,end);*/

    printf("**************************** Q.2 *********************************\n");
    print_tab(t,t+end);

    

}