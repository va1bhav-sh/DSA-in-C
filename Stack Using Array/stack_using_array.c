#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
//Fucntion to check stack is empty.
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // true
    }
    return 0; // false
}
//Function to check to stack is full.
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
    //Implementation without pointer
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int*) malloc(sizeof(struct stack));
    //Implementation by pointer to struct
    // Here, the stack s is a pointer to struct stack.The struct itself is allocated in heap memory.This makes the stack dynamic and can be easily passed to functions without copying the entire struct.
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    //Manully pushing
    s->arr[0]=7;
    s->top++;
    s->arr[1]=17;
    s->top++;
    s->arr[2]=27;
    s->top++;
    s->arr[3]=47;
    s->top++;
    s->arr[4]=57;
    s->top++;
    s->arr[5]=67;
    s->top++;

    //Chcek isf stack is full
    if (isFull(s))//Here, s itself is already a pointer to a struct.So it does not need &s.
    {
        printf("Stack is full.\n");
    }
    else
    {
        printf("Stack is not full.\n");
    }

    return 0;
}
