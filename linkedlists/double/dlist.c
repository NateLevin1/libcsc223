#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

Dnode* make_dnode(int data) {
    Dnode* new = malloc(sizeof(Dnode));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->val = data;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

char* print_dlist(Dnode* head) {
    char* result = malloc(1024);

    int index = 0;
    Dnode* Dnode = head;
    while (Dnode != NULL) {
        int num_len = snprintf(NULL, 0, "%d", Dnode->val);
        snprintf(result + index, 8, "%d", Dnode->val);
        index += num_len - 1;
        if (Dnode->next != NULL) {
            result[++index] = ' ';
            result[++index] = '-';
            result[++index] = '>';
            result[++index] = ' ';
        }
        index++;

        Dnode = Dnode->next;
    }
    result[index] = '\0';

    return result;
}

void dlist_insert_in_order(Dnode** list, Dnode** newDnode){

    Dnode* current;

    if(*list == NULL){
        *list = newDnode;
    }

    else if((*list)->next >= (*newDnode)->val){
        (*newDnode)->next = *list;
        (*newDnode)->next->prev = newDnode;
        *list = newDnode;
    }

    else { 
        current = *list; 
  
        // locate the node after which the new node 
        // is to be inserted 
        while (current->next != NULL &&  
               current->next->val < (*newDnode)->val) 
            current = current->next; 
  
        /* Make the appropriate links */
        (*newDnode)->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            (*newDnode)->next->prev = newDnode; 
  
        current->next = newDnode; 
        newDnode->prev = current; 
    } 
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
