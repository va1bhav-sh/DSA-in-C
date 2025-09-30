#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
// Fucntion to check stack is empty.
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // true
    }
    return 0; // false
}
// Function to check to stack is full.
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // true
    }
    return 0; // false
}
// Push operation
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow Cannot Push!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d pushed to stack\n", value);
    }
}
// Pop Operation
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack Underflow");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
// Peek to look at the top element
int peek(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty.");
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}
// Peek at a particular postion
int peekAtPos(struct stack *ptr, int pos)
{
    int index = ptr->top - pos + 1;
    if (index < 0)
    {
        printf("Invalid Positon!");
        return -1;
    }
    else
    {
        return ptr->arr[index];
    }
}
// Display
void display(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty! ");
    }
    else
    {
        printf("Stack (top->bottom):");
        for (int i = 0; i < ptr->top; i++)
        {
            printf("%d", ptr->arr[i]);
            printf("\n");
        }
    }
}
int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // Perform stack operations
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    // printf("Popped: %d\n",pop(s));
    // printf("Popped: %d\n",pop(s));

    printf("Top element:%d\n", peek(s));
    printf("2nd element from top~:%d\n", peekAtPos(s, 2));

    // Displaying the array
    display(s);
    // Cleanup
    free(s->arr);
    free(s);
    return 0;
}