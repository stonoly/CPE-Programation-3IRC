/* Fichier: boucles.c
* Affichage d'un triangle rectangle avec des boucles
* auteur: Pierre MOLY
* Exercice 1.6
*/

#include <stdio.h>
// inclusion de la bibliothèque string.h pour utiliser la fonction strcat
#include <string.h>

int triangle(int size){
    // boucle for pour afficher le triangle
    for (int i = 0; i < size + 1; i++){
        // déclaration d'un tableau de caractères pour stocker les pixels
        char pixels[(i + 1) * 2];
        // initialisation du tableau de caractères
        pixels[0] = '\0';

        for (int j = 0; j < i; j++){
            // condition pour afficher les pixels
            if (j == i - 1 || j == 0 || i == size){
                strcat(pixels, "* ");
            } else {
                strcat(pixels, "# ");
            }
        }
        // affichage du tableau de caractères
        printf("%s\n", pixels);
    }
    return 0;
}

int triangle_while(int size){
    // initialisation de la variable i
    int i = 0;
    // boucle while pour afficher le triangle
    while (i < size + 1){
        // déclaration d'un tableau de caractères pour stocker les pixels
        char pixels[(i + 1) * 2];
        // initialisation du tableau de caractères
        pixels[0] = '\0';

        // initialisation de la variable j
        int j = 0;
        // boucle while pour afficher les pixels
        while (j < i){
            // condition pour afficher les pixels
            if (j == i - 1 || j == 0 || i == size){
                strcat(pixels, "* ");
            } else {
                strcat(pixels, "# ");
            }
            j++;
        }
        // affichage du tableau de caractères
        printf("%s\n", pixels);
        // incrémentation de la variable i
        i++;
    }
    return 0;
}


int main(){
    // déclaration de la variable size
    int size;
    // affichage d'un message pour demander à l'utilisateur de saisir une valeur
    printf("Entrez une valeur pour taille (strictement inférieure à 10) pour voir le triangle rectangle: ");
    // lecture de la valeur saisie par l'utilisateur
    scanf("%d",&size);

    // vérification de la valeur saisie par l'utilisateur
    if (size >= 10 || size <= 0){
        // affichage d'un message d'erreur si la valeur saisie n'est pas valide
        printf("Erreur la taille doit être strictement inférieure à 10 et supérieur à 0\n");
        // retourne 1 pour indiquer que l'erreur est due à une valeur invalide
        return 1;
    }

    // appel de la fonction triangle_while avec la valeur saisie par l'utilisateur
    triangle_while(size);
    return 0;
}

