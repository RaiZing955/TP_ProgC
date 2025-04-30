#include <stdio.h>

int main() {
    int n;
    
    // Demander à l'utilisateur combien de termes de la suite de Fibonacci il souhaite afficher
    printf("Entrez le nombre de termes de la suite de Fibonacci à afficher : ");
    scanf("%d", &n);
    
    // Vérification que n est positif
    if (n <= 0) {
        printf("Veuillez entrer un nombre positif.\n");
        return 1; // Arrêt du programme en cas d'entrée invalide
    }
    
    // Déclaration des deux premiers termes de la suite
    int a = 0, b = 1;
    
    // Affichage des premiers termes de la suite
    printf("Suite de Fibonacci jusqu'à U%d : ", n);
    
    // Boucle pour générer et afficher les termes de la suite
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", a); // Affiche U0
        } else if (i == 1) {
            printf(", %d", b); // Affiche U1
        } else {
            int next_term = a + b;  // Calcul du prochain terme
            printf(", %d", next_term);
            a = b;  // Mettre à jour a pour le prochain calcul
            b = next_term;  // Mettre à jour b pour le prochain calcul
        }
    }
    
    printf("\n");
    
    return 0;
}
