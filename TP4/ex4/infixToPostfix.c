#include "infixToPostFix.h"

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

int infixToPostfix(const char stringInfix[100], char exitString[100]) {

    char pileOperator[100];  // Pile pour les opérateurs
    int positionOperator = 0;

    int i = 0;
    while (i < strlen(stringInfix) - 1) {
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

        // Si c'est une parenthèse ouvrante
        else if(stringInfix[i] == '('){
            // Empiler l'opérateur courant
            pileOperator[positionOperator++] = stringInfix[i];
            i++;
        }
        // Si c'est une parenthèse fermante
        else if (stringInfix[i] == ')') {
            // Dépiler les opérateurs jusqu'à la parenthèse ouvrante
            while (positionOperator > 0 && pileOperator[positionOperator - 1] != '(') {
                // Dépiler les opérateurs de plus haute ou égale priorité
                char op[2] = {pileOperator[--positionOperator], '\0'};
                // Ajouter à la sortie
                strcat(exitString, op);
                strcat(exitString, " ");
            }
            // Dépiler la parenthèse ouvrante
            if (positionOperator > 0) {
                positionOperator--;
            } else {
                printf("Erreur : Parenthèse fermante sans correspondance.\n \n");
                return 1;  // Erreur
            }
            i++;
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
        } else {
            printf("Erreur : Caractère invalide.\n \n");
            return 1;
        }
    }

    // Ajouter les opérateurs restants dans la pile à la sortie
    while (positionOperator > 0) {
        char op[2] = {pileOperator[--positionOperator], '\0'};
        strcat(exitString, op);
        strcat(exitString, " ");
    }

    return 0;
}