// linkedStack class with push O(1), pop O(1) and display functions,constructor and destructor

#include "linkedStack.h"
LinkedStack::LinkedStack()
{
    top = nullptr;
}
LinkedStack::~LinkedStack() // time complexity of O(n) because we need to traverse the entire stack to delete all nodes and free up memory, which takes linear time proportional to the number of nodes in the stack.
{

    Node *current = top;       // creas a pointer called current and initialize it to the top of the stack. This pointer will be used to traverse the stack and delete each node until we reach the end of the stack (when current becomes nullptr).
    Node *next = nullptr;      // we also create another pointer called next, which will be used to temporarily store the next node in the stack while we delete the current node. This is necessary because once we delete the current node, we won't be able to access its next pointer to move to the next node in the stack.
    while (current != nullptr) // we use a while loop to traverse the stack until we reach the end (when current becomes nullptr). Inside the loop, we first store the next node in the stack using the next pointer, then we delete the current node to free up memory, and finally, we move the current pointer to the next node in the stack to continue the traversal and deletion process until we have deleted all nodes in the stack.
    {
        next = current->next; // points to the next node in the stack, allowing us to keep track of the remaining nodes before we delete the current node.
        delete current;
        current = next;
    }
}
void LinkedStack::push(int value) // time complexity of O(1) because we are adding a new node to the top of the stack without needing to traverse the stack, and we are simply updating the top pointer to point to the new node, which is a constant time operation regardless of the size of the stack.
{

    Node *newNode = new Node(); // creating a new node using the new operator to allocate memory for it. This allows us to dynamically add nodes to the stack as needed without worrying about the underlying memory management.
    newNode->data = value;      // we set the data member of the new node to the value passed as an argument to the push function. This allows us to store the value in the stack for later retrieval when we pop elements from the stack.
    newNode->next = top;        // set the next pointer of the new node to point to the current top of the stack. This way, the new node becomes the new top of the stack, and it maintains a link to the previous top node, allowing us to easily pop elements from the stack later on.
    top = newNode;              // Finally, we update the top pointer to point to the new node, making it the new top of the stack. This ensures that the stack maintains its Last-In-First-Out (LIFO) property, where the most recently added element is always at the top of the stack and will be the first one to be removed when we pop elements from the stack.
}
void LinkedStack::pop() // time complexity of O(1) because we are removing the top node from the stack without needing to traverse the stack, and we are simply updating the top pointer to point to the next node in the stack, which is a constant time operation regardless of the size of the stack.
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

void LinkedStack::merge(LinkedStack &stack1, LinkedStack &stack2)
{
    Node *temp1 = stack1.top;
    Node *temp2 = stack2.top;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data < temp2->data)
        {
            push(temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            push(temp2->data);
            temp2 = temp2->next;
        }
    }
    while (temp1 != nullptr)
    {
        push(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        push(temp2->data);
        temp2 = temp2->next;
    }
}
