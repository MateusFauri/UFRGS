#include "tree.h"

void initTree(Tree **tree, int info)
{
    *tree = malloc(sizeof(Tree));
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    (*tree)->key = info;
    (*tree)->factor = 0;
    (*tree)->color = 'R';
}


Tree* insertRB(Tree *root, int info)
{

    if(root == NULL)
        initTree(&root, info);
    else
        if(info < root->key)
        {
            root->left = insert(root->left, info);
        }
        else if (info == root->key)
            printf("Key already exist! \n");
        else
            root->right = insert(root->right, info);

    return root;
}

void changeColors(Tree *root, int height)
{
    if(height == 1)
        root->color = 'B';
    else if(height > 2)
    {

    }
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
    root->left = grandson->left;
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
