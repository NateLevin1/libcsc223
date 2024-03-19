#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctest.h>
#include "../llstack.h"

// Function to reverse a given string
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

// Function to check if a character is an operand (alphabet)
int isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

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

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    StackNode* stack = NULL; // Initialize an empty stack
    int i = 0, j = 0;
    char token, popped;

    // Reverse the infix expression
    reverseString(infix);

    // Push a right parenthesis ')' onto the stack
    llstack_push(&stack, ')');

    // Concatenate a left parenthesis '(' to the infix expression
    strcat(infix, "(");

    // Iterate through each character of the infix expression
    while (infix[i] != '\0') {
        token = infix[i];

        // If the current token is ')', push it onto the stack
        if (token == ')') {
            llstack_push(&stack, token);
        }
        // If the token is an operand (alphabet), add it to the prefix expression
        else if (isOperand(token)) {
            prefix[j++] = token;
        }
        // If the token is '(', pop operators from the stack until ')' is encountered
        else if (token == '(') {
            while ((popped = llstack_pop(&stack)) != ')') {
                prefix[j++] = popped;
            }
        }
        // If the token is an operator
        else { 
            // Pop operators from the stack with higher precedence and append to prefix
            while (!llstack_is_empty(&stack) && precedence(token) < precedence(llstack_top(&stack))) {
                popped = llstack_pop(&stack);
                prefix[j++] = popped;
            }
            // Push the current operator onto the stack
            llstack_push(&stack, token);
        }
        i++; // Move to the next character in the infix expression
    }

    // Add null terminator to the prefix expression
    prefix[j] = '\0';

    // Reverse the prefix expression to get the final prefix expression
    reverseString(prefix);
}


int main() {
    // Test case using CTest framework
    BEGIN_TESTING("infixtoprefix.c");

    // Test for converting infix expression to prefix
    TEST("Converts infix expression to prefix") {
        char infix[] = "(A+B)(CD)";
        char expected_prefix[] = "+ABCD";

        char prefix[100];
        infixToPrefix(infix, prefix);

        // Assertion to check if the obtained prefix expression matches the expected one
        ASSERT_STR_EQ(prefix, expected_prefix);
    }

    END_TESTING(); // End testing

    return 0;
}
