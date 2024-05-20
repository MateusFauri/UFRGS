#include "fila.h"


void inserir(Nodo **nodo_inicial)
{
    Produto produto;
    Nodo *novo_nodo, *iterador, *iteradorAuxiliar;
    bool adicionado;

    iterador = *nodo_inicial;
    adicionado = false;

    novo_nodo = malloc(sizeof(Nodo));
    adicionarNovoProduto(novo_nodo);

    if(iterador == NULL)
    {
        *nodo_inicial = novo_nodo;
	novo_nodo->proximoNodo = NULL;
    }
    else
    {
	if(novo_nodo->produto.codigo < iterador->produto.codigo)
	{
		*nodo_inicial = novo_nodo;
		novo_nodo->proximoNodo = iterador;
	}
	else
	{
		iteradorAuxiliar = iterador->proximoNodo;

		while(iteradorAuxiliar != NULL && !adicionado)
		{
			if(novo_nodo->produto.codigo < iteradorAuxiliar->produto.codigo)
			{
				novo_nodo->proximoNodo = iteradorAuxiliar;
				iterador->proximoNodo = novo_nodo;
				
			    	adicionado = true;
			}
			else
			{
				iterador = iteradorAuxiliar;
				iteradorAuxiliar = iteradorAuxiliar->proximoNodo;
			}
		}

		if(!adicionado)
		{
			iterador->proximoNodo = novo_nodo;
			novo_nodo->proximoNodo = NULL;
		}
	}
    }

}


void exibeLista(Nodo *nodo_inicial)
{
    Nodo *iterador = nodo_inicial;

    printf("\n -----------Exibir Lista---------------- \n");

    while(iterador != NULL)
    {
        printf("Codigo do produto: %d \n", iterador->produto.codigo);
        printf("Nome do produto: %s \n", iterador->produto.nome);
        printf("Preco do produto: %.2f \n \n", iterador->produto.preco);

        iterador = iterador->proximoNodo;
    }

}

void consulta(Nodo *nodo_inicial)
{
    Nodo *iterador = nodo_inicial;
    char nome[NOME];

    printf("Digite o nome do produto: ");
    gets(nome);

    while(iterador != NULL)
    {
        if (strcmp(nome, iterador->produto.nome) == 0) 
            printf("--> %s \n", iterador->produto.nome);
        iterador = iterador->proximoNodo;
    }

}

bool remover(Nodo **nodo_inicial)
{
    Nodo *iteradorAuxiliar, *iterador;
    int codigo;
    bool removido = false;

    iterador = *nodo_inicial;
    iteradorAuxiliar = iterador;
    
    printf("Digite o nome do filme que deseja remover: ");
    scanf("%d",&codigo);

    if(codigo == iterador->produto.codigo)
    {
        if(iterador->proximoNodo != NULL)
            *nodo_inicial = iterador->proximoNodo;

        free(iterador);
        removido = true;
    }
    
    iteradorAuxiliar = iterador->proximoNodo;

    while(iteradorAuxiliar != NULL || removido == false)
    {

        if(codigo == iterador->produto.codigo)
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
