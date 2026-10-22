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
// =============================== Week 3 ===============================
// Fill in these bodies question by question. The stubs compile and link,
// so the whole project builds from the start.
void LinkedList::insertAtEnd(int value) // Q2
{
 Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // Eğer liste boşsa, yeni düğüm doğrudan head olur
    if (isEmpty()) {
        head = newNode;
        return;
        }

    // Liste boş değilse, son düğüme kadar git
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode;
}
int LinkedList::length() const 
{
    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        count++;
    }
    return count;
}
void LinkedList::createFromArray(const int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        insertAtEnd(arr[i]);
    }
}
int LinkedList::search(int value) const // Q3
{
    int index = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data == value)
            return index;
        index++;
    }
    return -1;                              // bulunamadi
}
int LinkedList::update(int oldValue, int newValue) // Q4
{
    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data == oldValue) {        // break yok: hepsini degistir
            cur->data = newValue;
            count++;
        }
    }
    return count;
}
bool LinkedList::insertAt(int index, int value) // Q5
{
    if (index < 0 || index > length())
        return false;

    if (index == 0) {                       // yeni ilk dugum
        insertAtFront(value);
        return true;
    }

    // index-1. dugume (oncekine) git
    Node* prev = head;
    for (int i = 0; i < index - 1; i++)
        prev = prev->next;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = prev->next;             // once yeni dugumu bagla
    prev->next = newNode;                   // sonra oncekini yeni dugume yonlendir
    return true;
}
bool LinkedList::deleteValue(int value) // Q6
{
    if (isEmpty())
        return false;

    if (head->data == value) {              // head siliniyor
        Node* victim = head;
        head = head->next;
        delete victim;
        return true;
    }

    Node* prev = head;
    while (prev->next != nullptr && prev->next->data != value)
        prev = prev->next;

    if (prev->next == nullptr)              // bulunamadi
        return false;

    Node* victim = prev->next;
    prev->next = victim->next;              // atla
    delete victim;                          // bellegi geri ver
    return true;
}
void LinkedList::merge(LinkedList& other) // Q7
{
    if (this == &other || other.head == nullptr)
        return;

    if (head == nullptr) {
        head = other.head;
    } else {
        Node* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = other.head;             // dugumleri tasi, kopyalama
    }
    other.head = nullptr;                   // artik dugumler bu listenin
}
// =============================== Week 5 ===============================
void LinkedList::displayBackward() const
{
    printBackward(head);
    cout << endl;
}

void LinkedList::printBackward(const Node* node)
{
    if (node == nullptr)
        return;
    printBackward(node->next);
    cout << node->data << " ";
}

void LinkedList::reverse()
{
    head = reverseFrom(head);
}

Node* LinkedList::reverseFrom(Node* node)
{
    if (node == nullptr || node->next == nullptr)
        return node;
    Node* newHead = reverseFrom(node->next);
    node->next->next = node;
    node->next = nullptr;
    return newHead;
}
