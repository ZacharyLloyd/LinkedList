#include <iostream>
#include "linkedlist.h"
#include "linkedlistfunc.h"

using namespace std;

/*Program to test Node, DLList and their functions*/
int main() {
	//Initiate an Integar Doubly Linked List
	DLList<double> myList = DLList<double>();

	//Logged value
	Node <double>* loggedData = nullptr;

	//Simple test for inserting the front of doubly linked list
	myList.InsertNode(27, nullptr, Placement::FRONT);

	myList.InsertNode(13, nullptr, Placement::FRONT);

	myList.InsertNode(38, nullptr, Placement::FRONT);

	//Now we insert at the end of doubly linked list
	myList.InsertNode(49, nullptr, Placement::END);

	//The node that 38 is defined, place a node before it
	myList.InsertNode(56, myList.FindNode(38), Placement::BEFORE);

	//The node that 56 is defined, place a node after it
	myList.InsertNode(93, myList.FindNode(56), Placement::AFTER);

	//Test what is in the list
	myList.DisplayList();

	cout << "Now we'll delete some values..." << endl << endl;

	//Delete from head
	myList.DeleteNode(&myList.head, myList.head);
	myList.DisplayList();

	myList.DeleteNode(&myList.head, myList.head);
	myList.DisplayList();

	myList.DeleteNode(&myList.head, myList.head);

	//Test what is in list
	myList.DisplayList();

	//Delete from 27
	Node<double>* refNode = myList.FindNode(27);
	myList.DeleteNode(&refNode, refNode);

	//Test what is in list
	myList.DisplayList();

	//Delete 49 from 13
	refNode = myList.FindNode(13);

	myList.DeleteNode(&refNode, refNode->nextPtr);

	//Test what is in the list
	myList.DisplayList();

	//Find value 13
	if (myList.FindNode(13) != nullptr) {
		cout << "Data found." << endl;
	}
	else {
		cout << "Data not found." << endl;
	}

	//Find value 77
	if (myList.FindNode(77) != nullptr) {
		cout << "Data found." << endl;
	}
	else {
		cout << "Data not found." << endl;
	}

	system("pause");

	//More robust test
	double inputInt;

	//Decide to insert using loggedData
	int insertChoice = -1;

	//Ask the use for placement info
	int placementInt = -1;

	//Ask the user if they want to use the logged data, or delete from the front or end of data
	int referenceChoice;

	//Now ask if to delete the value before or after it
	int deleteTarget;

	//Default placement
	Placement placement = Placement::FRONT;

	int choice = 99;

	do {
		cout << "\nMenu to Linked List:\n";
		cout << "1: To insert an integer on list\n";
		cout << "2: To find a specific node\n";
		cout << "3: To delete a node\n";
		cout << "4: To display list\n";
		cout << "99 Exit\n";
		cout << "Please enter your choice (#): ";

		//User input
		cin >> choice;

		switch (choice) {
		case 1:


			cout << "\nEnter an integer: ";

			cin >> inputInt;

			cout << "Insert using logged data?\n";
			cout << "1: Yes\n";
			cout << "2: No\n";

			//Check if user will insert with logged data
			cin >> insertChoice;
			switch (insertChoice) {
			case 1:
				cout << "Your logged data is currently: " << loggedData->data << endl;
				cout << "Would you like to: \n";
				cout << "1: Before\n";
				cout << "2: After\n";

				cin >> placementInt;

				placement = ((placementInt == 1) ? Placement::BEFORE : Placement::AFTER);

				myList.InsertNode(inputInt, loggedData, placement);

				break;
			case 2:
				cout << "Would you like to: \n";
				cout << "1: In front?\n";
				cout << "2: At end?\n";

				cin >> placementInt;

				placement = ((placementInt == 1) ? Placement::FRONT : Placement::END);

				myList.InsertNode(inputInt, nullptr, placement);
				break;
			}

			break;
		case 2:
			cout << "\nEnter the integer to be found: ";
			cin >> inputInt;
			{
				Node <double>* nPtr = myList.FindNode(inputInt);
				if (nPtr != nullptr) {
					cout << "Found data: " << nPtr->data << endl;
					cout << "Value " << nPtr->data << " has been logged for used..." << endl;

					loggedData = nPtr;
				}
				else
				{
					cout << "Data not found." << endl;
				}
			}
			break;
		case 3:


			cout << "Your logged data is currently: " << loggedData->data << endl;
			cout << "Would you like to use it as a reference point?: \n";
			cout << "1: Yes\n";
			cout << "2: No\n";

			//Ask for user input
			cin >> referenceChoice;

			//Check for user's choice
			switch (referenceChoice) {
			case 1:
				cout << "\nUsing logged data " << loggedData->data << " as reference data\n";
				break;
			case 2:
				//Change the loggedData to the head (default)
				//Check user input one last time
				loggedData = myList.head;
				cout << "Logged data has been modified to " << loggedData->data;
				break;
			}


			cout << "\nYour logged data is currently: " << loggedData->data << endl;
			cout << "Would you like to: \n";
			cout << "1: Before\n";
			cout << "2: After\n";

			//User Input
			cin >> deleteTarget;

			switch (deleteTarget) {
			case 1:
				try
				{
					//Delete the previous pointer
					myList.DeleteNode(&loggedData, loggedData->nextPtr);
				}
				catch (exception e) {
					cout << "Failed to delete node: \nReason: " << e.what();
				}
				break;
			case 2:
				try {
					//Delete the next pointer
					myList.DeleteNode(&loggedData, loggedData->previousPtr);
				}
				catch (exception e) {
					cout << "Failed to delete node: \nReason: " << e.what();
				}
				break;
			}
			cout << "Deletion was successful!!!" << endl;
			break;

		case 4:
			myList.DisplayList();
			break;
		}
	} while (choice != 99);

	cout << "ending Program ...\n";
	system("pause");
	return 0; //Program ended successfully
}