#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

Node *top = NULL;

void Push(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop()
{
    Node *temp;
    if (top == NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
}

void Print()
{
    Node *temp = top;
    if (temp == NULL)
        return;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    Push(2);
    Print();
    Push(5);
    Print();
    Push(4);
    Print();
    Pop();
    Print();
}