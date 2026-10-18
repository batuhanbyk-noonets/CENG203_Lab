#include "CircularList.h"
#include <iostream>
using namespace std;

CircularList::CircularList()
{
    head = nullptr;
}

CircularList::~CircularList()
{
    if (head == nullptr)
        return;
    // halkayi kir: head->next'ten baslayip head'e donene kadar sil
    Node* cur = head->next;
    while (cur != head) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

void CircularList::append(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {              // tek dugum kendini gosterir
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* last = head;                  // son dugum: next'i head olan
    while (last->next != head)
        last = last->next;

    newNode->next = head;
    last->next = newNode;
}

void CircularList::display() const
{
    if (head == nullptr) {
        cout << "(empty)" << endl;
        return;
    }
    Node* cur = head;
    do {
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);
    cout << "(back to " << head->data << ")" << endl;
}

int CircularList::length() const
{
    if (head == nullptr)
        return 0;
    int count = 0;
    Node* cur = head;
    do {
        count++;
        cur = cur->next;
    } while (cur != head);
    return count;
}
