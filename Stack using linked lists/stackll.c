#include "stackll.h"

int main()
{
    struct stack *s = createStack();
    push(s, 4);
    push(s, 87);
    push(s, 66);
    size(s);
    push(s, 97);
    printf("%d is at the top of stack\n", peek(s));
    pop(s);
    pop(s);
    printf("%d is at the top of stack\n", peek(s));
    pop(s);
    pop(s);
}