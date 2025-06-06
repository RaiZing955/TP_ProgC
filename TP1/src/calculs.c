
#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 3;
    char op = '+'; // Changez cette valeur pour tester d'autres opérateurs

    int resultat;

    switch (op) {
        case '+':
            resultat = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, resultat);
            break;
        case '-':
            resultat = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, resultat);
            break;
        case '*':
            resultat = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, resultat);
            break;
        case '/':
            if (num2 != 0) {
                resultat = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, resultat);
            } else {
                printf("Erreur : Division par zéro.\n");
            }
            break;
        case '%':
            if (num2 != 0) {
                resultat = num1 % num2;
                printf("%d %% %d = %d\n", num1, num2, resultat);
            } else {
                printf("Erreur : Modulo par zéro.\n");
            }
            break;
        case '&':
            resultat = num1 & num2;
            printf("%d & %d = %d\n", num1, num2, resultat);
            break;
        case '|':
            resultat = num1 | num2;
            printf("%d | %d = %d\n", num1, num2, resultat);
            break;
        case '~':
            resultat = ~num1;
            printf("~%d = %d\n", num1, resultat);
            break;
        default:
            printf("Opérateur invalide : '%c'\n", op);
    }

    return 0;
}
