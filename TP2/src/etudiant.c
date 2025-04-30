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
    
    char adresses[NB_ETUDIANTS][TAILLE_MAX] = {
        "12 rue A, Paris", 
        "34 rue B, Lyon", 
        "56 rue C, Marseille", 
        "78 rue D, Toulouse", 
        "90 rue E, Lille"
    };
    
    float notes_prog[NB_ETUDIANTS] = {15.5, 13.0, 17.0, 12.5, 16.5};
    float notes_sys[NB_ETUDIANTS] = {14.0, 12.0, 18.0, 11.5, 15.0};

    // Affichage des informations des étudiant.e.s
    printf("=== Informations des étudiant.e.s ===\n\n");
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Étudiant %d :\n", i + 1);
        printf("Nom       : %s\n", noms[i]);
        printf("Prénom    : %s\n", prenoms[i]);
        printf("Adresse   : %s\n", adresses[i]);
        printf("Note en Programmation C      : %.2f\n", notes_prog[i]);
        printf("Note en Système d'exploitation : %.2f\n", notes_sys[i]);
        printf("----------------------------------------\n");
    }

    return 0;
}
