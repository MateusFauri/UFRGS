#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NOME 50

typedef struct
{
    int codigo;
    char nome[NOME];
    float preco;
}Produto;

typedef struct
{
        Produto produto;
        struct Nodo *proximoNodo;
}Nodo;

void inserir(Nodo **nodo_inicial);

void exibeLista(Nodo *nodo_inicial);

void consulta(Nodo *nodo_inicial);

bool remover(Nodo **nodo_inicial);

void destruir(Nodo *nodo_inicial);

void adicionarNovoFilme(Nodo *nodo);

#endif // FILA_H_INCLUDED
