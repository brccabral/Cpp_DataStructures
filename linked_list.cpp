#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Insert(int data, int pos);
void Print();
void InsertEnd(int data);
void Delete(int pos);

Node *head;

int main()
{
    head = NULL;

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
