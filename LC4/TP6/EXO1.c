#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/***************************** Q.1 **********************************/
char * dupliquer(const char * s){
    char * res=malloc((strlen(s)+1)*sizeof(char));
    strcpy(res,s);
    res[strlen(s)]='\0';
    return res;
}

/***************************** Q.2 **********************************/
int ordrealpha(const char * s1, const char * s2){
    int i=0;
   
    while(s1[i] && s2[i]){ //tant que les deux chaines ont des caractères à comparer
        if(s1[i]>s2[i]){ //s1 superieir à s2
            return 1;
        } else if (s1[i]<s2[i]){
            return -1;
        }
        i++;
    }
    if(s1[i]=='\0' && s1[i]=='\0'){ //les deux chaines sont identiques
        return 0;
    } else if(s1[i]=='\0'){ //s1 plus court que s2
        return -1;
    } else { //s2 plus court que s1
        return 1;
    }
}
/***************************** Q.3 **********************************/
char * multiplier(const char *s, unsigned int n){
   assert(s != NULL);
    size_t l = strlen(s);
    char * res = malloc(sizeof(char) * (l*n+1));
    assert(res);
    *res='\0';
    for(int i = 0; i < n; i++) {
        strcat(res,s);
    }
    res[strlen(res)] = '\0';
    return res;
}

int main(int argc, char *argv[]){
    printf("**************************** Q.1 *********************************\n");
    char *s="Bonjour";
    char *dup=dupliquer(s);
    printf("dupliquer -> %s\n",dup);
    free(dup);
    printf("**************************** Q.2 *********************************\n");
    char *s1="okay";
    char *s2="pkay";
    int alpha=ordrealpha(s1,s2);
    printf("ordrealpha -> %d\n",alpha);
    printf("**************************** Q.3 *********************************\n");
    char *o="okay";
    char *multipli=multiplier(o,3);
    printf("multiplier -> %s\n",multipli);
    printf("**************************** EXO2.1 *********************************\n");
    if (argc < 3) { // vérifie qu'il y a assez d'arguments
        printf("Ce programme attend 2 arguments, mais vous ne lui en avez fourni que %d.\n", argc - 1);
        return 1;
    }
    int resultat = ordrealpha(argv[1], argv[2]);
    if (resultat == 0) {
        printf("%s = %s\n", argv[1], argv[2]);
    } else if (resultat < 0) {
        printf("%s < %s\n", argv[1], argv[2]);
    } else {
        printf("%s > %s\n", argv[1], argv[2]);
    }

    if(argc < 3){
        printf("Ce programme attend 2 arguments, mais vous ne lui en avez fourni que %d.\n",argc-1);
        return 1;
    }
    int n = atoi(argv[2]); // convertit le deuxième argument en entier
    if (n == 0) { // vérifie que la conversion s'est bien passée
        printf("Ce programme attend un entier comme second argument.\n");
        return 1;
    }
    free(argv[1]);
    free(s);
    char *mult = multiplier(s1, n);
    printf("%s x %d = %s\n", s1, n, mult);
    free(mult); // libère la mémoire allouée par la fonction multiplier
    
    return 0;
}