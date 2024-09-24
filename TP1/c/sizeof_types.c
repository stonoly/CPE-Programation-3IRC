/* Fichier: sizeof_types.c
* Donne les tailles des variables de différents types en C
* auteur: Pierre MOLY
* Exercice 1.3
*/
#include <stdio.h>

int main() {

    printf("Size of different types:\n");

    printf("Size of char is %lu", sizeof(char));
    printf("\n");

    printf("Size of short is %lu", sizeof(short));
    printf("\n");

    printf("Size of int is %lu", sizeof(int));
    printf("\n");

    printf("Size of long is %lu", sizeof(long));
    printf("\n");

    printf("Size of long long is %lu", sizeof(long long));
    printf("\n");

    printf("Size of float is %lu", sizeof(float));
    printf("\n");

    printf("Size of double is %lu", sizeof(double));
    printf("\n");

    printf("Size of long double is %lu", sizeof(long double));
    printf("\n");

    printf("-----Size of unsigned type-----");
    printf("\n");

    printf("Size of unsigned char is %lu", sizeof(unsigned char));
    printf("\n");

    printf("Size of unsigned short is %lu", sizeof(unsigned short));
    printf("\n");

    printf("Size of unsigned int is %lu", sizeof(unsigned int));
    printf("\n");

    printf("Size of unsigned long is %lu", sizeof(unsigned long));
    printf("\n");

     printf("-----Size of signed type-----");
     printf("\n");

     printf("Size of signed char is %lu", sizeof(signed char));
    printf("\n");

    printf("Size of signed short is %lu", sizeof(signed short));
    printf("\n");

    printf("Size of signed int is %lu", sizeof(signed int));
    printf("\n");

    printf("Size of signed long is %lu", sizeof(signed long));
    printf("\n");

    return 0;
}