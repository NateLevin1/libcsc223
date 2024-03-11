#include "llstack.h"
#include <ctest.h>

int main() {
    BEGIN_TESTING("llstack.h");

    TEST("Can create stack") {
        StackNode* n = new_llstack_node(1);
        ASSERT_EQ(n->val, 1);
        ASSERT_EQ(n->next, NULL);
    }

    TEST("Can pop") {
        // Create stack of one element
        // After that single element is popped out, the stack should be null
        Stack head = new_llstack_node(1);
        // note: head->val is not accessible in the below assertion
        //       because head will be freed by the pop
        ASSERT_EQ(llstack_pop(&head), 1);
        ASSERT_EQ(head, NULL);

        head = new_llstack_node(3);
        llstack_push(&head, 2);
        llstack_push(&head, 1);
        ASSERT_EQ(llstack_pop(&head), 1);
        ASSERT_EQ(llstack_top(&head), 2);
    }

    TEST("stack operations work") {
        Stack stack = new_llstack_node(1);
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