#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NOME 50

typedef struct
{
    char diretor[NOME];
    char nome[NOME];
}Filme;

typedef struct
{
        Filme filme;
        struct Nodo *proximoNodo;
}Nodo;

Nodo* inserirInicio(Nodo *nodo_inicial);

void inserirFinal(Nodo **nodo_inicial);

void exibeLista(Nodo *nodo_inicial);

void consulta(Nodo *nodo_inicial);

bool remover(Nodo **nodo_inicial);

void destruir(Nodo *nodo_inicial);

int tamanhoLista(Nodo *nodo);

#endif // FILA_H_INCLUDED
