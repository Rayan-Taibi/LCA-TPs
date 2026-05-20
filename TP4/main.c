#include "linked_list_int.h"
#include <stdio.h>

int main() 
{
    LinkedListInt *myList = LinkedListInt_create();

    // Test de pushFront
    LinkedListInt_pushFront(myList, 20);
    LinkedListInt_pushFront(myList, 46);
    LinkedListInt_pushFront(myList, 87);
    LinkedListInt_pushFront(myList, 79);

    printf("Liste initiale : ");
    LinkedListInt_print(myList); // Attendu : 79 -> 87 -> 46 -> 20 -> 

    // Test de popFront
    int popped = LinkedListInt_popFront(myList);
    printf("Valeur extraite (popFront) : %d\n", popped); // Attendu : 79
    printf("Liste après popFront : ");
    LinkedListInt_print(myList); // Attendu : 87 -> 46 -> 20 -> 

    // Test de insertAfter (valeur existante)
    printf("\nInsertion de 99 après 46 :\n");
    LinkedListInt_insertAfter(myList, 46, 99);
    LinkedListInt_print(myList); // Attendu : 87 -> 46 -> 99 -> 20 -> 

    // Test de insertAfter (valeur absente -> insertion à la fin)
    printf("\nInsertion de 5 après 100 (absent, donc à la fin) :\n");
    LinkedListInt_insertAfter(myList, 100, 5);
    LinkedListInt_print(myList); // Attendu : 87 -> 46 -> 99 -> 20 -> 5 -> 

    // Nettoyage complet
    LinkedListInt_delete(myList);
    return 0;
}