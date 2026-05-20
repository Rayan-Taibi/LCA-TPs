#ifndef __LINKED_LIST_INT_H__
#define __LINKED_LIST_INT_H__

#include <stdlib.h>
#include <stdio.h>

// Déclarations opaques pour l'encapsulation (Question 6)
typedef struct NodeLinkedListInt NodeLinkedListInt;
typedef struct LinkedListInt LinkedListInt;

// Spécifications de base fournies
LinkedListInt *LinkedListInt_create();
void LinkedListInt_delete(LinkedListInt *const list);
void LinkedListInt_clear(LinkedListInt *const list);
int LinkedListInt_pushFront(LinkedListInt *list, const int val);

// Nouvelles fonctions à ajouter (Questions 2, 3, 5)
void LinkedListInt_print(const LinkedListInt *list);
int LinkedListInt_popFront(LinkedListInt *list);
int LinkedListInt_insertAfter(LinkedListInt *list, const int val, const int toInsert);

#endif