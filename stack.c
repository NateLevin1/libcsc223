#include <stdio.h>
#define MAX_SIZE 100


struct Stack {
    int arr[MAX_SIZE];
    int top;
};

int Top(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; 
    }

    return stack->arr[stack->top];
}


    