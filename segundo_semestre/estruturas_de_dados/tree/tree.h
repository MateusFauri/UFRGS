#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

// Binary Tree 
typedef struct
{
    int key;
    int factor;
    struct Tree *left;
    struct Tree *right;
}Tree;


void initTree(Tree **tree, int info);

Tree* insert(Tree *root, int info);

Tree* delete(Tree *root, int infoDelete, int *change);


Tree* graterRootLeft(Tree *root, int *done);
int balanceFactor(Tree *root);
int height(Tree *root);

//paths through the tree

void preFixedLeft(Tree *root, int nivel);
void centralLeft(Tree *root, int nivel);
void postFixedLeft(Tree *root, int nivel);
void preFixedRight(Tree *root, int nivel);
void centralRight(Tree *root, int nivel);
void postFixedRight(Tree *root, int nivel);

// four types of rotate tree

Tree* rotateRight(Tree *root);
Tree* rotateLeft(Tree *root);
Tree* doubleRotateRight(Tree *root);
Tree* doubleRotateLeft(Tree *root);

// exercicios prova
int fatorArvore(Tree *root);
int fator(Tree *root);
int altura(Tree *root);

#endif