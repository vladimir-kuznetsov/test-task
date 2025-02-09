
#include"list.hpp"
using namespace std;

void test_for_count_list_items() {

	cout << "Checking test_for_count_list_items" << endl;

	// Case 1 -> When list is empty 
	// The count should be zero in this case
	unique_ptr<list_t> head = nullptr;
	assert(head == nullptr );
	try {
		assert(count_list_items(head.get()) == 0);
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught :" << e.what() << endl;
	}


    //Case 2 -> When list has only 1 item
	head = make_unique<list_t>(101);
	assert(head != nullptr);
	try {
		assert(count_list_items(head.get()) == 1);
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught : " << e.what() << endl;
	}

     //Case 3 -> When list is having more than 1 item 
	    
	try {
		insert_next_to_list(head.get(), 202);
		insert_next_to_list(head.get(), 303);
		assert(count_list_items(head.get()) == 3);
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	}

	cout << "-> test_for_count_list_items running successfully" << endl << endl;

}

void test_for_insert_next_to_list() {

	cout << "Checking test_for_insert_next_to_list" << endl;

	// Case 1 -> Insert in an empty list 
	// This case should throw an Exception 
	unique_ptr<list_t>head = nullptr;
	assert(head == nullptr);
	try {
		insert_next_to_list(head.get(), 100);
		assert(count_list_items(head.get()) == 0);
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	}


	// Case 2 and 3 -> Insert after any item and after null item
	head = make_unique<list_t>(101);
	assert(head->data == 101);
	assert(head->next == nullptr);
	try {
		insert_next_to_list(head.get(), 202);
		insert_next_to_list(head->next.get(), 303);
		assert(count_list_items(head.get()) == 3);
		assert(head->next != nullptr);
		assert(head->next->data == 202);
		assert(head->next->next->next == nullptr );
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	}

	cout << "-> test_for_insert_next_to_list running successfully" << endl<<endl;
}

void test_for_remove_next_from_list() {
	cout << "Checking test_for_remove_next_from_list" << endl;

	// Case 1: Remove from an empty list
	// This case should throw an Exception 
	unique_ptr<list_t>head = nullptr;
	assert(count_list_items(head.get()) == 0);
	try {
		remove_next_from_list(head.get());
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	}

    // Case 2 and 3 -> Removing when there is only 1 item and when there are more than 1 item
	head = make_unique<list_t>(101);
	assert(count_list_items(head.get()) == 1);
	assert(head->next == nullptr);
	try {
		insert_next_to_list(head.get(), 202);
		insert_next_to_list(head->next.get(), 303);
		remove_next_from_list(head->next.get());
		assert(head->next != nullptr);
		assert(head->next->data == 202);
		remove_next_from_list(head.get());
		assert(count_list_items(head.get()) == 1);
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	}

	cout << "-> test_for_remove_next_from_list running successfully"<<endl<<endl;
}

void test_for_item_data() {

	cout << "Checking test_for_item_data" << endl;

	// Case 1 -> When list is empty
	// This case should return an exception
	unique_ptr<list_t> head = nullptr;
	assert(head == nullptr);
	try {
	    item_data(head.get());
	}
	catch (const invalid_argument& e){
		cout << "Exception caught: " << e.what() << endl;
	}
	

		// Case 2 and 3 -> Single item and more than single item
		head = make_unique<list_t>(101);
		try {
			insert_next_to_list(head.get(), 202);
			insert_next_to_list(head->next.get(), 303);
			assert(item_data(head->next.get()) == "202");
			remove_next_from_list(head->next.get());
			remove_next_from_list(head.get());
			assert(item_data(head.get()) == "101");
		}
		catch (const invalid_argument& e) {
			cout << "Exception caught: " << e.what() << endl;
		}
		cout << "-> test_for_item_data running successfully."<<endl<<endl;
	}

void test_for_print_empty_list() {
	cout << "Checking test_for_print_empty_list" << endl;

	auto head = make_unique<list_t>(1001);
	assert(head->data == 1001);
	assert(head->next == nullptr);
	// List should be empty in this case 
	try {
		print(nullptr);
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	}

	try {
		insert_next_to_list(head.get(), 1002);
		insert_next_to_list(head->next.get(), 1003);
		insert_next_to_list(head->next->next.get(), 1004);
		assert(count_list_items(head.get()) == 4);
		print(head.get());
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	
	cout << "-> test_for_print_empty_list running successfully" <<endl<<endl;
}



int main() {

	//Test cases 
	cout << "Checking unit test cases" << endl<<endl;

	test_for_count_list_items();
	test_for_insert_next_to_list();
	test_for_remove_next_from_list();
	test_for_item_data();

	// For Additional functions 
	test_for_print_empty_list();

  // In all these functions the memory is getting deallocated automatically
  // beacuse we are using smart pointers

	cout<<"All unit test cases passed "<<endl;
}