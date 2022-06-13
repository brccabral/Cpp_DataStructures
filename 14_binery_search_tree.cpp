// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it

#include <iostream>

using namespace std;

// Definition of Node for Binary search tree
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

// Function to create a new Node in heap
BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    { // empty tree
        root = GetNewNode(data);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    // else, insert in right subtree.
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

// To insert data in BST, returns address of root node
BstNode *InsertNoRecursion(BstNode *root, int data)
{
    if (root == NULL)
    { // empty tree
        return GetNewNode(data);
    }

    BstNode *curr = root;

    while (true)
    {
        // if data to be inserted is lesser, insert in left subtree.
        if (data <= curr->data)
        {
            if(curr->left == NULL){
                curr->left = GetNewNode(data);
                return root;
            }
            curr = curr->left;
        }
        // else, insert in right subtree.
        else
        {
            if(curr->right == NULL){
                curr->right = GetNewNode(data);
                return root;
            }
            curr = curr->right;
        }
    }
}

// To search an element in BST, returns true if element is found
bool Search(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

int main()
{
    BstNode *root = NULL; // Creating an empty tree
    /*Code to test the logic*/
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    // Ask user to enter a number.
    int number;
    cout << "Enter number be searched\n";
    cin >> number;
    // If number is found, print "FOUND"
    if (Search(root, number) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";

    BstNode *root_no_rec = NULL; // Creating an empty tree
    /*Code to test the logic*/
    root_no_rec = Insert(root_no_rec, 45);
    root_no_rec = Insert(root_no_rec, 40);
    root_no_rec = Insert(root_no_rec, 50);
    root_no_rec = Insert(root_no_rec, 55);
    root_no_rec = Insert(root_no_rec, 38);
    root_no_rec = Insert(root_no_rec, 42);
    // Ask user to enter a number.
    cout << "Enter number be searched\n";
    cin >> number;
    // If number is found, print "FOUND"
    if (Search(root_no_rec, number) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";
}
