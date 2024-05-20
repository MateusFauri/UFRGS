#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

// Binary Tree 
typedef struct 
{
    int key;
    int factor;
    char color;
    struct Tree *left;
    struct Tree *right;
}Tree;


void initTree(Tree **tree, int info);

Tree* insertRB(Tree *root, int info);

// calculate the factor of each branch of the tree
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


#endif