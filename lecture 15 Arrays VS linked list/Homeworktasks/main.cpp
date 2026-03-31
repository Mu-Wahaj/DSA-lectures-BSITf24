
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
    return 0;
}