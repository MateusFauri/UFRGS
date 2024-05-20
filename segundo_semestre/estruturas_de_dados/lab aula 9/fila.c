#include "fila.h"

void inserir(Nodo **nodo_inicial)
{
    Produto produto;
    Nodo *novo_nodo, *iterador, *iteradorAuxiliar;
    bool adicionado;

    adicionado = false;

    novo_nodo = malloc(sizeof(Nodo));
    adicionarNovoProduto(novo_nodo);

    if(*nodo_inicial == NULL)
    {
	    novo_nodo->proximoNodo = novo_nodo;
        novo_nodo->nodoAnterior = novo_nodo;
        *nodo_inicial = novo_nodo;
    }
    else
    {
        iteradorAuxiliar = *nodo_inicial;

        do
        {
            if(novo_nodo->produto.codigo < iteradorAuxiliar->produto.codigo)
            {
                novo_nodo->proximoNodo = iteradorAuxiliar;
                novo_nodo->nodoAnterior = iteradorAuxiliar->nodoAnterior;

                iteradorAuxiliar->nodoAnterior->proximoNodo = novo_nodo;
                iteradorAuxiliar->nodoAnterior = novo_nodo;

                if(iteradorAuxiliar == *nodo_inicial)
                    *nodo_inicial = novo_nodo;
                
                adicionado = true;
            }
            
            iteradorAuxiliar = iteradorAuxiliar->proximoNodo;
        }while(iteradorAuxiliar != *nodo_inicial && !adicionado);

        if(!adicionado)
        {
            novo_nodo->proximoNodo = iteradorAuxiliar;
            novo_nodo->nodoAnterior = iteradorAuxiliar->nodoAnterior;

            iteradorAuxiliar->nodoAnterior->proximoNodo = novo_nodo;
            iteradorAuxiliar->nodoAnterior = novo_nodo;

            adicionado = true;
        }

    }
}

void exibeLista(Nodo *nodo_inicial)
{
    Nodo *iterador = nodo_inicial;

    printf("\n -----------Exibir Lista---------------- \n");
    if(iterador != NULL)
    {
        if(iterador->proximoNodo == iterador)
        {
            printf("Codigo do produto: %d \n", iterador->produto.codigo);
            printf("Nome do produto: %s \n", iterador->produto.nome);
            printf("Preco do produto: %.2f \n \n", iterador->produto.preco);
        }
        else
            do
            {
                printf("Codigo do produto: %d \n", iterador->produto.codigo);
                printf("Nome do produto: %s \n", iterador->produto.nome);
                printf("Preco do produto: %.2f \n \n", iterador->produto.preco);

                iterador = iterador->proximoNodo;
            }while(iterador != nodo_inicial);
    }

}

void exibeListaContrario(Nodo *nodo_inicial)
{
    Nodo *iterador;

    iterador = nodo_inicial->nodoAnterior;

    printf("\n -----------Exibir Lista ao Contrario---------------- \n");
    if(iterador != NULL)
    {
        if(iterador->proximoNodo == iterador)
        {
            printf("Codigo do produto: %d \n", iterador->produto.codigo);
            printf("Nome do produto: %s \n", iterador->produto.nome);
            printf("Preco do produto: %.2f \n \n", iterador->produto.preco);
        }
        else
            do
            {
                printf("Codigo do produto: %d \n", iterador->produto.codigo);
                printf("Nome do produto: %s \n", iterador->produto.nome);
                printf("Preco do produto: %.2f \n \n", iterador->produto.preco);

                iterador = iterador->nodoAnterior;
            }while(iterador != nodo_inicial->nodoAnterior);
    }

}

bool remover(Nodo **nodo_inicial)
{
    int codigo;
    Nodo *iteradorAuxiliar = *nodo_inicial;
    
    if(*nodo_inicial != NULL)
    {
        printf("Digite o codigo do produto para remocao: ");
        scanf("%d",&codigo);

        do
        {
            if(codigo == iteradorAuxiliar->produto.codigo)
            {
                iteradorAuxiliar->proximoNodo->nodoAnterior = iteradorAuxiliar->nodoAnterior;
                iteradorAuxiliar->nodoAnterior->proximoNodo = iteradorAuxiliar->proximoNodo;

                if(iteradorAuxiliar->proximoNodo == iteradorAuxiliar && iteradorAuxiliar->nodoAnterior == iteradorAuxiliar)
                    *nodo_inicial = NULL;
                else
                    if(iteradorAuxiliar == *nodo_inicial)
                        *nodo_inicial = iteradorAuxiliar->proximoNodo;
                    

                free(iteradorAuxiliar);
                return true;
            }
            
            iteradorAuxiliar = iteradorAuxiliar->proximoNodo;
        }while(iteradorAuxiliar != *nodo_inicial);

    }
    return false;
}

void destruirLista(Nodo **nodo_inicial)
{
    Nodo *iteradorAuxiliar;

    if(*nodo_inicial != NULL)
    {
        (*nodo_inicial)->nodoAnterior->proximoNodo = NULL;
        while(*nodo_inicial != NULL)
        {   
            iteradorAuxiliar = *nodo_inicial;
            *nodo_inicial = (*nodo_inicial)->proximoNodo;
            free(iteradorAuxiliar);
        }
        free(*nodo_inicial);
    }
}

void adicionarNovoProduto(Nodo *nodo)
{
    Produto produto;

    printf("Codigo do produto: ");
    scanf("%d",&produto.codigo);
    getchar();
    printf("Nome do produto: ");
    gets(produto.nome);
    printf("Preco do produto: ");
    scanf("%f",&produto.preco);
    getchar();

    nodo->produto= produto;
}
