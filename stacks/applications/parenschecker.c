#include <ctest.h>
#include "../llstack.h"

bool isBalanced(char exp[]) {
    Stack stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            llstack_push(&stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (llstack_is_empty(&stack)) return false;

            char popped = llstack_pop(&stack);
            if (
                (ch == ')' && popped != '(')
                || (ch == ']' && popped != '[')
                || (ch == '}' && popped != '{')
                ) {
                return false;
            }
        }

    }

    return llstack_is_empty(&stack);
}

int main() {
    BEGIN_TESTING("parenschecker.c");

    TEST("isBalanced") {
        ASSERT_EQ(isBalanced("()"), true);
        ASSERT_EQ(isBalanced("()("), false);
        ASSERT_EQ(isBalanced("()()"), true);
        ASSERT_EQ(isBalanced("([)]"), false);
        ASSERT_EQ(isBalanced("{[]}"), true);
        ASSERT_EQ(isBalanced(")("), false);
    }

    END_TESTING();
}
