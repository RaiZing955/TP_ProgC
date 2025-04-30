#include <stdio.h>

int main() {
    // Déclaration des variables
    int a = 2; // Base
    int b = 3; // Exposant
    int resultat = 1; // Initialisation du résultat à 1

    // Calcul de la puissance
    for (int i = 0; i < b; i++) {
        resultat *= a; // Multiplication répétée
    }

    // Affichage du résultat
    printf("%d élevé à la puissance %d est : %d\n", a, b, resultat);

    return 0;
}
 
