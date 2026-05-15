#include<stdio.h>
#include<stdlib.h>

void printMemoryRepresentation(void *ptr , size_t size ){
   char *p = (char *)ptr;
   for(int i = 0 ; i < size ; i++){
      printf("%.2x " , p[i]);
   }
   printf("\n");

}

//on c on ne peut pas afficher les bits directement
// on doit faire un décalage de bits et un AND pour obtenir chaque bit individuellement
// après on les assemble pour afficher la représentation binaire de chaque octet

void printBits(unsigned char val){
    for(int i = 7 ; i >= 0 ; i--){ // on affiche les bits de gauche à droite parce que c'est plus facile à lire
        printf("%d" , (val >> i) & 1);// on décale les bits de val de i positions vers la droite et on fait un AND avec 1 pour obtenir le bit de poids faible
    }
    printf(" ");
}

void printMemoryRepresentationBits(void *ptr , size_t size){
    char *p = (char *)ptr;
    for(int i= 0; i< size ; i++){
        printf("Octet %i [%.2X] : [Bits : " , i , p[i]);
        printBits(p[i]);
        printf("]\n");
    }

}

int main(){
    int val = 0x01234567;

    printMemoryRepresentation(&val , sizeof(int));
    
    // resultat : 67 45 23 01 (little endian) du coup ma machine est en little endian
    printMemoryRepresentationBits(&val , sizeof(int));
    // resultat :
    // Octet 0 [67] : [Bits : 01100111 ]    
    // Octet 1 [45] : [Bits : 01000101 ]
    // Octet 2 [23] : [Bits : 00100011 ]
    // Octet 3 [01] : [Bits : 00000001 ]
    // Explication de lordre d'affichage :
    // On affiche les octets de gauche à droite, c'est à dire que l'octet de poids faible (67) est affiché en premier, suivi de l'octet de poids fort (01) qui est affiché en dernier.
    // C'est l'ordre d'affichage naturel pour les humains, même si la machine stocke les octets dans l'ordre inverse (little endian).
    // c'est une convention logicielle pour faciliter la lecture et la compréhension de la représentation mémoire, même si cela peut sembler contre-intuitif par rapport à l'ordre de stockage réel en mémoire.
    return 0;
}