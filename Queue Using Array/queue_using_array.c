#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int frontInd;
    int backInd;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->frontInd == q->backInd)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct queue *q)
{
    if (q->backInd == q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow!");
    }
    else
    {
        q->backInd++;
        q->arr[q->backInd] = value;
        printf("Enqueued:%d\n", value);
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!");
        return -1;
    }
    else
    {
        q->frontInd++;
        int val = q->arr[q->frontInd];
        printf("Dequeued:%d\n", val);
        return val;
    }
}

void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return; // stop further execution
    }
    printf("Queue elements:\n");
    for (int i = q->frontInd + 1; i <= q->backInd; i++)
    {
        printf("%d", q->arr[i]);
        printf("\n");
    }
}

int main()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->frontInd = q->backInd = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 15);
    enqueue(q, 56);
    enqueue(q, 23);
    dequeue(q);
    display(q);
    free(q->arr);
    free(q);
    return 0;
}