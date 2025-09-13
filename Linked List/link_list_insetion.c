#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void Traverese(struct Node *ptr)
{ // Pass the head node
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("Traversing Completed\n");
}
// CASE 1 Insert at begininng
//  struct Node* (before the function name).This means the function will return a pointer to a struct Node.
struct Node *insertAtBeginning(struct Node *head, int value)
{
    // Step 0: Declare a new pointer
    struct Node *ptr;
    // Step 1: Create a new node in heap memory
    ptr = (struct Node *)malloc(sizeof(struct Node));
    // Step 2: Assign value to data field
    ptr->data = value;
    // Step 3: Point new node’s next to the current head
    ptr->next = head;
    // Step 4: Return new node as the new head
    return ptr;
}
// CASE 2 INsert in between at a given position
struct Node *insertAtPosition(struct Node *head, int value, int position)
{
    // Step 1: Create a new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    // Step 2: If inserting at beginning
    while (position == 1)
    {
        ptr->next = head;
        return ptr;
    }
    // Step 3: Traverse to (pos-1)-th node
    struct Node *temp = head; // temp will be our “traveller pointer” to move through the nodes.
 //     In a linked list, head is the pointer that always stores the address of the first node.
 // If we lose head, we lose access to the entire list. so we cretad a temp one
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next; // Traversing the head till the pos-1
    }
    // If position is invalid (greater than list length+1)
    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(ptr);
        return head;
    }
    // Step 4: Adjust links
    ptr->next = temp->next;
    temp->next = ptr;

    return head;
}
//Case 3
struct Node* insertAtEnd(struct Node *head, int value){
 struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
 // Step 1: Create new node
    ptr->data = value;
  
    
    // Step 2: If list is empty
    if (head==NULL)
    {
        return ptr;
    }
    // Step 3: Traverse to last node
    struct Node*temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
      ptr->next = NULL;
      return head;
    
    
}
//Case 4
struct Node* insertAfterValue(struct Node *head,int value, int aftervalue){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
     ptr->data = value;
     struct Node*temp=head;
     while (temp!=NULL&&temp->data !=aftervalue)
     {
        temp=temp->next;
     }
    // If afterValue not found
    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", aftervalue);
        free(ptr);
        return head;
    }
     ptr->next=temp->next;
     temp->next=ptr;
     return head;
}
int main()
{
    // Declare four pointers of sturct node type thes will store address of the nodes of the linked list
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Alloacting memory for those four pointes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // Linking each node
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = fourth;
    fourth->data = 66;
    fourth->next = NULL;
printf("Linked list before insertion\n");
    Traverese(head);
    // printf("Case 1\n");
    // head = insertAtBeginning(head, 55); // This fn is returning a new head
    // Traverese(head); 
    // printf("Case 2\n");
    // head=insertAtPosition(head,56,3);
    // Traverese(head);
    //     printf("case3\n");
    // head=insertAtEnd(head,67);
    // Traverese(head);
printf("case4\n");
head=insertAfterValue(head,78,41);
Traverese(head);
    return 0;
}