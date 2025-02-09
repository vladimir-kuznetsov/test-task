#include <cassert>
#include <iostream>
#include <string>
#include "abstract.hpp"

using namespace std;

// Function prototypes for unit tests
void test_create_node();
void test_insert_after();
void test_remove_next_node();
void test_item_data();

int main() {
    // Run all unit tests
    try {
        test_create_node();
        test_insert_after();
        test_remove_next_node();
        test_item_data();
        cout <<endl<< "All tests passed!" << endl;
    }
    catch (const exception& e) {
        cerr << endl << "Test failed: " << e.what() << endl;
    }
    return 0;
}

// Test for creating a node
void test_create_node() {
    auto head = create_node(10);
    assert(head != nullptr);
    assert(head->data == 10);
    assert(head->next == nullptr);
}

// Test for inserting a node
void test_insert_after() {
    try {
        auto head = create_node(10);
        insert_next_to_list(head, 20);
        assert(count_list_items(head) == 2);
        assert(head->next != nullptr);
        assert(head->next->data == 20);

        insert_next_to_list(head->next, 30);
        assert(count_list_items(head) == 3);
        assert(head->next->next != nullptr);
        assert(head->next->next->data == 30);

        insert_next_to_list(head->next->next->next, 44); // failed insertion
    }
    catch (const exception& e) {
        cerr << endl << "Insert after test failed: " << e.what() << endl;
    }
}

// Test for removing the next node
void test_remove_next_node() {
    try {
        auto head = create_node(10);
        insert_next_to_list(head, 20);
        remove_next_from_list(head);
        assert(count_list_items(head) == 1);
        assert(head->next == nullptr);

        remove_next_from_list(head); //No next item to remove


    }
    catch (const exception& e) {
        cerr << endl << "Remove next node test failed: " << e.what() << endl;
    }

    try {
        auto head = create_node(10);
        assert(count_list_items(head) == 1);
        assert(head->next == nullptr);

        remove_next_from_list(head->next);  // Cannot remove from null.
    }
    catch (const exception& e) {
        cerr << "Remove next node test failed: " << e.what() << endl;
    }
}

// Test for item_data function
void test_item_data() {
    try {
        auto head = create_node(10);
        string data_str = item_data(head);
        assert(data_str == "10");

        insert_next_to_list(head, 33);
        string data_str1 = item_data(head->next);
        assert(data_str1 == "33");

        auto newHead = nullptr;
        string data_str2 = item_data(newHead); // Data from null Node
        
    }
    catch (const exception& e) {
        cerr << endl << "Item data test failed: " << e.what() << endl;
    }
}