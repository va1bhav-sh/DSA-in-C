#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack Definition
struct Stack
{
    int size;
    int top;
    char *arr; // char beacuse we have to make array of parenthesis
};

// Fucntion to create stack
struct Stack *createStack(int size)
{
    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (char *)malloc(s->size * (sizeof(char)));
    return s;
}

// Check is stack is empty
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

// Check is stack is full
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
// ---------- Parentheses Matching ----------
int isBalanced(char *exp)
{
    // Create a stack with size equal to length of expression
    struct Stack *stack = createStack(strlen(exp));
    char x; // Temporary variable to store popped element
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(stack))
            {
                return 0; // No matching opening → Not balanced
            }
            else
            {
                x = pop(stack); // Pop last opening bracket
            }

            // Check if popped bracket matches the current closing bracket
            if ((exp[i] == ')' && x != '(') ||
                (exp[i] == ']' && x != '[') ||
                (exp[i] == '}' && x != '{'))
            {
                return 0; // Mismatch → Not balanced
            }
        }
    }
    // After all traversal
    //  If stack is empty → Balanced, else Not balanced
    return isEmpty(stack);
}

int main()
{
    char exp[100];
    printf("Enter an expression.");
    scanf("%s", exp);
    if (isBalanced(exp))
    {
        printf("Expression is balanced.");
    }
    else
    {
        printf("Expression is not balanced");
    }

    return 0;
}