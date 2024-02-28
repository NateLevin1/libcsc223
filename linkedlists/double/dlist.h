typedef struct node {
    int val;
    struct node* next;
} Node;

Node* make_node(int);