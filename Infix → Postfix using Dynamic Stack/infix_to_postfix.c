#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack
{
    int size;  // Maximum size of stack
    int top;   // Index of top element
    char *arr; // Dynamic array to store characters (operators)
};

// Create Stack in Heap (Dynamic Memory)
struct Stack *createStack(int size)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char)); // Allocate memory for array to store elements
    return s;
}
// Check if stack is empty
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check fs stack is full
int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push operation
void push(struct Stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack overflow!");
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}
// Pop operation
char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!");
        return -1;
    }
    else
    {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}
char peek(struct Stack *s)
{
    return s->arr[s->top]; // Return top element
}
// Function to return precedence of operators
int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
        return 0; // Non-operators (e.g., '(') have 0 precedence
}
void infixToPostfix(char *exp)
{
    struct Stack *s = createStack(strlen(exp));
    char result[100]; // Array to store postfix expression
    int k = 0;        // Index for result array
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i]; // Current Character
        if (isalpha(c))
        {
            result[k++] = c;
        }
        else if (c == '(')
        {
            push(s, c);
        }
        else if (c == ')')
        {
            while (!isEmpty(s) && peek(s) != '(')
            {
                result[k++] = pop(s);
            }
            pop(s); // We dont want '(' in the result
        }
        else
        {
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(c))
            {
                result[k++] = pop(s); // Pop higher or equal precedence operators from stack
               
            }
             push(s, c);           // Push current operator onto stack
        }
    }
    while (!isEmpty(s))
    {
        result[k++]=pop(s);
    }
    result[k]='\0';
    printf("Postfix:%s\n",result);
    free(s->arr);
    free(s);    
}
int main()
{
    char exp[] = "(A+B)*C-D";  
    infixToPostfix(exp);       
    return 0;
}