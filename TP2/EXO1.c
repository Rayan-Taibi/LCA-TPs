#include<stdio.h>
#include<stdlib.h>
int global_init = 42; 
int global_uninit;
int const global_const = 100;


// dans cet exercice on a 2 variables globales :
// - global_init : qui est initialisée à 42, elle sera stockée dans la section .data du programme
// - global_uninit : qui n'est pas initialisée, elle sera stockée dans la section .bss du programme, qui est une section spéciale pour les variables non initialisées.  
// et du coup pour voir la différence on compile le programme et on utilise la commande "size EXO1.exe" pour voir la taille de chaque section du programme. On verra que la section .data a une taille de 4 octets (pour la variable global_init) et la section .bss a une taille de 4 octets (pour la variable global_uninit).
// la variable global_const est une constante, elle sera stockée dans la section .rodata du programme, qui est une section spéciale pour les données en lecture seule. Elle n'est pas modifiable pendant l'exécution du programme. 
// et on remarque que la section text du programme s'augmente de 4 octets pour stocker la variable global_const, car elle est utilisée dans le code du programme.

void test_stack() {
    int a = 1;
    int b = 2;
    int c = 3;

    printf("--- PILE (STACK) ---\n");
    printf("Adresse de a : %p\n",(void*) &a); // on utilise (void*) pour éviter les warnings de format de printf sinon elle marche aussi mais c'est mieux de faire ça pour être sûr que le format est correct
    printf("Adresse de b : %p\n", (void*)&b);//%p est le format pour afficher une adresse mémoire, et (void*) est utilisé pour convertir l'adresse en un pointeur générique, ce qui est nécessaire pour éviter les warnings de format de printf.
    printf("Adresse de c : %p\n", (void*)&c);

    //Les adresses sont très proches les unes des
    // autres (souvent séparées de 4 octets pour un int). 
    //Tu remarqueras que l'adresse de c est plus petite que celle de a, confirmant que la pile "descend"

}

void test_heap() {
    int* p1 =(int*) malloc(sizeof(int));
    int* p2 = (int*) malloc(sizeof(int));
    int* p3 = (int*) malloc(sizeof(int));
    printf("--- HEAP ---\n");
    printf("Adresse de p1 : %p\n", (void*)p1);
    printf("Adresse de p2 : %p\n", (void*)p2);
    printf("Adresse de p3 : %p\n", (void*)p3);

    // Les adresses sont généralement plus éloignées les unes des autres que celles de la pile, et elles peuvent être dans n'importe quel ordre. 
    // La mémoire allouée sur le tas peut être fragmentée, ce qui signifie que les adresses peuvent ne pas être contiguës. Les adresses du tas sont situées dans une zone complètement différente de la pile (plus "basses" dans la mémoire globale)

    free(p1);
    free(p2);
    free(p3);
}
int main(){
    test_stack();
    test_heap();

    // en résumé la pile et le tas groississent dans des directions opposées : la pile "descend" vers des adresses plus petites, tandis que le tas "monte" vers des adresses plus grandes.
    // pour éviter de se rentrer dedans trop vite, les systèmes d'exploitation allouent généralement une grande quantité de mémoire pour la pile et le tas, et ils peuvent également utiliser des techniques de protection de la mémoire pour empêcher les débordements de pile ou de tas.
    return 0;
}
//dans .bss on trouve les variables globales non initialisées, dans .data on trouve les variables globales initialisées, dans .rodata on trouve les données en lecture seule (comme les constantes), et dans .text on trouve le code exécutable du programme.
//dans stack on trouve les variables locales et les paramètres de fonction, tandis que dans heap on trouve la mémoire allouée dynamiquement.