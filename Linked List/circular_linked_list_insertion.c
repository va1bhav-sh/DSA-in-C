#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
// Function to traverse a circular linked list
void cllTraversal(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("Element=%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}
// Case ! Insert at beginning
struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = newNode; // point to itself Think of newNode as a temporary handle to the node you are inserting.
        head = newNode;
        return head;
    }
    struct Node *temp = head; // Whenever we create temp we do not allocate heap memory bcs we just want to traverse it
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}
// Case 2 Insert At end
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = newNode; // point to itself Think of newNode as a temporary handle to the node you are inserting.
        head = newNode;
        return head;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode; // last node points to new node
    newNode->next = head; // new node points back to head
    return head;
}
// Case 3 Insertin after a given node
struct Node *insertAfterNode(struct Node *head,struct Node* givenNode,int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = newNode; // point to itself Think of newNode as a temporary handle to the node you are inserting.
        head = newNode;
        return head;
    }
    
    if (givenNode == NULL) {
        printf("Given node cannot be NULL!\n");
        return head;
    }
    newNode->next=givenNode->next;
    givenNode->next=newNode;
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 6;
    third->next = fourth;
    fourth->data = 8;
    fourth->next = head;
    cllTraversal(head);
    printf("\n");
    // Case1
    //  head = insertAtBeginning(head, 54);
    //  cllTraversal(head);
    //Case 2
    // head = insertAtEnd(head, 84);
    // cllTraversal(head);
    //Case 3
    head = insertAfterNode(head, third,34);
    cllTraversal(head);
    return 0;
}