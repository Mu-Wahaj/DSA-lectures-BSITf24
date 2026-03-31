#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== QUEUE DATA STRUCTURE DEMONSTRATION =====" << endl;
    cout << endl;
    
    Queue q;
    
    cout << "1. BASIC OPERATIONS" << endl;
    
    cout << "Enqueuing elements: 10, 20, 30, 40, 50" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    
    cout << "Peek front element: " << q.peek() << endl;
    
    cout << "Dequeue element" << endl;
    q.dequeue();
    q.display();
    
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    cout << endl;
    
    cout << "2. REVERSE OPERATION" << endl;
    cout << "--------------------" << endl;
    cout << "Before reverse: ";
    q.display();
    q.reverse();
    cout << "After reverse: ";
    q.display();
    cout << endl;
    
    cout << "3. SORT OPERATION" << endl;
    cout << "-----------------" << endl;
    cout << "Before sorting: ";
    q.display();
    q.sortAscending();
    cout << "After sorting (ascending): ";
    q.display();
    cout << endl;
    
    cout << "4. COPY OPERATION" << endl;
    cout << "-----------------" << endl;
    cout << "Original queue: ";
    q.display();
    Queue qCopy = q.copy();
    cout << "Copied queue: ";
    qCopy.display();
    
    cout << "Modifying original (enqueue 99)" << endl;
    q.enqueue(99);
    cout << "Original: ";
    q.display();
    cout << "Copy (unchanged): ";
    qCopy.display();
    cout << endl;
    
    cout << "5. REVERSE FIRST K ELEMENTS" << endl;
    cout << "---------------------------" << endl;
    Queue q2;
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);
    q2.enqueue(7);
    q2.enqueue(8);
    q2.enqueue(9);
    q2.enqueue(10);
    
    cout << "Original queue: ";
    q2.display();
    
    q2.reverseFirstK(4);
    cout << "After reversing first 4 elements: ";
    q2.display();
    
    q2.reverseFirstK(6);
    cout << "After reversing first 6 elements: ";
    q2.display();
    cout << endl;
    
    cout << "6. CLEAR OPERATION" << endl;
    cout << "-----------------" << endl;
    cout << "Before clear: ";
    q.display();
    q.clear();
    cout << "After clear: ";
    q.display();
    cout << endl;
    
    cout << "7. CIRCULAR BEHAVIOR DEMONSTRATION" << endl;
    cout << "----------------------------------" << endl;
    Queue q3;
    cout << "Enqueuing 5 elements: ";
    for (int i = 1; i <= 5; i++) {
        q3.enqueue(i * 10);
        cout << i * 10 << " ";
    }
    cout << endl;
    q3.display();
    
    cout << "Dequeuing 3 elements" << endl;
    q3.dequeue();
    q3.dequeue();
    q3.dequeue();
    q3.display();
    
    cout << "Enqueuing 4 more elements: 60, 70, 80, 90" << endl;
    q3.enqueue(60);
    q3.enqueue(70);
    q3.enqueue(80);
    q3.enqueue(90);
    q3.display();
    cout << "Notice front and rear wrap around - circular behavior" << endl;
    cout << endl;
    
    cout << "8. EDGE CASES" << endl;
    cout << "------------" << endl;
    Queue q4;
    cout << "Dequeuing from empty queue: " << (q4.dequeue() ? "Success" : "Failed") << endl;
    cout << "Peeking from empty queue: " << q4.peek() << endl;
    
    cout << "Filling queue to capacity" << endl;
    for (int i = 1; i <= MAX_SIZE + 5; i++) {
        if (!q4.enqueue(i)) {
            cout << "Queue full at element " << i << endl;
            break;
        }
    }
    
    cout << endl;
    cout << "===== QUEUE DEMONSTRATION COMPLETE =====" << endl;
    
    return 0;
}