#include <stdio.h>

int main() {
    int n = 10; // nombre de termes à générer
    int i;
    unsigned long long a = 0, b = 1, suivant;

    printf("Suite de Fibonacci jusqu'au terme U%d :\n", n);

    for (i = 0; i <= n; i++) {
        if (i == 0) {
            printf("%llu ", a);
        } else if (i == 1) {
            printf("%llu ", b);
        } else {
            suivant = a + b;
            printf("%llu ", suivant);
            a = b;
            b = suivant;
        }
    }

    printf("\n");
    return 0;
}
