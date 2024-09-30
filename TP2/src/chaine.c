/* Fichier: chaine.c
* Manipulation de Chaînes de Caractères
* auteur: Pierre MOLY / Maxence LERDA
* Exercice 2.4
*/

#include <stdio.h>

int str_count(char str[]){
    // Compter le nombre de caractères dans la chaîne
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
    // recopier str1 dans resultat
    resultat = str1;
    // récupérer la taille de str1 avec str_count
    int size1 = str_count(str1);

    for (; str2[i] != '\0'; i++){
        // ajouter les caractères de str2 à la fin de str1
        resultat[size1 + i] = str2[i];
    }
    // ajouter le caractère nul '\0' pour terminer la chaîne
    resultat[size1 + i] = '\0';
    // retourner la chaîne concaténée
    return resultat;
}

int main() {
    // déclarer les chaînes de caractères
    char str1[100];
    char str1_copy[100];
    char str2[100];
    char concat[100];
    // demander à l'utilisateur de saisir une chaîne de caractères sans espace
    printf("Entrez une chaîne de caractères sans espace: ");
    // lire la chaîne de caractères saisie par l'utilisateur
    scanf("%s", str1);
    // afficher la longueur de la chaîne
    printf("La longueur de la chaîne est : %d\n", str_count(str1));
    // afficher la chaîne source et la chaîne copiée
    printf("La chaîne source est %s et la chaîne copiée est %s\n", str1, copie_chaine(str1_copy, str1));
    // demander à l'utilisateur de saisir une deuxième chaîne de caractères sans espace
    printf("Entrez une deuxième chaîne de caractères sans espace: ");
    scanf("%s", str2);
    // afficher la chaîne concaténée
    printf("La chaîne concaténée est : %s\n", str_concat(concat, str1, str2));
    return 0;
}

