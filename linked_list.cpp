#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Insert(int data, int pos);
void Print();
void Print(Node *head);
void PrintRecursive(Node *p);
void ReversePrintRecursive(Node *p);
void InsertEnd(int data);
Node *InsertEnd(Node *head, int data);
void Delete(int pos);
void Reverse();
Node *Reverse(Node *head);

Node *head = NULL;

int main()
{
    Node *head_local = NULL;

    // Insert(2, 1); // 2
    // Insert(3, 2); // 2,3
    // Insert(4, 1); // 4,2,3
    // Insert(5, 2); // 4,5,2,3
    InsertEnd(2);
    InsertEnd(4);
    InsertEnd(6);
    InsertEnd(5); // 2,4,6,5
    Print();

    printf("Enter a position to delete\n");
    int d;
    scanf("%d", &d);
    Delete(d);
    Print();
    Reverse();
    Print();

    head_local = InsertEnd(head_local, 2);
    head_local = InsertEnd(head_local, 4);
    head_local = InsertEnd(head_local, 6);
    head_local = InsertEnd(head_local, 5); // 2,4,6,5
    Print(head_local);
    PrintRecursive(head_local);
    ReversePrintRecursive(head_local);
    printf("\n");

    head_local = Reverse(head_local);
    Print(head_local);

    return (0);
}

// Insert at position "pos" of the list
void Insert(int data, int pos)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }

    Node *temp2 = head;
    for (int i = 1; i < pos - 1; i++) // start from 1 because our list starts on 1
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

void Print(Node *head)
{
    printf("List is:");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

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

Node *InsertEnd(Node *head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        Node *temp2 = head;
        while (temp2->next != NULL)
            temp2 = temp2->next;

        temp2->next = temp;
    }
    return head;
}

void Delete(int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; i < pos - 1; i++)
    {
        if (temp->next == NULL)
            break;
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    if (temp2 != NULL)
        temp->next = temp2->next;

    free(temp2);
}

void Reverse()
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

Node *Reverse(Node *head)
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void PrintRecursive(Node *p)
{
    // uses more memory for temp variables and functions stack
    if (p == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    PrintRecursive(p->next);
}

void ReversePrintRecursive(Node *p)
{
    // uses more memory for temp variables and functions stack
    if (p == NULL)
    {
        return;
    }
    ReversePrintRecursive(p->next);
    printf("%d ", p->data);
}
