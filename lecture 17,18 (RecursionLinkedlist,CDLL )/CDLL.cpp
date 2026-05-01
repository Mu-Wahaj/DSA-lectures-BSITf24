

#include "CDLL.h"
#include <iostream>
using namespace std;

// Constructor
CDLL::CDLL()
{
    head.next = &head;
    head.prev = &head;
}

// Destructor
CDLL::~CDLL()
{
    clear();
}

// Sorted Insert (exactly from your sir's image)
bool CDLL::sorted_Insert(int val)
{
    DNode *temp = new DNode;
    temp->data = val;

    DNode *curr = head.next;

    while (curr != &head && curr->data < val)
    {
        curr = curr->next;
    }

    temp->next = curr;
    temp->prev = curr->prev;
    curr->prev->next = temp;
    curr->prev = temp;

    return true;
}
bool merge (CDLLD& list1, CDLLD& list2) 
{

    
}
// Insert at beginning
void CDLL::insertAtBeginning(int val)
{
    DNode *temp = new DNode;
    temp->data = val;

    DNode *first = head.next;

    temp->next = first;
    temp->prev = &head;
    first->prev = temp;
    head.next = temp;
};

// Insert at end
void CDLL::insertAtEnd(int val)
{
    DNode *temp = new DNode;
    temp->data = val;

    DNode *last = head.prev;

    temp->next = &head;
    temp->prev = last;
    last->next = temp;
    head.prev = temp;
}

// Insert at specific position (1-based)
bool CDLL::insertAtPosition(int position, int val)
{
    if (position < 1)
    {
        cout << "Invalid position!" << endl;
        return false;
    }

    DNode *curr = head.next;
    int currentPos = 1;

    // Traverse to find the position
    while (curr != &head && currentPos < position)
    {
        curr = curr->next;
        currentPos++;
    }

    if (currentPos != position && position != currentPos) //
    {
        cout << "Position out of range!" << endl;
        return false;
    }

    DNode *temp = new DNode;
    temp->data = val;

    temp->next = curr;
    temp->prev = curr->prev;
    curr->prev->next = temp;
    curr->prev = temp;

    return true;
}

// Delete from beginning
bool CDLL::deleteFromBeginning()
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return false;
    }

    DNode *toDelete = head.next;
    DNode *newFirst = toDelete->next;

    head.next = newFirst;
    newFirst->prev = &head;

    delete toDelete;
    return true;
}

// Delete from end
bool CDLL::deleteFromEnd()
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return false;
    }

    DNode *toDelete = head.prev;
    DNode *newLast = toDelete->prev;

    newLast->next = &head;
    head.prev = newLast;

    delete toDelete;
    return true;
}

// Delete from position
bool CDLL::deleteFromPosition(int position)
{
    if (isEmpty() || position < 1)
    {
        cout << "Invalid operation!" << endl;
        return false;
    }

    DNode *curr = head.next;
    int currentPos = 1;

    while (curr != &head && currentPos < position)
    {
        curr = curr->next;
        currentPos++;
    }

    if (curr == &head || currentPos != position)
    {
        cout << "Position not found!" << endl;
        return false;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete curr;
    return true;
}

// Delete first occurrence of value
bool CDLL::deleteValue(int val)
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return false;
    }

    DNode *curr = head.next;

    while (curr != &head)
    {
        if (curr->data == val)
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            return true;
        }
        curr = curr->next;
    }

    cout << "Value " << val << " not found!" << endl;
    return false;
}

// Search for value
bool CDLL::search(int val)
{
    if (isEmpty())
        return false;

    DNode *curr = head.next;

    while (curr != &head)
    {
        if (curr->data == val)
            return true;
        curr = curr->next;
    }

    return false;
}

// Get element at position
int CDLL::getAtPosition(int position)
{
    if (position < 1 || isEmpty())
    {
        cout << "Invalid position!" << endl;
        return -1;
    }

    DNode *curr = head.next;
    int currentPos = 1;

    while (curr != &head && currentPos < position)
    {
        curr = curr->next;
        currentPos++;
    }

    if (curr == &head || currentPos != position)
    {
        cout << "Position out of range!" << endl;
        return -1;
    }

    return curr->data;
}

// Check if empty
bool CDLL::isEmpty()
{
    return head.next == &head;
}

// Display forward (exactly from your sir's image)
void CDLL::display()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *cur = head.next;

    while (cur != &head)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// Display backward
void CDLL::displayBackward()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *cur = head.prev;

    while (cur != &head)
    {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << endl;
}

// Display circular nature
void CDLL::displayCircular()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *cur = head.next;
    cout << "Circular (2 cycles): ";

    int count = 0;
    int totalNodes = this->count(); // get count first

    while (count < totalNodes * 2)
    {
        cout << cur->data << " ";
        cur = cur->next;
        if (cur == &head)
            cur = cur->next;
        count++;
    }
    cout << endl;
}

// Clear the list
void CDLL::clear()
{
    while (!isEmpty())
    {
        deleteFromBeginning();
    }
}

// Reverse the list
void CDLL::reverse()
{
    if (isEmpty())
        return;

    DNode *cur = head.next;
    DNode *temp = nullptr;

    // Traverse and reverse links
    while (cur != &head)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    // Update head connections
    temp = head.next;
    head.next = head.prev;
    head.prev = temp;
}

// Count nodes (traverse to count)
int CDLL::count()
{
    if (isEmpty())
        return 0;

    DNode *cur = head.next;
    int counter = 0;

    while (cur != &head)
    {
        counter++;
        cur = cur->next;
    }

    return counter;
};