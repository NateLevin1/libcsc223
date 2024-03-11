typedef struct node {
    int val;
    struct node* next;
} StackNode;

typedef StackNode* Stack;

StackNode* new_llstack_node(int);
int llstack_is_empty(StackNode** stack);
int llstack_pop(StackNode** stack);
int llstack_top(StackNode** stack);
void llstack_push(StackNode** stack, int val);