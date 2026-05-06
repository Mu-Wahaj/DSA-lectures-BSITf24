#include <iostream>
#include <functional>
#include "bst.h"
using namespace std;

/* Constructor */
BST::BST()
{
    root = NULL;
}

/* Destructor */
BST::~BST()
{
    destroy(root);
}

/* Destroy tree */
void BST::destroy(Node *node)
{
    if (node == NULL)
        return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}

/* Insert (recursive) */
Node *BST::insert(Node *node, int val)
{
    if (node == NULL)
        return new Node{val, NULL, NULL};

    if (val < node->data)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);

    return node;
}

void BST::insert(int val)
{
    root = insert(root, val);
}

/* Traversals */
void BST::inorder(Node *node) const
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BST::preorder(Node *node) const
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::postorder(Node *node) const
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

/* Public traversal calls */
void BST::inorder() const { inorder(root); }
void BST::preorder() const { preorder(root); }
void BST::postorder() const { postorder(root); }

/* Search */
Node *BST::search(Node *node, int val) const
{
    if (node == NULL || node->data == val)
        return node;

    if (val < node->data)
        return search(node->left, val);
    else
        return search(node->right, val);
}

bool BST::search(int val) const
{
    return search(root, val) != NULL;
}

/* Find minimum */
Node *BST::findMin(Node *node) const
{
    while (node && node->left != NULL)
        node = node->left;

    return node;
}

/* Delete */
Node *BST::remove(Node *node, int val)
{
    if (node == NULL)
        return NULL;

    if (val < node->data)
        node->left = remove(node->left, val);
    else if (val > node->data)
        node->right = remove(node->right, val);
    else
    {
        // Case 1: No child
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            return NULL;
        }
        // Case 2: One child
        else if (node->left == NULL)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children
        Node *temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

void BST::remove(int val)
{
    root = remove(root, val);
}

int BST::findMin() const
{
    Node *minNode = findMin(root);
    return minNode ? minNode->data : -1; // Return -1 if tree is empty
}

int BST::findMax() const
{
    Node *node = root;
    while (node && node->right != NULL)
        node = node->right;

    return node ? node->data : -1; // Return -1 if tree is empty
}
bool BST::isEmpty() const
{
    return root == NULL;
}

bool BST::isBST() const
{
    // Helper function to validate BST properties
    function<bool(Node *, int, int)> validate = [&](Node *node, int min, int max)
    {
        if (node == NULL)
            return true;
        if (node->data <= min || node->data >= max)
            return false;
        return validate(node->left, min, node->data) && validate(node->right, node->data, max);
    };

    return validate(root, INT_MIN, INT_MAX);
}
bool BST::isBalanced() const
{
    // Helper function to check balance and calculate height
    function<int(Node *)> checkBalance = [&](Node *node)
    {
        if (node == NULL)
            return 0;

        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1)
            return -1; // Left subtree is not balanced

        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1)
            return -1; // Right subtree is not balanced

        if (abs(leftHeight - rightHeight) > 1)
            return -1; // Current node is not balanced

        return max(leftHeight, rightHeight) + 1; // Return height
    };

    return checkBalance(root) != -1;
}
bool BST::isFull() const
{
    // Helper function to check if tree is full
    function<bool(Node *)> checkFull = [&](Node *node)
    {
        if (node == NULL)
            return true;
        if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
            return false; // Node has only one child
        return checkFull(node->left) && checkFull(node->right);
    };

    return checkFull(root);
}
bool BST::searchIterative(int val) const
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->data == val)
            return true;
        else if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}