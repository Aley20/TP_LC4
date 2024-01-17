#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>


//Question 1//
int nbr_words(const char *s){
    int cpt=0;
    int l=1;

    for(int i=0;i<strlen(s);i++){
        int p=isspace(s[i]);
        if(p==1){
            l=1;
        }
         else if(l==1){
            l=0;
            cpt++;
        }

    }

    return cpt;

}



//Question 2//
int word_len(const char *w){ 
   int estLettre=(*w>='a' && *w<='z') || (*w>='A' && *w<='Z');
   assert(estLettre);

   int len=strlen(w);
   int i=0;
   int esp=0;
   int occ=0;
   while(i<len && esp==0){
       int p=isspace(w[i]);
       if(p==1){
           esp=1;
       }
       else
       {
           occ++;
       }
        i++;
   }
  
   return occ;

}
//Question 3//
char* extract_world(const char * w, int * pl){
    int estLettre=(*w>='a' && *w<='z') || (*w>='A' && *w<='Z');
    assert(estLettre);
    int l=word_len(w);
    *pl=l;
    char *r=malloc(sizeof(char)*(l+1));
    assert(r);
    memmove(r,w,sizeof(char)*l);
    r[l]='\0';
    return r;

}

//Question 4//
char *next_word(const char *w){
    int len=strlen(w);
    int i=0;
    while(i<len){
        if(!isspace(w[i])){
            return (char*)w+i;

        }
        i++;
    }
    return NULL;
}


int main(){
    char * s="a aa ba a bbbb";
    char * v=" abc d";
    int j=0;
    int *i=&j;
    //Question 1//
    printf("*************** Question 1 **********\n");
    printf("%s -> %d\n",s,nbr_words(s));
    //Question 2//
    printf("*************** Question 2 **********\n");
    printf("%s -> %d\n",v,word_len(v+1));

    //Question3//
    printf("*************** Question 3 **********\n");
    printf("avant : w=%s , pl=%d\n",v,*i);
    printf("%s \n",extract_world((v+1),i));
    printf("apres : w=%s , pl=%d\n",v,*i);

    //Question 4//
    printf("*************** Question 4 **********\n");
    printf("%s -> %s\n", v, next_word(v));
    printf("%s -> %s", v, next_word(v+4));
}