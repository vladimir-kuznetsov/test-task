#include "list.hpp"
#include <stdexcept>
#include <string>

using namespace std;

int count_list_items(const list_t* head) {
    return head ? 1 + count_list_items(head->next.get()) : 0;
}

void insert_next_to_list(list_t* item, int data) {
    if (!item) throw invalid_argument("Cannot insert into a null node.");
    auto newNode = make_unique<list_t>(data);
    newNode->next = move(item->next);
    item->next = move(newNode);
}

void remove_next_from_list(list_t* item) {
    if (!item || !item->next) throw invalid_argument("No next node to remove.");
    item->next = move(item->next->next); 
}

string item_data(const list_t* list) {
    if (!list) throw invalid_argument("Cannot retrieve data from a null node.");
    return to_string(list->data);
}

void print_list(const list_t* head) {
    if (!head) {
        cout << "Nothing to print\n";
        return;
    }
    while (head) {
        cout << head->data << " ";
        head = head->next.get();
    }
    cout << endl;
}
//
//int main() {
//    try {
//        auto head = make_unique<list_t>(23);
//
//        insert_next_to_list(head.get(), 87);
//        insert_next_to_list(head->next.get(), 35);
//        insert_next_to_list(head->next->next.get(), 76);
//        insert_next_to_list(head->next->next->next.get(), 65);
//
//        cout << "Linked List: ";
//        print_list(head.get());
//
//        cout << "Total items: " << count_list_items(head.get()) << endl;
//
//        remove_next_from_list(head->next.get()); // Removes node with value 35
//
//        cout << "After removal: ";
//        print_list(head.get());
//
//        cout << "Item data of second node: " << item_data(head->next.get()) << endl;
//
//        // No need for delete, unique_ptr handles cleanup automatically
//    }
//    catch (const exception& e) {
//        cerr << "Exception caught: " << e.what() << endl;
//    }
//
//    return 0;
//}
