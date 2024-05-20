#include <stdio.h>
#include "fila.h"

void menu(Nodo *iterador);

int main(void)
{
    Nodo *iterador = NULL;
    
    menu(iterador);

    return 0;
}

void menu(Nodo *iterador)
{
    Nodo **iteradorPtr;
    int codigo;

    do
    {
        printf("\n -------- Menu de Opcoes ----------\n");
        printf("1. Inserir \n");
        printf("2. Exclusao por Codigo \n");
        printf("3. Consulta por Nome de Produto \n");
        printf("4. Mostrar a Lista Completa \n");
        printf("0. Sair do Menu \n");
        printf("Sua opcao: ");
        scanf("%d", &codigo);
        getchar();
        
        iteradorPtr = &iterador;

        switch(codigo)
        {
            case 1:
                inserir(iteradorPtr);
                printf("\nProduto inserido!\n");
                break;
            case 2:
                if(remover(iteradorPtr))
                    printf("\nProduto removido com sucesso!\n");
                else
                    printf("\nNao foi achado este Produto");
                break;
            case 3:
                consulta(iterador);
                break;
            case 4:
                exibeLista(iterador);
                break;
            default:
                printf("\nFinalizando sistema! \n");
        }
    }while (codigo != 0);

}
