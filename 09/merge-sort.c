#include <stdio.h>
#include <stdlib.h>
#include "merge-sort.h"
#include "mylib.h"

#define ARRAY_SIZE 100000

void merge(int *a, int *w, int n){
    int i = 0, k = 0, j = n/2;
    while(i < n/2 && j < n){
        if(a[i] < a[j]){
            *(w+k) = *(a+i);
            i++;
        } else {
            *(w+k) = *(a+j);
            j++;
        }
        k++;
    }
    while(i < n/2){
        w[k] = a[i];
        i++;
        k++;
    }
    while(j < n){
        w[k] = a[j];
        j++;
        k++;
    }
    
}

void merge_sort(int *a, int *w, int n){
    int i;
    if(n > 1){
        merge_sort(a, w, n/2);
        merge_sort(a+(n/2), w, n-(n/2));
        merge(a,w,n);   

        for(i = 0; i < n; i++){
            *(a+i) = *(w+i);
        }
    }
}
