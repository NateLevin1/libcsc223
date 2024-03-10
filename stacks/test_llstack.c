#include "llstack.h"
#include <ctest.h>

int main() {
    BEGIN_TESTING("llstack.h");

    TEST("Can create stack") {
        StackNode* n = new_llstack(1);
        ASSERT_EQ(n->val,1);
        ASSERT_EQ(n->next,NULL);
    }

    TEST("Can pop") {
        // Create stack of one element
        // After that single element is popped out, the stack should be null
        StackNode* head = new_llstack(1);
        ASSERT_EQ(llstack_pop(head),NULL);
        // Create a stack of two elements
        // LIFO, second node is popped out
        StackNode* n = new_llstack(2);
        head->next = n;
        ASSERT_EQ(llstack_pop(head),head);
        // Three-element stack
        StackNode* n2 = new_llstack(3);
        n2->next = head;
        ASSERT_EQ(llstack_pop(head), n2);
    }

    TEST("stack operations work") {
        Stack stack = new_llstack(1);
        ASSERT_EQ(llstack_top(&stack), 1);

        llstack_push(&stack, 2);
        ASSERT_EQ(llstack_top(&stack), 2);

        llstack_pop(&stack);
        ASSERT_EQ(llstack_top(&stack), 1);

        llstack_pop(&stack);
        ASSERT(llstack_is_empty(&stack));
    }

    END_TESTING();
}