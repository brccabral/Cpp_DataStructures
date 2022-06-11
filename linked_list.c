#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head; // global

void Insert(int x);
void Print();

int main()
{
    head = NULL; // empty list

    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n); // get input
    for (i = 0; i < n; i++)
    {
        printf("Enter the number\n");
        scanf("%d", &x);
        Insert(x);
    }
    Print();

    return (0);
}

// Insert at beginning of the list
void Insert(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    head = temp;
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