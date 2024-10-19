#include "postFixToResult.h"

// Fonction pour appliquer l'opérateur sur deux opérandes
int applyOperator(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0){
                printf("Erreur : Division par 0 impossible\n\n");
                return 0;
            }
            return operand1 / operand2;

        default: return 0;  // Au cas où, même si on ne devrait jamais atteindre ce cas
    }
}

int postFixToResult(char postfixExpression[100]){
    // Déclaration des variables
    int operandStack[100];
    int top = -1;

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
    printf("%d\n", finalResult);

    return 0;
}
