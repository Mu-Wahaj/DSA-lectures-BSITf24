#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;

    cout << "Removed element: " << q.dequeue() << endl;

    cout << "Front element after dequeue: " << q.getFront() << endl;

    q.enqueue(40);
    q.enqueue(50);

    cout << "Removed element: " << q.dequeue() << endl;
    cout << "Removed element: " << q.dequeue() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    q.clear();

    if (q.isEmpty())
    {
        cout << "Queue cleared successfully" << endl;
    }

    return 0;
}