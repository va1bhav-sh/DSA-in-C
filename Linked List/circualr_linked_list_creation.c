#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
// Function to traverse a circular linked list
void cllTraversal(struct Node*head){
    if (head==NULL)
    {
        printf("The list is empty");
        return;
    }
    
    struct Node*temp=head;
    do
    {
        printf("Element=%d\n",temp->data);
        temp=temp->next;
    } while (temp!=head);
   
}

int main(){
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=3;
    second->next=third;
    third->data=6;
    third->next=fourth;
    fourth->data=8;
    fourth->next=head;
   cllTraversal(head);

    return 0;
}