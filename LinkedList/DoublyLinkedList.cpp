#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head != nullptr) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void DoublyLinkedList::insertAtFront(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head == nullptr)                // bos liste: hem head hem tail
        tail = newNode;
    else
        head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail == nullptr)                // bos liste
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
}

void DoublyLinkedList::displayForward() const
{
    cout << "Forward:  ";
    for (DNode* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

void DoublyLinkedList::displayBackward() const
{
    cout << "Backward: ";
    for (DNode* cur = tail; cur != nullptr; cur = cur->prev)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

bool DoublyLinkedList::deleteValue(int value)
{
    DNode* victim = head;
    while (victim != nullptr && victim->data != value)
        victim = victim->next;

    if (victim == nullptr)              // bulunamadi
        return false;

    if (victim->prev != nullptr)
        victim->prev->next = victim->next;
    else
        head = victim->next;            // head siliniyor

    if (victim->next != nullptr)
        victim->next->prev = victim->prev;
    else
        tail = victim->prev;            // tail siliniyor

    delete victim;
    return true;
}
