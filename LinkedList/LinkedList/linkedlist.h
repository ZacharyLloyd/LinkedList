#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

enum Placement {
	FRONT,
	END,
	BEFORE,
	AFTER
};

/*Definition of a node in doubly linked list*/
template <class T>
class Node {
public:
	//Data stored in this node
	//It can be of any type.
	T data;

	//The pointer to the next node
	Node* nextPtr;

	//And the pointer to the previous node
	Node* previousPtr;

	//Create Node Constructor
	Node(T newData) {
		data = newData;
		nextPtr = nullptr;
	}

private:
	//Nothing to be private
};

/*Definition of a doubly linked list*/
template <class T>
class DLList {
public:
	//Beginning of linked list
	Node<T>* head;

	//The number of nodes in our list
	int dllSize;



	//Doubly Linked List Constructor
	DLList() {
		head = nullptr;
		dllSize = 0;
	}

	//Finds the node of a specified type
	Node<T>* FindNode(T dataToFind);

	//Inserts a node with a specified type
	//and also with a specified position
	void InsertNode(T newData, Node<T>* relativeData = nullptr, Placement nodePlacement = Placement::FRONT);

	//Delete: Added after base program works
	void DeleteNode(Node<T>** relativeData, Node<T>* targetData);

	//Display all node in our list
	void DisplayList();

private:

};

#endif // LINK