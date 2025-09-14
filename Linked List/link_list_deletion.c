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
    printf("Linked List after deleting first node.\n");
    head=deleteFirstNode(head);
    Traverse(head);

    return 0;
}