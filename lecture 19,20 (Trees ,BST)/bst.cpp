#include <iostream>
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
void BST::destroy(Node* node)
{
    if (node == NULL)
        return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}

/* Insert (recursive) */
Node* BST::insert(Node* node, int val)
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
void BST::inorder(Node* node) const
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BST::preorder(Node* node) const
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::postorder(Node* node) const
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
Node* BST::search(Node* node, int val) const
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
Node* BST::findMin(Node* node) const
{
    while (node && node->left != NULL)
        node = node->left;

    return node;
}

/* Delete */
Node* BST::remove(Node* node, int val)
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
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

void BST::remove(int val)
{
    root = remove(root, val);
}