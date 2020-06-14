#ifndef LINKED_LIST_FUNC_H
#define LINKED_LIST_FUNC_H

#include <iostream>
#include "linkedlist.h"  // include definition of Node and LLIst

// returns a pointer to the node whose key matches dataToFind.
template <class T>
Node <T> * LList<T>::findNode(T dataToFind) {
	Node <T> * nPtr = head;
	while (nPtr != nullptr  &&  nPtr->data != dataToFind)
		nPtr = nPtr->nextPtr;
	return nPtr;
}

// inserts a new node at the start of the list with a key equal to newData.
template <class T>
void LList<T>::insertNode(T newData) {
	Node <T> * nPtr = new Node <T> (newData);
	nPtr->nextPtr = head;
	head = nPtr;
	llSize++;
}

// inserts a new node at the end of the list
template <class T>
void LList<T>::insertNodeEnd(T newdata) 
{
	Node <T>* lPtr = head;
	//Set data for new node
	nPtr->data = newdata;
	//New node is  the last node, so set next of new nude to null
	nPtr->nextPtr = nullptr;
	//Check if list is empty, if yes make new node the head of list
	if (head == nullptr) {
		nPtr->previousPtr = nullptr;
		head = nPtr;
	}
	else {
		//Otherwise tranverse the list to go to last node
		while (lPtr->nextPtr != null) {
			lPtr = lPtr->nextPtr;
			//Set next of last to new node
			lPtr->nextPtr = nPtr;
			//Set last to previous of new node
			nPtr->previousPtr = lPtr;
			return;
		}
	}
}

// display all nodes in the list
template <class T>
void LList<T>::displayList() {
	Node <T> * nPtr;
	if (head != nullptr) {
		std::cout << "\n# of nodes in the list = " << llSize << std::endl;
		std::cout << "Data on the list: " << std::endl;
		nPtr = head;
		while (nPtr != nullptr) {
			std::cout << nPtr->data << ' ';
			nPtr = nPtr->nextPtr;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "List is empty" << std::endl << std::endl;
	}
}

#endif // LINKED_LIST_FUNC_H