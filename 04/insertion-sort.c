#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* insertion sorting method.
   takes pointer for my_array, and takes count;
   stores position at i in the key.
   move left item that us greater than key to the right.
   places key in the left vacted position.
 */
void insertion_sort(int *a, int n){
    int i, j, k;
    for(i = 1; i < n; i++){
        k = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > k){
            a[j+1] = a[j];
                j--;
        }
        a[j+1] = k;
    }
}
/* main method which takes no paramters. 
   counts the amount of positions being fed into the array.
   calls the sorting method.
   runs clock to determine time taken to sort.
   prints the sorted array and time taken.
 */
int main(void){
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count =0;
    
    while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count++;
    }
    
    start = clock();
    insertion_sort(my_array, count);
    end = clock();
    
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;    
}
