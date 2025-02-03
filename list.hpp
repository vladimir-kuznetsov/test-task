#include<memory>
#pragma once

typedef struct list_s
{
    struct list_s* next; /* NULL for the last item in a list */
    int data;
}
list_t;

/* Counts the number of items in a list.
 */
int count_list_items(const list_t* head) {
    // Handle the case where the list is empty
    if (head == NULL) {
        return 0;
    }
    else if (head->next) {
        return count_list_items(head->next) + 1;
    }
    else {
        return 1;
    }
}

/* Inserts a new list item after the one specified as the argument.
*/
int insert_next_to_list(list_t* item, int data) {
    if (item == NULL) return 1; // Safety check

    list_t* new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        return 2;
    }
    new_node->next = item->next;
    new_node->data = data;
    item->next = new_node;
    return 0;
}

/* Removes an item following the one specificed as the argument
*/
int remove_next_from_list(list_t* item) {
    if (item == NULL) return 1;  // Safety check
    if (item->next == nullptr) return 2;

    list_t* temp = item->next;
    //changed the order of below statements.
    item->next = item->next->next;
    free(temp);
    return 0;

}

/* Returns item data as text.
 */
char* item_data(const list_t* list)
{
    if (list == NULL) return NULL; //safety check
    char* buf = (char*)malloc(12); // Allocate memory for the string
    if (buf == nullptr) {
        printf("Failed to allocate memory for data string.\n");
        exit(EXIT_FAILURE);
    }
    // Use sprintf_s with buffer size, ensuring buf is not nullptr
    sprintf_s(buf, 12, "%d", list->data);
    return buf; // Return the string
}
