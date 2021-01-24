#include <stdio.h>
#include <stdlib.h>

binary_search(int a[], int first, int last, int c){
    int m;
    m = a[last/2]; 
        if(m == c){
            return 1;
        } else if[m > c){
            return binary_search(a, first, m-1, c);
        } else {
            return binary_search(a, m+1, last, c);
        }
    }
    return 0;
}

int main(int argc, char **argv){
FILE *infile
    int count, query,
}
