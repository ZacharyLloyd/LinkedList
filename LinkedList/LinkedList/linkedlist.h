#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* definition of a node in linked list */
template <class T>
class Node {
public:
	T data; // data stored in this Node
	Node* nextPtr; // pointer to next Node
	Node* previousPtr;
	Node(T newData) {  // Constructor for Node
		data = newData;
		nextPtr = nullptr;
		previousPtr = nullptr;
		
	}

private:
};

/* definition of a forward (single) linked list */
template <class T>
class LList {
public:
	Node <T> * head;  // beginning of linked list
	int llSize;  // # of nodes in the list
	LList() {   // Constructor for LList
		head = nullptr;
		llSize = 0;
	}
	   
	Node <T> * findNode(T dataToFind); // returns a pointer to the node whose key matches dataToFind
	void insertNode(T newData);  // inserts a new node at the start of the list with a key equal to newData
	void insertNodeEnd(T newData); // inserts a new node at the end of the list

	void displayList();  // display all nodes in the list
private:
};

#endif // LINKED_LIST_H
