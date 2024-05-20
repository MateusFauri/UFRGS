#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack* stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    imprimeStack(stack);

    pop(&stack);
    printf("%d \n", consulta(stack));


    return 0;
}