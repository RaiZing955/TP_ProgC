#include <stdio.h>

// Définir des constantes pour le nombre d'étudiants et la longueur maximale des chaînes
#define NB_ETUDIANTS 5
#define TAILLE_MAX 100

int main() {
    // Déclaration des tableaux pour stocker les informations
    char noms[NB_ETUDIANTS][TAILLE_MAX] = {
        "Dupont", "Martin", "Durand", "Bernard", "Petit"
    };
    
    char prenoms[NB_ETUDIANTS][TAILLE_MAX] = {
        "Alice", "Bruno", "Claire", "David", "Emma"
    };
