#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void){
    int item;
    
    flexarray my_flexarray = f_new();

    while(1 == scanf("%d", &item)){
        f_append(my_flexarray, item);
    }
    f_sort(my_flexarray);
    f_print(my_flexarray);
    f_free(my_flexarray);
    
    return EXIT_SUCCESS;
}
