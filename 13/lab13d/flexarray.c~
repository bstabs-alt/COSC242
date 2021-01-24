#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec{
    int capacity;
    int itemcount;
    int *items;
};

static void *emalloc(size_t s){
    void *r = malloc(s);
    if(NULL == r){
        exit(EXIT_FAILURE);
    }
    return r;
}

static void *erealloc(void *p, size_t s){
    void *r = realloc(p,s);
    if(NULL == r){
        exit(EXIT_FAILURE);
    }
    return r;
}

flexarray flexarray_new(){
    flexarray f = emalloc(sizeof *f);
    f->capacity = 2;
    f->itemcount = 0;
    f->items = emalloc(f->capacity*sizeof f->items[0]);
    return f;
}

void flexarray_append(flexarray f, int num){
    if(f->itemcount == f->capacity){
        f->capacity *= 2;
        f->items = erealloc(f->items, f->capacity *sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f){
    int i;
    for(i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}

void pr(flexarray f){
    int i;
    for(i = 0; i < f->itemcount; i++){
        fprintf(stderr, "%d\n", f->items[i]);
    }
}

void flexarray_sort(flexarray f){
    int i,j,k;
    for(i = 0;i < f->itemcount; i++){
        k =  f->items[i];
        j = i-1;
        
        if(i == (f->itemcount/2)){
            pr(f);
        }
        while(j >= 0 &&  f->items[j] > k){
            f->items[j+1] =  f->items[j];
            j=j-1;
        }
        f->items[j+1] = k;
    }
}

void flexarray_free(flexarray f){
    free(f->items);
    free(f);

}
