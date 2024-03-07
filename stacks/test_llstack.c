#include <ctest.h>
#include "llstack.h"

int main() {
    BEGIN_TESTING("llstack.h");

    TEST("Can create stack"); {
        StackNode* n = new_node(1);
        ASSERT_EQ(n->val,1);
        ASSERT_EQ(n->next,NULL);
    }

    TEST("Can pop"); {
        // Create stack of one element
        // After that single element is popped out, the stack should be null
        StackNode* head = new_node(1);
        ASSERT_EQ(pop(head),NULL);
        // Create a stack of two elements
        // LIFO, second node is popped out
        StackNode* n = new_node(2);
        head->next = n;
        ASSERT_EQ(pop(head),head);
        // Three-element stack
        StackNode* n2 = new_node(3);
        n2->next = head;
        ASSERT_EQ(pop(head), n2);
    }

    TEST("Can ")
    END_TESTING();
}