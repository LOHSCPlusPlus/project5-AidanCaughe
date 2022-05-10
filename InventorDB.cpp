#include "InventorDB.h"
#include "ReadUtils.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
Set head and tail to nullptr
*/
InventorDB::InventorDB(){
  head = nullptr;
  tail = nullptr;
}

InventorDB::~InventorDB() {
    deleteAllNodes();
}

// Delete all the current nodes and set head & tail to nullptr
void InventorDB::deleteAllNodes() {
  while(head != nullptr) {
	Node *next = head->next;
	delete head;
	head = next;
}
tail = nullptr;
head = nullptr;
}

// Append a new entry at the tail of the list
void InventorDB::append(Inventor inventor) {
Node *nodePtr = new Node(inventor);
if (tail == nullptr) {
    head = nodePtr;
}
else {
	tail->next = nodePtr;
}
tail = nodePtr;

}

// Traverse the list printing all the data in the nodes
void InventorDB::print() {
  Node *curr = head;
while(curr != nullptr) {
    curr->data.print();
	curr = curr->next;
}
}

// Insert a new entry at the head of the list
void InventorDB::insertInFront(Inventor inventor){
Node *nodePtr = new Node(inventor);
  if (head == nullptr) {
    tail = nodePtr;
}
else {
	nodePtr->next = head;
}
head = nodePtr;
}

// If there is an entry at the head of the list, remove it.
void InventorDB::removeFront() {
  if (head != nullptr) {
	Node *next = head->next;
	delete head;
	head = next;
}
if (head == nullptr) {
tail = nullptr;
}

}


// Traverse the list and if a call to isAlive on the data
// in the node returns true, print that data.
void InventorDB::printAlive() {
  Node *curr = head;
while(curr != nullptr) {
    if(curr->data.isAlive()==true){
     curr->data.print(); 
    }
	curr = curr->next;
}

}



/**
Print a menu with the things the user is allowed to do with this database.
If we add new functions, we'll expand this function so that the user is presented
with new options.
*/
void InventorDB::dbMenu(){
    // This will let us use meaningful names in the switch.
    enum MenuOptions{
        RELOAD = 1, // enum will automatically add 1 to the values that follow
        INSERT,
        APPEND,
        REMOVE,
        PRINT,
        PRINT_ALIVE,
        DELETE_ALL,
        QUIT,
    };
    // cstrings we will print as menu options.
    const char *options[] = {
        "Reload DB From File",
        "Insert a new entry at front",
        "Add a new entry to the end",
        "Remove an entry from front",
        "Print all",
        "Print living inventors",
        "Delete all entries",
        "Quit"
    };

    // Spin here until the user enters the QUIT value.
    int option = -1;
    Inventor temp;
    while(option != QUIT) {
        // Print the menu options (we use index - 1) because 
        // the first option is 1, but the first entry in the array
        // is at index 0.
        for (int index = RELOAD; index <= QUIT; index++) {
            cout << index << ") " << options[index - 1] << endl;
        }
        option = readInt("Enter your selection: ");
        switch(option) {
            case RELOAD:
                reload();
                break;
            case INSERT:
                temp.readFromUser(); 
                insertInFront(temp);
                break;
            case APPEND:
                temp.readFromUser(); 
                append(temp);
                break;
            case REMOVE:
                removeFront();
                break;
            case PRINT:
                print();
                break;
            case PRINT_ALIVE:
                printAlive();
                break;
            case DELETE_ALL:
                deleteAllNodes();
                break;
            case QUIT:
                break;
            default:
                cout << "Invalid selection!" << endl;
                break;
        }
    }
    
}

void InventorDB::reload(){
    deleteAllNodes();
    readFile("AfricanAmericanInventors.txt");
}

/**
Loads individual inventors, then calls append
Used in the reload function.
*/
void InventorDB::readFile(const char fileName[]) {
    ifstream file(fileName);
    while(file.peek() != EOF) {
        Inventor temp;
        temp.readFromFile(file);
        if (file.peek() != EOF) {
            append(temp);
        }
    }
    if (head == nullptr) {
        cout << "There is no inventor data in " << fileName << " did you spell it correctly?" << endl;
    }
}
