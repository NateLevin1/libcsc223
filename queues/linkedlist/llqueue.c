#include <stdio.h>
#include <stdlib.h>
#include "../../linkedlists/single/list.h"
#include "llqueue.h"

LLQueue* llq_new() {
    LLQueue* queue = malloc(sizeof(LLQueue));
    return queue;
}

void llq_add(int val, LLQueue* queue) {
    Node* node = make_node(val);

    // handle empty
    if (queue->start == NULL) {
        queue->start = node;
        queue->end = node;
        return;
    }

    // otherwise just append to end
    queue->end->next = node;
    queue->end = node;
}

int llq_front(LLQueue* queue) {
    if (queue->start == NULL) {
        printf("Underflow: tried to get front of an empty queue\n");
        exit(1);
    }

    return queue->start->val;
}

int llq_remove(LLQueue* queue) {
    if (queue->start == NULL) {
        printf("Underflow: tried to remove from an empty queue\n");
        exit(1);
    }

    Node* old_start = queue->start;
    int old_val = old_start->val;

    Node* new_start = queue->start->next;
    queue->start = new_start;

    free(old_start);

    return old_val;
}

char* llq_print(LLQueue* queue) {
    return print_list(queue->start);
}
