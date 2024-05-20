#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
	int dado;
	struct Queue* eloQueue;
}Queue;

typedef struct 
{
	struct Queue* inicial;
	struct Queue* final;
}DescritorQueue;


DescritorQueue* inicializaQueue();

int QueueVazia(DescritorQueue* Queue);

void push(DescritorQueue* ponteiroQueue, int dado);

void pop(DescritorQueue* ponteiroQueue);

int consulta(Queue* Queue);

void destroiQueue(DescritorQueue* ponteiroQueue);

void imprimeQueue(Queue* Queue);


#endif