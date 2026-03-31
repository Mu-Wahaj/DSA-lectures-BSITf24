#ifndef QUEUE_H
#define QUEUE_H

struct Node
{
    int data;
    Node* next;
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();

    bool isEmpty();
    void enqueue(int value);
    int dequeue();
    int getFront();
    void clear();
};

#endif