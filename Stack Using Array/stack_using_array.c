#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // true
    }
    return 0; // false
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // true
    }
    return 0; // false
}

int main()
{
    // Here, the stack s is a pointer to struct stack.The struct itself is allocated in heap memory.This makes the stack dynamic and can be easily passed to functions without copying the entire struct.
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (isFull(s))
    {
        printf("Stack is full.\n");
    }
    else
    {
        printf("Stack is not full.\n");
    }

    return 0;
}
