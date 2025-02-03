#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRTDBG_MAP_ALLOC  // Enables memory leak reporting
#include <crtdbg.h>         


/* Counts the number of items in a list.
 */
int count_list_items(const list_t* head) {
    if (!head) return 0;
    return count_list_items(head->next) + 1;
}

/* Inserts a new list item after the one specified as the argument.
          */
void insert_next_to_list(list_t* item, int data) {
    if (!item) {
        printf("%s", "No item to insert\n");
        return;
    }
    list_t* new_item = malloc(sizeof(list_t));
    if (!new_item) {
        printf("%s", "Memory could not be allocated\n");
        return;
    }
    new_item->data = data;
    new_item->next = item->next;
    item->next = new_item;
}

/* Removes an item following the one specificed as the argument.
          */
void remove_next_from_list(list_t* item) {
    if (!item || !item->next) {
        printf("%s", "Element could not be removed\n");
        return;
    }
    list_t* temp = item->next;
    item->next = temp->next;
    free(temp);
}

/* Returns item data as text.
 */
char* item_data(const list_t* list)
{
    if (!list) return NULL;
    char* buf = malloc(12 * sizeof(char));
    if (!buf) {
        printf("%s", "Memory buffer could not be created\n");
        return NULL;
    }

    snprintf(buf, 12, "%d", list->data);
    return buf;
}
//
//int main() {
//    list_t* head = malloc(sizeof(list_t));
//    if (!head) {
//        printf("%s", "Memory could not be allocated\n");
//        return 1;
//    }
//    head->data = 1;
//    head->next = NULL;
//
//    insert_next_to_list(head, 2);
//    insert_next_to_list(head, 3);
//
//    printf("List count: %d\n", count_list_items(head));
//
//    printf("Elements in the list: ");
//    list_t* current = head;
//    while (current) {
//        char* data_str = item_data(current);
//        printf("%s ", data_str);
//        free(data_str);
//        current = current->next;
//    }
//    printf("\n");
//
//    remove_next_from_list(head);
//
//    printf("List count after removal: %d\n", count_list_items(head));
//
//    while (head) {
//        list_t* temp = head;
//        head = head->next;
//        free(temp);
//    }
//
//    return 0;
//}