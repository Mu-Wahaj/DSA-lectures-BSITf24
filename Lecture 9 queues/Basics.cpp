
// Stack Operations
// Push
// Pop
// Peek (Front)
// Check empty
// Check full
// Clear
// Reverse an array using stack
// Check balanced parentheses
// Sort stack ascending
// Sort stack descending
// Find min element ofstack
// Queue Operations
// Enqueue
// Dequeue
// Peek (Front)
// Check empty
// Clear
// Reverse queue
// Copy queue
// Sort queue (ascending)
// Reverse first K elements
// Stack & Queue Interaction / Extra
// Reverse queue using stack
// Sort stack using extra stack
// Sort queue using array + bubble sort
#include <iostream>
using namespace std;

// ======================= STACK =======================
struct Stack {
    int *arr;
    int top;
    int maxSize;

    Stack(int size) {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int val) {
        if (isFull() == false) {
            top = top + 1;
            arr[top] = val;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    int pop() {
        if (isEmpty() == false) {
            int val = arr[top];
            top = top - 1;
            return val;
        } else {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

    int peek() {
        if (isEmpty() == false) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    void clear() {
        top = -1;
    }
};

// ======================= QUEUE =======================
struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        clear();
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            Node* temp = front;
            int val = temp->data;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }
            delete temp;
            return val;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return front->data;
        }
    }

    void clear() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
    }
};

// ======================= STACK LAB FUNCTIONS =======================

// 1. Reverse array using stack
void reverseArray(int arr[], int n) {
    Stack s(n);
    for (int i = 0; i < n; i = i + 1) {
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i = i + 1) {
        arr[i] = s.pop();
    }
}

// 2. Check balanced parentheses
bool checkParentheses(char expr[]) {
    Stack s(100);
    int i = 0;
    while (expr[i] != '\0') {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            s.push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '[')) {
                return false;
            }
        }
        i = i + 1;
    }
    return s.isEmpty();
}

// 3. Sort stack using extra stack (ascending)
void sortStack(Stack &s) {
    Stack tmp(s.maxSize);
    while (s.isEmpty() == false) {
        int val = s.pop();
        while (tmp.isEmpty() == false && tmp.peek() > val) {
            s.push(tmp.pop());
        }
        tmp.push(val);
    }
    while (tmp.isEmpty() == false) {
        s.push(tmp.pop());
    }
}

// 4. Find min element of stack
int minStack(Stack &s) {
    if (s.isEmpty()) return -1;
    Stack tmp(s.maxSize);
    int min = s.peek();
    while (s.isEmpty() == false) {
        int val = s.pop();
        if (val < min) min = val;
        tmp.push(val);
    }
    while (tmp.isEmpty() == false) s.push(tmp.pop());
    return min;
}

// ======================= QUEUE LAB FUNCTIONS =======================

// 5. Reverse queue using stack
void reverseQueue(Queue &q) {
    Stack s(100);
    while (q.isEmpty() == false) {
        s.push(q.dequeue());
    }
    while (s.isEmpty() == false) {
        q.enqueue(s.pop());
    }
}

// 6. Copy queue
Queue copyQueue(Queue &q) {
    Queue q2;
    Node* temp = q.front;
    while (temp != NULL) {
        q2.enqueue(temp->data);
        temp = temp->next;
    }
    return q2;
}

// 7. Sort queue using array
void sortQueue(Queue &q) {
    int arr[100];
    int n = 0;
    while (q.isEmpty() == false) {
        arr[n] = q.dequeue();
        n = n + 1;
    }
    // Simple Bubble sort
    for (int i = 0; i < n - 1; i = i + 1) {
        for (int j = 0; j < n - i - 1; j = j + 1) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i = i + 1) {
        q.enqueue(arr[i]);
    }
}

// ======================= STACK-QUEUE INTERACTION =======================

// 8. Reverse first k elements of queue
void reverseFirstK(Queue &q, int k) {
    Stack s(k);
    int n = 0;
    Queue q2;
    Node* temp = q.front;
    while (temp != NULL) {
        n = n + 1;
        temp = temp->next;
    }
    for (int i = 0; i < k; i = i + 1) {
        s.push(q.dequeue());
    }
    while (s.isEmpty() == false) q.enqueue(s.pop());
    for (int i = 0; i < n - k; i = i + 1) {
        q.enqueue(q.dequeue());
    }
}

// 9. Sort stack (descending)
void sortStackDesc(Stack &s) {
    Stack tmp(s.maxSize);
    while (s.isEmpty() == false) {
        int val = s.pop();
        while (tmp.isEmpty() == false && tmp.peek() < val) {
            s.push(tmp.pop());
        }
        tmp.push(val);
    }
    while (tmp.isEmpty() == false) {
        s.push(tmp.pop());
    }
}

// ======================= MAIN FUNCTION DEMO =======================
int main() {

    cout << "STACK OPERATIONS" << endl;
    Stack s1(10);
    s1.push(30);
    s1.push(10);
    s1.push(50);
    s1.push(20);
    cout << "Min of stack: " << minStack(s1) << endl;
    sortStack(s1);
    cout << "Stack after ascending sort: ";
    while (s1.isEmpty() == false) cout << s1.pop() << " ";
    cout << endl;

    char expr[] = "{(a+b)*(c-d)}";
    if (checkParentheses(expr)) cout << "Expression is balanced" << endl;
    else cout << "Expression is not balanced" << endl;

    cout << endl << "QUEUE OPERATIONS" << endl;
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(40);
    q1.enqueue(20);
    q1.enqueue(30);

    cout << "Queue front: " << q1.getFront() << endl;
    reverseQueue(q1);
    cout << "Queue after reverse: ";
    Queue qcopy = copyQueue(q1);
    while (qcopy.isEmpty() == false) cout << qcopy.dequeue() << " ";
    cout << endl;

    sortQueue(q1);
    cout << "Queue after sort ascending: ";
    while (q1.isEmpty() == false) cout << q1.dequeue() << " ";
    cout << endl;

    cout << endl << "Reverse first K elements of queue demo" << endl;
    Queue q2;
    for (int i = 1; i <= 6; i = i + 1) q2.enqueue(i);
    reverseFirstK(q2, 3);
    cout << "Queue after reversing first 3 elements: ";
    while (q2.isEmpty() == false) cout << q2.dequeue() << " ";
    cout << endl;

    return 0;
}