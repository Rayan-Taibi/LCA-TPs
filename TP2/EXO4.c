#include<stdio.h>
#include<stdlib.h>

void intToString(int number, char str[]) {
    int i = 0;
    int negative = 0;
    // cas nombre négatif
    if (number < 0) {
        negative = 1;
        number = -number; // rendre le nombre positif pour le traitement
    }
    // cas nombre zéro
    if (number == 0){
        str[i++] = '0';
        str[i] = '\0';// terminer la chaîne
        return;
    }
    // on extrait les chiffres du nombre
    while(number > 0){
        str[i++] = '0' + (number % 10) ; // 0 + '4' = '4' on convertit le chiffre en caractère
        number/=10;
    }

    if(negative){
        str[i++] = '-';
    }
    str[i] = '\0';// terminer la chaîne

    //on retourne la chaine inversée
    int debut =  0;
    int fin = i - 1;

    while(debut < fin){
        char temp = str[debut];
        str[debut] = str[fin];
        str[fin] = temp;
        debut++;
        fin--;
    }
}

int main(void) {
    char str[50];
 
    intToString(1234, str);
    printf("%s\n", str);   // 1234
 
    intToString(-567, str);
    printf("%s\n", str);   // -567
 
    intToString(0, str);
    printf("%s\n", str);   // 0
 
    return 0;
}

