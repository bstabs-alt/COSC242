#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10000

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

int main(int argc, char **argv){
    FILE *infile;
    int my_array[ARRAY_MAX];
    int check, count = 0, i;
    

    if(NULL == (infile = fopen(argv[1], "r"))){
        fprintf(stderr, "%s: cant find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }
    while(count < ARRAY_MAX && 1 == fscanf(infile, "%d", &my_array[count])){
        count++;
    }

    fclose(infile);
    selection_sort(my_array, count);

    while(1 == scanf("%d", &check)){
        for(i = 0; i < count; i++){
            printf("%s\n", my_array[i] == check ? "+" : "-");     
        }
    }
    printf("%d", argc);
    return EXIT_SUCCESS;        
}
