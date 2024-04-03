#include <stdio.h>
#include <stdlib.h>
#include "arqueue.h"
#include <ctest.h>

int main() {
    BEGIN_TESTING("arqueue.h");

    // Test case 1: Can create a new queue
    TEST("Can create a new queue") {
        Queue* queue = arq_new();
        ASSERT(queue != NULL);
        ASSERT_EQ(queue->front, 0);
        ASSERT_EQ(queue->rear, -1);
        ASSERT_EQ(queue->size, 0);
        free(queue);
    }

    // Test case 2: Can get front element of an empty queue
    TEST("Can get front element of an empty queue") {
        Queue* queue = arq_new();
        ASSERT_EQ(arq_front(queue), -1); // This should exit the program as the queue is empty
        free(queue);
    }

    // Test case 3: Can get front element of a non-empty queue
    TEST("Can get front element of a non-empty queue") {
        Queue* queue = arq_new();
        queue->items[0] = 10;
        queue->rear = 0;
        queue->size = 1;
        ASSERT_EQ(arq_front(queue), 10);
        free(queue);
    }


    END_TESTING();
}