#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int topIndex;

public:
    Stack();
    bool push(int value);
    bool pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
    void reverseArray(int arr[], int size);
    bool checkBalancedParentheses(const char expr[]);
    void sortAscending();
    void sortDescending();
    int findMin();
    void sortUsingExtraStack();
    void mergeSort(int arr[], int left, int right);
    void display();
};

#endif