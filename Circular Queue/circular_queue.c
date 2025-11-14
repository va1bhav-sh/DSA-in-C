#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

// Function for isFull (Your function was correct)
int isFull(struct circularQueue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
        return 0;
}

// Function for isEmpty (Your function was correct)
int isEmpty(struct circularQueue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    else
        return 0;
}

// Function For Enqueue (FIXED)
void enqueue(struct circularQueue *q, int x)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        // FIX: Handle first element insertion
        if (isEmpty(q))
        {
            q->front = 0; 
        }
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
        printf("Enqueued: %d\n", x);
    }
}

// Function For Dequeue (FIXED)
int dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("This Queue is Empty\n");
        return -1; // FIX: Must return an error value
    }

    int value = q->arr[q->front];

    // if this was the last element, reset queue to empty state
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }

    printf("Dequeued: %d\n", value);
    return value;
}

// Function For Display (FIXED)
void display(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return; // stop further execution
    }
    printf("Queue elements (Front -> Rear):\n");
    
    // FIX: Corrected loop logic
    int i = q->front;
    while (1)
    {
        printf("%d", q->arr[i]);
        if (i == q->rear)
        {
            break; // Stop AFTER printing the last element
        }
        printf(", ");
        i = (i + 1) % q->size; // Update i inside the loop
    }
    printf("\n"); // Add a final newline
}

// Main function (EXPANDED for testing)
int main()
{
    struct circularQueue *q;
    q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->size = 5; // Using a smaller size to test 'full' condition
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    printf("--- Enqueuing elements ---\n");
    enqueue(q, 15);
    enqueue(q, 56);
    enqueue(q, 23);
    enqueue(q, 13);
    
    display(q); // Test display

    printf("\n--- Dequeuing elements ---\n");
    dequeue(q);
    dequeue(q);

    display(q); // Test display after dequeuing

    printf("\n--- Testing wrap-around ---\n");
    enqueue(q, 100);
    enqueue(q, 200);
    display(q);
    
    printf("\n--- Testing full queue ---\n");
    enqueue(q, 300); // Queue should now be full
    display(q);
    enqueue(q, 400); // Should print "Queue is full"

    printf("\n--- Testing empty queue ---\n");
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q); // Should print "Queue is empty"
    dequeue(q); // Should print "Queue is Empty"

    // Free allocated memory
    free(q->arr);
    free(q);

    return 0;
}