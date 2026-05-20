#include "queue.h"

struct NodeQueue 
{
    void *data;               // Pointeur générique pour stocker tout type de donnée
    struct NodeQueue *next;
};

struct Queue 
{
    NodeQueue *head;
    NodeQueue *tail;          // Ajout d'un pointeur de fin pour enfiler en O(1)
    PrintFunc print_element;  // Stockage du pointeur de fonction d'affichage (Question 1)
};

Queue *Queue_create(PrintFunc print_fn)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q != NULL)
    {
        q->head = NULL;
        q->tail = NULL;
        q->print_element = print_fn;
    }
    return q;
}

void Queue_delete(Queue *q)
{
    if (q == NULL) return;
    while (!Queue_isEmpty(q))
    {
        Queue_dequeue(q); // Libère les nœuds internes de la file
    }
    free(q);
}

int Queue_isEmpty(const Queue *q)
{
    return (q == NULL || q->head == NULL);
}

void *Queue_head(const Queue *q)
{
    if (Queue_isEmpty(q)) return NULL;
    return q->head->data;
}

int Queue_enqueue(Queue *q, void *val)
{
    if (q == NULL) return -1;

    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (newNode == NULL) return -1;

    newNode->data = val;
    newNode->next = NULL;

    if (Queue_isEmpty(q))
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    return 0;
}

void *Queue_dequeue(Queue *q)
{
    if (Queue_isEmpty(q)) return NULL;

    NodeQueue *temp = q->head;
    void *data = temp->data;

    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL; // La file est devenue vide
    }

    free(temp);
    return data;
}

void Queue_print(const Queue *q)
{
    if (Queue_isEmpty(q))
    {
        printf("(File vide)\n");
        return;
    }

    NodeQueue *current = q->head;
    while (current != NULL)
    {
        // Appel de la fonction utilisateur pointée pour afficher la donnée
        if (q->print_element != NULL)
        {
            q->print_element(current->data);
        }
        current = current->next;
    }
    printf("\n");
}