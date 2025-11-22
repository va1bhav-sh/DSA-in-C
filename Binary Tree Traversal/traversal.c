#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};

//Create a new node
struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void preorder(struct Node*root){
    if (root ==NULL)
    {
        return;
    }
    else{
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }   
}
void inorder(struct Node*root){
    if (root ==NULL)
    {
        return;
    }
    else{
    inorder(root->left);       
    printf("%d ", root->data);  
    inorder(root->right);  
    }   
}
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);      
    postorder(root->right);  
    printf("%d", root->data);  
}
int main(){
       /*
            1
          /   \
         2     3
        / \
       4   5
    */
    struct Node* root = createNode(1);
    root->left  = createNode(2);
    root->right = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder (LNR): ");
    preorder(root);
    printf("\n");

    printf("Preorder (NLR): ");
    preorder(root);
    printf("\n");

    printf("Postorder (LRN): ");
    postorder(root);
    return 0;
}