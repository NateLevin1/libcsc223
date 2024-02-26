#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

void insert_in_front(Node** list, Node** newnode) {
    (*newnode)->next = *list;
    *list = *newnode;
}

int list_length(Node* head) {
    int count = 0;
    Node* ptr = head;
    while (ptr != NULL) {
        count = count + 1;
        ptr = ptr->next;
    }
    return count;
}

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

Node* find_in_list(Node* list, int target) {
    Node* current = list;

    for (Node* current = list; current != NULL; current = current->next) {
        if (current->val == target) {
            return current;
        }
    }
    return NULL;
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

void insert_in_order(Node** list, Node** newnode) {
    Node* current, * previous;

    previous = *list;
    if (previous == NULL) {
        *list = *newnode;
        return;
    }
    current = previous->next;
    while (current != NULL && current->val > (*newnode)->val) {
        previous = current;
        current = current->next;
    }
    // insert newnode between previous and current (or at end)
    (*newnode)->next = current;
    previous->next = *newnode;
}

Node* remove_from_list(Node** list, int val) {
    Node* current, * previous;
    previous = *list;
    if (previous == NULL) {
        return NULL;
    }
    current = previous->next;
    while (current != NULL && current->val != val) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return NULL;  // val not found

    // disconnect found node from list and return
    previous->next = current->next;
    return current;
}
