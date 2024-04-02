#include <ctest.h>
#include "../llstack.h"
#include "../../linkedlists/single/list.h"

void reverselinkedlist(Node** list) {
    Stack* reversed; // Initialize the stack
    Node* temp = *list;

    while (temp != NULL){
        llstack_push(reversed, temp->val);
        temp = temp->next;
    }

    temp = *list;
    while (reversed != NULL && llstack_top(reversed) == 1){ // Change condition to check if the stack is empty
        temp->val = llstack_pop(reversed); // Update the value of the node
        temp = temp->next;
    }
}

int main(){
    BEGIN_TESTING("reverselinkedlist.c");

    TEST("Works with single node"){
        Node* node = make_node(0);
        reverselinkedlist(&node); // Pass the pointer to the pointer
        ASSERT_EQ(node->val, 0); // Compare the value of the node
    }

    TEST("Works with multiple nodes"){
        Node* head = make_node(1);
        head->next = make_node(2);
        head->next->next = make_node(3);
        head->next->next->next =  make_node(4);
        head->next->next->next->next = make_node(5);

        reverselinkedlist(&head); // Pass the pointer to the pointer
        ASSERT_EQ(head->val,5);
        ASSERT_EQ(head->next->val,4);
        ASSERT_EQ(head->next->next->val,3);
        ASSERT_EQ(head->next->next->next->val,2);
        ASSERT_EQ(head->next->next->next->next->val,1);
    }

    END_TESTING();
}
