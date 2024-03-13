#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctest.h>
#include "../llstack.h"

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    StackNode* stack = NULL;
    int i = 0, j = 0;
    char token, popped;

    llstack_push(&stack, '(');
    strcat(infix, ")");

    while (infix[i] != '\0') {
        token = infix[i];

        if (token == '(') {
            llstack_push(&stack, token);
        } else if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token;
        } else if (token == ')') {
            while ((popped = llstack_pop(&stack)) != '(') {
                postfix[j++] = popped;
            }
        } else { // token is an operator
            while (!llstack_is_empty(&stack) && llstack_top(&stack) != '(' && precedence(token) <= precedence(llstack_top(&stack))) {
                popped = llstack_pop(&stack);
                postfix[j++] = popped;
            }
            llstack_push(&stack, token);
        }
        i++;
    }
    postfix[j] = '\0';
}

int main() {


    BEGIN_TESTING("infixtopostfix.c");

    TEST("Converts infix expression to postfix") {
        char infix[] = "(A+B)*(C*D)";
        char expected_postfix[] = "AB+CD**";

        char postfix[100];
        infixToPostfix(infix, postfix);

        ASSERT_STR_EQ(postfix, expected_postfix);
    }

    END_TESTING();

}
