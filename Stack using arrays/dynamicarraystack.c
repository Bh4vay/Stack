#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    int *array;
    int capacity;
};

struct Stack *createStack(int capacity)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->capacity = capacity;
    s->array = (int *)malloc(capacity * sizeof(int));
    return s;
}

void push(struct Stack *s, int data)
{
    if (s->capacity == s->top + 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->array[s->top] = data;
    printf("%d is pushed to stack\n", data);
}
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return;
    }
    printf("%d is popped\n", s->array[s->top]);
    s->top--;
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        return INT_MIN;
    }
    return s->array[s->top];
}

int size(struct Stack *s)
{
    return s->top + 1;
}

int main()
{
    int n;
    printf("Enter the size of stack: ");
    scanf("%d", &n);
    struct Stack *stack = createStack(n);
    push(stack, 20);
    push(stack, 60);
    printf("%d is at the size of stack\n", size(stack));
    push(stack, 30);
    push(stack, 90);
    printf("%d is at the top of stack\n", peek(stack));
    push(stack, 100);
    push(stack, 200);
    printf("%d is at the size of stack\n", size(stack));
    pop(stack);
    pop(stack);
    pop(stack);
    printf("%d is at the top of stack\n", peek(stack));
    pop(stack);
    pop(stack);
    pop(stack);
    printf("%d is at the top of stack\n", peek(stack));
    printf("%d is at the size of stack\n", size(stack));
}