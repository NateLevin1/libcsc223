#include <ctest.h>
#include "../llstack.h"

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    BEGIN_TESTING("fibonnaci.c");

    TEST("Fibonacci") {
        ASSERT_EQ(fibonacci(1), 1);
        ASSERT_EQ(fibonacci(2), 1);
        ASSERT_EQ(fibonacci(3), 2);
        ASSERT_EQ(fibonacci(4), 3);
        ASSERT_EQ(fibonacci(5), 5);
        ASSERT_EQ(fibonacci(6), 8);
        ASSERT_EQ(fibonacci(7), 13);
        ASSERT_EQ(fibonacci(8), 21);
        ASSERT_EQ(fibonacci(9), 34);
        ASSERT_EQ(fibonacci(10), 55);
    }

    END_TESTING();
}
