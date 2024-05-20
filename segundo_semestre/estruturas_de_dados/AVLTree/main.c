#include <stdio.h>
#include "tree.h"

int main(void)
{
    Tree *root = NULL;
    Tree *root2 = NULL;
    int *done;

    *done = 0;
    // // Arvore A
    // root = insertAVL(root, 42);
    // insertAVL(root, 15);
    // insertAVL(root, 88);
    // insertAVL(root, 6);
    // insertAVL(root, 27);
    // insertAVL(root, 63);
    // insertAVL(root, 94);
    // insertAVL(root, 20);
    // insertAVL(root, 57);
    // insertAVL(root, 71);

    // preFixedLeft(root, 0);
    // printf("Fator da Arvore: %d \n", balanceFactor(root));
 
    // Arvore B
    root2 = insertAVL(root2, 42, done);
    preFixedLeft(root2, 0);

    printf("Adicionando novo nodo....\n");
    root2 = insertAVL(root2, 15, done);
    preFixedLeft(root2, 0);

    printf("Adicionando novo nodo....\n");
    root2 = insertAVL(root2, 27, done);
    preFixedLeft(root2, 0);

    printf("Adicionando novo nodo....\n");
    root2 = insertAVL(root2, 20, done);
    preFixedLeft(root2, 0);

    printf("Removendo um nodo....\n");
    root2 = delete(root2, 27);
    preFixedLeft(root2, 0);
    
    printf("Removendo um nodo....\n");
    root2 = delete(root2, 20);
    preFixedLeft(root2, 0);

    printf("Removendo um nodo....\n");
    root2 = delete(root2, 15);
    preFixedLeft(root2, 0);

    printf("Fator da Arvore 2: %d \n", balanceFactor(root2));

    return 0;
}