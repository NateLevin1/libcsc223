#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctest.h>
#include "../llstack.h"

// Function to determine precedence of operators
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
            return 0; // Default precedence for other characters
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    StackNode* stack = NULL; // Initialize an empty stack
    int i = 0, j = 0;
    char token, popped;

    // Push '(' onto the stack to handle expressions starting with '('
    llstack_push(&stack, '(');

    // Append ')' to the infix expression to mark the end
    strcat(infix, ")");

    // Iterate through each character of the infix expression
    while (infix[i] != '\0') {
        token = infix[i];

        // If the current token is '(', push it onto the stack
        if (token == '(') {
            llstack_push(&stack, token);
        }
        // If the token is an operand (alphabet), add it to the postfix expression
        else if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token;
        }
        /* If the scanned character is an ‘)’, 
        pop and add to the output string from the stack
        until an ‘(‘ is encountered.*/
        else if (token == ')') {
            while ((popped = llstack_pop(&stack)) != '(') {
                postfix[j++] = popped;
            }
        }
        // If the token is an operator
        else { 
            // Pop operators from the stack with higher or equal precedence and append to postfix
            while (!llstack_is_empty(&stack) && llstack_top(&stack) != '(' && precedence(token) <= precedence(llstack_top(&stack))) {
                popped = llstack_pop(&stack);
                postfix[j++] = popped;
            }
            // Push the current operator onto the stack
            llstack_push(&stack, token);
        }
        i++; // Move to the next character in the infix expression
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    // Test case using CTest framework
    BEGIN_TESTING("infixtopostfix.c");

    TEST("Converts infix expression to postfix") {
        char infix[] = "A+B*C+D";
        char expected_postfix[] = "ABC*+D+";

        char postfix[100];
        infixToPostfix(infix, postfix);

        ASSERT_STR_EQ(postfix, expected_postfix);
    }

    END_TESTING();

}
