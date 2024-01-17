#include <stdio.h>
#include <stdlib.h>
int main() {
    unsigned a=3;
    int n = 42;
    int m = 2;
    double x = 3.14;
                        // (dans le terminal :) 
    printf("%u\n",a); //3
    printf("%d\n", n + 1); // 43
    printf("%d + %d = %d\n", n, m, n + m); // 42 + 2 = 44
    printf("%d / %lf = %lf\n", n, x, n / x); // 42 / 3.140000 = 13.375796

    unsigned v;
    unsigned p;
    printf ("Valeur x : ");
    scanf("%u",&v);
    printf ("Valeur y : ");
    scanf("%u",&p);
    printf ("valeur x y  : %u %u\n",v,p);
    printf ("Somme %u\n",v+p);
    return EXIT_SUCCESS;
    //return EXIT_SUCCESS;




}