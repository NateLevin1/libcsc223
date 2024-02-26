#include <stdio.h>
#include <ctest.h>
#include "list.h"

int main() {
    BEGIN_TESTING("list.h");

    TEST("Can create node") {
        Node* n = make_node(3);
        ASSERT_EQ(n->val, 3);
        ASSERT_EQ(n->next, NULL);
    }

    TEST("Can create two nodes and link them together") {
        Node* n1 = make_node(3);
        Node* n2 = make_node(2);
        n1->next = n2;
        ASSERT_EQ(n1->val, 3);
        ASSERT_EQ(n1->next->val, 2);
        ASSERT_NOT_EQ(n1->next, NULL);
        ASSERT_EQ(n1->next->next, NULL);
    }

    TEST("Can add node to empty list") {
        Node* mylist = NULL;
        Node* n = make_node(2);
        insert_in_front(&mylist, &n);
        ASSERT_EQ(mylist->val, 2);
        ASSERT_EQ(mylist->next, NULL);
    }

    TEST("Can add node to list with one node") {
        Node* mylist = NULL;
        Node* n = make_node(2);
        insert_in_front(&mylist, &n);
        n = make_node(1);
        insert_in_front(&mylist, &n);
        ASSERT_EQ(mylist->val, 1);
        ASSERT_EQ(mylist->next->val, 2);
        ASSERT_EQ(mylist->next->next, NULL);
    }

    TEST("Can print list") {
        Node* mylist = NULL;
        RETURNS_STR(print_list, "", (mylist));

        Node* n = make_node(1);
        insert_in_front(&mylist, &n);
        RETURNS_STR(print_list, "1", (mylist));

        // Test with 4 nodes
        for (int i = 2; i < 5; i++) {
            n = make_node(i);
            insert_in_front(&mylist, &n);
        }
        RETURNS_STR(print_list, "4 -> 3 -> 2 -> 1", (mylist));

        // One last test with big value gap 
        n = make_node(1024);
        insert_in_front(&mylist, &n);
        RETURNS_STR(print_list, "1024 -> 4 -> 3 -> 2 -> 1", (mylist));
    }

    TEST("Can output list length") {
        Node* mylist = NULL;
        ASSERT_EQ(list_length(mylist), 0);

        Node* n = make_node(1);
        insert_in_front(&mylist, &n);
        ASSERT_EQ(list_length(mylist), 1);

        for (int i = 2; i < 10; i++) {
            n = make_node(i);
            insert_in_front(&mylist, &n);
        }
        ASSERT_EQ(list_length(mylist), 9);
    }

    TEST("Can find item in list") {
        Node* mylist = NULL;
        Node* n;
        for (int i = 0; i < 7; i += 2) {
            n = make_node(i);
            insert_in_front(&mylist, &n);
        }
        RETURNS_STR(print_list, "6 -> 4 -> 2 -> 0", (mylist));
        Node* result = find_in_list(mylist, 2);
        ASSERT_EQ(mylist->next->next, result);
        // Verify returns null when item not found
        result = find_in_list(mylist, 3);
        ASSERT_EQ(NULL, result);
    }

    TEST("Can insert node at end of list") {
        // Insert at end of empty list
        Node* mylist = NULL;
        Node* n = make_node(1);
        insert_at_end(&mylist, &n);
        RETURNS_STR(print_list, "1", (mylist));
        // Insert at end of list with one node
        n = make_node(7);
        insert_at_end(&mylist, &n);
        RETURNS_STR(print_list, "1 -> 7", (mylist));
        // One more time for good measure 
        n = make_node(42);
        insert_at_end(&mylist, &n);
        RETURNS_STR(print_list, "1 -> 7 -> 42", (mylist));
    }

    TEST("Can insert node in order in descending list") {
        // Confirm works with empty list
        Node* mylist = NULL;
        Node* n = make_node(4);
        insert_in_order(&mylist, &n);
        RETURNS_STR(print_list, "4", (mylist));
        for (int i = 6; i < 10; i += 2) {
            n = make_node(i);
            insert_in_front(&mylist, &n);
        }
        // Confirm list is starts as desired
        RETURNS_STR(print_list, "8 -> 6 -> 4", (mylist));
        n = make_node(5);
        insert_in_order(&mylist, &n);
        // Confirm new node inserted in order 
        RETURNS_STR(print_list, "8 -> 6 -> 5 -> 4", (mylist));
        // Confirm insert smallest at end works 
        n = make_node(3);
        insert_in_order(&mylist, &n);
        RETURNS_STR(print_list, "8 -> 6 -> 5 -> 4 -> 3", (mylist));
    }

    TEST("Can can remove node from list") {
        Node* mylist = NULL;
        Node* n;
        for (int i = 0; i < 7; i += 2) {
            n = make_node(i);
            insert_in_front(&mylist, &n);
        }
        RETURNS_STR(print_list, "6 -> 4 -> 2 -> 0", (mylist));
        Node* testptr = mylist->next;
        n = remove_from_list(&mylist, 4);
        ASSERT_EQ(testptr, n);
        RETURNS_STR(print_list, "6 -> 2 -> 0", (mylist));
    }

    END_TESTING();
}
