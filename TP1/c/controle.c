/* Fichier: controle.c
* Afficher les nombres de 1 à 1000 qui répondent à une condition donnée
* auteur: Pierre MOLY
* Exercice 1.7
*/

#include <stdio.h>

// fonction pour vérifier si un nombre est divisible par 4 mais pas par 6
int divisible_by4_but_not_by6(int n){
    if (n % 4 == 0 && n % 6 != 0){
        return 1;
    }
    return 0;
}

// fonction pour vérifier si un nombre est pair et divisible par 8
int number_pairs_and_divisible_by8(int n){
    if (n % 2 == 0 && n % 8 == 0){
        return 1;
    }
    return 0;
}

// fonction pour vérifier si un nombre est divisible par 5 ou 7 mais pas par 10
int divisible_by5_or_7_but_not10(int n){
    if ((n % 5 == 0 || n % 7 == 0) && n % 10 != 0){
        return 1;
    }
    return 0;
}

int main(){
    // initialisation des tableaux de 1000 éléments à 0
    int div4_not6[1000] = {0};
    int div8_pairs[1000] = {0};
    int div5_or7_not10[1000] = {0};

    for (int i = 0; i < 1000; i++){
        // vérification de la condition pour le tableau div4_not6
        if (divisible_by4_but_not_by6(i+1)){
            div4_not6[i] = i+1;
        }

        // vérification de la condition pour le tableau div8_pairs
        if (number_pairs_and_divisible_by8(i+1)){
            div8_pairs[i] = i+1;
        }

        // vérification de la condition pour le tableau div5_or7_not10
        if (divisible_by5_or_7_but_not10(i+1)){
            div5_or7_not10[i] = i+1;
        }
    }

    // affichage des résultats
    printf("--------------------\n");
    printf("Voici les chiffres qui sont div par 4 mais pas par 6:\n");
    for (int i = 0; i < 1000; i++) {
        if (div4_not6[i] != 0) {
            printf("%d, ", div4_not6[i]);
        }

    }
    printf("\n");

    printf("--------------------\n");
    printf("Voici les chiffres pairs et div par 8:\n");
    for (int i = 0; i < 1000; i++) {
        if (div8_pairs[i] != 0) {
            printf("%d, ", div8_pairs[i]);
        }

    }
    printf("\n");

    printf("--------------------\n");
    printf("Voici les chiffres div par 5 ou 7 mais pas par 10:\n");
    for (int i = 0; i < 1000; i++) {
        if (div5_or7_not10[i] != 0) {
            printf("%d, ", div5_or7_not10[i]);
        }

    }
    printf("\n");

    return 0;
}

