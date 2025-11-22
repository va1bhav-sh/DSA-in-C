#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// BFS Traversal (Level Order)
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    // Simple static queue
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {

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

    printf("BFS Traversal (Level Order): ");
    levelOrder(root);

    printf("\n");

    return 0;
}
