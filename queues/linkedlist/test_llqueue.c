#include "llqueue.h"
#include <ctest.h>

int main() {
    BEGIN_TESTING("llqueue.h");

    TEST("llq_new") {
        LLQueue* queue = llq_new();
        ASSERT_STR_EQ(llq_print(queue), "");
    }

    TEST("llq_add") {
        LLQueue* queue = llq_new();
        llq_add(1, queue);
        ASSERT_STR_EQ(llq_print(queue), "1");
        llq_add(2, queue);
        ASSERT_STR_EQ(llq_print(queue), "1 -> 2");
        llq_add(3, queue);
        ASSERT_STR_EQ(llq_print(queue), "1 -> 2 -> 3");
    }

    TEST("llq_top") {
        LLQueue* queue = llq_new();
        llq_add(1, queue);
        ASSERT_EQ(llq_front(queue), 1);
        llq_add(2, queue);
        ASSERT_EQ(llq_front(queue), 1);
        llq_add(3, queue);
        ASSERT_EQ(llq_front(queue), 1);
    }

    TEST("llq_remove") {
        LLQueue* queue = llq_new();
        llq_add(1, queue);
        ASSERT_EQ(llq_remove(queue), 1);
        ASSERT_STR_EQ(llq_print(queue), "");
        llq_add(1, queue);
        llq_add(2, queue);
        ASSERT_EQ(llq_remove(queue), 1);
        ASSERT_STR_EQ(llq_print(queue), "2");
        llq_add(3, queue);
        ASSERT_EQ(llq_remove(queue), 2);
        ASSERT_STR_EQ(llq_print(queue), "3");
    }

    END_TESTING();
}