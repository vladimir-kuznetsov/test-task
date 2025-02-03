#pragma once

#ifndef LIST_HPP
#define LIST_HPP

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>

// Structure Declaration
typedef struct list_s {
    struct list_s* next;
    int data;
} list_t;

// Function prototypes
int count_list_items(const list_t* item);
void insert_next_to_list(list_t* item, int data);
void remove_next_from_list(list_t* item);
char* item_data(const list_t* list);
void free_item_memory(list_t* head);
void print(const list_t* curr);

#endif // LIST_HPP


