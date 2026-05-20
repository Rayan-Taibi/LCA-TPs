#include "binary_tree.h"
#include "queue.h" // Inclusion de la file de l'exercice 2

BinaryTreeInt *BinaryTreeInt_createNode(int val)
{
    BinaryTreeInt *node = (BinaryTreeInt *)malloc(sizeof(BinaryTreeInt));
    if (node != NULL)
    {
        node->data = val;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void BinaryTreeInt_delete(BinaryTreeInt *root)
{
    if (root == NULL) return;
    BinaryTreeInt_delete(root->left);
    BinaryTreeInt_delete(root->right);
    free(root);
}

// Question 2 : Parcours Préfixe (Racine -> Gauche -> Droite)
void BinaryTreeInt_printPrefixe(const BinaryTreeInt *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    BinaryTreeInt_printPrefixe(root->left);
    BinaryTreeInt_printPrefixe(root->right);
}

// Question 2 : Parcours Infixe (Gauche -> Racine -> Droite)
void BinaryTreeInt_printInfixe(const BinaryTreeInt *root)
{
    if (root == NULL) return;
    BinaryTreeInt_printInfixe(root->left);
    printf("%d ", root->data);
    BinaryTreeInt_printInfixe(root->right);
}

// Question 2 : Parcours Postfixe (Gauche -> Droite -> Racine)
void BinaryTreeInt_printPostfixe(const BinaryTreeInt *root)
{
    if (root == NULL) return;
    BinaryTreeInt_printPostfixe(root->left);
    BinaryTreeInt_printPostfixe(root->right);
    printf("%d ", root->data);
}

// Fonction de callback requise pour instancier la file générique lors du parcours en largeur
static void printNodeCallback(const void *ptr)
{
    const BinaryTreeInt *node = (const BinaryTreeInt *)ptr;
    printf("%d ", node->data);
}

// Question 3 : Parcours en largeur en utilisant la file générique
void BinaryTreeInt_printLargeur(const BinaryTreeInt *root)
{
    if (root == NULL) return;

    // On passe le callback d'affichage à la création de la file
    Queue *q = Queue_create(printNodeCallback);
    if (q == NULL) return;

    // On enfile la racine (on transtype le const pour correspondre au void* de la file)
    Queue_enqueue(q, (void *)root);

    while (!Queue_isEmpty(q))
    {
        BinaryTreeInt *current = (BinaryTreeInt *)Queue_dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            Queue_enqueue(q, current->left);
        }
        if (current->right != NULL)
        {
            Queue_enqueue(q, current->right);
        }
    }
    printf("\n");

    Queue_delete(q); // Nettoyage de la structure de contrôle de la file
}