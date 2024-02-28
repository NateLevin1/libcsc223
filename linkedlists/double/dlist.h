typedef struct dnode {
    int val;
    struct dnode* next;
    struct dnode* prev;
} Dnode;

Dnode* make_dnode(int);
char* print_dlist(Dnode*);
void remove_from_dlist(Dnode**, Dnode*);
void dlist_insert_at_index(Dnode **, int, int);
/*
void dlist_insert_in_order(Dnode**, Dnode**);
int dlist_length(Dnode*);
void dlist_insert_at_index(Dnode**, Dnode**);
Dnode* find_in_dlist(Dnode*, int);
Dnode* remove_from_dlist(Dnode**, int);
*/
