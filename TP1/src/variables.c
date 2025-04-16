#include <stdio.h>

int main() {
    // Types char
    char c = 'A';
    signed char sc = -65;
    unsigned char uc = 200;

    // Types short
    short s = -12345;
    signed short ss = -32000;
    unsigned short us = 65000;

    // Types int
    int i = -100000;
    signed int si = -200000;
    unsigned int ui = 400000;

    // Types long int
    long int li = -1000000L;
    signed long int sli = -2000000L;
    unsigned long int uli = 4000000UL;

    // Types long long int
    long long int lli = -9000000000LL;
    signed long long int slli = -8000000000LL;
    unsigned long long int ulli = 18000000000ULL;

    // Types flottants
    float f = 3.14f;
    double d = 2.718281828;
    long double ld = 1.6180339887L;

    // Affichage
    printf("char               : %c\n", c);
    printf("signed char        : %d\n", sc);
    printf("unsigned char      : %u\n", uc);

    printf("short              : %hd\n", s);
    printf("signed short       : %hd\n", ss);
    printf("unsigned short     : %hu\n", us);

    printf("int                : %d\n", i);
    printf("signed int         : %d\n", si);
    printf("unsigned int       : %u\n", ui);

    printf("long int           : %ld\n", li);
    printf("signed long int    : %ld\n", sli);
    printf("unsigned long int  : %lu\n", uli);

    printf("long long int           : %lld\n", lli);
    printf("signed long long int    : %lld\n", slli);
    printf("unsigned long long int  : %llu\n", ulli);

    printf("float              : %.2f\n", f);
    printf("double             : %.9f\n", d);
    printf("long double        : %.10Lf\n", ld);

    return 0;
}
