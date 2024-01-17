#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
  size_t indice;
  size_t len;
} mutation;

/***************************** Q.1 **********************************/
int nboc(const char *s, const char *sub){
    int res=0;
    int len_s=strlen(s);
    int len_sub=strlen(sub);
    for(size_t i=0;i<=len_s-len_sub;i++){
        int j;
        for(j=0;j<len_sub;j++){
            if(s[i+j]!=sub[j]){
                break;
            }
        }
        if(j==len_sub){
            res++;
        }
    }
    return res;

}
/***************************** Q.2 **********************************/
/*mutation diff(const char *s, const char *t){
    assert(strlen(s)==strlen(t));
    mutation m;
    m.indice=-1;
    m.len=0;
    int i;
    for(i=0;i<strlen(s);i++){
        if(s[i]!=t[i]){
            if(m.indice==-1){
                m.indice=i;
                m.len=1;
            } else {
                m.len++;
            }
        }
    }
    return m;
}*/

mutation diff(const char *s, const char *t){
  
assert(strlen(s) == strlen(t));

int index=0;
while(s[index]!='\0' && t[index]!='\0' && s[index]==t[index]){
    index++;
}
int indice=index;
int l=0;
for(size_t i=index;i<strlen(s);i++){
    if(s[i]!=t[i]){
        l++;
    }
    //index++;
    //l++;
}
mutation m={m.indice=indice,m.len=l};
return m;
}

/***************************** Q.3 **********************************/
mutation longest(const char *s, const char *t){
    assert(strlen(s) == strlen(t));
    mutation m = {.indice = 0, .len = 0};
    mutation d = m;
    size_t l = strlen(s);
    for(int j = 0; j < l; j += d.indice + d.len) {
        d = diff(s + j, t + j); 
        if (d.len == 0) break;
        if (d.len > m.len) {
            m.indice = d.indice;
            m.len = d.len;
        }
    }
    return m;
}

char *longest_string(const char *s, const char *t) {
    mutation longest_mutation = longest(s, t);
    char *result = (char*) malloc((longest_mutation.len + 1) * sizeof(char));
    strncpy(result, t + longest_mutation.indice, longest_mutation.len);
    result[longest_mutation.len] = '\0';
    return result;
}

int main() {
    printf("**************************** Q.1 *********************************\n");
    const char *s = "aaacaa";
    const char *sub = "aa";
    printf("nboc -> %d\n", nboc(s, sub)); 
    printf("**************************** Q.2 *********************************\n");
    mutation m = diff("acca", "aaaa");
    printf ("diff -> m.indice=%zu, m.len=%zu \n",m.indice,m.len);
    printf("**************************** Q.3 *********************************\n");
    m = longest("atcgatatt", "aaagccata");
    printf ("longest -> m.indice=%zu, m.len=%zu \n",m.indice,m.len);
    char *c = longest_string("atcgatatt", "aaagccata");
    printf("%s\n",c);
    return 0;
}
