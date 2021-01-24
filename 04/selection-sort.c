#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* selection sorting method.
   goes through each position in the array except the last.
   finds the smallest item from current position to n-1.
   swaps smallest item with current positions item.
 */
void selection_sort(int *a, int n){
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(a[j] < a[i]){
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
}

/*main method which takes no parameters.
  counts the amount of positions being fed into the array.
  calls the sorting method.
  runs clock to determine time taken to sort.
  prints the sorted array and time taken
 */
int main(void){
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    
    while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count++;
    }
    
    start = clock();
    selection_sort(my_array, count);
    end = clock();
    
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;        
}
