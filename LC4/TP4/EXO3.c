#include <stdio.h>
#include <stdlib.h>

/***************************** Q.1 **********************************/

size_t nbr_occ (int *t, size_t nbr, int v){
    size_t res=0;
    for (size_t i=0;i<nbr;i++){
        if(t[i]==v){
            res++;
        }
    }
    return res;
}

/***************************** Q.2 **********************************/
void nbr_occ_op (int *t, size_t nbr, int v, size_t *pnv){
    *pnv=nbr_occ(t,nbr,v);

}

/***************************** Q.3 **********************************/
void min_max_op (int *t, size_t nbr, int *pmin, int *pmax){
    int min=t[0];
    int max=t[0];
    for(size_t i=0;i<nbr;i++){
        if(t[i]>max){
            max=t[i];

        }
        if(t[i]<min) 
        {
            min=t[i];
        }
        
    }
    *pmin=min;
    *pmax=max;
}


int main(){
    int t[]={4,2,3,4,4};
    size_t nbr=5;
    int v=4;
    printf("**************************** Q.1 *********************************\n");
    printf("t={");
    for (size_t i=0;i<5;i++){
        printf("%d ",t[i]);
    }
    printf("} , nbr=%zu  ,v=%d\n ",nbr,v);
    printf("occ -> %zu\n",nbr_occ(t,nbr,v));

    printf("**************************** Q.2 *********************************\n");
    size_t pnv=0;
    printf("pnv avant : %zu\n",pnv);
    nbr_occ_op(t,nbr,v,&pnv);

    printf("pnv apres : %zu\n",pnv);

    printf("**************************** Q.3 *********************************\n");
    int tab[]={1,2,-1,5,9,1};
    size_t n=6;
    printf("tab={");
    for (size_t i=0;i<5;i++){
        printf("%d ",tab[i]);
    }
    printf("}\n");
    int pmin=0;
    int pmax=0;
    printf("pmin avant: %d , pmax avant: %d\n",pmin,pmax);
    min_max_op(tab,n,&pmin,&pmax);
    printf("pmin apres: %d , pmax apres: %d\n",pmin,pmax);

    return 0;
}

