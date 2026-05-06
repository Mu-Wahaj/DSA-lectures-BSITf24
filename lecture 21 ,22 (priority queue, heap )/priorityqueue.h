#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

class PriorityQueue
{
private:
    int* arr;
    int capacity;
    int size;

    void heapify(int i);

public:
    PriorityQueue(int cap);
    ~PriorityQueue();

    void enqueue(int val);   // insert
    int dequeue();           // remove highest priority
    int peek() const;
    bool isEmpty() const;
    void display() const;
};

#endif