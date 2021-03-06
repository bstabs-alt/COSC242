#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec{
    int capacity;
    int num_keys;
    int *freq;
    char **key_arr; 
};

htable htable_new(int capacity){
    int i;
    htable result = emalloc(sizeof * result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->freq = emalloc(result->capacity * sizeof result->freq[0]);
    result->key_arr = emalloc(result->capacity * sizeof result->key_arr[0]);
    for(i = 0; i < result->capacity; i++){
        result->freq[i] = 0;
        result->key_arr[i] = NULL;
    }
    return result;
}

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

static unsigned int htable_step(htable h, unsigned int i_key) {
    return 1 + (i_key % (h->capacity - 1));
}

int htable_insert (htable h, char *str){
    unsigned int word, pos, i, opos, step;
    
    word = htable_word_to_int(str);
    pos = word % h->capacity;
    step = htable_step(h, word);
    
    if (h->key_arr[pos] != NULL && strcmp(h->key_arr[pos], str) == 0){
        h->freq[pos]++;
        return h->freq[pos];
    } else {
        opos = pos;
        i = pos;
        do{
            if (h->key_arr[i] == NULL){
                h->key_arr[i] = emalloc((strlen(str)+1) * sizeof (char));
                strcpy(h->key_arr[i], str);
                h->freq[i]++;
                h->num_keys++;
                return 1;
            } else if (strcmp(h->key_arr[i], str) == 0){
                h->freq[i]++;
                return h->freq[i];
            }
            i = (i+step)%h->capacity;
        } while (i != opos);
        return 0;
    }
    return 0;
}

void htable_print(htable h, FILE *stream){
    int i;

    for(i = 0; i < h->capacity; i++){
        if(h->key_arr != NULL){
            fprintf(stream,"%10d, %s\n",h->freq[i],h->key_arr[i]);
        }
    }
}

int htable_search(htable h, char *str){
    unsigned int word, step;
    int cols = 0, pos;
    word = htable_word_to_int(str);
    pos = word % h->capacity;
    step = htable_step(h,word);
    while(h->key_arr[pos] != NULL && strcmp(h->key_arr[pos], str) != 0 && cols != h->capacity){
        pos = pos + step;
        cols++;
    }

    if(cols == h->capacity){
        return 0;
    } else {
        return h->freq[pos];
    }
}

void htable_free(htable h){
    int i;
    for(i=0;i<h->capacity;i++){
        if(h->key_arr[i] != NULL){
            free(h->key_arr[i]);
        }
    }
    free(h->key_arr);
    free(h->freq);
    free(h);
}
