#include <stdio.h>
#include <stdlib.h>

/* scanf needs & infront of variables because it needs to know the memory addresses it will read the data into*/

void max_min(int *a, int j, int *max, int *min){
    int i = 0;
    *min = a[i];
    for(i = 0; i < j; i++){
        if(*max < a[i]){
            *max = a[i];
        }
        if(*min > a[i]){
            *min = a[i];
        }
    }
}


int main(void){
    int max=0, min=0;
    int arr[] = {7,4,6,2,2,4,9};
    max_min(arr, 7, &max, &min);
    printf("Max: %d\nMin: %d\n", max, min);
    return EXIT_SUCCESS;
}
