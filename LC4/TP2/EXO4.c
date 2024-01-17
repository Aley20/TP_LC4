#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/***************************** Q.1 **********************************/
struct fraction {
long int num;
long int den;
} typedef fraction;

/***************************** Q.2 **********************************/
fraction build(long int n, long int d){
    assert(d!=0);
    fraction f={.num=n, .den=d};
    return f;
}

/***************************** Q.4 **********************************/
bool eq_fraction(fraction f, fraction g){
    return f.num*g.den==g.num*f.den;
   
}

/***************************** Q.5 **********************************/
bool is_int(fraction f){
    return f.den==1;

}

/***************************** Q.6 **********************************/
fraction sum(fraction f, fraction g){ 
    long int n=(f.num*g.den)+(g.num*f.den);
    long int d=f.den*g.den;
    return build(n,d);

}

fraction sub(fraction f, fraction g) {// soustraction
    long int n=(f.num*g.den)-(g.num*f.den);
    long int d=f.den*g.den;
    return build(n,d);

}

fraction mul(fraction f, fraction g) {// multiplication
    long int n=f.num*g.num;
    long int d=f.den*g.den;
    return build(n,d);

}

/***************************** Q.7 **********************************/
long pgcd(long a, long b){
    long x=a;
    long y=b;
    while (y !=0){
        long r=x%y;
        x=y;
        y=r;
    }
    return x;

}

fraction reduce(fraction f){
    long int diviseur = pgcd(f.num, f.den);
    f.num /= diviseur;
    f.den /= diviseur;
    if (f.den < 0) {
        f.num *= -1;
        f.den *= -1;
    }
    return f;
}
int main(){

    //Q.2
    printf("**************************** Q.2 *********************************\n");
    fraction f=build(5,8);
    printf("numerateur: %ld / denominateur: %ld \n",f.num,f.den);
    printf("\n");
    //Q.3
    printf("**************************** Q.3 *********************************\n");
    fraction ex_fractions[7]={
        build(1,1),
        build(1,2),
        build(2,4),
        build(-9,3),
        build(8,-20),
        build(-5,-1),
        build(1,-3)
    };
    for(size_t i=0;i<sizeof(ex_fractions)/sizeof(ex_fractions[0]);i++){
        printf("%zu. numerateur: %ld / denominateur: %ld \n",i,ex_fractions[i].num,ex_fractions[i].den);
    }
    printf("\n");
    //Q.4
    printf("**************************** Q.4 *********************************\n");
    printf(eq_fraction(ex_fractions[1],ex_fractions[2]) ? "true" : "false"); //true
    printf("\n");
    printf(eq_fraction(ex_fractions[0],ex_fractions[4]) ? "true" : "false"); //false
    printf("\n");

    //Q.5
    printf("**************************** Q.5 *********************************\n");
    printf(is_int(ex_fractions[1]) ? "true" : "false"); //false
    printf("\n");
    printf(is_int(ex_fractions[0]) ? "true" : "false"); //true
    printf("\n");
     //Q.6
    printf("**************************** Q.6 *********************************\n");
    printf("Somme :");
    printf(" %ld / %ld ,",ex_fractions[0].num,ex_fractions[0].den);
    printf(" %ld / %ld -> ",ex_fractions[1].num,ex_fractions[1].den);
    printf(" %ld / %ld \n",sum(ex_fractions[0],ex_fractions[1]).num,sum(ex_fractions[0],ex_fractions[1]).den);

    printf("Soustraction :");
    printf(" %ld / %ld ,",ex_fractions[0].num,ex_fractions[0].den);
    printf(" %ld / %ld -> ",ex_fractions[1].num,ex_fractions[1].den);
    printf(" %ld / %ld \n",sub(ex_fractions[0],ex_fractions[1]).num,sub(ex_fractions[0],ex_fractions[1]).den);

    printf("Multiplication :");
    printf(" %ld / %ld ,",ex_fractions[0].num,ex_fractions[0].den);
    printf(" %ld / %ld -> ",ex_fractions[1].num,ex_fractions[1].den);
    printf(" %ld / %ld \n",mul(ex_fractions[0],ex_fractions[1]).num,mul(ex_fractions[0],ex_fractions[1]).den);

    //Q.7
    printf("**************************** Q.7 *********************************\n");
    for(size_t i=0;i<sizeof(ex_fractions)/sizeof(ex_fractions[0]);i++){
        printf(" %ld/%ld -> %ld/%ld \n",ex_fractions[i].num,ex_fractions[i].den,reduce(ex_fractions[i]).num,reduce(ex_fractions[i]).den);
    }
    return 0;
}