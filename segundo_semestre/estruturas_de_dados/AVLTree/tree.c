#include "tree.h"


Tree* insertAVL(Tree *root, int info, int *done)
{
    if (root == NULL)
    {
        root = malloc(sizeof(Tree));
        root->key = info;
        root->left = NULL;
        root->right = NULL;
        root->factor = 0;
        *done = 1;
    }
    else if (info < root->key)
    {
        root->left = insertAVL(root->left, info, done);
        if(*done)
        {
            switch(root->factor)
            {
                case -1:
                    root->factor = 0;
                    *done = 0;
                    break;

                case 0:
                    root->factor = 1;
                    break;

                case 1:
                    root = case1(root, done);
                    break;
            }
        }
    }
    else
    {
        root->right = insertAVL(root->right, info, done);
        
        if(*done)
        {
            switch(root->factor)
            {
                case 1:
                    root->factor = 0;
                    *done = 0;
                    break;
                case 0:
                    root->factor = -1;
                    break;
                case -1:
                    root = case2(root, done);
                    break;
            }
        }
    }

    return root;
}


Tree* delete(Tree* root, int info )
{
    Tree* aux;

    if( root == NULL )
        printf( "Elemento nao encontrado.\n" );
    else if( info < root->key ) 
        root->left = delete(root->left, info);
    else if( info > root->key ) 
        root->right = delete(root->right, info);
    else 
        if( root->left && root->right ) /* o elemento tem as 2 subarvores */
        {
            /* substitui pelo maior valor da subárvore esquerda */
            aux = greater( root->left );
            root->key = aux->key;
            root->left = delete( root->left, root->key );
        }
        else /* uma ou nenhuma sub-árvore */
        {
            aux = root;
            if( root->left == NULL ) /* substitui pelo filho right -- se não tiver filhos, substitui por NULL*/
                root = root->right;
            else if( root->right == NULL )
                root = root->left; /*substitui pelo filho esq*/
            free( aux );
        }

    return root;
}

Tree* rotateRight(Tree *root)
{
    Tree *aux;

    aux = root->left;
    root->left = aux->right;
    aux->right = root;
    root->factor = 0;
    root = aux;
    return root;
}

Tree* rotateLeft(Tree *root)
{
    Tree *aux;

    aux = root->right;
    root->right = aux->left;
    aux->left = root;
    root->factor = 0;
    root = aux;
    return aux;
}

Tree* doubleRotateRight(Tree *root)
{
    Tree *son, *grandson;

    son = root->left;
    grandson = son->right;
    son->right = grandson->left;
    grandson->left = son;
    root->left = grandson->right;
    grandson->right = root;

    if(grandson->factor == 1)
        root->factor = -1;
    else   
        root->factor = 0;

    if(grandson->factor == -1)
        son->factor = 1;
    else
        son->factor = 0;
    
    root = grandson;

    return root;
}

Tree* doubleRotateLeft(Tree *root)
{
    Tree *son, *grandson;

    son = root->right;
    grandson = son->left;
    son->left = grandson->right;
    grandson->right = son;
    root->right = grandson->left;
    grandson->left = root;

    if(grandson->factor == -1)
        root->factor = 1;
    else
        root->factor = 0;

    if(grandson->factor == 1)
        son->factor = -1;
    else
        son->factor = 0;

    root = grandson;

    return root;
}


void preFixedLeft(Tree *root, int nivel)
{
    int i;

    if(root != NULL)
    {
        for(i = 0; i < nivel; i++)
        {
            printf("=");
            fflush(stdout);
        }
        printf("%d \n", root->key);
        preFixedLeft(root->left, nivel + 1);
        preFixedLeft(root->right,nivel + 1);
    }
}

void centralLeft(Tree *root, int nivel)
{
    int i;

    if(root != NULL)
    {
        for(i = 0; i < nivel; i++)
        {
            printf("=");
            fflush(stdout);
        }
        centralLeft(root->left, nivel + 1);
        printf("%c \n", root->key);
        centralLeft(root->right, nivel + 1);
    }
}

void postFixedLeft(Tree *root, int nivel)
{
    int i;

    if(root != NULL)
    {
        for(i = 0; i < nivel; i++)
        {
            printf("=");
            fflush(stdout);
        }
        postFixedLeft(root->left, nivel + 1);
        postFixedLeft(root->right, nivel + 1);
        printf("%c \n", root->key);
    }
}

void preFixedRight(Tree *root, int nivel)
{
    int i;

    if(root != NULL)
    {
        for(i = 0; i < nivel; i++)
        {
            printf("=");
            fflush(stdout);
        }
        printf("%d \n", root->key);
        preFixedRight(root->right, nivel + 1);
        preFixedRight(root->left, nivel + 1);
    }
}

void centralRight(Tree *root, int nivel)
{
    int i;

    if(root != NULL)
    {
        for(i = 0; i < nivel; i++)
        {
            printf("=");
            fflush(stdout);
        }
        centralRight(root->right, nivel + 1);
        printf("%c \n", root->key);
        centralRight(root->left, nivel + 1);
    }
}

void postFixedRight(Tree *root, int nivel)
{
    int i;

    if(root != NULL)
    {
        for(i = 0; i < nivel; i++)
        {
            printf("=");
            fflush(stdout);
        }
        postFixedRight(root->right, nivel + 1);
        postFixedRight(root->left, nivel + 1);
        printf("%c \n", root->key);
    }
}



Tree* case1(Tree *root, int *done)
{
    Tree *son;

    son = root->left;
    if(son->factor == 1)
        root = rotateRight(root);
    else
        root = doubleRotateRight(root);

    root->factor = 0;
    *done = 0;
    return root;
}

Tree* case2(Tree *root, int *done)
{
    Tree *son;

    son = root->right;
    if(son->factor == -1)
        root = rotateLeft(root);
    else
        root = doubleRotateLeft(root);

    root->factor = 0;
    *done = 0;
    return root;
}


Tree* greater( Tree* root)
{
    if( root != NULL )
        while( root->right != NULL )
            root =root->right;

        return root;
}


int balanceFactor(Tree *root)
{
    int factor, leftFactor, rightFactor;

    if(root == NULL)
        return 0;
    else
    {
        leftFactor = balanceFactor(root->left);
        rightFactor = balanceFactor(root->right);

        factor = height(root->left) - height(root->right);
        if(factor < 0)
            factor = factor * -1;

        if(factor > rightFactor && factor > leftFactor)
            return factor;
        else if(rightFactor > leftFactor)
            return rightFactor;
        else
            return leftFactor;
    }
}

int height(Tree *root)
{
    int heightRight, heightLeft;

    if(root == NULL)
        return 0;
    else
    {
        heightLeft = height(root->left);
        heightRight = height(root->right);
        if (heightLeft > heightRight)
            return (1 + heightLeft);
        else
            return (1 + heightRight);
    }
}
