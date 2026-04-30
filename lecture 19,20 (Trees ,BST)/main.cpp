#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal:" << endl;
    tree.inorder();
    cout << endl;

    cout << "Preorder traversal:" << endl;
    tree.preorder();
    cout << endl;

    cout << "Postorder traversal:" << endl;
    tree.postorder();
    cout << endl;

    cout << "Search 40: " << tree.search(40) << endl;

    tree.remove(50);

    cout << "After deleting 50:" << endl;
    tree.inorder();
    cout << endl;

    return 0;
}