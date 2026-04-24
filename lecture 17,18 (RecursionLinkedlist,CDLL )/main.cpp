#include "CDLL.h"
#include <iostream>
using namespace std;

int main()
{
    CDLL list;
    
    cout << "=== Circular Doubly Linked List (Sir's Style) ===\n\n";
    
    // Test sorted insert
    cout << "Sorted Insert (5, 3, 8, 1, 7):" << endl;
    list.sorted_Insert(5);
    list.sorted_Insert(3);
    list.sorted_Insert(8);
    list.sorted_Insert(1);
    list.sorted_Insert(7);
    list.display();  // Expected: 1 3 5 7 8
    
    cout << "Count: " << list.count() << endl;
    
    // Test backward display
    cout << "\nBackward display: ";
    list.displayBackward();
    
    // Test search
    cout << "\nSearch for 5: " << (list.search(5) ? "Found" : "Not found") << endl;
    
    // Test delete operations
    cout << "\nAfter delete from beginning: ";
    list.deleteFromBeginning();
    list.display();
    
    cout << "After delete from end: ";
    list.deleteFromEnd();
    list.display();
    
    // Test reverse
    cout << "\nAfter reverse: ";
    list.reverse();
    list.display();
    
    // Test clear
    cout << "\nClearing list..." << endl;
    list.clear();
    cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}