// linked list in Data Structures and Algorithm in C++ by Adam Drozdek
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    friend void sortedInsert(LinkedList &list, int value);

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void inserEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        Node *temp = head, *prev = nullptr;
        while (temp != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr)
        {
            head = newNode;
        }
        else
        {
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

    ~LinkedList()
    {
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }
};
// sorted insert in linked list by prev and current pointer solution
void sortedInsert(LinkedList &list, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    Node *current = list.head, *prev = nullptr;
    while (current != nullptr && current->data < value)
    {
        prev = current;
        current = current->next;
    }
    if (prev == nullptr)
    {
        newNode->next = list.head;
        list.head = newNode;
    }
    else
    {
        prev->next = newNode;
        newNode->next = current;
    }
}

//homework
//bool linkedlits::search(int value)
//int  linkedlist::findMax()
   //shoudl return the maximum value in the linked list else -999 if the list is empty
//void  linkedlist:: displayReverse() //display the linked list in reverse order , iterative solution,complexity O(n) and space complexity O(1)

// linkedStack class with push O(1), pop O(1) and display functions,constructor and destructor
int main()
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.inserEnd(40);
    list.insert(50);
    list.insert(60);
    cout << "Linked List: ";
    list.display();

    return 0;
}
