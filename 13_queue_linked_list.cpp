/*Queue - Linked List implementation*/
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
};
// Two glboal variables to store address of front and rear nodes.
struct Node *front = NULL;
struct Node *rear = NULL;

// To Enqueue an integer
void Enqueue(int x)
{
    struct Node *temp =
        (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// To Dequeue an integer.
void Dequeue()
{
    struct Node *temp = front;
    if (front == NULL)
    {
        printf("Dequeue: Queue is Empty\n");
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

int Front()
{
    if (front == NULL)
    {
        printf("Front: Queue is empty\n");
        return INT_MIN;
    }
    return front->data;
}

void Print()
{
    printf("Queue: ");
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    /* Drive code to test the implementation. */
    // Printing elements in Queue after each Enqueue or Dequeue
    Print();
    printf("%d \n", Front());
    Dequeue();
    Enqueue(2);
    printf("%d \n", Front());
    Print();
    Enqueue(4);
    Print();
    Enqueue(6);
    Print();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Print();
    Enqueue(8);
    Print();
    Enqueue(7);
    Print();
    Enqueue(3);
    Print();
    Enqueue(1);
    Print();
    Enqueue(5);
    Print();
    Enqueue(9);
    Print();
    printf("%d \n", Front());
    Enqueue(0);
    Print();
    printf("%d \n", Front());
    Enqueue(-1);
    Print();
    printf("%d \n", Front());
    Enqueue(-3);
    Print();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
    Dequeue();
    printf("%d \n", Front());
}
