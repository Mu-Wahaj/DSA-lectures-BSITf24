// linkedStack class with push O(1), pop O(1) and display functions,constructor and destructor
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedStack
{
private:
    Node *top;
public:
    LinkedStack();
    ~LinkedStack();
    void push(int value);
    void pop();
    void display();
};
    
#endif