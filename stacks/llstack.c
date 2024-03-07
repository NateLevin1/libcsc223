#include <stdio.h>
#include <stdlib.h>
#include "llstack.h"

StackNode* new_node(int data) {
    StackNode* new = malloc(sizeof(StackNode));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->val = data;
    new->next = NULL;

    return new;
}

StackNode* pop(StackNode** stack) {
    return NULL;
}

StackNode* top(StackNode** stack) {
    return NULL;
}

void push(StackNode** stack, StackNode*) {
}

