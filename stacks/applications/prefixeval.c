#include <ctest.h>
#include "../llstack.h"

// note: all numbers are single digit
int evaluatePrefix(char input[]) {
    int result = 0;
    // TODO
    return result;
}

int main() {
    BEGIN_TESTING("prefixeval.c");

    TEST("Evaluates empty to 0") {
        char input[] = "";
        ASSERT_EQ(evaluatePrefix(input), 0);
    }

    TEST("Evaluates 1 to 1") {
        char input[] = "1";
        ASSERT_EQ(evaluatePrefix(input), 1);
    }

    TEST("Evaluates +-927 to 14 (add/sub)") {
        char input[] = "+-927";
        ASSERT_EQ(evaluatePrefix(input), 14);
    }

    TEST("Evaluates /2*23 to 3 (mul/div)") {
        char input[] = "/2*23";
        ASSERT_EQ(evaluatePrefix(input), 3);
    }

    END_TESTING();
}
