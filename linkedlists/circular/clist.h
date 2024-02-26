typedef struct node {
    int val;
    struct node* next;
} Node;

Node* make_node(int);
// int list_length(Node*);
char* print_clist(Node*);
// Node* find_in_list(Node*, int);
// Node* insert_at_index(Node*, int);
void clist_insert_in_order(Node**, Node**);
// Node* remove_from_list(Node**, int);
int clist_length(Node* head);
