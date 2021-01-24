#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void){
    int n, i = 0, j = 0;
    double a, b, c;
    float judge1[SIZE];
    float judge2[SIZE];
    float judge3[SIZE];
    float m1 = 0.0, m2 = 0.0, m3 = 0.0;
    
    while(4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)){    
            judge1[i] = a;
            judge2[i] = b;
            judge3[i] = c;
            i++;
    }
    for(j = 0; j < i; j++){
        m1 += judge1[j];
        m2 += judge2[j];
        m3 += judge3[j];
    }
    m1 /= i;
    m2 /= i;
    m3 /= i;
    printf("%f\t%f\t%f\n", m1, m2, m3); 
       
    return EXIT_SUCCESS;
}
