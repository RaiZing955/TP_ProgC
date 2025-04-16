#include <stdio.h>

void afficherBinaire(unsigned int n) {
    int i;
    int debut = 0;

    // Affiche 32 bits
    for (i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (bit) debut = 1; // On a trouvé un 1, on commence à afficher

        if (debut) {
            printf("%d", bit);
        }
    }

    // Si tous les bits sont 0, on affiche au moins un 0
    if (!debut) {
        printf("0");
    }

    printf("\n");
}

int main() {
    unsigned int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = sizeof(nombres) / sizeof(nombres[0]);

    for (int i = 0; i < taille; i++) {
        printf("Décimal : %u => Binaire : ", nombres[i]);
        afficherBinaire(nombres[i]);
    }

    return 0;
}
