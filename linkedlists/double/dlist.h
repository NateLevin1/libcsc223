typedef struct dnode {
    int val;
    struct dnode* next;
    struct dnode* prev;
} Dnode;

Dnode* make_dnode(int);