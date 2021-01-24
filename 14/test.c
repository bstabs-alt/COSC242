#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void print_node(char *c){
    printf("%s\n", c);
}

int main (void){
    char arr[80];
    bst b = bst_new();

    while (1 == scanf("%79s", arr)){
        bst_insert(b, arr);
    }
    bst_search(b, arr);
    bst_delete(b, arr);
    bst_preorder(b,print_node);
    bst_free(b);
    return EXIT_SUCCESS;
}
