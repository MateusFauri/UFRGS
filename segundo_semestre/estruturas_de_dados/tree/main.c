#include <stdio.h>
#include "tree.h"

int main(void)
{
    Tree *root = NULL;
    Tree *root2 = NULL;
    int *change;

    *change = 0;

    // Arvore A
    root = insert(root, 42);
    insert(root, 15);
    insert(root, 88);
    insert(root, 6);
    insert(root, 27);
    insert(root, 63);
    insert(root, 94);
    insert(root, 20);
    insert(root, 57);
    insert(root, 71);

    preFixedLeft(root, 0);
    //printf("Altura da arvore: %d \n", height(root));
    

    // printf("Removendo o nodo 27 \n");
    // delete(root, 27, change);
    //printf("Removendo o nodo 15 \n");
    //delete(root, 15, change);
    //preFixedLeft(root, 0);


    // teste para prova abaixo:
    printf("Altura da arvore: %d \n", altura(root));
    printf("Fator da arvore: %d \n", fatorArvore(root));

    return 0;
}