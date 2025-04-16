#include <stdio.h>

int main() {
    int n = 5;  // Hauteur de la pyramide (modifiable)
    int i, j;

    // Génération de la pyramide
    for (i = 1; i <= n; i++) {
        // Affichage des espaces pour centrer
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Affichage des nombres croissants
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Affichage des nombres décroissants
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Nouvelle ligne après chaque niveau
        printf("\n");
    }

    // Message final
    printf("Pyramide générée avec succès !\n");

    return 0;
}

