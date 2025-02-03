#pragma once

#include "list.hpp"
#include <stdio.h>



/* function to create a new list node */
list_t* create_node(int data) {
    list_t* node = (list_t*)malloc(sizeof(list_t));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

void insert_after(list_t* item, int data) {
    int retval = insert_next_to_list(item, data);
    if (retval == 1) {
        printf("Cannot insert after a null item.\n");
    }
    if (retval == 2) {
        printf("Failed to allocate memory for new node.\n");
        exit(EXIT_FAILURE);
    }
}

void  remove_next_node(list_t* item) {
    int return_val = remove_next_from_list(item);
    if (return_val == 1) {
        printf("Cannot remove next item from a null item.\n");
    }
    else if (return_val == 2) {
        printf("No next item to remove.\n");
        return;
    }
}

void listfree(list_t* item) {
    if (item->next == NULL) {
        free(item);
        return;
    }
    listfree(item->next);
    free(item);
}

