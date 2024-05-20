#include <stdio.h>
#include "lista.h"

#define TAMANHO 10


int main(void)
{
    Produto produtos[TAMANHO];
    Descritor descritor;

    inicializa(produtos, &descritor);

    if(insere(produtos, &descritor, 5))
        printf("Inserido com sucesso!\n");


    return 0;
}
