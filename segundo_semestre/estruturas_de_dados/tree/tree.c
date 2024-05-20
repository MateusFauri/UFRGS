#include "tree.h"

void initTree(Tree **tree, int info)
{
    *tree = malloc(sizeof(Tree));
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    (*tree)->key = info;
}


Tree* insert(Tree *root, int info)
{
    if(root == NULL)
        initTree(&root, info);
    else
        if(info < root->key)
            root->left = insert(root->left, info);
        else if (info == root->key)
            printf("Key already exist! \n");
        else
            root->right = insert(root->right, info);

    return root;
}

Tree* delete(Tree *root, int infoDelete, int *change)
{
    Tree *aux, *aux2;
    int *done;
    int height_root;

    *done = 0;

    if(root != NULL)
    {
        if(root->key == infoDelete)
        {
            height_root = height(root);

            if(height_root == 1)
                *change = 1;
            else if(height_root != 1 && (root->left == NULL || root->right == NULL))
                *change = 2;
            else
                *change = 3;

            printf("Chegou aqui!!! %d \n", root->key);
            return root;
        }
        else if(root->key > infoDelete)
            delete(root->left, infoDelete, change);
        else
            delete(root->right, infoDelete, change);

        printf("Change %d \n", *change);
        if(*change != 0)
        {
            printf("Enter in change, with change %d \n", *change);
            switch(*change)
            {
                printf("Here!\n");
                case 1:
                    aux2 = root->left;
                    if(aux2->key == infoDelete)
                    {
                        free(root->left);
                        root->left = NULL;
                    }
                    else
                    {
                        aux2 = root->right;
                        free(root->right);
                        root->right = NULL;
                    }
                    break;

                case 2:
                    aux = root->left;
                    if(aux->key == infoDelete)
                    {
                        if(aux->left != NULL)
                        {
                            root->left = aux->left;
                            free(aux);
                        }
                        else if(aux->right != NULL)
                        {
                            root->left = aux->right;
                            free(aux);
                        }
                    }
                    else 
                    {
                        aux=root->right;

                        if(aux->left != NULL)
                        {
                            root->right = aux->left;
                            free(aux);
                        }
                        else if(aux->right != NULL)
                        {
                            root->right = aux->right;
                            free(aux);
                        }
                    }
                    break;

                case 3:
                    aux = root->left;
                    if(aux->key != infoDelete)
                        aux = root->right;

                    aux2 = aux->left;
                    aux2 = graterRootLeft(aux2, done);

                    //aux2 agora contem o end do maior valor da subarvore a esquerda!
                    printf("Key da maior subarvore a esquerda aux2 %d \n", aux2->key);

                    if(aux == root->left)
                        root->left = aux2;
                    else
                        root->right = aux2;

                    aux2->left = aux->left;
                    aux2->right = aux->right;
                    free(aux);

                    break;

                default:
                    printf("Some error occurs! \n");
                    break;
            }
            *change = 0;
        }
    }
    else
    {
        printf("Number not fund! \n");
    }

    return root;    
}

Tree* graterRootLeft(Tree *root, int *done)
{
    Tree *temporario;
    if(root->right != NULL)
        temporario = graterRootLeft(root->right, done);
    else
    {
        temporario = root;
        *done = 1;
        return temporario;
    }

    if(*done == 1)
    {
        root->right = NULL;
        *done = 0;
    }
    
    return temporario;
}

int height(Tree *root)
{
    int height_left, height_right;

    if(root == NULL)
        return 0;
    else
    {
        height_left = height(root->left) ;
        height_right = height(root->right);

        if(height_left > height_right)
            return 1 + height_left;
        else
            return 1 + height_right;
    }
    
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


// exercicios para prova!!

int fatorArvore(Tree *root)
{
    int fatorEsquerdo, fatorDireito, fator;

    if(root == NULL)
    {
        return 0;
    }
    else
    {
        fatorEsquerdo = fatorArvore(root->left);
        fatorDireito = fatorArvore(root->right);

        fator = altura(root->left) - altura(root->right);

        if(fator > fatorEsquerdo && fator > fatorDireito)
            return fator;
        else if (fatorEsquerdo > fatorDireito)
            return fatorEsquerdo;
        else
            return fatorDireito;
    }
}

int altura(Tree *root)
{
    int alturaEsquerda, alturaDireita;

    if(root == NULL)
    {
        return 0;
    }
    else
    {
        alturaEsquerda = 1 + altura(root->left);
        alturaDireita = 1 + altura(root->right);

        if(alturaEsquerda > alturaDireita)
            return alturaEsquerda;
        else
            return alturaDireita;
    }
}