#include <iostream>
#include "sorted.h"
using namespace std;

int main()
{

    sorted sList(10);

    cout << " Inserting elements ";
    sList.insert(5);
    sList.insert(2);
    sList.insert(8);
    sList.insert(1);
    sList.insert(6);

    cout << "Sorted list elements after insertions:";
    sList.display();

    cout << " Searching elements ";
    int index;

    if (sList.search(5, index))
        cout << "Linear search: 5 found at index " << index << endl;
    else
        cout << "5 not found" << endl;

    if (sList.binarySearch(6, index))
        cout << "Binary search: 6 found at index " << index << endl;
    else
        cout << "6 not found" << endl;

    if (sList.binarySearch(10, index))
        cout << "Binary search: 10 found at index " << index << endl;
    else
        cout << "10 not found" << endl;

    cout << " Removing all occurrences of 5 ";
    int removed = sList.removeAll3(5); 
    cout << "Removed " << removed << " element(s)";
    sList.display();

    cout << " Copying list to another object ";
    sorted copyList = sList; 
    copyList.display();

    cout << " Testing equality operator ";
    if (sList == copyList)
        cout << "Lists are equal";
    else
        cout << "Lists are NOT equal";

    cout << " Deleting element at index 2 ";
    int val;
    if (sList.deleteItem(2, val))
        cout << "Deleted value: " << val << endl;
    else
        cout << "Invalid index" << endl;
    sList.display();

    return 0;
}
