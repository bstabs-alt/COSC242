#include <stdio.h>
#include<stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum {
    int x;
    int y;
    double conc;
};

void print_ocean_datum(struct ocean_datum *o){
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}
int read_ocean_datum(struct ocean_datum *o){
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

int cmp(struct ocean_datum c1, struct ocean_datum c2){
    if(c1.conc > c2.conc){
        return 1;
    }else if(c1.conc == c2.conc){
        return 0;
    } else {
        return -1;
    }
}

void insertion_sort(struct ocean_datum a[], int n){
    int i, j;
    struct ocean_datum k;

    for(i=1; i<n; i++){
        k = a[i];
        j=i-1;
        while(j>=0 && cmp(a[j], k) < 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=k;
    }
}

int main(void){
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items = 0;
    int i;

    while(num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])){
        num_items++;
    }

    insertion_sort(ocean_data, num_items);
    
    for(i = 0; i < num_items; i++){
        print_ocean_datum(&ocean_data[i]);
    }
    
    return EXIT_SUCCESS;
}
