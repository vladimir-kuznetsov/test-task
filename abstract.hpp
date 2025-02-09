#pragma once

#include "list.hpp"

using namespace std;

/* Function to create a new list node */
shared_ptr<list_t> create_node(int data) {
    auto node = make_shared<list_t>();
    node->data = data;
    node->next = nullptr;
    return node;
}




