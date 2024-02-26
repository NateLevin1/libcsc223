#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

Node* make_node(int data) {
    Node* new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->val = data;
    new->next = NULL;

    return new;
}

char* print_clist(Node* head) {
    char* result = malloc(1024);

    int index = 0;
    Node* node = head;
    if (node == NULL) {
        result[0] = '\0';
        return result;
    }
    while (node != head || index == 0) {
        int num_len = snprintf(NULL, 0, "%d", node->val);
        snprintf(result + index, 8, "%d", node->val);
        index += num_len - 1;
        if (node->next != head) {
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

void clist_insert_in_order(Node** list, Node** newnode) {
    // empty list
    if (*list == NULL) {
        (*newnode)->next = *newnode;
        (*list) = *newnode;
        return;
    }

    // beginning insertion
    if ((*list)->val > (*newnode)->val) {
        (*newnode)->next = *list;
        Node* last = *list;
        while (last->next != *list) {
            last = last->next;
        }
        last->next = *newnode;
        (*list) = *newnode;
        return;
    }

    // otherwise, loop through and insert
    Node* cur = (*list)->next;
    Node* prev = *list;

    while (cur != *list && cur->val < (*newnode)->val) {
        prev = cur;
        cur = cur->next;
    }
    // insert newnode between previous and current (or at end)
    (*newnode)->next = cur;
    prev->next = *newnode;
}

int clist_length(Node* head)
{
    Node* ptr = head;
    int result = 0;
    if (ptr != NULL) {
        do {
            ptr = ptr->next;
            result++;
        } while (ptr != head);
    }

    return result;
}

void insert_at_end(Node** list, Node** newnode) {
    // If the list is empty, make the new node the head of the list
    if (*list == NULL) {
        *list = *newnode;
    } else {
        // Traverse the list to find the last node
        Node* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        // Insert the new node at the end of the list
        current->next = *newnode;
    }
}

Node* remove_from_clist(Node** list, int val) {
    Node *current, *previous;
    previous = *list;

    // If the list is empty, return NULL
    if (previous == NULL) {     
        return NULL;
    }

    current = previous->next;

    // If list contains only one node
    if (previous->next == previous && previous->val == val) {
        *list = NULL;
        free(previous);
        return previous;
    }

    // Traverse the list until either the end is reached or the value to be removed is found
    while (current != *list && current->val != val) {
        previous = current;
        current = current->next;
    }

    // If the value to be removed is not found in the list return NULL
    if (current == *list && current->val != val) { // Value not found
        return NULL;
    }

    // If node to be removed is the head of the list
    if (current == *list) {
        previous->next = current->next;
        *list = previous->next;
    } else { // If node to be removed is not the head of the list
        previous->next = current->next;
    }

    free(current);
    return current;
}

void clist_insert_at_index(Node** list, int val, int index) {
    Node* new_node = make_node(val);

    if (*list == NULL) { // If the list is empty, insert the node as the only node
        *list = new_node;
        new_node->next = new_node; // Circular reference to itself
        return;
    }

    if (index <= 0) { // Insert at the beginning of the list
        Node* last_node = *list;
        while (last_node->next != *list) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        new_node->next = *list;
        *list = new_node;
        return;
    }

    // Traverse the list to find the node at the specified index
    Node* current = *list;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
        if (current == *list) {
            printf("Index out of range\n");
            return;
        }
    }

    // Insert the node at the specified index
    new_node->next = current->next;
    current->next = new_node;
}
