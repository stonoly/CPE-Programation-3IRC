/* Fichier: ex1.c
* Parser l'expression en notation postfixée
* Auteur: Pierre MOLY Maxence LERDA
* Exercice 4.1

* https://koor.fr/C/cstring/strcspn.wp
* https://code.quora.com/How-to-check-if-a-string-is-a-number-in-C#:~:text=If%20you%20want%20to%20check,and%20return%20zero%20if%20not.
* https://koor.fr/C/cctype/isdigit.wp
*/

#include "ex1.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fonction pour vérifier si un caractère est un opérateur
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Fonction pour déterminer la priorité des opérateurs
int priority_operator(char op) {
    // Priorité des opérateurs
    if (op == '*' || op == '/') {
        return 2;
    // Priorité des opérateurs
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

int main() {
    char exitString[100] = "";  // Chaîne de sortie postfixée
    char stringInfix[100] = ""; // Chaîne d'entrée infixée

    // Lire l'expression infixée
    printf("Entrez une expression arithmétique en notation infixée (35 + 42 * 52): ");
    fgets(stringInfix, sizeof(stringInfix), stdin);

    // Supprimer le '\n' capturé par fgets
    stringInfix[strcspn(stringInfix, "\n")] = '\0';

    char pileOperator[100];  // Pile pour les opérateurs
    int positionOperator = 0;

    int i = 0;
    while (i < strlen(stringInfix)) {
        // Ignorer les espaces
        if (stringInfix[i] == ' ') {
            i++;
            continue;
        }

        // Si c'est un nombre (multi-chiffres possible)
        if (isdigit(stringInfix[i])) {
            // Extraire le nombre complet
            while (i < strlen(stringInfix) && isdigit(stringInfix[i])) {
                char digit[2] = {stringInfix[i], '\0'}; // Créer une chaîne avec le chiffre
                strcat(exitString, digit);              // Ajouter à la sortie
                i++;
            }
            // Ajouter un espace après chaque nombre
            strcat(exitString, " ");
        }
        // Si c'est un opérateur
        else if (isOperator(stringInfix[i])) {
            // Comparer la priorité de l'opérateur actuel avec celui au sommet de la pile
            while (positionOperator > 0 && 
                   priority_operator(pileOperator[positionOperator - 1]) >= priority_operator(stringInfix[i])) {
                // Dépiler les opérateurs de plus haute ou égale priorité
                char op[2] = {pileOperator[--positionOperator], '\0'};
                strcat(exitString, op);
                strcat(exitString, " ");
            }
            // Empiler l'opérateur courant
            pileOperator[positionOperator++] = stringInfix[i];
            i++;
        }
    }

    // Ajouter les opérateurs restants dans la pile à la sortie
    while (positionOperator > 0) {
        char op[2] = {pileOperator[--positionOperator], '\0'};
        strcat(exitString, op);
        strcat(exitString, " ");
    }

    printf("Postfix expression: %s\n", exitString);

    return 0;
}
