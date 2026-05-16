#include <stdlib.h>

typedef struct {
    int *data; // Tableau contenant les entiers
    size_t size; // Nombre d'elements dans le tableau (taille)
    size_t capacity; // Nombre d'elements pre-alloue (capacite)
} IntVector;

// Initialise 'vector' :
// - Alloue 'size' * 2 int
// - capacity = 2 * 'size'
// - les entiers doivent etre initialisés à 0
// Retourne 0 si l'execution a fonctionne, -1 sinon
// On considere que l'utilisateur a donne une taille 'size' valide
int vectorInit(IntVector *const vector, const size_t size);

// Libere la memoire de 'vector' (data)
// Met 'size' et 'capacity' a 0
void vectorFree(IntVector *vector);

// Affiche les elements de 'vector' (data)
void vectorPrint(const IntVector *const vector);

// Retourne la taille de 'vector'
size_t vectorSize(const IntVector *const vector);

// Retourne la capacite de 'vector'
size_t vectorCapacity(const IntVector *const vector);

// Retourne l'element 'i' de 'vector'
// On considere que l'utilisateur a donne un indice 'i' valide
int vectorGet(IntVector *const vector, const int i);

// Affecte 'x' a l'element 'i' de 'vector'
// On considere que l'utilisateur a donne un indice 'i' valide
void vectorSet(IntVector *const vector, const int x, const int i);

// Ajoute 'x' a la fin de 'vector' (data)
// Retourne 0 si l'execution a fonctionne, -1 sinon
int vectorPushBack(IntVector *vector, const int x);

// Retourne le dernier element de 'vector' (data)
// Reduit la taille 'size'
int vectorPopBack(IntVector *const vector);

// Affecte 0 a tous les elements de 'vector' (data) 
void vectorReset(IntVector *const vector);

// Compare 'vector1' et 'vector2'
// Retourne -1 () si 'vector1' est "plus petit" que 'vector2' 
// ===> si sa taille est plus petite ou si son premier element different est plus petit
// Retourne 1 () si 'vector1' est "plus grand" que 'vector2' 
// ===> si sa taille est plus grande ou si son premier element different est plus grand
// Retourn 0 s'ils sont egaux
int vectorCompare(IntVector *const vector1, IntVector *const vector2);

// Copie 'vectorSrc' dans 'vectorDest'
// Retourne 0 si l'execution a fonctionne, -1 sinon
int vectorCopy(IntVector *const vectorDest, const IntVector *const vectorSrc);

// Fait en sorte que la capacite de 'vector' soit egale a sa taille
// Gere la memoire en consequence 
void vectorShrinkToFit(IntVector *const vector);

// Retire l'element 'i' de 'vector' (data)
// Gere la memoire et la taille en consequence
// On considere que l'utilisateur a donne un indice 'i' valide
void vectorRemove(IntVector *vector, const int i);



