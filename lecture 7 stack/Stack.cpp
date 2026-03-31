#include "Stack.h"
#include <iostream>
#include <cstring>
using namespace std;

Stack::Stack() {
    topIndex = -1;
}

bool Stack::push(int value) {
    if (isFull()) {
        return false;
    }
    arr[++topIndex] = value;
    return true;
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }
    topIndex--;
    return true;
}

int Stack::peek() {
    if (isEmpty()) {
        return -1;
    }
    return arr[topIndex];
}

bool Stack::isEmpty() {
    return topIndex == -1;
}

bool Stack::isFull() {
    return topIndex == MAX_SIZE - 1;
}

void Stack::clear() {
    topIndex = -1;
}

void Stack::reverseArray(int arr[], int size) {
    Stack s;
    for (int i = 0; i < size; i++) {
        s.push(arr[i]);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = s.peek();
        s.pop();
    }
}

bool Stack::checkBalancedParentheses(const char expr[]) {
    Stack s;
    int len = strlen(expr);
    
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            s.push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (s.isEmpty()) {
                return false;
            }
            char top = s.peek();
            s.pop();
            
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

void Stack::sortAscending() {
    if (isEmpty()) return;
    
    int temp[MAX_SIZE];
    int tempIndex = -1;
    
    while (!isEmpty()) {
        int current = peek();
        pop();
        
        while (tempIndex >= 0 && temp[tempIndex] > current) {
            push(temp[tempIndex]);
            tempIndex--;
        }
        temp[++tempIndex] = current;
    }
    
    while (tempIndex >= 0) {
        push(temp[tempIndex]);
        tempIndex--;
    }
}

void Stack::sortDescending() {
    if (isEmpty()) return;
    
    int temp[MAX_SIZE];
    int tempIndex = -1;
    
    while (!isEmpty()) {
        int current = peek();
        pop();
        
        while (tempIndex >= 0 && temp[tempIndex] < current) {
            push(temp[tempIndex]);
            tempIndex--;
        }
        temp[++tempIndex] = current;
    }
    
    while (tempIndex >= 0) {
        push(temp[tempIndex]);
        tempIndex--;
    }
}

int Stack::findMin() {
    if (isEmpty()) {
        return -1;
    }
    
    int min = arr[0];
    for (int i = 1; i <= topIndex; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void Stack::sortUsingExtraStack() {
    Stack extraStack;
    
    while (!isEmpty()) {
        int temp = peek();
        pop();
        
        while (!extraStack.isEmpty() && extraStack.peek() > temp) {
            push(extraStack.peek());
            extraStack.pop();
        }
        extraStack.push(temp);
    }
    
    while (!extraStack.isEmpty()) {
        push(extraStack.peek());
        extraStack.pop();
    }
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = topIndex; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Stack::mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        int i = left, j = mid + 1, k = 0;
        int temp[MAX_SIZE];
        
        while (i <= mid && j <= right) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        
        for (i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
        }
    }
}