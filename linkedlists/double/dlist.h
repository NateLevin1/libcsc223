typedef struct dnode {
    int val;
    struct dnode* next;
    struct dnode* prev;
} Dnode;

Dnode* make_dnode(int);
char* print_dlist(Dnode*);
void remove_from_dlist(Dnode**, Dnode*);
void dlist_insert_at_index(Dnode**, int, int);
Dnode* find_in_dlist(Dnode*, int);