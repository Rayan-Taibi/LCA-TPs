#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // --- Question 1 ---
    //argv[0] = nom du programme
    // argv[1] = prénom, argv[2] = nom
    printf("%s %s\n", argv[1], argv[2]);

    // --- Question 2 ---
    // Format : prenom.nom@unilim.fr
    // Taille exacte = len(prénom) + 1 (.) + len(nom) + 8 (@unilim.fr) + 1 (\0)
    size_t taille = strlen(argv[1]) + 1 + strlen(argv[2]) + strlen("@unilim.fr") + 1;
    char *email = malloc(taille);

    strcpy(email, argv[1]);       // "prenom"
    strcat(email, ".");           // "prenom."
    strcat(email, argv[2]);       // "prenom.nom"
    strcat(email, "@unilim.fr");  // "prenom.nom@unilim.fr"

    printf("%s\n", email);

    // --- Question 3 ---
    // strcspn renvoie le nombre de caractères avant le premier '.'
    size_t len_prenom = strcspn(email, ".");
    printf("Longueur du prenom : %zu\n", len_prenom); // zu pour size_t

    // --- Question 4 ---
    // Le nom commence après "prenom." et finit avant "@"
    // On cherche '@' à partir du point
    // strchr renvoie un pointeur vers le caractère trouvé, on peut faire la différence de pointeurs pour obtenir la longueur
    char *arobase = strchr(email, '@');
    char *point   = strchr(email, '.');
    size_t len_nom = arobase - point - 1; // -1 pour ne pas compter le '.'
    printf("Longueur du nom : %zu\n", len_nom);

    free(email);
    return 0;
}
// la différence entre strcspn et strchr est que strcspn renvoie un nombre (taille) tandis que strchr renvoie un pointeur vers le caractère trouvé.