#include <stdio.h>
#include <stdlib.h>

/***************************** Q.1 **********************************/
size_t occ (int *t, size_t nbr, int v){
    size_t res=0;
    for(size_t i=0;i<nbr;i++){
        if(t[i]==v){
            res= i;
            break;
        }
        else 
        {
            res=nbr;
        }
    }
    return res;
}

/***************************** Q.2 **********************************/
int *occ_ptr (int *t, size_t nbr, int v){
    for(size_t i=0;i<nbr;i++){
        if(t[i]==v){
            return &t[i];
        }
    }
    return NULL;
}
int main(){
    int t[]={1,2,3,4,4};
    size_t nbr=5;
    int v=4;
    printf("**************************** Q.1 *********************************\n");
    printf("t={");
    for (size_t i=0;i<5;i++){
        printf("%d ",t[i]);
    }
    printf("} , nbr=%zu  ,v=%d\n ",nbr,v);
    printf("occ -> %zu\n",occ(t,nbr,v));
    printf("**************************** Q.2 *********************************\n");
    printf("t={");
    for (size_t i=0;i<5;i++){
        printf("%d ",t[i]);
    }
    printf("} , nbr=%zu  ,v=%d\n ",nbr,v);
    printf("occ_ptr -> %p \n ",occ_ptr(t,nbr,v));
}