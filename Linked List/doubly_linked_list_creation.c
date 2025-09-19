#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};
// Print Forward
void printForward(struct Node *head)
{
    struct Node *temp = head;
     printf("Forward Traversal:\n");
     while (temp != NULL)// loop until the end of DLL
    {
        printf("Element:%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}
void printBackward(struct Node *head)
{
    struct Node *temp = head;
      // Move to last node first
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("Backward Traversal:\n");
while (temp!=NULL)  
{
    printf("Element:%d\n", temp->data);
    temp=temp->prev;
}

    printf("\n");
    
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 34;
    head->next = second;
    head->prev = NULL;

    second->data = 67;
    second->prev = head;
    second->next = third;

    third->data = 23;
    third->next = fourth;
    third->prev = second;

    fourth->data = 89;
    fourth->next = NULL;
    fourth->prev = third;

    printForward(head);
    printf("\n");
    printBackward(head);

    return 0;
}