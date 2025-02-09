#include <memory>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

#pragma once

struct list_t {
    shared_ptr<list_t> next; // Use smart pointer
    int data;
};


/* Counts the number of items in a list. */
int count_list_items(const shared_ptr<list_t>& head) {
    if (!head) {
        return 0;
    }
    return 1 + count_list_items(head->next);
}

/* Inserts a new list item after the one specified as the argument. */
void insert_next_to_list(shared_ptr<list_t> item, int data) {
    if (!item) throw invalid_argument("Cannot insert after a null item.");

    auto new_node = make_shared<list_t>();
    new_node->data = data;
    new_node->next = item->next;
    item->next = new_node;
}

/* Removes an item following the one specified as the argument. */
void remove_next_from_list(shared_ptr<list_t> item) {
    if (!item) throw invalid_argument("Cannot remove next item from a null item.");
    if (!item->next) throw runtime_error("No next item to remove.");

    item->next = item->next->next; // Automatically frees the removed node
}

/* Returns item data as text. */
string item_data(const shared_ptr<list_t>& list) {
    if (!list) throw invalid_argument("Cannot get data from a null item.");
    return to_string(list->data);
}