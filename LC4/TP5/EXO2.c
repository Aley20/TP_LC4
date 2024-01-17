#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct array {
  int *content;
  size_t capacity;
  size_t size;
};
typedef struct array array;

/***************************** Q.1 **********************************/
array *array_init(size_t capacity){
    array *res=malloc(sizeof(array));
    if(res==NULL){
        return NULL;
    }
    res->capacity=capacity;
    res->size=0;
    res->content=malloc(capacity*sizeof(int));
    if(res->content==NULL){
        return NULL;
    }

    return res;
}

/***************************** Q.2 **********************************/
void array_destroy(array *pa){
    free(pa->content);
    free(pa);

}

/***************************** Q.3 **********************************/
   int array_get(array *pa, size_t index){
    assert(index<pa->size);
    return pa->content[index];
   }

    void array_set(array *pa, size_t index, int value){
        assert(index<pa->size);
        pa->content[index]=value;

    }

/***************************** Q.4 **********************************/
    bool array_append(array *pa, int value){
        bool ok=false;
        if(pa->capacity>pa->size){ 
        pa->content[pa->size]=value;
        pa->size++;
        ok=true;
        }
        return ok;
    }

/***************************** Q.5 **********************************/
    void array_print(array *pa){
        printf("Capacité : %ld, Taille : %ld\n", pa->capacity, pa->size);
        printf("[ ");
        for (size_t i = 0; i < pa->size; i++) {
            printf("%d ", pa->content[i]);
        }
        printf("]\n");

    }

/***************************** Q.6 **********************************/
    int *array_search(array *pa, int value){
        for(size_t i=0;i<pa->size;i++){
            if(pa->content[i]==value){
                return &(pa->content[i]);
            }
            
        }
        return NULL;
    }

/***************************** Q.7 **********************************/
    array *array_init_from(int *data, size_t length, size_t capacity){
        assert(capacity>=length);
        array *res=malloc(sizeof (array));
        if(res==NULL) return NULL;
        res->content=malloc(capacity*sizeof(int));
        if(res->content==NULL) {
            free(res);
            return NULL;
        }
        res->capacity=capacity;
        res->size=length;

        memcpy(res->content, data, length * sizeof(int));

        return res;
    }

/***************************** Q.8 **********************************/
    void array_remove(array *pa, size_t index){
        assert(index<pa->size);
        for(size_t i=index;i<pa->size;i++){
            pa->content[i]=pa->content[i+1];
        }

        pa->size--;

    }

/***************************** Q.9 **********************************/
    void array_insert(array *pa, size_t index, int value){
        assert(index<=pa->size);

        if(pa->size==pa->capacity){
            pa->capacity*=2;
            pa->content=realloc(pa->content,pa->capacity*sizeof(int));
        }

        for(size_t i=pa->size;i>index;i--){
            pa->content[i]=pa->content[i-1];
        }

        pa->content[index]=value;
        pa->size++;

    }




int main() {
    printf("**************************** Q.1 *********************************\n");
    array *arr = array_init(10);
    if (arr == NULL) {
        printf("Erreur !\n");
    }
    free(arr->content);
    free(arr);

    printf("**************************** Q.2 *********************************\n");
    arr=array_init(4);
    array_destroy(arr);

    printf("**************************** Q.3 *********************************\n");
    array_print(arr);

    printf("**************************** Q.4 *********************************\n");
    printf("ajout 5 : %d\n",array_append(arr,5));
    printf("ajout 3 : %d\n",array_append(arr,3));
    printf("ajout 2 : %d\n",array_append(arr,2));
    printf("ajout 4 : %d\n",array_append(arr,4));
    printf("ajout 4 : %d\n",array_append(arr,4));
    array_print(arr);

    int p=array_get(arr,0);
    printf("array_get(0) %d \n",p);
    array_set(arr,0,4);
    printf("array_set(0,4) \n");

    array_print(arr);

    printf("**************************** Q.6 *********************************\n");
    int *r=array_search(arr,4);
    printf("Q.6 -> %p\n",r);

    printf("**************************** Q.7 *********************************\n");
    int t []={1,2,3};
    array_print(array_init_from(t,3,10));

    printf("**************************** Q.8 *********************************\n");
    array* a=array_init_from(t,3,10);
    array_remove(a,1);
    array_print(a);

    printf("**************************** Q.9 *********************************\n");
    array_insert(a,2,6);
    array_insert(a,1,6);
    array_insert(a,4,6);
    array_print(a);
   

    return 0;

}
