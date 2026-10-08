#include "LinkedList.h" // 1) your own header first
#include <iostream> // 2) then what THIS file needs
using namespace std;
LinkedList::LinkedList() // LinkedList:: = member of LinkedList
{
head = nullptr;
}
LinkedList::~LinkedList()
{
while (head != nullptr) { // delete the nodes one by one
Node* temp = head;
head = head->next;
delete temp;
}
}
void LinkedList::insertAtFront(int value)
{
Node* newNode = new Node;
newNode->data = value;
newNode->next = head;
head = newNode;
}
void LinkedList::display() const
{
for (Node* cur = head; cur != nullptr; cur = cur->next)
cout << cur->data << " -> ";
cout << "NULL" << endl;
}
bool LinkedList::isEmpty() const
{
return head == nullptr;
}