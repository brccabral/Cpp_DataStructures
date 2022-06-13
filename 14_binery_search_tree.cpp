// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it

#include <iostream>
#include <bits/stdc++.h>

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
            if (curr->left == NULL)
            {
                curr->left = GetNewNode(data);
                return root;
            }
            curr = curr->left;
        }
        // else, insert in right subtree.
        else
        {
            if (curr->right == NULL)
            {
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

int FindMin(BstNode *curr)
{
    if (curr == NULL)
    {
        cout << "Error: tree is empty\n";
        return INT_MIN;
    }
    while (curr->left != NULL)
        curr = curr->left;
    return curr->data;
}

int FindMinRecursive(BstNode *curr)
{
    if (curr == NULL)
    {
        cout << "Error: tree is empty\n";
        return INT_MIN;
    }
    else if (curr->left == NULL)
        return curr->data;

    return FindMinRecursive(curr->left);
}

int FindMax(BstNode *curr)
{
    if (curr == NULL)
    {
        cout << "Error: tree is empty\n";
        return INT_MIN;
    }
    while (curr->right != NULL)
        curr = curr->right;
    return curr->data;
}

int FindMaxRecursive(BstNode *curr)
{
    if (curr == NULL)
    {
        cout << "Error: tree is empty\n";
        return INT_MIN;
    }
    else if (curr->right == NULL)
        return curr->data;

    return FindMaxRecursive(curr->right);
}

int FindHeight(BstNode *curr)
{
    if (curr == NULL)
        return -1;

    return max(FindHeight(curr->left), FindHeight(curr->right)) + 1;
}

// Function to print Nodes in a binary tree in Level order
void LevelOrder(BstNode *root)
{
    if (root == NULL)
        return;
    queue<BstNode *> Q;
    Q.push(root);
    // while there is at least one discovered node
    while (!Q.empty())
    {
        BstNode *current = Q.front();
        Q.pop(); // removing the element at front
        printf("%c ", current->data);
        // cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }
}

// Function to visit nodes in Preorder
void Preorder(struct BstNode *root)
{
    // base condition for recursion
    // if tree/sub-tree is empty, return and exit
    if (root == NULL)
        return;

    printf("%c ", root->data); // Print data
    Preorder(root->left);      // Visit left subtree
    Preorder(root->right);     // Visit right subtree
}

// Function to visit nodes in Inorder
void Inorder(BstNode *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);       // Visit left subtree
    printf("%c ", root->data); // Print data
    Inorder(root->right);      // Visit right subtree
}

// Function to visit nodes in Postorder
void Postorder(BstNode *root)
{
    if (root == NULL)
        return;

    Postorder(root->left);     // Visit left subtree
    Postorder(root->right);    // Visit right subtree
    printf("%c ", root->data); // Print data
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
    root = Insert(root, 13);

    // Ask user to enter a number.
    int number;
    char *buffer = NULL;
    size_t n = 0;
    cout << "Enter number be searched\n";
    getline(&buffer, &n, stdin);
    sscanf(buffer, "%d", &number);
    // If number is found, print "FOUND"
    if (Search(root, number) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";

    printf("FindMin: %d\n", FindMin(root));
    printf("FindMax: %d\n", FindMax(root));
    printf("FindMinRecursive: %d\n", FindMinRecursive(root));
    printf("FindMaxRecursive: %d\n", FindMaxRecursive(root));
    printf("FindHeight: %d\n", FindHeight(root));

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
    getline(&buffer, &n, stdin);
    sscanf(buffer, "%d", &number);
    // If number is found, print "FOUND"
    if (Search(root_no_rec, number) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";

    BstNode *root_order = NULL;
    root_order = Insert(root_order, 'M');
    root_order = Insert(root_order, 'B');
    root_order = Insert(root_order, 'Q');
    root_order = Insert(root_order, 'Z');
    root_order = Insert(root_order, 'A');
    root_order = Insert(root_order, 'C');

    LevelOrder(root_order); // M B Q A C Z
    printf("\n");

    Preorder(root_order); // M B A C Q Z
    printf("\n");

    Inorder(root_order); // A B C M Q Z
    printf("\n");

    Postorder(root_order); // A C B Z Q M
    printf("\n");
}
