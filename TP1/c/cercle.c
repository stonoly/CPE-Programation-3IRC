/* Fichier: cercle.c
* calcule l'aire et le périmètre d'un cercle
* auteur: Pierre MOLY
* Exercice 1.2
*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main() {
    float rayon;
    printf("Tapez le rayon du cercle : ");
    scanf("%f", &rayon);

    float aire =  PI * pow(rayon, 2);
    float perimetre =  2 * PI * rayon;

    printf("Aire = %f", aire);
    printf("\n");
    printf("Perimetre = %f", perimetre);
    printf("\n");

    return 0;
}