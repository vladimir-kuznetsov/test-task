
#include"list.hpp"
using namespace std;

/* Counts the number of items in a list.
           */
int count_list_items(const list_t* head) {
    if (head == nullptr) 
        return 0;
    

    int count = 0;
    while (head != nullptr) {
        ++count;
        head = head->next.get();
    }

    return count;
}

/* Inserts a new list item after the one specified as the argument.
          */
void insert_next_to_list(list_t* item, int data) {
    
    if (item == nullptr) 
        throw invalid_argument("Cannot insert after a NULL node");
    

    unique_ptr<list_t> temp = make_unique<list_t>(data); 
    temp->next = move(item->next);
    item->next = move(temp);
}

/* Removes an item following the one specificed as the argument.
          */
void remove_next_from_list(list_t* item) {

    if (item == nullptr || item->next == nullptr) 
        throw invalid_argument(" Cannot remove node.Either item is NULL or has no next node");
    

    item->next = move(item->next->next);
}

/* Returns item data as text.
            */
string item_data(const list_t* item){

    if (item == nullptr) 
        throw invalid_argument("The item is null, cannot retrieve data from a null item");
     
    return to_string(item->data);
}

// Additional Functionalities 

// Printing the item data
void print(const list_t* curr) {

    if (curr == nullptr)
        cout << "The list is empty , nothing to print";

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next.get();
    }
    cout << endl;
}



