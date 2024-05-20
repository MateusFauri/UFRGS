#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NOME 50

typedef struct Produto
{
    int codigo;
    char nome[NOME];
    float preco;
}Produto;

typedef struct Nodo
{
        struct Nodo *nodoAnterior;
        Produto produto;
        struct Nodo *proximoNodo;
}Nodo;

void inserir(Nodo **nodo_inicial);

void exibeLista(Nodo *nodo_inicial);

void exibeListaContrario(Nodo *nodo_inicial);

bool remover(Nodo **nodo_inicial);

void destruirLista(Nodo **nodo_inicial);

void adicionarNovoProduto(Nodo *nodo);

#endif // FILA_H_INCLUDED
