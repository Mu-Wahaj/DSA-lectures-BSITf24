// linkedStack class with push O(1), pop O(1) and display functions,constructor and destructor

#include "linkedStack.h"
LinkedStack::LinkedStack()
{
    top = nullptr;
}
LinkedStack::~LinkedStack()
{
    Node *current = top;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}
void LinkedStack::push(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void LinkedStack::pop()
{
    if (top == nullptr)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}
void LinkedStack::display()
{
    Node *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
