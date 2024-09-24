/* Fichier: variables.c
* Affectation et affichage des variables de types de base en C
* auteur: Pierre MOLY
* Exercice 1.4
*/

#include <stdio.h>

int main (){

    char letter_a = 'a';
    printf("Char: %c\n", letter_a);

    signed char letter_b = 'b';
    printf("Signed Char: %c\n", letter_b);

    unsigned char letter_c = 'c';
    printf("Unsigned Char: %c\n", letter_c);

    short short_integger = -32767;
    printf("Short: %d\n", short_integger);

    unsigned short unsigned_short_integger = 65535;
    printf("Unsigned Short: %d\n", unsigned_short_integger);

    int integger = -2147483647;
    printf("Integer: %d\n", integger);

    unsigned int unsigned_integger = 4294967295;
    printf("Unsigned Integer: %d\n", unsigned_integger);

    long int long_integger = 2147483647;
    printf("Long: %ld\n", long_integger);

    unsigned long int unsigned_long_integger = 4294967295;
    printf("Unsigned Long: %ld\n", unsigned_long_integger);

    long long int long_long_integger = 9223372036854775807;
    printf("Long: %lld\n", long_long_integger);

    float floating = 3.14159265358979323846;
    printf("Floating: %f\n", floating);

    double doubling = 3.14159265358979323846;
    printf("Double: %lf\n", doubling);

    long double long_double = 3.14159265358979323846;
    printf("Long Double: %Lf\n", long_double);

    return 0;
}