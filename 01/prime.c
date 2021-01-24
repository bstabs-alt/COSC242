#include <stdio.h>

int is_prime(int can){
    int n;
    for(n = 2; n < can; n++){
        if(can%n == 0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int can = 2;
    int num = 0;
    while(num < 100){
        if(is_prime(can)){
            printf("%d ", can);
            num++;
        }
        can++;
    }
    return 0;
}
