#include <stdio.h>


typedef struct Lista
{
    int numero;
    Lista *proximo, *anterior;
}Lista;

typedef struct
{
    Lista *primeiro, *ultimo;
}Descritor;

void meioLista(Descritor *descritor)
{
    Lista *proximo, *anterior;

    proximo = descritor->ultimo;
    anterior = descritor->primeiro;
    
    if(descritor->ultimo->anterior == NULL || descritor->primeiro->proximo == NULL)
        printf("%d \n", proximo->numero);
    else
    {
        while(anterior->proximo != proximo->anterior)
        {
            if(anterior->proximo == proximo->anterior->anterior)
            {
                printf("%d",anterior->proximo->numero);
                anterior->proximo = proximo->anterior;
            }
            else
            {
                anterior = anterior->proximo;
                proximo = proximo->anterior;
            }
        }
    }
    
}