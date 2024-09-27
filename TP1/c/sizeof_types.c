/* Fichier: sizeof_types.c
* Donne les tailles des variables de différents types en C
* auteur: Pierre MOLY
* Exercice 1.3
*/
#include <stdio.h>

int main() {
    // affichage de la taille des différents types
    printf("Size of different types:\n");

    // affichage de la taille de char
    printf("Size of char is %lu", sizeof(char));
    printf("\n");

    // affichage de la taille de short
    printf("Size of short is %lu", sizeof(short));
    printf("\n");

    // affichage de la taille de int
    printf("Size of int is %lu", sizeof(int));
    printf("\n");

    // affichage de la taille de long
    printf("Size of long is %lu", sizeof(long));
    printf("\n");

    // affichage de la taille de long long
    printf("Size of long long is %lu", sizeof(long long));
    printf("\n");

    // affichage de la taille de float
    printf("Size of float is %lu", sizeof(float));
    printf("\n");

    // affichage de la taille de double
    printf("Size of double is %lu", sizeof(double));
    printf("\n");

    // affichage de la taille de long double
    printf("Size of long double is %lu", sizeof(long double));
    printf("\n");

    // affichage de la taille des différents types non signés
    printf("-----Size of unsigned type-----");
    printf("\n");

    // affichage de la taille de unsigned char
    printf("Size of unsigned char is %lu", sizeof(unsigned char));
    printf("\n");

    // affichage de la taille de unsigned short
    printf("Size of unsigned short is %lu", sizeof(unsigned short));
    printf("\n");

    // affichage de la taille de unsigned int
    printf("Size of unsigned int is %lu", sizeof(unsigned int));
    printf("\n");

    // affichage de la taille de unsigned long
    printf("Size of unsigned long is %lu", sizeof(unsigned long));
    printf("\n");

    // affichage de la taille des différents types signés
    printf("-----Size of signed type-----");
    printf("\n");

    // affichage de la taille de signed char
    printf("Size of signed char is %lu", sizeof(signed char));
    printf("\n");

    // affichage de la taille de signed short
    printf("Size of signed short is %lu", sizeof(signed short));
    printf("\n");

    // affichage de la taille de signed int
    printf("Size of signed int is %lu", sizeof(signed int));
    printf("\n");

    // affichage de la taille de signed long
    printf("Size of signed long is %lu", sizeof(signed long));
    printf("\n");

    return 0;
}