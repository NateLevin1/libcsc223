typedef struct node {
    int val;
    struct node* next;
} StackNode;

StackNode* new_node(int);
StackNode* pop(StackNode** stack);
StackNode* top(StackNode** stack);
void push(StackNode** stack, StackNode*);