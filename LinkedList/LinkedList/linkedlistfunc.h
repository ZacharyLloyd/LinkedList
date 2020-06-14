#pragma once
#ifndef DOUBLY_LINKED_LIST_FUNC_H
#define DOUBLY_LINKED_LIST_FUNC_H

//Include definition of Node and DLList
#include <iostream>
#include "linkedlist.h"

using namespace std;

//Returns a pointer to the node whose key matches datatoFind
template<class T>
Node <T>* DLList<T>::FindNode(T dataToFind) {
	//Start from the head when finding our node
	Node<T>* nPtr = head;

	//While the pointer is not null, and we don't find the
	//type we are looking for, we head for the next node,
	//and read that information.
	while (nPtr != nullptr && nPtr->data != dataToFind) {
		nPtr = nPtr->nextPtr;
	}

	//Data != dataToFind should be false,
	//meaning that we found what we were looking for.
	return nPtr;
}


//Inserts a new node at a specified placement
template <class T>
void DLList<T>::InsertNode(T newData, Node<T>* relativeNode, Placement nodePlacement) {
	//Create a new node
	Node<T>* nPtr = new Node <T>(newData);
	Node<T>* lPtr = nullptr;

	//Use a switch case
	switch (nodePlacement)
	{
#pragma region Insert At Front
	case FRONT:
		//This node is now our new head
		nPtr->previousPtr = nullptr;
		nPtr->nextPtr = head;

		//If the head is present, previous wil lbe the new node
		if (head != nullptr) {
			head->previousPtr = nPtr;
		}

		head = nPtr;
		break;
#pragma endregion

#pragma region Insert At End
	case END:
		lPtr = head;

		//Set data for new node
		nPtr->data = newData;

		//Ne wnode is the last node, so set next of new node to null
		nPtr->nextPtr = nullptr;

		//Check if list is empty, if yes make new node the head of list
		if (head == nullptr)
		{
			nPtr->previousPtr = nullptr;
			head = nPtr;
			return;
		}

		//Otherwise tranverse the list to go to last node
		while (lPtr->nextPtr != nullptr)
			lPtr = lPtr->nextPtr;

		//Set next of last to new node
		lPtr->nextPtr = nPtr;

		//Set last to prev of new node
		nPtr->previousPtr = lPtr;

		break;
#pragma endregion

#pragma region Insert After
	case AFTER:
		//check if the next node is null
		if (relativeNode == nullptr) {
			cout << "Next Node is null." << endl;
			return;
		}

		//New node is alread allocated

		//Put in data
		nPtr->data = newData;

		//Make prev of new node as prev of next node
		nPtr->previousPtr = relativeNode->previousPtr;

		//Make the prev of next node as new node
		relativeNode->previousPtr = nPtr;

		//make new node as next of new node
		nPtr->nextPtr = relativeNode;

		//Change next of new nodes previous node
		if (nPtr->previousPtr != nullptr) {
			nPtr->previousPtr->nextPtr = nPtr;
		}
		else
		{
			head = nPtr;
		}


		break;
#pragma endregion

#pragma region Insert Before
	case BEFORE:
		//check if the previous node is null
		if (relativeNode == nullptr) {
			cout << "Previous Node is NULL...";
			return;
		}

		//Memory has already been allocated

		//Set next of new node to next of previous node
		nPtr->nextPtr = relativeNode->nextPtr;

		//set next of previosu node ot new node
		relativeNode->nextPtr = nPtr;

		//now set prev of new node to prev nod
		nPtr->previousPtr = relativeNode;

		//set prev of new node's next to newnode
		if (nPtr->nextPtr != nullptr) {
			nPtr->nextPtr->previousPtr = nPtr;
		}
		break;
#pragma endregion

	default:
		break;
	}

	//Increase the size
	dllSize++;
}

//Deletes a node
template <class T>
void DLList<T>::DeleteNode(Node<T>** relativeData, Node<T>* targetData) {
	//Base case
	if (*relativeData == nullptr || targetData == nullptr) {
		cout << ((*relativeData == nullptr) ? "Reference data is null" : "Target data is null") << endl;
		return;
	}

	//If node to be deleted is head node
	if (*relativeData == targetData)
		* relativeData = targetData->nextPtr;

	//Change next only if node to be 
	//deleted is NOT the last node
	if (targetData->nextPtr != nullptr)
		targetData->nextPtr->previousPtr = targetData->previousPtr;

	//Change prev only if node to be
	//deleted is NOT the first node
	if (targetData->previousPtr != nullptr)
		targetData->previousPtr->nextPtr = targetData->nextPtr;

	//Finally, fee the memory occupied by delete
	free(targetData);

	//Decrease the size
	dllSize--;

	return;
}

//dispaly all nodes in the list
template <class T>
void DLList<T>::DisplayList() {

	//The new nodes
	Node<T>* nPtr;

	//The last node
	Node<T>* lPtr;

	//If the head exists!
	if (head != nullptr) {
		cout << "\n# of nodes in the list = " << dllSize << endl;
		cout << "Data on the list: " << endl;
		nPtr = head;
		while (nPtr != nullptr) {
			cout << nPtr->data << "<==>";

			lPtr = nPtr;

			nPtr = nPtr->nextPtr;
		}
		cout << endl;
	}

	//Otherwise, there is no head, thus the list is empty
	else {
		cout << "List is empty" << endl << endl;
	}
}

#endif //DOUBLY_LIST_FUNC_H