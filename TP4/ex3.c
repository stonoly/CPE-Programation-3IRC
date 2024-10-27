/* Fichier: ex3.c
* Évaluer l'expression postfixée
* Auteur: Pierre MOLY Maxence LERDA
* Exercice 4.3
*
*/

#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fonction pour vérifier si un caractère est un opérateur
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Fonction pour appliquer l'opérateur sur deux opérandes
int applyOperator(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;  // Au cas où, même si on ne devrait jamais atteindre ce cas
    }
}

int main() {
    // Déclaration des variables
    char postfixExpression[100] = "";
    int operandStack[100];
    int top = -1;

    // Lire l'expression postfixée
    printf("Enter a postfix expression (e.g., '3 4 5 * +'): ");
    fgets(postfixExpression, sizeof(postfixExpression), stdin);

    // Supprimer le '\n' capturé par fgets
    postfixExpression[strcspn(postfixExpression, "\n")] = '\0';

    // Parcourir chaque caractère de l'expression postfixée
    int i = 0;
    while (i < strlen(postfixExpression)) {
        // Ignorer les espaces
        if (postfixExpression[i] == ' ') {
            i++;
            continue;
        }

        // Si c'est un opérande (nombre), on le pousse sur la pile
        if (isdigit(postfixExpression[i])) {
            // Extraire le nombre complet (multi-chiffres possibles)
            int operand = 0;
            while (i < strlen(postfixExpression) && isdigit(postfixExpression[i])) {
                // Construire le nombre en utilisant la fonction atoi
                operand = atoi(&postfixExpression[i]);
                i++;
            }
            // Pousser le nombre sur la pile
            operandStack[++top] = operand;
        }
        // Si c'est un opérateur, on dépile les deux derniers opérandes
        else if (isOperator(postfixExpression[i])) {
            // Dépiler les deux derniers opérandes
            int operand2 = operandStack[top--]; 
            int operand1 = operandStack[top--];
            

            // Appliquer l'opérateur et pousser le résultat sur la pile
            int result = applyOperator(postfixExpression[i], operand1, operand2);
            // Pousser le résultat sur la pile
            operandStack[++top] = result;

            i++;  // Passer à l'opérateur suivant
        }
    }

    // À la fin, le sommet de la pile contient le résultat final
    int finalResult = operandStack[top];
    printf("Résultat: %d\n", finalResult);

    return 0;
}
