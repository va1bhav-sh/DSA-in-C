#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// When deque is empty → both are NULL
struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed\n"); return; }
    newNode->data = value;
    newNode->next = front;

    // If deque was empty, both front and rear should point to newNode
    if (front == NULL) {
        front = rear = newNode;
    } else {
        // attach new node at beginning
        front = newNode;
    }
}

void insertRear(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL; // NULL (because it's last node)
    // If deque is empty
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    // This inserts at end.
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int deleteFront()
{
    if (front == NULL)
    {
        printf("Deque Underflow\n");
        return -1;
    }
    else
    {
        struct Node *temp = front;
        int val = temp->data;

        front = front->next;
        // If after deletion front = NULL → list became empty → rear = NULL
        if (front == NULL)
        {
            rear = NULL;
        }
        free(temp);
        return val;
    }
}
int deleteRear()
{
    if (front == NULL)
    {
        printf("Deque Underflow\n");
        return -1;
    }
    struct Node *temp = rear;
    if (front == rear)
    {
        int val = temp->data;
        free(temp);
        front = rear = NULL;
        return val;
    }
    struct Node *current = front;
    while (current->next != rear)
    {
        current = current->next;
    }
    int val = rear->data;
    free(rear);
    rear = current;
    rear->next = NULL;
    return val;
}

void display()
{
    if (front == NULL)
    {
        printf("Deque is Empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Deque: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n---- DEQUE MENU ----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;

        case 3:
            printf("Deleted: %d\n", deleteFront());
            break;

        case 4:
            printf("Deleted: %d\n", deleteRear());
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}