#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    int size;
    struct node *topNode;
};

struct stack *createStack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 0;
    s->topNode = NULL;
    return s;
}

void push(struct stack *s, int data)
{
    s->size++;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = s->topNode;
    s->topNode = newNode;
    printf("%d is pushed\n", data);
}

int isEmpty(struct stack *s)
{
    return s->topNode == NULL;
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return;
    }
    s->size--;
    struct node *temp = s->topNode;
    int data = temp->data;
    s->topNode = s->topNode->next;
    free(temp);
    printf("%d is popped from stack\n", data);
}

int peek(struct stack *s)
{
    if (isEmpty(s))
    {
        return INT_MIN;
    }
    return s->topNode->data;
}

void size(struct stack *s)
{
    printf("%d is the size of stack\n", s->size);
}