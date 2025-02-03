
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "abstract.hpp"

// Function prototypes for unit tests
void test_create_node();
void test_insert_after();
void test_remove_next_node();
void test_item_data();

int main() {
    // Run all unit tests
    test_create_node();
    test_insert_after();
    test_remove_next_node();
    test_item_data();

    printf("All tests passed!\n");
    return 0;
}

// Test for creating a node
void test_create_node() {
    list_t* head = create_node(10);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    free(head);
}

// Test for inserting a node
void test_insert_after() {
    list_t* head = create_node(10);
    insert_after(head, 20);
    assert(count_list_items(head) == 2);
    assert(head->next != NULL);
    assert(head->next->data == 20);
    free(head);
}

// Test for removing the next node
void test_remove_next_node() {
    list_t* head = create_node(10);
    insert_after(head, 20);
    remove_next_node(head);
    assert(count_list_items(head) == 1);
    assert(head->next == NULL);
    listfree(head);
}

// Test for item_data function
void test_item_data() {
    list_t* head = create_node(10);
    char* data_str = item_data(head);
    assert(data_str != NULL);
    assert(strcmp(data_str, "10") == 0);
    free(data_str);
    listfree(head);
}
