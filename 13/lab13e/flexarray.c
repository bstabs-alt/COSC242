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

flexarray f_new(){
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void f_append(flexarray f, int n){
    if(f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f-> capacity *sizeof f->items[0]);
    }
    f->items[f->itemcount++] = n;
}

void f_print(flexarray f){
    int i;
    for(i=0;i < f->itemcount;i++){
        printf("%d\n", f->items[i]);
    }
}

void pr(flexarray f){
    int i;
    for(i=0;i < f->itemcount;i++){
        fprintf(stderr, "%d\n", f->items[i]);
    }
}

void f_sort(flexarray f){
    int i,j,k,x;
    for(i = 0; i < f->itemcount-1;i++){
        if(i==f->itemcount/2){
            pr(f);
        }
        x = i;
        for(j = i+1; j < f->itemcount; j++){
            if(f->items[j] < f->items[x]){
                x = j;
            }
        }
        k = f->items[i];
        f->items[i] = f->items[x];
        f->items[x] = k;
    }
}

void f_free(flexarray f){
    free(f->items);
    free(f);
}
