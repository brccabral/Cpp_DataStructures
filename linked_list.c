#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *Insert(int x, Node *head);
void Print(Node *head);

int main()
{
    Node *head = NULL;

    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n); // get input
    for (i = 0; i < n; i++)
    {
        printf("Enter the number\n");
        scanf("%d", &x);
        head = Insert(x, head);
    }
    Print(head);

    return (0);
}

// Insert at beginning of the list
Node *Insert(int x, Node *head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
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