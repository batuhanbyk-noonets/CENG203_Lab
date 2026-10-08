#pragma once
#include "Node.h" // same folder -> just the file name
class LinkedList
{
private:
Node* head; // first node (nullptr = empty list)
public:
LinkedList(); // constructor: creates an empty list
~LinkedList(); // destructor : deletes all nodes
void insertAtFront(int value); // prototypes only - NO bodies here
void display() const;
bool isEmpty() const;
};