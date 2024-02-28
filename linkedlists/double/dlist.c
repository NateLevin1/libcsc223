#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"


Dnode* make_dnode(int data)
{
    Dnode* new = malloc(sizeof(Dnode));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->val = data;
    new->next = NULL;
    new->prev= NULL;

    return new;
}

void remove_from_dlist(Dnode** head_ref, Dnode* del_node) {
    // Base case: If the list is empty or del_node is NULL, return
    if (*head_ref == NULL || del_node == NULL)
        return;

    // If the node to be deleted is the head node
    if (*head_ref == del_node)
        *head_ref = del_node->next;

    // Change next only if node to be deleted is NOT the last node
    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    // Change prev only if node to be deleted is NOT the first node
    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    // Free the memory allocated to the node
    free(del_node);
}

void dlist_insert_at_index(Dnode **head_ref, int index, int val) {
    // Check if index is negative
    if (index < 0)
        return;

    // Create a new node with the given value
    Dnode *new_node = make_dnode(val);
    if (new_node == NULL) {
        // Memory allocation failed
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // If index is 0, insert at the beginning
    if (index == 0) {
        new_node->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = new_node;
        *head_ref = new_node;
        return;
    }

    // Traverse to the node at position (index - 1)
    Dnode *current = *head_ref;
    int i;
    for (i = 0; current != NULL && i < index - 1; i++)
        current = current->next;

    // If index is greater than the number of nodes in the list, do nothing
    if (current == NULL)
        return;

    // Insert the new node after the node at position (index - 1)
    new_node->next = current->next;
    new_node->prev = current;
    if (current->next != NULL)
        current->next->prev = new_node;
    current->next = new_node;
}

/*
char* print_list(Node* head) {
    char* result = malloc(1024);

    int index = 0;
    Node* node = head;
    while (node != NULL) {
        int num_len = snprintf(NULL, 0, "%d", node->val);
        snprintf(result + index, 8, "%d", node->val);
        index += num_len - 1;
        if (node->next != NULL) {
            result[++index] = ' ';
            result[++index] = '-';
            result[++index] = '>';
            result[++index] = ' ';
        }
        index++;

        node = node->next;
    }
    result[index] = '\0';

    return result;
}
*/
