#include "llstack.h"
#include <ctest.h>

int main() {
    BEGIN_TESTING("llstack.h");

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

    TEST("stack operations return the correct values") {

    }

    END_TESTING();
}