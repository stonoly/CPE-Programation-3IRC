/* Fichier: operateurs.c
* Utilisation des opérateurs arithmétiques et logiques en C
* auteur: Pierre MOLY
* Exercice 1.5
*/

#include <stdio.h>
#include <stdbool.h>
int main(){

    int a = 16;
    int b = 3;

    int calcul = a + b;
    printf("a + b = %d\n", calcul);

    calcul = a - b;
    printf("a - b = %d\n", calcul);

    calcul = a * b;
    printf("a * b = %d\n", calcul);

    float division = (float)a / b;
    printf("a / b = %f\n", division);

    calcul = a % b;
    printf("a %% b = %d\n", calcul);

    bool boolean = a == b;
    printf("a == b = %d\n", boolean);

    boolean = a > b;
    printf("a > b = %d\n", boolean);

    return 0;
}