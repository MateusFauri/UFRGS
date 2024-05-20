#include "fila.h"

void adicionarNovoFilme(Nodo *nodo);

Nodo* inserirInicio(Nodo *nodo_inicial)
{
    Filme filme;
    Nodo *novo_nodo;

    novo_nodo = malloc(sizeof(Nodo));
    adicionarNovoFilme(novo_nodo);
    novo_nodo->proximoNodo = nodo_inicial;

    return novo_nodo;
}

void inserirFinal(Nodo **nodo_inicial)
{
    Nodo *novo_nodo, *iterador;

    iterador = *nodo_inicial;
        
    novo_nodo = malloc(sizeof(Nodo));
    adicionarNovoFilme(novo_nodo);
    novo_nodo->proximoNodo = NULL;

    if(iterador == NULL)
        *nodo_inicial = novo_nodo;
    else
    {
        while(iterador->proximoNodo != NULL)
            iterador = iterador->proximoNodo;
    
        iterador->proximoNodo = novo_nodo;
    }
}

void exibeLista(Nodo *nodo_inicial)
{
    Nodo *iterador = nodo_inicial;

    printf("\n -----------Exibir Lista---------------- \n");

    while(iterador != NULL)
    {
        printf("Nome do diretor: %s \n", iterador->filme.diretor);
        printf("Nome do filme: %s \n", iterador->filme.nome);
        
        iterador = iterador->proximoNodo;
    }

}

void consulta(Nodo *nodo_inicial)
{
    Nodo *iterador = nodo_inicial;
    char diretor[NOME];

    printf("Digite o nome do diretor: ");
    gets(diretor);

    printf("\n----------Lista de Filmes----------------\n");

    while(iterador != NULL)
    {
        if (strcmp(diretor, iterador->filme.diretor) == 0) 
            printf("--> %s \n", iterador->filme.nome);
        iterador = iterador->proximoNodo;
    }

}

bool remover(Nodo **nodo_inicial)
{
    Nodo *iteradorAuxiliar, *iterador;
    char filmeRemocao[NOME], diretorRemocao[NOME];
    bool diretor, filme, removido = false;

    iterador = *nodo_inicial;
    iteradorAuxiliar = iterador;
    
    printf("Digite o nome do filme que deseja remover: ");
    gets(filmeRemocao);
    printf("Digite o nome do diretor do filme: ");
    gets(diretorRemocao);

    filme = strcmp(filmeRemocao, iterador->filme.nome) == 0;
    diretor = strcmp(diretorRemocao, iterador->filme.diretor) == 0;

    if(diretor && filme)
    {
        if(iterador->proximoNodo != NULL)
            *nodo_inicial = iterador->proximoNodo;

        free(iterador);
        removido = true;
    }
    
    iteradorAuxiliar = iterador->proximoNodo;

    while(iteradorAuxiliar != NULL || removido == false)
    {
        filme = strcmp(filmeRemocao, iteradorAuxiliar->filme.nome) == 0;
        diretor = strcmp(diretorRemocao, iteradorAuxiliar->filme.diretor) == 0;

        if(diretor && filme)
        {
            if(iteradorAuxiliar->proximoNodo != NULL)
                iterador->proximoNodo = iteradorAuxiliar->proximoNodo;
            else
                iterador->proximoNodo = NULL;
            free(iteradorAuxiliar);
            removido = true;
        }
        
        iterador = iteradorAuxiliar;
        iteradorAuxiliar = iterador->proximoNodo;
    }

    return removido;
}

int tamanhoLista(Nodo *nodo)
{
    int contador = 0;
    Nodo *iterador = nodo;

    if(iterador == NULL)
        return 0;
    
    while(iterador != NULL)
    {
        contador++;
        iterador = iterador->proximoNodo;
    }

    return contador;
}


//   Funçoes auxiliares

void adicionarNovoFilme(Nodo *nodo)
{
    Filme filme;

    printf("Nome do diretor: ");
    gets(filme.diretor);
    printf("Nome do filme: ");
    gets(filme.nome);

    nodo->filme = filme;
}

