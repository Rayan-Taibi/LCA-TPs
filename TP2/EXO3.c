#include<stdio.h>
#include "vector.h"

int vectorInit(IntVector *const vector, const size_t size){
    vector->data = calloc(size * 2 , sizeof(int));// calloc initialise la memoire a 0 elle prend en parametre le nombre d'elements et la taille de chaque element

    if(!vector->data)return -1;
    vector->size = size;
    vector->capacity = 2 * size ; 
   
    return 0 ; // else return 0
}

void vectorFree(IntVector *vector){
      free(vector->data);
      vector->data = NULL; // pour eviter les fuites de memoire et les acces a des zones de memoire liberees
      vector->size = 0;
      vector->capacity = 0;
}

void vectorPrint(const IntVector *const vector){
    for(int i = 0 ; i < vector->size ; i++){ // on met size pas capacity parceque on souhaite affiché que les nombres existant pas les zéros
        printf("%d\n" , vector->data[i]);
    }
}

size_t vectorSize(const IntVector *const vector){
    return vector->size;
}
size_t vectorCapacity(const IntVector *const vector){
    return vector->capacity;
}
int vectorGet(IntVector *const vector, const int i){
        return vector->data[i];
}
void vectorSet(IntVector *const vector, const int x, const int i){
    vector->data[i] = x;
}
int vectorPushBack(IntVector *vector, const int x){
    // si le vector est plein on double sa capacite
    if(vector->size == vector->capacity){
        int *tmp = realloc(vector->data , vector->capacity * 2 * sizeof(int)); // realloc prend en parametre le pointeur vers la memoire a reallouer et la nouvelle taille de la memoire
        if(!tmp)return -1;
        vector-> data = tmp ; 
        vector->capacity *= 2;
    }
    vector->data[vector->size++] = x; // on ajoute x a la fin du vector et on incremente la taille
    return 0;
}
int vectorPopBack(IntVector *const vector){
    return vector->data[vector->size];
     vector->size--; // on reduit la taille du vector
}
void vectorReset(IntVector *const vector){
    for (int i = 0 ; i < vector ->size ; i++ ){
        vector -> data[i] = 0;
    }
    // on peut aussi faire un memset pour initialiser la memoire a 0
    // memset(vector->data , 0 , vector->size * sizeof(int));
}
int vectorCompare(IntVector *const vector1, IntVector *const vector2){
    
}
