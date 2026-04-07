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
//it is the head of the linked list and it is initialized to nullptr in the constructor beaose the linked list is initially empty. The head pointer is used to keep track of the first node in the linked list, allowing us to perform various operations such as insertion, traversal, and searching.
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
//newnode is the obkect of the node class and it is created using the new operator to allocate memory for a new node in the linked list. The data member of the new node is set to the value passed as an argument to the insert function, and the next pointer of the new node is initialized to nullptr since it will be the last node in the list after insertion.
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
int findMax(LinkedList &list) //we passes the whole array 
{
    if (list.head == nullptr) //checif the list is empty or not if it is empty we return -999
    {
        return -999; // List is empty
    }
    int maxVal = list.head->data;
    Node *temp = list.head->next; //we start from the second node because we have already considered the first node's data as the initial maxVal
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
    Node *prev = nullptr, *current = list.head, *next = nullptr; //we initialize three pointers: prev to keep track of the previous node, current to traverse the list, and next to temporarily store the next node during the reversal process.
    while (current != nullptr)
    {
        //what we doing is we are reversing the linked list by changing the next pointers of each node to point to the previous node instead of the next node. This way, we can traverse the list in reverse order without using any additional data structures like a stack or recursion.
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

    int valueToSearch = 3;
    if (list.search(valueToSearch))
    {
        cout << "Value " << valueToSearch << " found in the list." << endl;
    }
    else
    {
        cout << "Value " << valueToSearch << " not found in the list." << endl;
    }

    int maxValue = findMax(list);
    if (maxValue != -999)
    {
        cout << "Maximum value in the list: " << maxValue << endl;
    }
    else
    {
        cout << "The list is empty." << endl;
    }


    cout << "Linked List in reverse order: ";
    displayReverse(list);
    return 0;
}