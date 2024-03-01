#include <stdio.h>
#include <ctest.h>
#include "dlist.h"

int main() {
    BEGIN_TESTING("dlist.h");

    TEST("Can create node") {
        Dnode* n = make_node(3);
        ASSERT_EQ(n->val, 3);
        ASSERT_EQ(n->next, NULL);
    }

    TEST("Can print list") {
        Dnode* mydlist = NULL;
        RETURNS_STR(print_dlist, "", (mydlist));

        mydlist = make_node(1);
        mydlist->next = mydlist;
        RETURNS_STR(print_dlist, "1", (mydlist));

        Dnode* two = make_node(2);
        two->next = mydlist;
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

    TEST("Can remove node from dlist") {
        // Create a doubly linked list with three nodes: 1 <-> 2 <-> 3
        Dnode* head = make_dnode(1);
        Dnode* node2 = make_dnode(2);
        Dnode* node3 = make_dnode(3);
        head->next = node2;
        node2->prev = head;
        node2->next = node3;
        node3->prev = node2;

        // Remove node2 from the list
        remove_from_dlist(&head, node2);

        // Check if node2 is successfully removed
        ASSERT_EQ(head->next, node3);
        ASSERT_EQ(node3->prev, head);

        // Free memory
        free(node3);
    }

    END_TESTING();
}
