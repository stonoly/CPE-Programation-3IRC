/* Fichier: boucles.c
* Affichage d'un triangle rectangle avec des boucles
* auteur: Pierre MOLY
* Exercice 1.6
*/

#include <stdio.h>
#include <string.h>

int triangle(int size){
    for (int i = 0; i < size + 1; i++){
        char pixels[(i + 1) * 2];
        pixels[0] = '\0';

        for (int j = 0; j < i; j++){
            if (j == i - 1 || j == 0 || i == size){
                strcat(pixels, "* ");
            } else {
                strcat(pixels, "# ");
            }
        }
        printf("%s\n", pixels);
    }
    return 0;
}

int triangle_while(int size){
    int i = 0;
    while (i < size + 1){
        char pixels[(i + 1) * 2];
        pixels[0] = '\0';

        int j = 0;
        while (j < i){
            if (j == i - 1 || j == 0 || i == size){
                strcat(pixels, "* ");
            } else {
                strcat(pixels, "# ");
            }
            j++;
        }
        printf("%s\n", pixels);
        i++;
    }
    return 0;
}


int main(){
    int size;
    printf("Entrez une valeur pour taille (strictement inférieure à 10) pour voir le triangle rectangle: ");
    scanf("%d",&size);

    if (size >= 10 || size <= 0){
        printf("Erreur la taille doit être strictement inférieure à 10 et supérieur à 0\n");
        return 1;
    }

    triangle_while(size);
    return 0;
}

