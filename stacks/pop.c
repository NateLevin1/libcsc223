#include <stdio.h>
#include <stdlib.h>
#include "pop.h"

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
