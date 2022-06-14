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

BstNode *FindMinNode(BstNode *curr)
{
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
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
// Function to print Nodes in a binary tree in Level order
void LevelOrderInt(BstNode *root)
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
        printf("%d ", current->data);
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

// check for all values on left are lesser than value
bool IsSubtreeLesser(BstNode *curr, int value)
{
    if (curr == NULL)
        return true;

    if (curr->data <= value && IsSubtreeLesser(curr->left, value) && IsSubtreeLesser(curr->right, value))
        return true;
    return false;
}

// check for all values on right are greater than value
bool IsSubtreeGreater(BstNode *curr, int value)
{
    if (curr == NULL)
        return true;

    if (curr->data > value && IsSubtreeGreater(curr->left, value) && IsSubtreeGreater(curr->right, value))
        return true;
    return false;
}

// check if a binary tree is a binary SEARCH tree
// if it follow the rule of left is less or equal
// root and right is greater than root
// The time complexity is O(n^2)
bool IsBinarySearchTree(BstNode *curr)
{
    if (curr == NULL)
        return true;

    if (IsSubtreeLesser(curr->left, curr->data) && IsSubtreeGreater(curr->right, curr->data) && IsBinarySearchTree(curr->left) && IsBinarySearchTree(curr->right))
        return true;
    return false;
}
// check if a binary tree is a binary SEARCH tree
// if it follow the rule of left is less or equal
// root and right is greater than root
// The time complexity is O(n)
bool IsBstFast(BstNode *curr, int minValue, int maxValue)
{
    if (curr == NULL)
        return true;

    if (curr->data <= minValue && curr->data < maxValue && IsBstFast(curr->left, minValue, curr->data) && IsBstFast(curr->right, curr->data, maxValue))
        return true;
    return false;
}

// another option is to get Inorder values and check if they are sorted
bool IsBinarySearchTreeFast(BstNode *curr)
{
    return IsBstFast(curr, INT_MIN, INT_MAX);
}

BstNode *FakeBST1(BstNode *root)
{
    root = GetNewNode(7);
    root->left = GetNewNode(4);
    root->left->left = GetNewNode(1);
    root->left->right = GetNewNode(6);
    root->right = GetNewNode(9);
    return root;
}

BstNode *FakeBST2(BstNode *root)
{
    root = GetNewNode(8);
    root->left = GetNewNode(6);
    root->left->left = GetNewNode(4);
    return root;
}

BstNode *FakeBST3(BstNode *root)
{
    // this is not a BST, one value is not in order
    root = GetNewNode(10);
    root->left = GetNewNode(5);
    root->right = GetNewNode(16);
    root->left->right = GetNewNode(7);
    root->left->right->right = GetNewNode(11);
    root->left->left = GetNewNode(4);
    root->left->left->left = GetNewNode(1);
    return root;
}

BstNode *FakeBST4(BstNode *root)
{
    // this is not a BST, one value is not in order
    root = GetNewNode(5);
    root->left = GetNewNode(1);
    root->right = GetNewNode(8);
    root->right->left = GetNewNode(9);
    root->right->right = GetNewNode(12);
    return root;
}

BstNode *FakeBST5(BstNode *root)
{
    root = GetNewNode(12);
    root->left = GetNewNode(5);
    root->right = GetNewNode(15);
    root->left->left = GetNewNode(3);
    root->left->right = GetNewNode(7);
    root->right->left = GetNewNode(13);
    root->right->right = GetNewNode(17);
    root->left->left->left = GetNewNode(1);
    root->left->right->right = GetNewNode(9);
    return root;
}

BstNode *Delete(BstNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else // value is equal
    {
        // case 1: no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2: one child right
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        // case 2: one child left
        else if (root->right == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children. Find Min on right side
        else
        {
            BstNode *temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            // int value = FindMin(root->right);
            // root->data = value;
            // root->right = Delete(root->right, value);
        }
    }
    return root;
}

BstNode *Find(BstNode *curr, int data)
{
    if (curr == NULL)
        return NULL;
    else if (data < curr->data)
        return Find(curr->left, data);
    else if (data > curr->data)
        return Find(curr->right, data);
    return curr;
}

// Find Inorder Successor in a BST
BstNode *GetSuccessor(BstNode *root, int data)
{
    BstNode *curr = Find(root, data); // O(h) - h = height of tree
    if (curr == NULL)
        return NULL;
    // case 1: curr node has right subtree
    //  get the left most value of right = Minimum value
    if (curr->right != NULL)
        return FindMinNode(curr->right); // O(h) - h = height of tree
    // case 2: no right subtree  // O(h) - h = height of tree
    //  get the ancestor that has NOT been visited yet
    else
    {
        BstNode *successor = NULL;
        BstNode *ancestor = root;
        while (ancestor != curr)
        {
            if (curr->data < ancestor->data)
            {
                successor = ancestor; // save parent before descend one level
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
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

    BstNode *root_check = NULL;
    root_check = FakeBST1(root_check);
    LevelOrderInt(root_check);
    printf("\n");
    printf("IsBinarySearchTree: %d\n", IsBinarySearchTree(root_check));
    printf("IsBinarySearchTreeFast: %d\n", IsBinarySearchTreeFast(root_check));

    root_check = FakeBST2(root_check);
    LevelOrderInt(root_check);
    printf("\n");
    printf("IsBinarySearchTree: %d\n", IsBinarySearchTree(root_check));
    printf("IsBinarySearchTreeFast: %d\n", IsBinarySearchTreeFast(root_check));

    root_check = FakeBST3(root_check);
    LevelOrderInt(root_check);
    printf("\n");
    printf("IsBinarySearchTree: %d\n", IsBinarySearchTree(root_check));
    printf("IsBinarySearchTreeFast: %d\n", IsBinarySearchTreeFast(root_check));

    root_check = FakeBST4(root_check);
    LevelOrderInt(root_check);
    printf("\n");
    printf("IsBinarySearchTree: %d\n", IsBinarySearchTree(root_check));
    printf("IsBinarySearchTreeFast: %d\n", IsBinarySearchTreeFast(root_check));

    BstNode *root_delete = NULL;
    root_delete = FakeBST5(root_delete);
    LevelOrderInt(root_delete); // 12 5 15 3 7 13 17 1 9
    printf("\n");
    Delete(root_delete, 15);
    LevelOrderInt(root_delete); // 12 5 17 3 7 13 1 9
    printf("\n");

    BstNode *root_successor = NULL;
    root_successor = Insert(root_successor, 5);
    root_successor = Insert(root_successor, 10);
    root_successor = Insert(root_successor, 3);
    root_successor = Insert(root_successor, 4);
    root_successor = Insert(root_successor, 1);
    root_successor = Insert(root_successor, 11);
    BstNode *successor = GetSuccessor(root_successor, 1);
    if (successor == NULL)
        printf("No successor Found\n");
    else
        printf("Successor is %d\n", successor->data); // 3
}
