#include <stdio.h>
#include <stdlib.h>

int is_prime(int c){
    int n;
    for(n = 2; n < c; n++){
        if((c%n) == 0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int c = 2, n = 0;
    while(n < 200){
        if(is_prime(c)){
            printf("%5d", c);
            n++;
            if(n % 10 == 0){
                printf("\n");
            }
        }
        c++;
    }
    return EXIT_SUCCESS;
}
