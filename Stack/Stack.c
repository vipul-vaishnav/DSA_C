#include <stdio.h>
#include <stdlib.h>

// Defining a stack
struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};

struct Stack *createStack(unsigned int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int) * stack->capacity);
    return stack;
}

void isStackFull(struct Stack *stack)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack is Full\n");
    }
}

void isStackEmpty(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is Empty\n");
    }
}

void pushStack(struct Stack *stack, int val)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        stack->arr[++stack->top] = val;
        printf("%d is pushed to stack\n", val);
    }
}

int popStack(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        return stack->arr[stack->top--];
    }
}

void stackTraverse(struct Stack *stack)
{
    for (int i = 0; i < stack->top; i++)
    {
        printf("Stack %d: %d\n", i, stack->arr[i]);
    }
}

int peek(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        return stack->arr[stack->top];
    }
}

int main(void)
{
    struct Stack *stack = createStack(10);

    pushStack(stack, 20);
    pushStack(stack, 30);
    pushStack(stack, 40);
    pushStack(stack, 50);

    stackTraverse(stack);

    int val = popStack(stack);
    printf("Popped Value: %d\n", val);

    int top = peek(stack);
    printf("Top of the stack: %d\n", top);
    return 0;
}

// A stack is a linear data structure that follows the principle of last in first out
// (LIFO). This means that the last element inserted inside the stack is removed first.

// **Push**: Add an element to the top of a stack
// **Pop**: Remove an element from the top of a stack
// **IsEmpty**: Check if the stack is empty
// **IsFull**: Check if the stack is full
// **Peek**: Get the value of the top element without removing it

// TOP pointer
// Let size = 3
// TOP == -1 (stack is empty)
// TOP == 0 (stack[0] = el1)
// TOP == 1 (stack[1] = el2)
// TOP == 2 (stack[2] = el3)
// TOP == size - 1 (stack is full)