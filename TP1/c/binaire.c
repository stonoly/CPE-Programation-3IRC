/* Fichier: binaire.c
* Affichage d'un nombre en format binaire
* auteur: Pierre MOLY
* Exercice 1.9
*/

#include <stdio.h>

int main(){
    int num;
    printf("Entrez un nombre: ");
    scanf("%d", &num);
    int bin[32];
    int position_tab = 0;

    if (num == 0) {
        printf("le binaire de %d est : 0\n", num);
        return 0;
    }

    for (int num_compt = num ; num_compt > 0; num_compt /= 2){
        bin[position_tab] = num_compt %2;
        position_tab++;
    }
    printf("le binaire de %d est : ", num);

    for (int i = position_tab-1; i >= 0; i--){
        printf("%d", bin[i]);
    }

    return 0;
}