
#include "linkedStack.h"
#include <iostream>
using namespace std;
int main()
{
    LinkedStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.display();

    LinkedStack stack1, stack2;
    stack1.push(1);
    stack1.push(3);
    stack1.push(5);
    stack2.push(2);
    stack2.push(4);
    stack2.push(6);
    LinkedStack mergedStack;
    mergedStack.merge(stack1, stack2);  
    cout << "Merged Stack: ";
    mergedStack.display();
    return 0;
}