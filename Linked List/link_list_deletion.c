#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void Traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Case 1 Deleting the first node
struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *temp = head; // temp is not a new node, it’s just a pointer variable that stores the address of the node you want to free.
    // temp does not create a new node.
    // It just points to the existing node that you want to remove.
    // You do not want new memory; you want to free existing memory.
    head = head->next; // move head to the next node
    free(temp);        // free memory of the first node
    return head;
}
// Case 2 Deleting a node in between
struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        return head;
    }
    if (position == 1)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *prev = head;
    // Traverse to postion-1
    for (int i = 1; i < position - 1 && prev != NULL; i++)
    {
        prev = prev->next;
    }
    if (prev == NULL || prev->next == NULL)
    { // Adds safety checks (prev == NULL || prev->next == NULL) → prevents segmentation faults.
        printf("Invalid Position!\n");
        return head;
    }
    // Store the node to delete
    struct Node *del = prev->next;
    // jump over the previous node
    prev->next = del->next;
    free(del);
    return head;
}
// Case 3 Deleting Last Node
struct Node *delLastNode(struct Node *head)
{
    if (head == NULL)
    { // if empty
        return NULL;
    }
    if (head->next == NULL)
    { // if the linked list has one node
        free(head);
        return NULL;
    }
    struct Node *prev = head;
    while (prev->next->next != NULL)
    { // Traverse to second last node
        prev = prev->next;
    }
    // prev->next is the last node free it
    free(prev->next);
    prev->next = NULL;
    return head;
}
// Case 4 Deletig a node with a given value
struct Node* delAtValue(struct Node*head,int value){
    if (head!=NULL && head->data==value)
    {
        struct Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct Node*prev=head;
    while (prev->next!=NULL && prev->next->data!=value)
    {
        prev=prev->next;
    }
    if(prev->next==NULL){
        printf("Value NOt Found!");
    }
    struct Node*del=prev->next;
    prev->next=del->next;
    free(del);
    return head;
    
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 43;
    head->next = second;
    second->data = 56;
    second->next = third;
    third->data = 76;
    third->next = fourth;
    fourth->data = 23;
    fourth->next = NULL;
    printf("Linked List before deletion.\n");
    Traverse(head);
    // printf("Linked List after deleting first node.\n");
    // head=deleteFirstNode(head);
    // Traverse(head);
    // printf("Deleting a node at a position\n");
    // head = deleteAtPosition(head, 5);
    // Traverse(head);
    // printf("Deleting last node\n");
    // head = delLastNode(head);
    // Traverse(head);
    printf("Deleting at a value\n");
    head = delAtValue(head,56);
    Traverse(head);
    return 0;
}