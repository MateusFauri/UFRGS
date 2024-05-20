#include <stdio.h>
#include "tree.h"

int main(void)
{
    Tree *root = NULL;
    Tree *root2 = NULL;
    int *done = 0;

    // // Arvore A
    // root = insert(root, 42);
    // insert(root, 15);
    // insert(root, 88);
    // insert(root, 6);
    // insert(root, 27);
    // insert(root, 63);
    // insert(root, 94);
    // insert(root, 20);
    // insert(root, 57);
    // insert(root, 71);

    // preFixedLeft(root, 0);
    // printf("Fator da Arvore: %d \n", balanceFactor(root));
 
    // Arvore B
    root2 = insertAVL(root2, 42, done);
    preFixedLeft(root2, 0);

    insertAVL(root2, 15, done);
    preFixedLeft(root2, 0);

    insertAVL(root2, 27, done);
    preFixedLeft(root2, 0);

    insertAVL(root2, 20, done);
    preFixedLeft(root2, 0);

    printf("Fator da Arvore 2: %d \n", balanceFactor(root2));

    return 0;
}