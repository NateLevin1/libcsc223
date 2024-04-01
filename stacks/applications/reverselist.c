#include <ctest.h>
#include "../llstack.h"

void main(StackNode** list) {
    Stack* stack;
    StackNode* temp = *list;

    while (temp != NULL){
        llstack_push(&stack, temp->val);
        temp = temp->next;
    }

    temp = *list;
    while (temp != NULL){
        temp->next = llstack_pop(stack);
        temp = temp->next;
    }
}
