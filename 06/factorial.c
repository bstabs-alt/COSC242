#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n > 1){
        n *= factorial(n-1);
    }
    return n;
}

int main(){
    int n;
    
    while(1 == scanf("%d", &n)){
        printf("%d\n", factorial(n));
    }
    
    return EXIT_SUCCESS;
}
