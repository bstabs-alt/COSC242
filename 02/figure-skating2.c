#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n = 0;
    int x = 0;
    double a = 0, b = 0, c = 0;
    double temp = 0.0;
    
    while(4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)){    
        scanf("%d%lg%lg%lg", &n, &a, &b, &c);
        if(temp < (a + b + c) / 3){
            x = n;
            temp = (a + b + c) / 3;
            
        }
    }
    printf("%d\t%f\n", x, temp);
    return EXIT_SUCCESS;
}
