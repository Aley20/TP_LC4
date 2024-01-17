#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pt=malloc(5*sizeof(int));
    pt[0]=10;
    pt[1]=20;
    pt[12]=30;
    printf("{ ");
    for(size_t i=0;i<13;i++){
        printf("%d ",pt[i]);
    }
    puts("}");


    return 0;
}