#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    clear();
}

bool Queue::isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        Node* temp = front;
        int value = temp->data;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
        return value;
    }
}

int Queue::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        return front->data;
    }
}

void Queue::clear()
{
    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;
}