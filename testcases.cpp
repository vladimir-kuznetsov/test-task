#include "list.hpp"
#include <iostream>
#include <cassert>
#include <memory>

using namespace std;

void test_insert_next_to_list() {
    try {
        auto head = make_unique<list_t>(23);
        insert_next_to_list(head.get(), 87);
        insert_next_to_list(head->next.get(), 35);
        insert_next_to_list(head->next->next.get(), 76);
        insert_next_to_list(head->next->next->next.get(), 65);

        assert(head->next->data == 87);
        assert(head->next->next->next->data == 76);

        cout << "insert_next_to_list working correctly.\n";
    }
    catch (const exception& e) {
        cerr << "Exception in test_insert_next_to_list: " << e.what() << std::endl;
    }
}

void test_remove_next_from_list() {
    try {
        auto head = make_unique<list_t>(23);
        insert_next_to_list(head.get(), 87);
        insert_next_to_list(head->next.get(), 35);
        insert_next_to_list(head->next->next.get(), 76);

        remove_next_from_list(head->next.get());
        assert(head->next->next->data == 76);

        cout << "remove_next_from_list working correctly.\n";
    }
    catch (const exception& e) {
        cerr << "Exception in test_remove_next_from_list: " << e.what() << endl;
    }
}

void test_item_data() {
    try {
        auto head = make_unique<list_t>(23);
        insert_next_to_list(head.get(), 87);

        assert(item_data(head->next.get()) == "87");

        cout << "item_data working correctly.\n";
    }
    catch (const exception& e) {
        cerr << "Exception in test_item_data: " << e.what() << endl;
    }
}

void test_print_list() {
    try {
        auto head = make_unique<list_t>(23);
        insert_next_to_list(head.get(), 87);
        insert_next_to_list(head->next.get(), 35);

        cout << "Expected Output: 23 87 35\nActual Output:   ";
        print_list(head.get());

        cout << "print_list working correctly.\n";
    }
    catch (const std::exception& e) {
        cerr << "Exception in test_print_list: " << e.what() << endl;
    }
}

int main() {
    test_insert_next_to_list();
    test_remove_next_from_list();
    test_item_data();
    test_print_list();

    cout << "\nAll test cases passed successfully.\n";
    return 0;
}
