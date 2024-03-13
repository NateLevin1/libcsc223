#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

Stack* new();
void push(int, Stack*);
int top(Stack *stack);
int pop(int[], int);
