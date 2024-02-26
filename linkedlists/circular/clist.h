typedef struct node {
    int val;
    struct node* next;
} Node;

Node* make_node(int);
// int list_length(Node*);
char* print_clist(Node*);
// Node* find_in_list(Node*, int);
void clist_insert_at_index(Node**, int, int);
void clist_insert_in_order(Node**, Node**);
int clist_length(Node* head);
Node* remove_from_clist(Node**, int);
void insert_at_end(Node**, Node**);
