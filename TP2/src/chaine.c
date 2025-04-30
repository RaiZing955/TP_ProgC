#include <stdio.h>

void main() {
    char chaine1[] = "Hello";
    char chaine2[] = "World !";
    int Length1 = 0;
    int Length2 = 0;

    while (chaine1[Length1] != '\0') {
        Length1++;
    }

    while (chaine2[Length2] != '\0') {
        Length2++;
    }

    // Déclaration de la chaîne finale avec +1 pour le '\0'
    char chaine_finale[Length1 + Length2 + 2];

    // Copie de chaine1
    for (int i = 0; i < Length1; i++) {
        chaine_finale[i] = chaine1[i];
    }

    chaine_finale[Length1+1]=' ';
    
    // Copie de chaine2 à la suite
    for (int i = 1; i < Length2; i++) {
        chaine_finale[Length1 + i] = chaine2[i];
    }

    // Ajout du caractère de fin
    chaine_finale[Length1 + Length2] = '\0';

    // Affichage de la chaîne finale
    printf("%s\n", chaine_finale);

}
