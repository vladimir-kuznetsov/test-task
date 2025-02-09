

#ifndef LIST_HPP
#define LIST_HPP

#include<iostream>
#include<memory>
#include<stdexcept>
#include<exception>
#include<string>
#include<assert.h> 

struct list_s {
public:
	int data;
	std::unique_ptr<list_s>next;

	list_s( int val) : data( val), next(nullptr) {};

};

using list_t = list_s;

//Function Prototypes 
int count_list_items(const list_t* head);
void insert_next_to_list(list_t* item, int data);
void remove_next_from_list(list_t* item);
std::string item_data(const list_t* item);
void print(const list_t* curr);

#endif

