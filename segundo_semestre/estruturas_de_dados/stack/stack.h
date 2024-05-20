#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
	int dado;
	struct Stack* anteriorStack;
}Stack;


int stackVazia(Stack *stack);

void push(Stack** ponteiroStack, int dado);

void pop(Stack** ponteiroStack);

int consulta(Stack* stack);

void destroiStack(Stack** ponteiroStack);

void imprimeStack(Stack* stack);


#endif