#include <iostream>
#include "heap.h"
#include "priorityqueue.h"
using namespace std;

int main()
{
    cout << "----- Max Heap -----" << endl;

    MaxHeap h(10);

    h.insert(40);
    h.insert(20);
    h.insert(50);
    h.insert(10);

    h.display();

    cout << "Max: " << h.getMax() << endl;
    cout << "Extract Max: " << h.extractMax() << endl;

    h.display();

    cout << endl;

    cout << "----- Priority Queue -----" << endl;

    PriorityQueue pq(10);

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(50);
    pq.enqueue(20);

    pq.display();

    cout << "Peek: " << pq.peek() << endl;
    cout << "Dequeue: " << pq.dequeue() << endl;

    pq.display();

    return 0;
}