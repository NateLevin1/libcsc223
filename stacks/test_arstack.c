#include <stdio.h>
#include <stdlib.h>
#include <ctest.h>
#include "arstack.h"

int main() {
    BEGIN_TESTING("arstack.h");

    // Test case 1: Can create a new stack
    TEST("Can create a new stack") {
        Stack* stack = new();
        ASSERT(stack != NULL);
        ASSERT_EQ(stack->top, -1);
        free(stack);
    }

    // Test case 2: Can push elements onto the stack
    TEST("Can push elements onto the stack") {
        Stack* stack = new();
        push(10, stack);
        push(20, stack);
        ASSERT_EQ(stack->items[0], 10);
        ASSERT_EQ(stack->items[1], 20);
        ASSERT_EQ(stack->top, 1);
        free(stack);
    }

    // Test case 3: Stack overflow condition
    TEST("Stack overflow condition") {
        Stack* stack = new();
        for (int i = 0; i < MAX_SIZE; i++) {
            push(i, stack);
        }
        push(MAX_SIZE + 1, stack); // Attempting to push one more element should result in overflow
        ASSERT_EQ(stack->top, MAX_SIZE - 1); // Top should remain at the maximum index
        free(stack);
    }



    TEST("Can get the top element of the stack") {
        Stack* stack = new();
        push(10, stack);
        push(20, stack);
        ASSERT_EQ(top(stack), 20);
        free(stack);
    }


    END_TESTING();
}