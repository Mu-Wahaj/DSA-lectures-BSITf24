#include <iostream>
#include "heap.h"
using namespace std;

MaxHeap::MaxHeap(int cap)
{
    capacity = cap;
    size = 0;
    arr = new int[cap];
}

MaxHeap::~MaxHeap()
{
    delete[] arr;
}

void MaxHeap::heapify(int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

void MaxHeap::insert(int val)
{
    if (size == capacity)
        return;

    int i = size++;
    arr[i] = val;

    while (i != 0 && arr[(i-1)/2] < arr[i])
    {
        swap(arr[i], arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int MaxHeap::extractMax()
{
    if (size <= 0)
        return -1;

    int root = arr[0];
    arr[0] = arr[size-1];
    size--;

    heapify(0);
    return root;
}

int MaxHeap::getMax() const
{
    if (size > 0)
        return arr[0];
    return -1;
}

void MaxHeap::buildHeap()
{
    for (int i = size/2 - 1; i >= 0; i--)
        heapify(i);
}

void MaxHeap::display() const
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}