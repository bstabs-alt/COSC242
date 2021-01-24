#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new() {
    int i;
    int default_size = 7;
    queue r = emalloc(sizeof *r);
    r->head = 0;
    r->capacity = default_size;
    r->num_items = 0;
    r->items = emalloc(r->capacity * sizeof r->items[0]);
    for(i = 0; i < r->capacity; i++){
        r->items[i] = 0.0;
    }
    return r;
}

void enqueue(queue q, double item) {
    if (q->num_items < q->capacity) {
        q->items[(q->head + q->num_items++) % q->capacity] = item;
    }
}

double dequeue(queue q) {
    int i = 0;
    if(q->num_items > 0){
        i = q->head;
        q->num_items--;
        q->head++;
        return q->items[i];
    }
    return 0.0;
}

void queue_print(queue q) {
    int i = 0;
    while(i < q->num_items){
            printf("%.2f\n", q->items[(q->head + i)%q->capacity]);
            i++;
        }
}

void queue_print_info(queue q) {
    int i;
    printf("capacity %d, num_items %d, head %d\n[", q->capacity,
           q->num_items, q->head);
    for (i = 0; i < q->capacity; i++) {
        printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
    }
    printf("]\n");
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    return q;
}
