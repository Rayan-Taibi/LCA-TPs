#include<stdio.h>

int global_init = 42; 
int global_uninit;
int const global_const = 100;
int main(){
    return 0;
}

// dans cet exercice on a 2 variables globales :
// - global_init : qui est initialisée à 42, elle sera stockée dans la section .data du programme
// - global_uninit : qui n'est pas initialisée, elle sera stockée dans la section .bss du programme, qui est une section spéciale pour les variables non initialisées.  
// et du coup pour voir la différence on compile le programme et on utilise la commande "size EXO1.exe" pour voir la taille de chaque section du programme. On verra que la section .data a une taille de 4 octets (pour la variable global_init) et la section .bss a une taille de 4 octets (pour la variable global_uninit).
// la variable global_const est une constante, elle sera stockée dans la section .rodata du programme, qui est une section spéciale pour les données en lecture seule. Elle n'est pas modifiable pendant l'exécution du programme. 
// et on remarque que la section text du programme s'augmente de 4 octets pour stocker la variable global_const, car elle est utilisée dans le code du programme.