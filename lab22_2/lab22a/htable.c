#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
struct htablerec {
    int capacity;
    int num_keys;
    char **keys;
};
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
    return i_key % h->capacity;
}

htable htable_new(int capacity) {
    int i;
    htable result = emalloc(sizeof * result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->keys = emalloc(result->capacity * sizeof result->keys[0]);
    for(i = 0; i < result->capacity; i++){
        result->keys[i] = NULL;
    }
    return result;
}

void htable_free(htable h) {
    int i;
    for(i = 0; i < h->capacity; i++){
        if(h->keys != NULL){
            free(h->keys[i]);
        }
    }
    free(h->keys);
    free(h);
}

int htable_insert(htable h, char *key) {
    int i = 0;
    int word = (htable_word_to_int(key) + i);
    int index = htable_hash(h, word);
    i = index;
    do{
        if(h->keys[i] == NULL){
            h->keys[i] = emalloc((strlen(key)+1) * sizeof (char));
            strcpy(h->keys[i], key);
            h->num_keys++;
            return 1;
        }
        if(strcmp(h->keys[i], key) == 0){
            return 0;
        }
        i++;
        i %= h->capacity;
    }while(i != index);
    return 0;
}


void htable_print(htable h, FILE *stream) {
    int i;
    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }
}
