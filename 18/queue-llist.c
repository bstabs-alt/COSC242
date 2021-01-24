#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

typedef struct q_item *q_item;

struct q_item {
    double item;
    q_item next;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    queue result = emalloc(sizeof * result);
    result->first = NULL;
    result->last = NULL;
    result->length = 0;
    return q;
}

void enqueue(queue q, double item) {
    q_item i = emalloc(sizeof *i);
    i->item = item;
    i->next = NULL;
    if (q->length == 0) {
        q->first = i;
    } else {
        q->last->next = i;
    }
    q->last = i;
    q->length++;
}

double dequeue(queue q) {
    q_item start = q->first;
    double dequeue;
    if(start == NULL){
        return 0.0;
    }
    q->first = q->first->next;
    dequeue = start->item;
    q->length--;
    free(start);
    return dequeue;
}

void queue_print(queue q){
    int i;
    for(i = 0; i < length; i++){
        printf("%0.2f", item[i]);
    }
}

void queue_print_info(queue q) {
    if (q->length == 0) {
        printf("The queue is empty\n");
    } else {
        printf("first %.2f, last %.2f, length %d\n", q->first->item,
               q->last->item, q->length);
    }
}

int queue_size(queue q) {
    return q->length;
}

void queue_free_aux(q_item i) {
    free(i);
}

queue queue_free(queue q) {
    q_item i;
    for(i = q->first; i != q->last; i++){
        free(i);
    }
    free(q->last);
    free(q);
    return q;
}
