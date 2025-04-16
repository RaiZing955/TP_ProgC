#include <stdio.h>

int main() {
    int compteur = 5; // Tu peux tester avec d'autres valeurs < 10

    if (compteur >= 10) {
        printf("La valeur de compteur doit être strictement inférieure à 10.\n");
        return 1;
    }

    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % 2 == 0 && j > 1 && j < i) {
                printf("# ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}
