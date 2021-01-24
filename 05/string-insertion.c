#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 10000
#define CHAR_MAX 80


void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr, "Memory Alloc failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void insertion_sort(char **a, int n){
    int i, j;
    char *k; 
    for(i = 1; i < n; i++){
        k = a[i];
        j = i-1;
        while(j >= 0 && strcmp(a[j], k) > 0){
            a[j+1] = a[j];
                j--;
        }
        a[j+1] = k;
    }
}


int main(void){
    char *words_array[WORD_MAX];
    char word[CHAR_MAX];
    int i, count = 0;
    
    while(count < WORD_MAX && 1 == scanf("%79s", word)){
        words_array[count] = emalloc((strlen(word) + 1) * sizeof words_array[0][0]);
        strcpy(words_array[count], word);
        count++;
    }
    
    insertion_sort(words_array, count);
    
    for(i = 0; i < count; i++){
        printf("%s\n", words_array[i]);
    }
    printf("%d\n", count);
    return EXIT_SUCCESS;    
}
