#include "../../linkedlists/single/list.h"

typedef struct LLQueue {
    Node* start;
    Node* end;
} LLQueue;

LLQueue* new();
void add(int val, LLQueue* queue);
int front(LLQueue* queue);
int remove(LLQueue* queue);