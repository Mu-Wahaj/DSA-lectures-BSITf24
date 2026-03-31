#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue();
    bool enqueue(int value);
    bool dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
    void reverse();
    Queue copy();
    void sortAscending();
    bool reverseFirstK(int k);
    void display();
    void mergequeues(Queue& q1, Queue& q2);
     void circularBehaviorDemo();
};

#endif