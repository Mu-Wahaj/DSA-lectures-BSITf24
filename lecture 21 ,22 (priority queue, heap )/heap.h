#ifndef HEAP_H
#define HEAP_H

class MaxHeap
{
private:
    int* arr;
    int capacity;
    int size;

    void heapify(int i);

public:
    MaxHeap(int cap);
    ~MaxHeap();

    void insert(int val);
    int extractMax();
    int getMax() const;
    void buildHeap();
    void display() const;
};

#endif