#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory> 
#include <string>

struct list_t {
    int data;
    std::unique_ptr<list_t> next; 

    list_t(int val) : data(val), next(nullptr) {}
};

int count_list_items(const list_t* head);
void insert_next_to_list(list_t* item, int data);
void remove_next_from_list(list_t* item);
std::string item_data(const list_t* list);
void print_list(const list_t* list);

#endif // LIST_HPP
  