#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

Stack* arstack_new();
void arstack_push(int, Stack*);
int arstack_top(Stack *stack);
int arstack_pop(int[], int);
