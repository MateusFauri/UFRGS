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
    int codigo, tamanho;

    do
    {
        printf("\n -------- Menu de Opcoes ----------\n");
        printf("1. Inserir no Inicio \n");
        printf("2. Inserir no Fim \n");
        printf("3. Exclusao por Filme \n");
        printf("4. Consulta por Diretor \n");
        printf("5. Mostrar a Lista Completa \n");
        printf("6. Mostrar o Tamanho da Lista \n");
        printf("0. Sair do Menu \n");
        printf("Sua opcao: ");
        scanf("%d", &codigo);

        getchar();
        system("cls");
        iteradorPtr = &iterador;

        switch(codigo)
        {
            case 1:
                iterador = inserirInicio(iterador);
                printf("\nFilme inserido no incio!\n");
                break;
            case 2:
                inserirFinal(iteradorPtr);
                printf("\nFilme inserido no final!\n");
                break;
            case 3:
                if(remover(iteradorPtr))
                    printf("\nFilme removido com sucesso!\n");
                else
                    printf("\nNao foi achado este filme do diretor");
                break;
            case 4:
                consulta(iterador);
                break;
            case 5:
                exibeLista(iterador);
                break;
            case 6:
                tamanho = tamanhoLista(iterador);
                printf("O tamanho da lista e %d. \n", tamanho);
                break;
            default:
                printf("\nFinalizando sistema! \n");
        }
    }while (codigo != 0);

}