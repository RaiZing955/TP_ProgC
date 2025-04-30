#include <stdio.h>

int main() {
    // Déclaration et initialisation de la variable d
    int d = 0x10010; // Exemple : valeur hexadécimale (peut être changée pour tester d'autres cas)

    // Masques pour vérifier les 4ème et 20ème bits
    int bit_4 = (d >> 3) & 1;  // Décalage de 3 bits à droite pour obtenir le 4ème bit
    int bit_20 = (d >> 19) & 1; // Décalage de 19 bits à droite pour obtenir le 20ème bit

    // Vérification des bits et affichage du résultat
    if (bit_4 == 1 && bit_20 == 1) {
        printf("1\n"); // Si les deux bits sont à 1
    } else {
        printf("0\n"); // Si l'un des deux bits ou les deux sont à 0
    }

    return 0;
}
