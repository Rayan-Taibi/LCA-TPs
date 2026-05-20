#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct BinaryTreeInt 
{
    int data;
    struct BinaryTreeInt *left;
    struct BinaryTreeInt *right;
} BinaryTreeInt;

// Fonctions de manipulation (Questions 1, 2, 3)
BinaryTreeInt *BinaryTreeInt_createNode(int val);
void BinaryTreeInt_delete(BinaryTreeInt *root);

void BinaryTreeInt_printPrefixe(const BinaryTreeInt *root);
void BinaryTreeInt_printInfixe(const BinaryTreeInt *root);
void BinaryTreeInt_printPostfixe(const BinaryTreeInt *root);
void BinaryTreeInt_printLargeur(const BinaryTreeInt *root);

#endif