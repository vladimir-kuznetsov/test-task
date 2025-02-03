#include"list.hpp"

/* Counts the number of items in a list.
           */
int count_list_items(const list_t* item) {
    if (item == NULL) {
        //printf("List is empty\n"); For Understanding
        return 0;
    }

    int count = 0;
    while (item != NULL) {
        count++;
        item = item->next;  // Move to next node
    }
    return count;
}


/* Inserts a new list item after the one specified as the argument.
          */
void insert_next_to_list(list_t* item, int data) {
    if (item == NULL) {
        printf("Cannot insert after a NULL node\n");
        return;
    }

    list_t* temp = (list_t*)malloc(sizeof(list_t));
    if (!temp) {
        printf("Memory not allocated\n ");
        exit(1);
    }

    temp->data = data;
    temp->next = item->next;
    item->next = temp;
}

/* Removes an item following the one specificed as the argument.
          */
void remove_next_from_list(list_t* item) {
    if (item == NULL || item->next == NULL) {
        printf(" Cannot remove node.Either item is NULL or has no next node.\n");
        return;
    }
    list_t* temp = item->next;
    item->next = temp->next;
    free(temp);
    temp = NULL;
}

/* Returns item data as text.
            */
char* item_data(const list_t* list)
{
    if (list == NULL) {
        return NULL;
    }

    int buffer_size = 12;
    char* buf = (char*)malloc(buffer_size);
    if (buf == NULL) {
        printf("Memory not allocated\n ");
        exit(1);
    }
    sprintf_s(buf, buffer_size, "%d", list->data);
    return buf;
}

// Some additional neccesary functionaities for own understanding and catching the errors 

// Deallocating the memory 
void free_item_memory(list_t* head) {
    while (head != NULL) {
        list_t* temp = head;
        head = head->next;
        free(temp);
    }
}

// Printing the item data
void print(const list_t* curr) {
    if (curr == NULL) {
        printf("The list is empty , nothing to print \n");
        return;
    }

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

