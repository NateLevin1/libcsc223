#include <stdio.h>
#include <ctest.h>
#include "clist.h"

int main() {
    BEGIN_TESTING("clist.h");

    TEST("Can create node") {
        Node* n = make_node(3);
        ASSERT_EQ(n->val, 3);
        ASSERT_EQ(n->next, NULL);
    }

    TEST("Can print list") {
        Node* myclist = NULL;
        RETURNS_STR(print_clist, "", (myclist));

        myclist = make_node(1);
        myclist->next = myclist;
        RETURNS_STR(print_clist, "1", (myclist));

        Node* two = make_node(2);
        two->next = myclist;
        myclist->next = two;

        Node* n = make_node(1024);
        n->next = myclist;
        two->next = n;

        RETURNS_STR(print_clist, "1 -> 2 -> 1024", (myclist));
    }

    TEST("Can insert node in order in descending list") {
        // Confirm works with empty list
        Node* myclist = NULL;

        Node* n = make_node(4);
        clist_insert_in_order(&myclist, &n);
        RETURNS_STR(print_clist, "4", (myclist));

        n = make_node(2);
        clist_insert_in_order(&myclist, &n);
        RETURNS_STR(print_clist, "2 -> 4", (myclist));

        n = make_node(3);
        clist_insert_in_order(&myclist, &n);
        RETURNS_STR(print_clist, "2 -> 3 -> 4", (myclist));

        n = make_node(5);
        clist_insert_in_order(&myclist, &n);
        RETURNS_STR(print_clist, "2 -> 3 -> 4 -> 5", (myclist));
    }

    END_TESTING();
}
