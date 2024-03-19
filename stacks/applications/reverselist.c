#include <ctest.h>
#include "../llstack.h"

void reverseList(int list[], int listLen) {
    Stack stack = NULL;
    for (int i = 0; i < listLen; i++) {
        llstack_push(&stack, list[i]);
    }
    for (int i = 0; i < listLen; i++) {
        list[i] = llstack_pop(&stack);
    }
}

int main() {
    BEGIN_TESTING("reverselist.c");

    TEST("Works with single") {
        int list[] = { 0 };
        reverseList(list, 1);
        ASSERT_EQ(list[0], 0);
    }

    TEST("Reverses a list") {
        int list[] = { 1, 2, 3, 4, 5 };
        reverseList(list, 5);
        ASSERT_EQ(list[0], 5);
        ASSERT_EQ(list[1], 4);
        ASSERT_EQ(list[2], 3);
        ASSERT_EQ(list[3], 2);
        ASSERT_EQ(list[4], 1);
    }

    END_TESTING();
}
