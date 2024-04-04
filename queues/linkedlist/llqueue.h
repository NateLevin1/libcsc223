#include "../../linkedlists/single/list.h"

typedef struct LLQueue {
    Node* start;
    Node* end;
} LLQueue;

LLQueue* llq_new();
void llq_add(int val, LLQueue* queue);
int llq_front(LLQueue* queue);
int llq_remove(LLQueue* queue);

char* llq_print(LLQueue* queue);
