#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <stdio.h>

// Déclarations opaques pour encapsuler les structures
typedef struct NodeQueue NodeQueue;
typedef struct Queue Queue;

// Prototype du pointeur de fonction d'affichage exigé par le sujet (Question 1)
typedef void (*PrintFunc)(const void *);

// Fonctions de l'interface de la file (Questions 1.1 à 1.6)
Queue *Queue_create(PrintFunc print_fn);
void Queue_delete(Queue *q);
int Queue_isEmpty(const Queue *q);
void *Queue_head(const Queue *q);
int Queue_enqueue(Queue *q, void *val);
void *Queue_dequeue(Queue *q);
void Queue_print(const Queue *q);

#endif