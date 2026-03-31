#include <iostream>
#include "Task.h"
using namespace std;

int main()
{
    UnsortedList ulist(10);   // capacity = 10

    cout << "Inserting elements into Unsorted List:\n";
    ulist.insert(5);
    ulist.insert(3);
    ulist.insert(7);
    ulist.insert(3);
    ulist.insert(9);

    cout << "Unsorted List elements:\n";
    ulist.display();

    cout << "\nRemoving all occurrences of 3 (unordered removal):\n";
    int removed = ulist.removeAll(3);
    cout << "Removed count: " << removed << endl;

    cout << "Updated Unsorted List:\n";
    ulist.display();

    return 0;
}
