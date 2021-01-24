#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 80
#define ARRAY_LEN 100

void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr, "Memmory Allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void average_print(char **a, double n, int c){
    if(c > 0){
        if(strlen(a[0]) > n){
            fprintf(stderr,"%s\n", a[0]);
        }
        average_print(a+1, n, c-1);
    }
}

int main(void){
    int i, count = 0;
    char word[WORD_LEN];
    char *wordlist[ARRAY_LEN];
    double average = 0.0;
    
    while(count < ARRAY_LEN && 1 == scanf("%79s", word)){
        wordlist[count] = emalloc((strlen(word)+1) * sizeof wordlist[0][0]);
        strcpy(wordlist[count], word);
        count++;
    }
    
    for(i = 0; i < count; i++){
        average += strlen(wordlist[i]);
    }

    if(count != 0){
    average = average/count;
    average_print(wordlist, average, count);
    fprintf(stderr, "%.2f\n", average);
    }
    
    for(i = 0; i < count; i++){
        free(wordlist[i]);
    }

    return EXIT_SUCCESS;
}
