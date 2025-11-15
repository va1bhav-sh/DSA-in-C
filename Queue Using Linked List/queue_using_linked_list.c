#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// If both are NULL, queue is empty.
struct Node *front = NULL, *rear = NULL;
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL; // Since this node will be added at the end, its next pointer is NULL
    if (rear == NULL)     // Empty
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode; // attach new node
        rear = newNode;       // move rear forward
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue UNderflow\n");
        return -1;
    }
    struct Node *temp = front;
    int val = temp->data;
    front = front->next;
    // Special Case: Queue becomes empty
    //  If front becomes NULL after deletion:
    //  It means queue had only 1 element.
    //  So rear must also be set to NULL.
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return val;
}
int peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return front->data;
}
int isEmpty()
{
    return front == NULL;
}
void display()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();//It always remove the first element
    display();
    return 0;
}