#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

class Stack
{
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
    void bubbleSort(int arr[], int size);
    void insertionSort(int arr[], int size);
    void selectionSort(int arr[], int size);
    // next greater element in stack
    void nextGreaterElement(int arr[], int size);
    // next smaller element in stack
    void nextSmallerElement(int arr[], int size);
    // sort stack using recursion
    void sortStackUsingRecursion();
    // reverse stack using recursion
    void reverseStackUsingRecursion();
    // sort stack using merge sort
    void sortStackUsingMergeSort();
    // sort stack using bubble sort
    void sortStackUsingBubbleSort();
    // sort stack using insertion sort
    void sortStackUsingInsertionSort();
    // sort stack using selection sort
    void sortStackUsingSelectionSort();
    // sort stack using quick sort
    void sortStackUsingQuickSort();
    // is stack sorted in ascending order
    bool isSortedAscending();
    // is stack sorted in descending order
    bool isSortedDescending();
    // ispalindrome stack
    bool isPalindrome();

    void display();
};

#endif