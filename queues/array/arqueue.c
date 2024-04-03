#include <stdio.h>
#include <stdlib.h>
#include "arqueue.h"

Queue* arq_new() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

int arq_front(Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->items[queue->front];
}