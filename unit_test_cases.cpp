
#include"list.hpp"

void test_for_count_list_items() {

    printf("Checking test_for_count_list_items \n ");

    // Case 1 -> When list is empty 
    list_t* head = NULL;
    assert(count_list_items(head) == 0);

    // Case 2 -> When list is having only 1 item 
    head = (list_t*)malloc(sizeof(list_t));
    assert(head != NULL);
    head->data = 10;
    head->next = NULL;
    assert(count_list_items(head) == 1);

    // Case 3 -> When list is having more than 1 item 
    insert_next_to_list(head, 20);
    insert_next_to_list(head, 30);
    assert(count_list_items(head) == 3);

    // After deallocating the memory
    free_item_memory(head);
    head = NULL;
    assert(count_list_items(head) == 0);

    printf("-> test_for_count_list_items running successfully.\n\n");

}

void test_for_insert_next_to_list() {

    printf("Checking test_for_insert_next_to_list\n ");

    // Case 1 -> Insert in an empty list 
    list_t* head = NULL;
    insert_next_to_list(head, 100);
    assert(count_list_items(head) == 0);


    // Case 2 -> Insert into after any item
    head = (list_t*)malloc(sizeof(list_t));
    assert(head != NULL);
    head->data = 101;
    head->next = NULL;

    insert_next_to_list(head, 202);
    assert(head->next != NULL);
    assert(head->next->data == 202);

    insert_next_to_list(head->next, 303);
    assert(head->next->next != NULL);
    assert(head->next->next->data == 303);

    // Case 3 -> Inserting an element after the last null item
    insert_next_to_list(head->next->next->next, 404);
    assert(head->next->next->next == NULL);
    assert(count_list_items(head) == 3);

    // After deallocating the memory
    free_item_memory(head);
    head = NULL;
    assert(count_list_items(head) == 0);

    printf("-> test_for_insert_next_to_list running successfully.\n\n");

}

void test_for_remove_next_from_list() {

    printf("Checking test_for_remove_next_from_list\n ");

    // Case 1: Remove from an empty list
    list_t* head = NULL;
    remove_next_from_list(head);

    // Case 2 and 3 -> Removing when there is only 1 item and when there are more than 1 item
    head = (list_t*)malloc(sizeof(list_t));
    assert(head != NULL);
    head->data = 101;
    head->next = NULL;

    insert_next_to_list(head, 202);
    insert_next_to_list(head->next, 303);
    assert(count_list_items(head) == 3);

    remove_next_from_list(head);
    assert(count_list_items(head) == 2);
    assert(head->next != NULL);
    assert(head->next->data == 303);

    remove_next_from_list(head);
    assert(count_list_items(head) == 1);
    assert(head->next == NULL);

    // After deallocating the memory
    free_item_memory(head);
    head = NULL;
    assert(head == NULL);

    printf("-> test_for_remove_next_from_list running successfully.\n\n");

}

void test_for_item_data() {
    printf("Checking test_for_item_data\n ");

    // Case 1 -> When list is empty
    list_t* head = NULL;
    char* str = item_data(head);
    assert(str == NULL);

    // Case 2 -> Single item
    head = (list_t*)malloc(sizeof(list_t));
    assert(head != NULL);
    head->data = 11;
    head->next = NULL;

    str = item_data(head);
    assert(str != NULL);
    assert(strcmp(str, "11") == 0);

    // Case 3 -> More than 1 item
    insert_next_to_list(head, 22);
    insert_next_to_list(head->next, 33);

    str = item_data(head->next->next);
    assert(str != NULL);
    assert(strcmp(str, "33") == 0);

    remove_next_from_list(head->next);
    str = item_data(head->next);
    assert(str != NULL);
    assert(strcmp(str, "22") == 0);

    // After deallocating the memory 

    free_item_memory(head);
    head = NULL;
    assert(head == NULL);

    printf("-> test_for_item_data running successfully.\n\n");

}


// For Additional functionalities 
void test_for_free_list() {
    printf("Checking test_for_free_list\n ");

    // Case 1 -> When head is NULL 
    list_t* head = NULL;
    free_item_memory(head);

    // Case 2 -> When there is more than 1 item
    head = (list_t*)malloc(sizeof(list_t));
    assert(head != NULL);
    head->data = 10;
    head->next = NULL;

    insert_next_to_list(head, 20);
    insert_next_to_list(head, 30);
    assert(count_list_items(head) == 3);

    free_item_memory(head);
    head = NULL;

    assert(count_list_items(head) == 0);  // Ensure list is empty after free
    printf("-> test_for_free_list running successfully.\n\n");
}

void test_for_print_empty_list() {
    printf("Checking test_for_print_empty_list\n ");

    list_t* head = (list_t*)malloc(sizeof(list_t));
    assert(head != NULL);
    head->data = 1001;
    head->next = NULL;

    insert_next_to_list(head, 1002);
    insert_next_to_list(head, 1003);
    insert_next_to_list(head, 1004);

    // Checking by printing the item data  
    print(head);

    printf("-> test_for_print_empty_list running successfully.\n\n");
}

int main() {
    //Test cases 
    printf("Checking unit test cases\n\n");

    test_for_count_list_items();
    test_for_insert_next_to_list();
    test_for_remove_next_from_list();
    test_for_item_data();

    // For Additional functions 
    test_for_free_list();
    test_for_print_empty_list();

    printf("All unit test cases passed ");

}