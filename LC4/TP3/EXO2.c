#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100

struct polynome{
    int de;
    int co[N]; 
}; typedef struct polynome polynome;

/***************************** Q.1 **********************************/
int eval(polynome p, int x){
    int res=0;
    for(size_t i=0;i<p.de+1;i++){
        res += p.co[i] * pow(x, i);
    }
    return res;
}

/***************************** Q.2 **********************************/
void print_poly(polynome p){
    for (int i = p.de; i >= 0; i--) {
    if (p.co[i] == 0) { //SI le coeff est égal à 0, on continue sans rien afficher
      continue;
    }
    if (i == p.de) { //Cas ou on est dans le dernier coeff (degré max p.de) 
      printf("%dX^%d", p.co[i], i);
    } else if (i == 0) { //Cas ou le degre vaut 0
      printf(" + %d", p.co[i]);
    } else if (i == 1) { //Cas ou le degre vaut 1
      printf(" + %dX", p.co[i]);
    } else {
      printf(" + %dX^%d", p.co[i], i);
    }
  }
}

/***************************** Q.3 **********************************/
polynome derive(polynome p){
    polynome res;
    res.de=p.de-1;
    for (size_t i=p.de;i>0;i--){
        res.co[i-1]=p.co[i]*i;
    }
    return res;
}

/***************************** Q.4 **********************************/
polynome addition(polynome p1,polynome p2){
    polynome res;
    int degre=fmax(p1.de,p2.de);
    res.de=degre;
    for(size_t i=0;i<=degre;i++){
        if(i<=p1.de){
            res.co[i]+=p1.co[i];
        }
        if(i<=p2.de){
            res.co[i]+=p2.co[i];
        }

    }
    return res;
}

/***************************** Q.5 **********************************/
polynome multiplication(polynome p1,polynome p2){
    polynome res;
    res.de=p1.de+p2.de;
    for(size_t i=0;i<=p1.de;i++){
        for(size_t j=0;j<=p2.de;j++){
            res.co[i+j] += p1.co[i]*p2.co[j];
        }
    }
    return res;
}

int main(){

    polynome p={3,{1, 4, 0, 3}};
    printf("**************************** Q.1 *********************************\n");
    printf("eval(p, -1) = %d\n",eval(p,-1));
    printf("\n");

    printf("**************************** Q.2 *********************************\n");
    print_poly(p);
    printf("\n");

    printf("**************************** Q.3 *********************************\n");
    print_poly(derive(p));
    printf("\n");

    printf("**************************** Q.4 *********************************\n");
    polynome p1={2,{1,1,2}};
    polynome p2={1,{2,3}};
    printf("polynome 1 : ");
    print_poly(p1);
    printf("\n");
    printf("polynome 2 : ");
    print_poly(p2);
    printf("\n");
    printf("Addition : ");
    print_poly(addition(p1,p2));
    printf("\n");
    printf("\n");

    printf("**************************** Q.5 *********************************\n");
    printf("polynome 1 : ");
    print_poly(p1);
    printf("\n");
    printf("polynome 2 : ");
    print_poly(p2);
    printf("\n");
    printf("Multiplication : ");
    print_poly(multiplication(p1,p2));
    printf("\n");

}