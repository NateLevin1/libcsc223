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
