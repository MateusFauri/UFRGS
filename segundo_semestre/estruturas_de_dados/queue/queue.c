#include "queue.h"

DescritorQueue* inicializaQueue()
{
	DescritorQueue *descritor;

	descritor = malloc(sizeof(DescritorQueue));

	descritor->inicial = NULL;
	descritor->final = NULL;

	return descritor;
}

int queueVazia(DescritorQueue* queue)
{
	if(queue->final == NULL && queue->inicial == NULL)
		return 1;
	return 0;
}

void push(DescritorQueue* ponteiroQueue, int dado)
{
	Queue* itemQueue;
	
	itemQueue = malloc(sizeof(Queue));
	itemQueue->dado = dado;

	if(!queueVazia(ponteiroQueue))
		itemQueue->eloQueue = ponteiroQueue->inicial;
	else
	{
		itemQueue->eloQueue = NULL;
		ponteiroQueue->final = itemQueue;
	}

	ponteiroQueue->inicial = itemQueue;
	
	printf("Novo item adicionado a fila! \n");
}

void pop(DescritorQueue* ponteiroQueue)
{
	Queue *auxiliar;

	auxiliar = ponteiroQueue->inicial;
	if(auxiliar != NULL)
	{
		if(ponteiroQueue->inicial != ponteiroQueue->final)
		{
			while(auxiliar->eloQueue != ponteiroQueue->final)
				auxiliar = auxiliar->eloQueue;

			ponteiroQueue->final = auxiliar;

			free(auxiliar->eloQueue);
			auxiliar->eloQueue = NULL;
		}
		else
		{
			ponteiroQueue->inicial = NULL;
			ponteiroQueue->final = NULL;
			free(auxiliar);
		}

		printf("Item removido da fila! \n");
	}
	else
		printf("Não há dados para remover na fila! \n");
}

int consulta(Queue* queue)
{
	return queue->dado;
}

void destroiQueue(DescritorQueue* ponteiroQueue)
{
	while (ponteiroQueue->inicial != NULL)
		pop(ponteiroQueue);
	
	printf("Fila destruida! \n");
}

void imprimeQueue(Queue* queue)
{
	while(queue != NULL)
	{
		printf("%d \n", queue->dado);
		queue = queue->eloQueue;
	}
}