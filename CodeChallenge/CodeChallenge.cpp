// CodeChallenge.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>

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

//template 
//template<typename T>

/*template<int N>
class Array {
	private:
		int myArray[N];
	public:
		int getSize() const {
			return N;
		}
};*/

///make it using template


struct node {
	
	node *next;
	int data;
	//make a previous pointer to make a doubly linked list
	//so we can have elements connected to the next and previous.
	node *prev;
	

};

node *temp;
node *first;
//start pointer set it to null
struct node *start = NULL;

//function to create node and to set up memory
node* createNode() {
	//create pointer of a new node
	node *n = new node;
	cout << "Enter Number for the node" << endl;
	cin >> n->data;
	//set them to null
	n->next = NULL;
	n->prev = NULL;
	return n;
}

//function to add a node
void addNode() {
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
void insert_head_node() {
	node *tmp;
	//create node and store in tmp
	tmp = createNode();
	//set it to start
	tmp->next = start;

	start->prev = tmp;
	start = tmp;


}

//function to add a node at a certain place
void insert_at() {
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
	}
	else if (traverse->prev == NULL) {
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
void delete_tail() {
	node *traverse;
	traverse = start;

	/*if (traverse->data == NULL) {

	}*/

	//run thru the last position until is null
	//if it is null this means we are at the last element
	while (traverse->next != NULL) {
		//keep moving until last element
		traverse = traverse->next;
	}
	//set to null
	traverse->prev->next = NULL;
	//display info
	cout << "-> " << traverse->data << " has been deleted " << endl;
	delete(traverse);
}

//function to delete the head node (first)
void delete_head() {



}

//function to search  an element in the linked list
void search() {
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
void displayList() {
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

//MAIN
int main() {

	int choice;

	//display menu
	do {
		cout << "\n-MENU-" << endl;
		cout << "(1) Add node" << endl;
		cout << "(2) Add Head node (first position)" << endl;
		cout << "(3) Add Node at certain position" << endl;
		cout << "(4) Delete Tail Node" << endl;
		cout << "(5) Delete" << endl;
		cout << "(6) Display linked list" << endl;
		//cout << "(7) Sort" << endl;
		cout << "(8) Search for element" << endl;
		cout << "(9) Exit\n" << endl;

		cin >> choice;

		//insertionSort() 

		switch (choice) {
		case 1:
			//add a noce function
			addNode();
			break;
		case 2:
			//add node to the first position
			insert_head_node();
			break;
		case 3:
			//call function to inser a node at certain element
			insert_at();
			break;
		case 4:
			//call function to delete last node(tail)
			delete_tail();
			break;
		case 5:
			//function to dete the head of the node ()
			delete_head();
			break;
		case 6:
			//call function
			displayList();
			break;
		case 7:
			//call function to do insertion sort
			//insertionSort();
			break;
		case 8:
			//call function to search
			search();
			break;
		
		}

	} while (choice != 9);



}

