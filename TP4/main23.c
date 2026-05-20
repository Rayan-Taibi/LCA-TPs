#include "queue.h"
#include "binary_tree.h"
#include <stdio.h>

// Petite fonction d'affichage pour une file d'entiers simples (Exercice 2)
void printInt(const void *ptr)
{
    printf("%d -> ", *(const int *)ptr);
}

int main()
{
    // ==========================================
    // TEST EXERCICE 2 : FILE GENERIQUE
    // ==========================================
    printf("--- TEST EXERCICE 2 : FILE ---\n");
    Queue *myQueue = Queue_create(printInt);

    int v1 = 10, v2 = 20, v3 = 30;
    Queue_enqueue(myQueue, &v1);
    Queue_enqueue(myQueue, &v2);
    Queue_enqueue(myQueue, &v3);

    printf("Contenu de la file : ");
    Queue_print(myQueue); // Attendu : 10 -> 20 -> 30 -> 

    int *dq = (int *)Queue_dequeue(myQueue);
    printf("Élément défilé : %d\n", *dq); // Attendu : 10
    
    printf("File après défilage : ");
    Queue_print(myQueue); // Attendu : 20 -> 30 -> 

    Queue_delete(myQueue);

    // ==========================================
    // TEST EXERCICE 3 : ARBRE BINAIRE
    // ==========================================
    printf("\n--- TEST EXERCICE 3 : ARBRE ---\n");
    /* Construction de l'arbre suivant :
             4
            / \
           2   5
          / \
         1   3
    */
    BinaryTreeInt *root = BinaryTreeInt_createNode(4);
    root->left = BinaryTreeInt_createNode(2);
    root->right = BinaryTreeInt_createNode(5);
    root->left->left = BinaryTreeInt_createNode(1);
    root->left->right = BinaryTreeInt_createNode(3);

    printf("Parcours Préfixe  : ");
    BinaryTreeInt_printPrefixe(root);  // Attendu : 4 2 1 3 5 
    printf("\n");

    printf("Parcours Infixe   : ");
    BinaryTreeInt_printInfixe(root);   // Attendu : 1 2 3 4 5 
    printf("\n");

    printf("Parcours Postfixe : ");
    BinaryTreeInt_printPostfixe(root); // Attendu : 1 3 2 5 4 
    printf("\n");

    printf("Parcours Largeur  : ");
    BinaryTreeInt_printLargeur(root);  // Attendu : 4 2 5 1 3 

    BinaryTreeInt_delete(root);
    return 0;
}