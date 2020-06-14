#include <iostream>
#include "linkedlist.h" // include definition of Node and LLIst
#include "linkedlistfunc.h" // include functions definition of Node and LLIst
using namespace std;

/* Program to test Node, LList and their functions */
int main() {
	// Initiate an Integer Linked List
	LList<double> myList = LList<double> ();

	// Simple test
	myList.insertNode(11);
	myList.insertNode(22);
	myList.insertNode(33);
	myList.displayList();
	if (myList.findNode(22) != nullptr)
		cout << "Data found." << endl;
	else
		cout << "Data not found." << endl;
	if (myList.findNode(77) != nullptr)
		cout << "Data found." << endl;
	else
		cout << "Data not found." << endl;

	system("pause");

	// More robust test
	double inputInt;
	int choice = 99;
	do {
		cout << "\nMenu to Linked List:\n";
		cout << "1: To insert an integer on list\n";
		cout << "2: To find a specific node\n";
		cout << "3: To display list\n";
		cout << "4: To insert an integer at the end of the list\n";
		cout << "99: Exit\n";
		cout << "Please enter your choice (#): ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nEnter an integer: ";
			cin >> inputInt;
			myList.insertNode(inputInt);
			break;
		case 2:
			cout << "\nEnter the integer to be found: ";
			cin >> inputInt;
			{
				Node <double> * nPtr = myList.findNode(inputInt);
				if (nPtr != nullptr)
					cout << "Found data: " << nPtr->data << endl;
				else
					cout << "Data not found." << endl;
			}
			break;
		case 3:
			myList.displayList();
			break;
		case 4:
			cout << "\nEnter an integer: ";
			cin >> inputInt;
			myList.insertNodeEnd(inputInt);
		}
	} while (choice != 99);

	cout << "Ending Program ...\n";
	system("pause");
	return 0;
}