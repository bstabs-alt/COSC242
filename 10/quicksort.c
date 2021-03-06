#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "mylib.h"

#define ARRAY_SIZE 100000

void quick_sort(int *a, int n){
    int i, j, k, p;
    if(n > 1){   
        p = a[0];
        i = -1;
        j = n;

        for(;;){
            do{
                i++;
            } while(a[i] < p);
           
            do{
                j--;
            } while(a[j] > p);
                
            if(i < j){
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            } else {
                break;
            }
        }
        quick_sort(a, j+1);
        quick_sort(a+j+1,n-j-1);
    }
}
