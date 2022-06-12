#include <stdio.h>
#include <stdlib.h>
#include <stack>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void InsertEnd(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

void Print()
{
    Node *temp = head;
    printf("List is:");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse()
{
    if (head == NULL)
        return;
    std::stack<Node *> s;
    Node *temp = head;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    InsertEnd(2);
    InsertEnd(5);
    InsertEnd(4);
    Print();
    Reverse();
    Print();
}