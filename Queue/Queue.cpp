#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    front = rear = nullptr;
    count = 0;
}

Queue::~Queue()
{
    int dummy;
    while (dequeue(dummy)) {}
}

void Queue::enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (rear == nullptr)            // bos kuyruk
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
    count++;
}

bool Queue::dequeue(int& value)
{
    if (isEmpty())
        return false;               // underflow
    Node* temp = front;
    value = temp->data;
    front = front->next;
    if (front == nullptr)           // kuyruk bosaldi
        rear = nullptr;
    delete temp;
    count--;
    return true;
}

bool Queue::peek(int& value) const
{
    if (isEmpty())
        return false;
    value = front->data;
    return true;
}

bool Queue::isEmpty() const
{
    return front == nullptr;
}

int Queue::size() const
{
    return count;
}

void Queue::display() const
{
    cout << "front ->";
    for (Node* cur = front; cur != nullptr; cur = cur->next)
        cout << " " << cur->data;
    if (isEmpty())
        cout << " (empty)";
    cout << " <- rear" << endl;
}
