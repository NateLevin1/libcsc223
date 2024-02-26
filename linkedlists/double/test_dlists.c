#include <stdio.h>
#include <ctest.h>
#include "dlist.h"

int main()
{
    BEGIN_TESTING("dlist.h");

    TEST("Can create dnode") {
        Dnode* dn = make_dnode(6);
        ASSERT_EQ(dn->val, 6);
        ASSERT_EQ(dn->next, NULL);
        ASSERT_EQ(dn->prev, NULL);
    }

/*
    TEST("Can print dlist") {
        Dnode* mydlist = NULL;
        RETURNS_STR(print_dlist, "", (mydlist));

        mydlist = make_dnode(6);
        mydlist->next = mydlist;
        RETURNS_STR(print_dlist, "6", (mydlist));

        Node* two = make_dnode(4);
        two->next = mydlist;
        mydlist->next = two;

        Node* n = make_dnode(1024);
        n->next = mydlist;
        two->next = n;

        RETURNS_STR(print_dlist, "1 -> 2 -> 1024", (mydlist));
    }

    TEST("Can insert node in order in descending list") {
        // Confirm works with empty list
        Node* mydlist = NULL;

        Node* n = make_dnode(4);
        clist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "4", (mydlist));

        n = make_dnode(2);
        clist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "2 -> 4", (mydlist));

        n = make_dnode(3);
        clist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "2 -> 3 -> 4", (mydlist));

        n = make_dnode(5);
        clist_insert_in_order(&mydlist, &n);
        RETURNS_STR(print_dlist, "2 -> 3 -> 4 -> 5", (mydlist));
    }

    TEST("Can add node to empty clist") {
        Node* mydlist = NULL;
        Node* n = make_dnode(2);
        clist_clist_insert_in_order(&mydlist, &n);
        ASSERT_EQ(mydlist->val, 2);
        ASSERT_EQ(mydlist->next, mydlist);
    }

    TEST("Can add node to clist with one node") {
        Node* mydlist = NULL;
        Node* n = make_dnode(2);
        clist_clist_insert_in_order(&mydlist, &n);
        n = make_dnode(1);
        clist_clist_insert_in_order(&mydlist, &n);
        ASSERT_EQ(mydlist->val, 1);
        ASSERT_EQ(mydlist->next->val, 2);
        ASSERT_EQ(mydlist->next->next, mydlist);
    }
*/

    END_TESTING();
}
