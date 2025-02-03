#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>     

void test_count_list_items() {
    list_t* head = NULL;
    assert(count_list_items(head) == 0);

    head = malloc(sizeof(list_t));
    if (!head) {
        printf("Memory allocation failed\n");
        return;
    }
    head->data = 54;
    head->next = NULL;
    assert(count_list_items(head) == 1);

    head->next = malloc(sizeof(list_t));
    if (!head->next) {
        printf("Memory allocation failed\n");
        free(head);
        return;
    }
    head->next->data = 132;
    head->next->next = NULL;
    assert(count_list_items(head) == 2);

    free(head->next);
    free(head);
}

void test_insert_next_to_list() {
    list_t* head = malloc(sizeof(list_t));
    if (!head) {
        printf("Memory allocation failed\n");
        return;
    }
    head->data = 123;
    head->next = NULL;

    insert_next_to_list(head, 54);
    assert(head->next != NULL);
    assert(head->next->data == 54);

    free(head->next);
    free(head);
}

void test_remove_next_from_list() {
    list_t* head = malloc(sizeof(list_t));
    if (!head) {
        printf("Memory allocation failed\n");
        return;
    }
    head->data = 21;
    head->next = NULL;

    insert_next_to_list(head, 42);
    insert_next_to_list(head, 12);
    insert_next_to_list(head, 87);
    insert_next_to_list(head, 56);

    remove_next_from_list(head);
    assert(head->next != NULL);
    assert(head->next->data == 87);

    while (head) {
        list_t* temp = head;
        head = head->next;
        free(temp);
    }
}

void test_item_data() {
    list_t* head = malloc(sizeof(list_t));
    if (!head) {
        printf("Memory allocation failed\n");
        return;
    }
    head->data = 124;
    head->next = NULL;

    insert_next_to_list(head, 87);
    insert_next_to_list(head, 56);

    char* data = item_data(head);
    assert(data != NULL);
    assert(strcmp(data, "124") == 0);
    free(data);

    while (head) {
        list_t* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);



    test_count_list_items();
    test_insert_next_to_list();
    test_remove_next_from_list();
    test_item_data();

    printf("All tests passed!\n");

    _CrtDumpMemoryLeaks();
    return 0;
}