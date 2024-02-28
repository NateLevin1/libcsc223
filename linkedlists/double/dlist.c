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
        newDnode->next = *list;
        newDnode->next->prev = newDnode;
        *list = newDnode;
    }

    else { 
        current = *list; 
  
        // locate the node after which the new node 
        // is to be inserted 
        while (current->next != NULL &&  
               current->next->val < newDnode->data) 
            current = current->next; 
  
        /* Make the appropriate links */
        newDnode->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            newDnode->next->prev = newDnode; 
  
        current->next = newDnode; 
        newDnode->prev = current; 
    } 
} 