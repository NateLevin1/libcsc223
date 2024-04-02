#pragma once

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* make_node(int);
void insert_in_front(Node**, Node**);
int list_length(Node*);
char* print_list(Node*);
Node* find_in_list(Node*, int);
void insert_at_end(Node**, Node**);
void insert_in_order(Node**, Node**);
Node* remove_from_list(Node**, int);
