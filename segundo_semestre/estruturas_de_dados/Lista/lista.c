#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include "lista.h"


void inicializa(Produto produtos[], Descritor *descritor)
{
    int iterador;

    for(iterador=0; iterador < TAMANHO; iterador++)
    {
        strcpy(produtos[iterador].nome, "");
        produtos[iterador].codigo = 0;
        produtos[iterador].preco = 0.0;
    }

    descritor->inicio = -1;
    descritor->fim = -1;
    descritor->tamanho = 0;

    printf("Lista Inicializada!\n");
}


int consulta(Produto produtos[], Descritor *descritor, int posicao)
{
    bool listaVazia = (descritor->inicio < 0) && (descritor->fim < 0);
    bool posicaoValida = (posicao >= descritor->inicio) && (posicao <= descritor->fim);

    if( !listaVazia && posicaoValida )
        return produtos[posicao].codigo;

    return -1;
}


int insere(Produto produtos[],Descritor *descritor, int posicao)
{
    int iterador;
    bool listaVazia = (descritor->inicio == -1) && (descritor->fim == -1);
    bool posicaoValida = (posicao >= descritor->inicio) && (posicao <= descritor->fim);
    bool deslocamentoValido = !((descritor->inicio == 0) && (descritor->fim == TAMANHO - 1));

    if(!listaVazia && posicaoValida && deslocamentoValido)
    {
        if (posicao == 0)
        {
            if(descritor->inicio != 0)
                descritor->inicio = descritor->inicio - 1;
            else
            {
                for(iterador = descritor->fim; iterador >= 0; iterador--)
                    produtos[iterador + 1] = produtos[iterador];

                descritor->fim = descritor->fim +1;
            }
        }
        else if (posicao == TAMANHO -1)
        {
            if(descritor->fim != TAMANHO - 1)
                descritor->fim = descritor->fim + 1;
            else
            {
                for(iterador = descritor->inicio ; iterador <= descritor->fim ; iterador++)
                    produtos[iterador - 1] = produtos[iterador];

                descritor->inicio = descritor->inicio - 1;
            }
        }
        else
        {
            if(descritor->fim < TAMANHO - 1)
            {
                for(iterador = descritor->fim ; iterador >= posicao; iterador--)
                    produtos[iterador + 1] = produtos[iterador];

                descritor->fim = descritor->fim + 1;
            }
            else
            {
                for(iterador = descritor->inicio ; iterador <= posicao ; iterador++)
                    produtos[iterador - 1] = produtos[iterador];

                descritor->inicio = descritor->inicio - 1;
            }
        }
    }
    else if(listaVazia)
    {
        posicao = posicao - 1;

        descritor->inicio = posicao;
        descritor->fim = posicao + 1;
    }
    else
    {
        printf("Error: Posicao Invalida!\n");
        return 0;
    }

    printf("Codigo do produto: ");
    scanf("%d", &produtos[descritor->inicio + posicao].codigo);
    printf("Nome do produto: ");
    scanf("%s", produtos[descritor->inicio + posicao].nome);
    printf("Preco do produto: ");
    scanf("%f", &produtos[descritor->inicio + posicao].preco);

    descritor->tamanho = descritor->tamanho + 1;

    return 1;
}

int remover(Produto produtos[], Descritor *descritor, int posicao)
{
    int iterador, codigoRemovido = 0;
    bool listaVazia = (descritor->inicio == -1) && (descritor->fim == -1);
    bool posicaoValida = (posicao >= descritor->inicio) && (posicao <= descritor->fim);

    if(listaVazia || !posicaoValida)
    {
        return -1;
    }

    posicao = posicao -1;

    codigoRemovido = produtos[descritor->inicio+posicao].codigo;

    for(iterador = descritor->inicio + posicao; iterador < descritor->fim; iterador++)
        produtos[iterador] = produtos[iterador + 1];

    strcpy(produtos[descritor->fim].nome, "");
    produtos[descritor->fim].codigo = 0;
    produtos[descritor->fim].preco = .0;
    descritor->fim = descritor->fim - 1;

    descritor->tamanho = descritor->tamanho - 1;


    if(descritor->fim == -1)
        descritor->inicio = -1;

    return codigoRemovido;

}

void destroi(Produto produtos[], Descritor *descritor)
{
    inicializa(produtos, descritor);
}


