// CodeChallenge.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Thread>
#include <mutex> 
#include <chrono>
#include <vector>

#include "LockGuard.h"

using namespace std; 

//C++11 threads/synchronization/protection:

/*
1) Create a templated linked list allowing any parameter
Traversable with iterators
Pretty print structure by overloading ostream. eg: cout << my_list;
Make it push and pop like a stack
Make it a doubly linked list
Add insert_at method
Add methods, sort, reverse sort, search and slice out ranges of the list into another list
Write a test infrastructure to assure your list performs as expected both with data integrity and speed measurements.
*/


template <class T>
class node {
	
private:
	T data;

public :
	node *next; //pointer to get next node
	node *start; //pointer to mark starting point
	//make a previous pointer to make a doubly linked list
	//so we can have elements connected to the next and previous.
	node *prev;
	
	//prototypes functions
	node createNode(); //constructor
	void add_node();
	void insert_head_node();
	void insert_at();
	void delete_head();
	void search();
	void delete_tail();
	void displayList();
	~node(); //destructor

};

//function to create node and to set up memory
template <class T>
typename node<T>::node* createNode() {
	//create pointer of a new node
	node *n = new node;
	cout << "Enter Number for the node ";
	cin >> n->data;
	//set them to null
	n->next = NULL;
	n->prev = NULL;
	return n;
};

//function to add a node
template <class T>
void node<T>::add_node() {
	node *tmp;
	//call function to create node and stored it in to tmp
	tmp = createNode();

	//check if there is nothing in that position
	if (start == NULL) {
		start = tmp;
	}
	else {
		//if not , we create a new pointer
		node *traverse;
		traverse = start;
		//we check while if the pointer is not at the end
		while (traverse->next != NULL) {
			//move 1 space to the next element
			traverse = traverse->next;
		}
		//set next point
		traverse->next = tmp;
		//traverse becomes the rear point
		tmp->prev = traverse;

	}
}

//function to add at head (first position)
template <class T>
void node<T>::insert_head_node() {
	node *tmp;
	//create node and store in tmp
	tmp = createNode();
	//set it to start
	tmp->next = start;

	start->prev = tmp;
	start = tmp;


}

//function to add a node at a certain place
template <class T>
void node<T>::insert_at() {
	node *tmp;

	//we create node and store in tmp
	tmp = createNode();

	//create the var/place where the element will be stored in our list
	int value;
	cout << "Enter value where element will be inserted: " << endl;
	//store input in value
	cin >> value;

	node *traverse;
	//set traverse clean
	traverse = start;
	
	//check if there is elements after, before or any
	if (traverse->next == NULL) {
		cout << "Error: there is no in between value\n" << endl
			 << "Try use (1) Add Tail node." << endl;
		return;
	} else if (traverse->prev == NULL) {
		cout << "Error. there is no node/element before this one\n" << endl
			 << "Try use (2) Add Head node" << endl;
		return;
	}
	

	//check if the traverse position element.data is not same as the value
	//we want to insert the new element in the middle.
	while (traverse->data != value) {
		//we move next one
		traverse = traverse->next;
	}
	//previous pointer points to traverse (1 previous element)
	tmp->prev = traverse;
	//the new node next points to traverse next element (1 ahead elemeent)
	tmp->next = traverse->next;
	//the element that is ahead by 1 space now points to tmp, our element we
	//want to insert
	traverse->next->prev = tmp;
	//tarverse next pointer now finally points to our tmp(new elemeent we want to insert)
	traverse->next = tmp;
	//let user know that the number was inserted
	cout << "Element was inserted successfuly!\n" << endl;
}

