#include <stdio.h>
#include <stdlib.h>

void display_repeats(int *a, int b){
    int i = 0, j = 0, count = 0, x = 0;
    for(i = 0; i < b; i++){
        for(j = 0; j < b; j++){
            if(a[i] == a[j]){
                count++;
            }
        }
        for(x = 0; x < i; x++){
            if (a[x] == a[i]){
                count = 0;
            }
        }
        if(count >= 2){
            printf("%d: %d repeats\n", a[i], count);
        }
        count = 0;
        x = 0;
    }
}

int main(void) {
    int array_size = 0;
    int *my_dynamic_array;
    int i = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);
    /* initialise the array to the appropriate size */
    my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
    if (NULL == my_dynamic_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < array_size; i++) {
        my_dynamic_array[i] = rand() % array_size;
    }
    printf("What’s in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_dynamic_array[i]);
    }
    printf("\n");
    /* release the memory associated with the array */

    display_repeats(my_dynamic_array, array_size);
    
    free(my_dynamic_array);
    return EXIT_SUCCESS;
}
