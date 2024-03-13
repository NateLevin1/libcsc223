#include <ctest.h>
#include "../llstack.h"

void move(int n, Stack* source, Stack* dest, Stack* spare) {
    if (n == 1) {
        printf("Moving val %d from %p to %p\n", llstack_top(source), source, dest);
        llstack_push(dest, llstack_pop(source));
        return;
    }
    move(n - 1, source, spare, dest);
    move(1, source, dest, spare);
    move(n - 1, spare, dest, source);
}

int main() {
    BEGIN_TESTING("towersofhanoi.c");

    TEST("Towers of Hanoi") {
        Stack source = new_llstack_node(3);
        llstack_push(&source, 2);
        llstack_push(&source, 1);

        Stack dest = NULL;
        Stack spare = NULL;

        move(3, &source, &dest, &spare);

        ASSERT(llstack_is_empty(&source));
        ASSERT(llstack_is_empty(&spare));
        ASSERT_EQ(llstack_top(&dest), 1);
    }

    END_TESTING();
}
