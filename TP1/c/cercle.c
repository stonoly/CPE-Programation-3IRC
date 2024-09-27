/* Fichier: cercle.c
* calcule l'aire et le périmètre d'un cercle
* auteur: Pierre MOLY
* Exercice 1.2
*/
#include <stdio.h>
// importation de la bibliothèque mathématique
#include <math.h>
// définition de la constante PI
#define PI 3.14159

int main() {
    // déclaration de la variable rayon
    float rayon;
    // affichage d'un message pour demander le rayon du cercle
    printf("Tapez le rayon du cercle : ");
    scanf("%f", &rayon);

    // calcul de l'aire du cercle
    float aire =  PI * pow(rayon, 2);
    // calcul du périmètre du cercle
    float perimetre =  2 * PI * rayon;

    // affichage de l'aire du cercle
    printf("Aire = %f", aire);
    printf("\n");
    // affichage du périmètre du cercle
    printf("Perimetre = %f", perimetre);
    printf("\n");

    return 0;
}