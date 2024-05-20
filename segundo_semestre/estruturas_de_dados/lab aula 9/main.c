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
    int codigo;

    do
    {
        printf("\n -------- Menu de Opcoes (lista Circular) ----------\n");
        printf("1. Inserir \n");
        printf("2. Exclusao por Codigo \n");
        printf("3. Mostrar a Lista Completa Reversa \n");
        printf("4. Mostrar a Lista Completa \n");
        printf("5. Destruir a Lista \n");
        printf("0. Sair do Menu \n");
        printf("Sua opcao: ");
        scanf("%d", &codigo);
        getchar();
        
        switch(codigo)
        {
            case 1:
                inserir(&iterador);
                printf("\nProduto inserido!\n");
                break;
            case 2:
                if(remover(&iterador))
                    printf("\nProduto removido com sucesso!\n");
                else
                    printf("\nNao foi achado este Produto\n");
                break;
            case 3:
                exibeListaContrario(iterador);
                break;
            case 4:
                exibeLista(iterador);
                break;
            case 5:
                destruirLista(&iterador);
                printf("\nLista destruida.\n");
                break;
            default:
                printf("\nFinalizando sistema! \n");
        }
    }while (codigo != 0);

}
