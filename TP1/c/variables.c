/* Fichier: variables.c
* Affectation et affichage des variables de types de base en C
* auteur: Pierre MOLY
* Exercice 1.4
*/

#include <stdio.h>

int main (){

    printf("Affectation et affichage des variables de types de base en C:\n");

    // affichage de la variable char
    char letter_a = 'a';
    printf("Char: %c\n", letter_a);

    // affichage de la variable signed char
    signed char letter_b = 'b';
    printf("Signed Char: %c\n", letter_b);

    // affichage de la variable unsigned char
    unsigned char letter_c = 'c';
    printf("Unsigned Char: %c\n", letter_c);

    // affichage de la variable short
    short short_integger = -32767;
    printf("Short: %d\n", short_integger);

    // affichage de la variable unsigned short
    unsigned short unsigned_short_integger = 65535;
    printf("Unsigned Short: %d\n", unsigned_short_integger);

    // affichage de la variable int
    int integger = -2147483647;
    printf("Integer: %d\n", integger);

    // affichage de la variable unsigned int
    unsigned int unsigned_integger = 4294967295;
    printf("Unsigned Integer: %d\n", unsigned_integger);

    // affichage de la variable long
    long int long_integger = 2147483647;
    printf("Long: %ld\n", long_integger);

    // affichage de la variable unsigned long
    unsigned long int unsigned_long_integger = 4294967295;
    printf("Unsigned Long: %ld\n", unsigned_long_integger);

    // affichage de la variable long long
    long long int long_long_integger = 9223372036854775807;
    printf("Long: %lld\n", long_long_integger);

    // affichage de la variable float
    float floating = 3.14159265358979323846;
    printf("Floating: %f\n", floating);

    // affichage de la variable double
    double doubling = 3.14159265358979323846;
    printf("Double: %lf\n", doubling);

    // affichage de la variable long double
    long double long_double = 3.14159265358979323846;
    printf("Long Double: %Lf\n", long_double);

    return 0;
}