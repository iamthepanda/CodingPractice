#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include "LinkedList.h"

using namespace std;
//need constructor
LinkedList::LinkedList(): numberOfNodes(0) {
	this->root = new Node;
	this->root->next = NULL;

}


// LinkedList::Node LinkedList::createNode(){
// 	return new Node;
// 	// return NULL;
// }

void LinkedList::addNode(int newData){
	Node * newNode = new Node;// = new Node;
	newNode->data = newData;
	newNode->next = this->root;
	this->root = newNode;
	numberOfNodes++;
}

void LinkedList::insertNode(int data, int position){

}

void LinkedList::deleteNode(int position){
	Node * thisNode = this->root;
	Node * deleteNode = this->root;
	if (position > numberOfNodes - 1 || position < 0){
		cout << "node position is out of bounds" << endl;
		return;
	} else {
		for (int i = 0; i < position; i++){
			if (thisNode->next != NULL){
			thisNode = thisNode->next;

			}
		}

		if (thisNode->next->next !=NULL){
			deleteNode = thisNode->next;
			delete deleteNode;
			thisNode->next = thisNode->next->next;
			numberOfNodes--;

		}else {
			thisNode->next = NULL;
		}
	}
}

int LinkedList::getData(int position){
	Node * thisNode = this->root;
	if (position > numberOfNodes){
		cout << "node position is out of bounds" << endl;
		return 0;
	} else {
		for (int i = 0; i < position - 1; i++){
			thisNode = thisNode->next;
		}
	}

	return thisNode->data;
}

int LinkedList::getNumberOfNodes(){
	return numberOfNodes;
}

void LinkedList::printList(){
	Node * thisNode = this->root;

	//I don't know why this is not working
	do{
		cout << thisNode->data << " ";
		thisNode = thisNode->next;
	} while (thisNode->next != NULL);

	cout << endl << endl;
}

void LinkedList::deleteDuplicateNodes(){
	// Currently throwing a fat error/core dump.
	Node * currentNode = this->root;
	Node * traversalNode;
	int currentPosition = 0;
	int traversalPosition = 1;
	while (currentNode != NULL){
		//cout << "current position: " << currentPosition << endl;
		traversalNode = currentNode->next;
		traversalPosition = currentPosition + 1;
		while (traversalNode != NULL) {
			//cout << "traversal position: " << traversalPosition << endl;
			if (currentNode->data == traversalNode->data){
				deleteNode(traversalPosition - 1);
			} else{
				traversalPosition++;
			}
			traversalNode = traversalNode->next;
		}
		currentPosition++;
		traversalPosition = currentPosition;
		currentNode = currentNode->next;
		traversalNode = currentNode;

	}
}

#endif /* end of LinkedList */

int main(int argc, char const *argv[])
{
	/* code */
	int choice = 0;
	int myNum = 0;
	LinkedList myList;


	myList.addNode(9);
	myList.addNode(8);
	myList.addNode(8);
	myList.addNode(6);
	myList.addNode(5);
	myList.addNode(5);
	myList.addNode(9);
	myList.addNode(8);
	myList.addNode(8);
	myList.addNode(6);
	myList.addNode(5);
	myList.addNode(5);
	myList.addNode(3);
	myList.addNode(2);
	myList.addNode(1);
	while (choice != 6){
		cout << "Your current list is :" << endl;
			if (myList.getNumberOfNodes() == 0){
				cout << "empty" << endl;
			} else {
				myList.printList();
			}


		cout << "Please choose a linked list option (1-6): " << endl;
		cout << "1 - add a node" << endl;
		cout << "2 - delete a node" << endl;
		cout << "3 - insert a node" << endl;
		cout << "4 - print the list" << endl;
		cout << "5 - remove duplicates from list" << endl;
		cout << "6 - exit" << endl;
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Please enter a number to add" << endl;
				cin  >> myNum;
				myList.addNode(myNum);
				break;
			case 2:
				cout << "Please enter a node position to delete" << endl;
				cin >> myNum;
				myList.deleteNode(myNum);
				break;
			case 3:
				cout << "Insert node is not currently functional.\n" << endl;
				break;
			case 4:
				cout << "Your current list is :" << endl;
				myList.printList();
				break;
			case 5:
				cout << "Deleting duplicates..." << endl;
				myList.deleteDuplicateNodes();
				break;
			case 6:
				cout << "Program exiting. Come again." << endl;
				break;

			default:
				cout << "Please enter a valid choice" << endl;
				break;
		}
	}
	cout << "The number of nodes in the list is: " << myList.getNumberOfNodes() << endl;
	// cout << myList.getData(3);
	// myList.printList();
	// myList.deleteNode(2);
	// cout << myList.getData(3);
	// myList.printList();
	return 0;
}
