#ifndef BST_H
#define BST_H

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BST
{
private:
    Node* root;

    Node* insert(Node* node, int val);
    void inorder(Node* node) const;
    void preorder(Node* node) const;
    void postorder(Node* node) const;
    Node* search(Node* node, int val) const;
    Node* findMin(Node* node) const;
    Node* remove(Node* node, int val);
    void destroy(Node* node);

public:
    BST();
    ~BST();

    void insert(int val);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    bool search(int val) const;
    void remove(int val);
};

#endif