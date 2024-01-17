#include <stdio.h>
#include <stdlib.h>
int main() {
    unsigned v;
    unsigned p;
    puts ("Valeur x : ");
    scanf("%u",&v);
    puts ("Valeur y : ");
    scanf("%u",&p);
    printf ("valeur x y  : %u %u\n",v,p);
    printf ("Somme %u + %u = %u \n",v,p,v+p);
    return EXIT_SUCCESS;

}