#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctest.h>
#include "../llstack.h"

void reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

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

void infixToPrefix(char* infix, char* prefix) {
    StackNode* stack = NULL;
    int i = 0, j = 0;
    char token, popped;

    // Reverse the infix expression
    reverseString(infix);

    // Push a right parenthesis ')' onto the stack
    llstack_push(&stack, ')');

    // Concatenate a left parenthesis '(' to the infix expression
    strcat(infix, "(");

    while (infix[i] != '\0') {
        token = infix[i];

        if (token == ')') {
            llstack_push(&stack, token);
        } else if (isOperand(token)) {
            prefix[j++] = token;
        } else if (token == '(') {
            while ((popped = llstack_pop(&stack)) != ')') {
                prefix[j++] = popped;
            }
        } else { // token is an operator
            while (!llstack_is_empty(&stack) && precedence(token) < precedence(llstack_top(&stack))) {
                popped = llstack_pop(&stack);
                prefix[j++] = popped;
            }
            llstack_push(&stack, token);
        }
        i++;
    }

    // Add null terminator to the prefix expression
    prefix[j] = '\0';

    // Reverse the prefix expression
    reverseString(prefix);
}


int main() {
    BEGIN_TESTING("infixtoprefix.c.c");

    TEST("Converts infix expression to prefix") {
        char infix[] = "(A+B)(CD)";
        char expected_postfix[] = "+ABCD";

        char postfix[100];
        infixToPrefix(infix, postfix);

        ASSERT_STR_EQ(postfix, expected_postfix);
    }

    END_TESTING();

}
