#include "llstack.h"
#include <ctest.h>

int main() {
    BEGIN_TESTING("llstack.h");

    TEST("Can create stack") {
        StackNode* n = new_llstack_node(1);
        ASSERT_EQ(n->val,1);
        ASSERT_EQ(n->next,NULL);
    }

    TEST("Can pop") {
        // Create stack of one element
        // After that single element is popped out, the stack should be null
        StackNode* head = new_llstack_node(1);
        ASSERT_EQ(llstack_pop(&head), head->val);
        // ASSERT_EQ(head, NULL);

        // StackNode* n1 = new_llstack_node(2);
        // StackNode* n2 = new_llstack_node(3);
        // StackNode* n3 = new_llstack_node(4);
        // n2 = n1->next;
        // n3 = n2->next;
        // ASSERT_EQ(llstack_pop(&n1), n1->val);
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