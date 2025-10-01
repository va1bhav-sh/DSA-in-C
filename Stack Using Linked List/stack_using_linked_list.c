#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
// Top pointer (points to the top of the stack)
struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elememt:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *test = (struct Node *)malloc(sizeof(struct Node));
    if (test == NULL)
    {
        return 1;
    }
    free(test);
    return 0;
}

void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow!(NO MEMORY)\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements (top -> bottom): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void peek(){
  if (isEmpty())
    {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Top element:%d\n",top->data);
}

void peekAtPos(int pos){
    if (isEmpty())
    {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node*temp=top;
    int count=1;
    while(temp!=NULL && count<pos){
        temp=temp->next;
        count++;
    }
    if (temp==NULL)
    {
        printf("Invalid Position!");
        
    }else{
        printf("Element at position %d:%d\n",pos,temp->data);
    }
    
}
int main()
{
    // At this stage, stack is created but empty
    printf("Stack using Linked List created successfully!\n");

    push(10);
    push(20);
    push(30);
    push(40);
    display();
    //pop(30);
    //display();
    peek();
    peekAtPos(2);
    return 0;
}