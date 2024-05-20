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

Tree* insertAVL(Tree *root, int info, int *done);
Tree* delete(Tree* root, int info );

int balanceFactor(Tree *root);
int height(Tree *root);
Tree* greater( Tree* root );
Tree* case1(Tree *root, int *done);
Tree* case2(Tree *root, int *done);
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