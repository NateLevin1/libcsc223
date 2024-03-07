#include <stdio.h>
#include <stdlib.h>
#include <ctest.h>
#include "dlist.h"

int main() {
    BEGIN_TESTING("dlist.h");

    TEST("Can create dnode") {
        Dnode* dn = make_dnode(6);
        ASSERT_EQ(dn->val, 6);
        ASSERT_EQ(dn->next, NULL);
        ASSERT_EQ(dn->prev, NULL);
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

    TEST("Can insert element at index in dlist") {
        // Create a doubly linked list: 1 <-> 3 <-> 5
        Dnode* head = make_dnode(1);
        dlist_insert_at_index(&head, 1, 3);
        dlist_insert_at_index(&head, 2, 5);

        // Insert element 4 at index 2: 1 <-> 3 <-> 4 <-> 5
        dlist_insert_at_index(&head, 2, 4);

        // Verify the list after insertion
        ASSERT_EQ(head->val, 1);
        ASSERT_EQ(head->next->val, 3);
        ASSERT_EQ(head->next->next->val, 4);
        ASSERT_EQ(head->next->next->next->val, 5);
        ASSERT_EQ(head->next->next->next->next, NULL);

        // Free memory
        free(head->next->next);
        free(head->next);
        free(head);
    }

    TEST("Can find in dlist") {
        // Create a doubly linked list: 1 <-> 3 <-> 5
        Dnode* head = make_dnode(1);
        dlist_insert_at_index(&head, 1, 3);
        dlist_insert_at_index(&head, 2, 5);

        // Should find 3, 5, and 1 in the list
        ASSERT_EQ(find_in_dlist(head, 3)->val, 3);
        ASSERT_EQ(find_in_dlist(head, 5)->val, 5);
        ASSERT_EQ(find_in_dlist(head, 1)->val, 1);

        // Shouldn't find 7
        ASSERT_EQ(find_in_dlist(head, 7), NULL);
    }

    TEST("Can get list length") {
        Dnode* head = make_dnode(1);
        dlist_insert_at_index(&head, 1, 3);
        dlist_insert_at_index(&head, 2, 5);

        ASSERT_EQ(dlist_length(head), 3);
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

    END_TESTING();
}
