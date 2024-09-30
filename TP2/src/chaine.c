/* Fichier: chaine.c
* Manipulation de Chaînes de Caractères
* auteur: Pierre MOLY / Maxence LERDA
* Exercice 2.4
*/

#include <stdio.h>

int str_count(char str[]){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return count;
}


char* copie_chaine(char destination[], char source[]) {
    int i = 0;

    // Copier source dans destination
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    // Ajouter le caractère nul '\0' pour terminer la chaîne
    destination[i] = '\0';

    return destination;
}

char* str_concat(char resultat[], char str1[], char str2[]){
    int i = 0;
    resultat = str1;
    int size1 = str_count(str1);
    for (; str2[i] != '\0'; i++){
        resultat[size1 + i] = str2[i];
    }
    resultat[size1 + i] = '\0';
    return resultat;
}

int main() {
    char str1[100];
    char str1_copy[100];
    char str2[100];
    char concat[100];
    printf("Entrez une chaîne de caractères sans espace: ");
    scanf("%s", str1);

    printf("La longueur de la chaîne est : %d\n", str_count(str1));
    printf("La chaîne source est %s et la chaîne copiée est %s\n", str1, copie_chaine(str1_copy, str1));

    printf("Entrez une deuxième chaîne de caractères sans espace: ");
    scanf("%s", str2);

    printf("La chaîne concaténée est : %s\n", str_concat(concat, str1, str2));
    return 0;
}

