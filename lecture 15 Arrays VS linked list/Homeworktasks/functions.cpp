//bool linkedlits::search(int value)
//int  linkedlist::findMax()
   //shoudl return the maximum value in the linked list else -999 if the list is empty
//void  linkedlist:: displayReverse() //display the linked list in reverse order , iterative solution,complexity O(n) and space complexity O(1)

// linkedStack class with push O(1), pop O(1) and display functions,constructor and destructor


#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head, *prev = nullptr;
        while (current != nullptr && current->data < value)
        {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = current;
            prev->next = newNode;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
int findMax(LinkedList &list)
{
    if (list.head == nullptr)
    {
        return -999; // List is empty
    }
    int maxVal = list.head->data;
    Node *temp = list.head->next;
    while (temp != nullptr)
    {
        if (temp->data > maxVal)
        {
            maxVal = temp->data;
        }
        temp = temp->next;
    }
    return maxVal;
}

void displayReverse(LinkedList &list)
{
    Node *prev = nullptr, *current = list.head, *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list.head = prev;

    // Display the reversed list
    Node *temp = list.head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    LinkedList list;
    list.insert(5);
    list.insert(3);
    list.insert(8);
    list.insert(1);
    list.insert(7);

    cout << "Linked List: ";
    list.display();

    return 0;
}