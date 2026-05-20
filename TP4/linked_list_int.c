#include "linked_list_int.h"

// Définition des structures internes (Masquées à l'utilisateur - Question 6)
struct NodeLinkedListInt 
{
    int data;
    struct NodeLinkedListInt *next;
};

struct LinkedListInt 
{
    NodeLinkedListInt *head;
};

// ==========================================
// FONCTIONS INTERNES (static)
// ==========================================

// Question 4 & 6 : Crée un nœud de manière isolée et factorisée
static NodeLinkedListInt *LinkedListInt_createNode(const int val)
{
    NodeLinkedListInt *newNode = (NodeLinkedListInt *)malloc(sizeof(NodeLinkedListInt));
    if (newNode != NULL)
    {
        newNode->data = val;
        newNode->next = NULL;
    }
    return newNode;
}

// ==========================================
// FONCTIONS DE BASE DU SQUELETTE
// ==========================================

LinkedListInt *LinkedListInt_create()
{
    LinkedListInt *list = (LinkedListInt *)malloc(sizeof(LinkedListInt));
    if (list != NULL)
    {    
        list->head = NULL;
    }
    return list;
}

void LinkedListInt_delete(LinkedListInt *const list) 
{
    if (list == NULL) return;
    LinkedListInt_clear(list);
    free(list);
}

void LinkedListInt_clear(LinkedListInt *const list)
{
    if (list == NULL) return;
    NodeLinkedListInt *node = list->head;
    NodeLinkedListInt *next = NULL;

    while (node != NULL) 
    {
        next = node->next;
        free(node);
        node = next;
    }
    list->head = NULL;
}

// Mise à jour de pushFront pour utiliser createNode (Question 4)
int LinkedListInt_pushFront(LinkedListInt *list, const int val)
{
    if (list == NULL) return -1;
    
    NodeLinkedListInt *node = LinkedListInt_createNode(val);
    if (node == NULL) return -1;
    
    node->next = list->head;
    list->head = node;

    return 0;
}

// ==========================================
// NOUVELLES FONCTIONS À IMPLÉMENTER
// ==========================================

// Question 2 : Affichage au format "79 -> 87 -> 46 -> 20 -> "
void LinkedListInt_print(const LinkedListInt *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("(liste vide)\n");
        return;
    }

    NodeLinkedListInt *current = list->head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Question 3 : Extrait et supprime l'élément en tête
int LinkedListInt_popFront(LinkedListInt *list)
{
    // Attention : Assure-toi que la liste n'est pas vide avant d'appeler
    if (list == NULL || list->head == NULL)
    {
        fprintf(stderr, "Erreur : Tentative de popFront sur une liste vide.\n");
        return -1; // Ou gestion d'erreur appropriée
    }

    NodeLinkedListInt *temp = list->head;
    int value = temp->data;

    list->head = temp->next;
    free(temp);

    return value;
}

// Question 5 : Insère après 'val', ou à la fin si 'val' n'est pas trouvé
int LinkedListInt_insertAfter(LinkedListInt *list, const int val, const int toInsert)
{
    if (list == NULL) return -1;

    NodeLinkedListInt *current = list->head;
    NodeLinkedListInt *prev = NULL;

    // Recherche de la valeur 'val'
    while (current != NULL && current->data != val)
    {
        prev = current;
        current = current->next;
    }

    // Création du nouveau nœud
    NodeLinkedListInt *newNode = LinkedListInt_createNode(toInsert);
    if (newNode == NULL) return -1;

    if (current != NULL)
    {
        // On a trouvé 'val' -> On insère juste après
        newNode->next = current->next;
        current->next = newNode;
    }
    else
    {
        // 'val' n'existe pas dans la liste
        if (prev == NULL)
        {
            // La liste était complètement vide, le nœud devient la tête
            list->head = newNode;
        }
        else
        {
            // On l'ajoute à la fin de la liste (prev pointe sur le dernier élément)
            prev->next = newNode;
        }
    }

    return 0;
}