//function to delete node at the tail (end)
template <class T>
void node<T>::delete_tail() {
	node *traverse;
	traverse = start;

	//if traverse found nothing, lists is empty, return to main menu
	if (traverse == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	else if (traverse->prev || traverse->next == NULL) {
		cout << "Can't delete tail because is the only element left." << endl
			 << "Choose another optionto delete it" << endl;
		return;
	}

	//run thru the last position until is null
	//if it is null this means we are at the last element
	while (traverse->next != NULL) {
		//keep moving until last element
		traverse = traverse->next;
	}
	//set to null
	traverse->prev->next = NULL;
	//display info
	cout << " -> " << traverse->data << " has been deleted " << endl;
	delete(traverse);
}

//function to delete the head node (first)
template <class T>
void node<T>::delete_head() {
	node *tmp;
	//set it to start
	tmp = start;
	if (tmp == NULL) {
		cout << "List is empty, Nothing else to delete\n" << endl;
		return;
	}

	start = start->next;
	cout << tmp->data << "Has been Deleted" << endl;
	delete(tmp);
}

//function to search  an element in the linked list
template <class T>
void node<T>::search() {
	//variables
	node *traverse;
	int x;

	traverse = start;

	cout << "Enter number of element to search: \n" << endl;
	//user input store
	cin >> x;
	bool isDataFound = false;

	//if its empty the list, let user know, and send it back to menu.
	if (traverse == NULL) {
		cout << "Error. There is no data in the linked list" << endl
			 << "Try add elements first.\n" << endl;
		return;
	}

	//while we don't find the end, we keep moving
	while (traverse != NULL) {

		//if the element match the element that we looking for
		if (traverse->data == x) {
			//set it to true
			isDataFound = true;
			break;
		}
		//keep moving next element
		traverse = traverse->next;
	}

	if (isDataFound) {
		cout << traverse->data << "-> Element Was Found" << endl;
	}
	else {
		cout << traverse << "-> Element Was Not Found" << endl;
	}
}

//function to sort (insertion sort)
//function to display linked list
template <class T>
void node<T>::displayList() {
	node *traverse;
	//traverse we set it to start
	traverse = start;
	//we keep running thru the list until there is no element (NULL)
	cout << "Linked List: \n" << endl;
	while (traverse != NULL) {

		//print traverse with the current data/element, witha space 
		cout << traverse->data << " ";
		//move forward one step to continue printing all eleemnts
		traverse = traverse->next;
	}

}


//Thread




//MAIN
int main() {

	int choice;

	//start 3 threads
	/*vector<thread> threads(3);
	for (auto& t : threads) {
		t = thread{};
	}
	
	//join them to the amin thread so it does not crash
	for (auto& t : threads) {
		t.join();
	}*/

	//display menu
	do {
		cout << "\n-MENU-" << endl;
		cout << "(1) Add node" << endl;
		cout << "(2) Add Head node (first position)" << endl;
		cout << "(3) Add Node at certain position" << endl;
		cout << "(4) Delete Head Node" << endl;
		cout << "(5) Delete Tail Node" << endl;
		cout << "(6) Display linked list" << endl;
		//cout << "(7) Sort" << endl;
		cout << "(8) Search for element" << endl;
		cout << "(9) Exit\n" << endl;
		cout << "Enter option: ";

		cin >> choice;

		switch (choice) {
		case 1:
			//add a noce function
			void add_node();
			break;
		case 2:
			//add node to the first position
			void insert_head_node();
			break;
		case 3:
			//call function to inser a node at certain element
			void insert_at();
			break;
		case 4:
			//function to dete the head of the node (Head)
			void delete_head();
			break;
		case 5:
			//call function to delete last node(tail)
			void delete_tail();
			break;
		case 6:
			//call function
			void displayList();
			break;
		case 7:
			//call function to do insertion sort
			
			break;
		case 8:
			//call function to search
			void search();
			break;
		case 9:
			//exit application
			cout << "Goodbye! " << endl;
			exit(EXIT_SUCCESS);
		default:
			cout << "Not valid Input. Try again\n" << endl;
		}

	} while (choice != 9);

	

	return 0;
}

