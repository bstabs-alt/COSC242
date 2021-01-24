#include <stdio.h>
#include <stdlib.h>

void repeat(int *a, int n){
    int i, j;
    int *arr = malloc(n* sizeof a[0]);
        
    for(i=0; i < n; i++){
        int count = 0;
        for(j = 0; j < n; j++){
            if(a[j]==i){
                count++;
            }
        }
        arr[i] = count;
    }
    for(i = 0; i < n; i++){
        if(arr[i] > 1){
            printf("%d occurs %d times\n", i, arr[i]);
        }
    }
    free(arr);
}
    
int main(void){
    int array_size = 0;
    int *my_array;
    int i = 0;

    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array){
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < array_size; i++){
        my_array[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for(i = 0; i < array_size; i++){
        printf("%d ", my_array[i]);
    }
    
    printf("\n");

    repeat(my_array, array_size);
    
    free(my_array);
    
    return EXIT_SUCCESS;
}
