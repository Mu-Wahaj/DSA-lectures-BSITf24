#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== STACK DATA STRUCTURE DEMONSTRATION =====" << endl;
    cout << endl;
    
    Stack s;
    
    cout << "1. BASIC OPERATIONS" << endl;
    cout << "-------------------" << endl;
    
    cout << "Pushing elements: 10, 20, 30, 40, 50" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    
    cout << "Peek top element: " << s.peek() << endl;
    
    cout << "Pop element" << endl;
    s.pop();
    s.display();
    
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;
    cout << endl;
    
    cout << "2. FIND MINIMUM ELEMENT" << endl;
    cout << "----------------------" << endl;
    cout << "Current stack: ";
    s.display();
    cout << "Minimum element: " << s.findMin() << endl;
    cout << endl;
    
    cout << "3. SORTING OPERATIONS" << endl;
    cout << "--------------------" << endl;
    
    cout << "Original stack: ";
    s.display();
    
    cout << "Sorting ascending" << endl;
    s.sortAscending();
    s.display();
    
    cout << "Sorting descending" << endl;
    s.sortDescending();
    s.display();
    
    cout << "Sort using extra stack" << endl;
    s.sortUsingExtraStack();
    s.display();
    cout << endl;
    
    cout << "4. REVERSE ARRAY USING STACK" << endl;
    cout << "---------------------------" << endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    s.reverseArray(arr, size);
    
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    cout << "5. BALANCED PARENTHESES CHECKING" << endl;
    cout << "-------------------------------" << endl;
    
    const char* expr1 = "{(a+b)*(c-d)}";
    const char* expr2 = "{(a+b)*(c-d]";
    const char* expr3 = "({[()]})";
    const char* expr4 = "({[(])})";
    
    cout << "Expression: " << expr1 << " -> " 
         << (s.checkBalancedParentheses(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << "Expression: " << expr2 << " -> " 
         << (s.checkBalancedParentheses(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << "Expression: " << expr3 << " -> " 
         << (s.checkBalancedParentheses(expr3) ? "Balanced" : "Not Balanced") << endl;
    cout << "Expression: " << expr4 << " -> " 
         << (s.checkBalancedParentheses(expr4) ? "Balanced" : "Not Balanced") << endl;
    cout << endl;
    
    cout << "6. CLEAR OPERATION" << endl;
    cout << "-----------------" << endl;
    cout << "Before clear: ";
    s.display();
    s.clear();
    cout << "After clear: ";
    s.display();
    cout << endl;
    
    cout << "7. EDGE CASES" << endl;
    cout << "------------" << endl;
    cout << "Popping from empty stack: " << (s.pop() ? "Success" : "Failed") << endl;
    cout << "Peeking from empty stack: " << s.peek() << endl;
    cout << "Pushing 5 elements to full stack test" << endl;
    for (int i = 1; i <= 105; i++) {
        if (!s.push(i)) {
            cout << "Stack full at element " << i << endl;
            break;
        }
    }
    

    //sort ascending 
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    s.bubbleSort(arr2, n);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    
    cout << endl;
    cout << "===== STACK DEMONSTRATION COMPLETE =====" << endl;
    
    return 0;
}