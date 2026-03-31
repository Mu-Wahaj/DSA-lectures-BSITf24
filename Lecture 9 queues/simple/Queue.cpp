#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

bool Queue::enqueue(int value)
{
    if (isFull())
    {
        return false;
    }
    rearIndex = (rearIndex + 1) % MAX_SIZE;
    arr[rearIndex] = value;
    count++;
    return true;
}

bool Queue::dequeue()
{
    if (isEmpty())
    {
        return false;
    }
    frontIndex = (frontIndex + 1) % MAX_SIZE;
    count--;
    return true;
}

int Queue::peek()
{
    if (isEmpty())
    {
        return -1;
    }
    return arr[frontIndex];
}

bool Queue::isEmpty()
{
    return count == 0;
}

bool Queue::isFull()
{
    return count == MAX_SIZE;
}

void Queue::clear()
{
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

void Queue::reverse()
{
    if (isEmpty())
        return;

    int temp[MAX_SIZE];
    int index = 0;

    while (!isEmpty())
    {
        temp[index++] = peek();
        dequeue();
    }

    for (int i = index - 1; i >= 0; i--)
    {
        enqueue(temp[i]);
    }
}

Queue Queue::copy()
{
    Queue newQueue;
    for (int i = 0; i < count; i++)
    {
        int pos = (frontIndex + i) % MAX_SIZE;
        newQueue.enqueue(arr[pos]);
    }
    return newQueue;
}

void Queue::sortAscending()
{
    if (isEmpty())
        return;

    int temp[MAX_SIZE];
    int tempCount = count;
    int index = 0;

    while (!isEmpty())
    {
        temp[index++] = peek();
        dequeue();
    }

    for (int i = 0; i < tempCount - 1; i++)
    {
        for (int j = 0; j < tempCount - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < tempCount; i++)
    {
        enqueue(temp[i]);
    }
}

bool Queue::reverseFirstK(int k)
{
    if (k > count || k <= 0)
    {
        return false;
    }

    int temp[MAX_SIZE];
    for (int i = 0; i < k; i++)
    {
        temp[i] = peek();
        dequeue();
    }

    for (int i = k - 1; i >= 0; i--)
    {
        enqueue(temp[i]);
    }

    int remaining = count - k;
    for (int i = 0; i < remaining; i++)
    {
        enqueue(peek());
        dequeue();
    }

    return true;
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements (front to rear): ";
    for (int i = 0; i < count; i++)
    {
        int pos = (frontIndex + i) % MAX_SIZE;
        cout << arr[pos] << " ";
    }
    cout << endl;
}
void Queue::mergequeues(Queue &q1, Queue &q2)
{
    clear();
    for (int i = 0; i < q1.count; i++)
    {
        int pos = (q1.frontIndex + i) % MAX_SIZE;
        enqueue(q1.arr[pos]);
    }
    for (int i = 0; i < q2.count; i++)
    {
        int pos = (q2.frontIndex + i) % MAX_SIZE;
        enqueue(q2.arr[pos]);
    }
}
void Queue::circularBehaviorDemo()
{
    cout << "Demonstrating circular behavior of the queue:" << endl;
    for (int i = 1; i <= 5; i++)
    {
        enqueue(i * 10);
        cout << "Enqueued: " << i * 10 << endl;
    }
    display();

    cout << "Dequeuing 3 elements" << endl;
    dequeue();
    dequeue();
    dequeue();
    display();

    cout << "Enqueuing 4 more elements: 60, 70, 80, 90" << endl;
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    display();
}