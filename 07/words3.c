#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 80
#define ARRAY_MAX 100

void *emalloc(size_t s){
    void *r = malloc(s);
    if(NULL == r){
        fprintf(stderr, "ERROR\n");
        exit(EXIT_FAILURE);
    }
    return r;
}

void print_arr(char **a, int n, double d){
    if(n > 0){
        if(d < strlen(a[0])){
            printf("%s\n",a[0]);
        }
        print_arr(a+1,n-1,d);
    }

}

int main(void){
    int i, c = 0;
    double ave = 0.0;
    char word[WORD_LEN];
    char *list[ARRAY_MAX];
    
    while(c < ARRAY_MAX && 1 == scanf("%79s", word)){
        list[c] = emalloc((strlen(word)+1)*sizeof list[0][0]);
        strcpy(list[c],word);
        ave += strlen(word);
        c++;
    }
    
    if(c !=  0){
        ave /= c;
        print_arr(list,c,ave);
        fprintf(stderr, "%.2f\n", ave);
     
    }

    for(i=0;i<c;i++){
        free(list[i]);
    }
    
    return EXIT_SUCCESS;
}
