#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s
{
    struct list_s* next;
    int data;
} list_t;

int count_list_items(const list_t* head);
void insert_next_to_list(list_t* item, int data);
void remove_next_from_list(list_t* item);
char* item_data(const list_t* list);

#endif