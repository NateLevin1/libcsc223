#include <stdio.h>
#include <stdlib.h>
#include "llstack.h"
#include <stdio.h>

StackNode* new_llstack_node(int data) {
    StackNode* new = malloc(sizeof(StackNode));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->val = data;
    new->next = NULL;

    return new;
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
    return old_top_val;
}

int llstack_top(StackNode** stack) {
    return (*stack)->val;
}

void llstack_push(StackNode** stack, int val) {
    StackNode* node = new_llstack_node(val);
    if (stack == NULL || (*stack) == NULL) {
        *stack = node;
    } else {
        node->next = *stack;
        *stack = node;
    }
}
