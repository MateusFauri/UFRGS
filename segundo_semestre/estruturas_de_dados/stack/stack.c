#include "stack.h"

int stackVazia(Stack *stack)
{
	if(stack == NULL)
		return 1;
	return 0;
}

void push(Stack** ponteiroStack, int dado)
{
	Stack* itemStack;
	
	itemStack = malloc(sizeof(Stack));

	if(stackVazia(*ponteiroStack))
		itemStack->anteriorStack = NULL;
	else
		itemStack->anteriorStack = *ponteiroStack;

	itemStack->dado = dado;
	
	*ponteiroStack = itemStack;
	
	printf("Novo item adicionado a pilha! \n");
}

void pop(Stack** ponteiroStack)
{
	Stack* auxiliar;
	
	auxiliar = *ponteiroStack;
	*ponteiroStack = (*ponteiroStack)->anteriorStack;
	
	free(auxiliar);
	printf("Item removido da pilha! \n");
}

int consulta(Stack* stack)
{
	return stack->dado;
}

void destroiStack(Stack** ponteiroStack)
{
	while (ponteiroStack != NULL)
		pop(ponteiroStack);
	
	printf("Pilha destruida! \n");
}

void imprimeStack(Stack* stack)
{
	while(stack != NULL)
	{
		printf("%d \n", stack->dado);
		stack = stack->anteriorStack;
	}
}