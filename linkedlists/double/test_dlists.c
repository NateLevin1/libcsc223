#include <stdio.h>
#include <ctest.h>
#include <stdlib.h>
#include "dlist.h"

int main() {
    BEGIN_TESTING("dlist.h");

    TEST("Can create Dnode") {
        Dnode* n = make_dnode(3);
        ASSERT_EQ(n->val, 3);
        ASSERT_EQ(n->next, NULL);
    }

    TEST("Can print list") {
        Dnode* mydlist = NULL;
        RETURNS_STR(print_dlist, "", (mydlist));

        mydlist = make_dnode(1);
        mydlist->next = mydlist;
        RETURNS_STR(print_dlist, "1", (mydlist));

        Dnode* two = make_dnode(2);
        two->next = mydlist;
        mydlist->next = two;

        Dnode* n = make_dnode(1024);
        n->next = mydlist;
        two->next = n;

        RETURNS_STR(print_dlist, "1 -> 2 -> 1024", (mydlist));
    }

    TEST("Can insert Dnode in order in descending list") {
        // Confirm works with empty list
        Dnode* mydlist = NULL;

        Dnode* n = make_dnode(4);
        dlist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "4", (mydlist));

        n = make_dnode(2);
        dlist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "2 -> 4", (mydlist));

        n = make_dnode(3);
        dlist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "2 -> 3 -> 4", (mydlist));

        n = make_dnode(5);
        dlist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "2 -> 3 -> 4 -> 5", (mydlist));
    }

    TEST("Can remove Dnode from dlist") {
        // Create a doubly linked list with three Dnodes: 1 <-> 2 <-> 3
        Dnode* head = make_dnode(1);
        Dnode* Dnode2 = make_dnode(2);
        Dnode* Dnode3 = make_dnode(3);
        head->next = Dnode2;
        Dnode2->prev = head;
        Dnode2->next = Dnode3;
        Dnode3->prev = Dnode2;

        // Remove Dnode2 from the list
        remove_from_dlist(&head, Dnode2);

        // Check if Dnode2 is successfully removed
        ASSERT_EQ(head->next, Dnode3);
        ASSERT_EQ(Dnode3->prev, head);

        // Free memory
        free(Dnode3);
    }

    END_TESTING();
}
