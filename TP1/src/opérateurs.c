#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    // Opérations arithmétiques
    int addition = a + b;
    int soustraction = a - b;
    int multiplication = a * b;
    int division = a / b;
    int modulo = a % b;

    // Opérations logiques (comparaisons)
    int egal = (a == b);
    int superieur = (a > b);

    // Affichage
    printf("a = %d, b = %d\n", a, b);
    printf("Addition       : %d + %d = %d\n", a, b, addition);
    printf("Soustraction   : %d - %d = %d\n", a, b, soustraction);
    printf("Multiplication : %d * %d = %d\n", a, b, multiplication);
    printf("Division       : %d / %d = %d\n", a, b, division);
    printf("Modulo         : %d %% %d = %d\n", a, b, modulo);

    // Affichage des résultats logiques (0 = faux, 1 = vrai)
    printf("a == b         : %d\n", egal);
    printf("a > b          : %d\n", superieur);

    return 0;
}
