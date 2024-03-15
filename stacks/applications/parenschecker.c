#include <ctest.h>
#include "../llstack.h"
#include <stdbool.h> 
#include <stdio.h>

bool isBalanced(char exp[])
{
    bool flag = true;
    int count = 0;
 
    for (int i = 0; exp[i] != '\0'; i++) {
 
        if (exp[i] == '(') {
            count++;
        }
        else {
            count--;
        }
        if (count < 0) {
            flag = false;
            break;
        }
    }
    if (count != 0) {
        flag = false;
    }
 
    return flag;
}

int main(){
    BEGIN_TESTING("parenschecker.c");

    TEST("isBalanced"){
        ASSERT_EQ(isBalanced("()"),  true);
        ASSERT_EQ(isBalanced("()("), false);
        ASSERT_EQ(isBalanced("()()"), true);
        ASSERT_EQ(isBalanced("([)]"), false);
        ASSERT_EQ(isBalanced("{[]}"), false);

        printf("All tests passed successfully!\n");
    }
   
    END_TESTING();
}