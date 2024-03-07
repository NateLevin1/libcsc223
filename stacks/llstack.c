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

StackNode* new_llstack(int data) {
    return new_node(data);
}

int llstack_is_empty(StackNode** stack) {
    return (*stack) == NULL;
}

int llstack_pop(StackNode** stack) {
    if ((*stack) == NULL) {
        printf("Underflow: tried to pop an empty stack\n");
        exit(1);
    }
    StackNode* old_top = *stack;
    int old_top_val = old_top->val;
    *stack = old_top->next;
    free(old_top);
    return old_top_val;
}

int llstack_top(StackNode** stack) {
    return (*stack)->val;
}

void llstack_push(StackNode** stack, int val) {
    StackNode* node = new_node(val);
    if (stack == NULL || (*stack) == NULL) {
        *stack = node;
    } else {
        node->next = *stack;
        *stack = node;
    }
}

