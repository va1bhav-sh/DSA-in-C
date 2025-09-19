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
    printf("\n");
}
// Case 1 Delete at first
struct Node *delAtFirst(struct Node *head)
{
    // If list is empty, nothing to delete
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    // Case A: If there is only one node
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    // Case B: More than one node
    struct Node *temp = head; // temp points to the node we want to delete (current head)
    struct Node *ptr = head;  // ptr will be used to find the last node

    // Traverse till the last node (last node points back to head)
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    // Now ptr is at the last node
    ptr->next = head->next; // last node should point to new head
    head = head->next;      // move head to next node
    free(temp);             // delete old head

    return head; // return new head
}
// Case 2 Delete last node
struct Node *delAtLast(struct Node *head)
{
    // If list is empty, nothing to delete
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    // Case A: If there is only one node
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *prev = head;
    while (prev->next->next != head)
    {
        prev = prev->next;
    }
//We must store the last node in a temp pointer before freeing it.
    struct Node *last = prev->next; // last node (to delete)
    prev->next = head;              // second-last node should now point to head
    free(last);                     // free last node
    return head;
}
//Case 3 delete at specific node
struct Node *delAtNode(struct Node *head,struct Node*delNode)

{
     // Case 0: Empty list
    if (head == NULL || delNode == NULL) {
        printf("List is empty or invalid node!\n");
        return head;
    }
    struct Node*prev=head;
    while (prev->next!=delNode &&prev->next!=head)
    {
        prev=prev->next;
    }
      if (prev->next == delNode) {
        prev->next = delNode->next;
        free(delNode);
    } else {
        printf("Node not found in the list!\n");
    }
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
    //Case 1
    // head=delAtFirst(head);
    // cllTraversal(head);
    //Case 2
   // head=delAtLast(head);
    // cllTraversal(head);
    
    //Case 3
    head=delAtNode(head,second);
     cllTraversal(head);
    return 0;
}