#include <stdio.h>
#include <stdlib.h>
#include "arstack.h"

// Function to create a new stack
Stack* new() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;  // Initialize top index to -1 to indicate an empty stack
    return stack;
}

// Function to push an element onto the stack
void push(int value, Stack* stack) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element onto a full stack\n");
        return;
    }
    stack->items[++stack->top] = value;  // Increment top and then insert the value
}

int top(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; 
    }

    return stack->items[stack->top];
}

// takes in an array and the index of the "top" of the array
int pop(int input_array[], int top)
{
    if (top <= 0)
    {
        printf("underflow!");
    }
    else
    {
        printf("\nPopped element: %d", input_array[top]);
        top = top - 1;
    }
    return top;
}

int top(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; 
    }

    return stack->items[stack->top];
}
