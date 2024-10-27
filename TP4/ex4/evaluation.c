/* Fichier: evaluation.c
 * Créer un tokenizeur, un parseur et un évaluateur capable d'évaluer des expressions arithmétiques (A opération B)
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 3.4
 */
#include "evaluation.h"
#include "parseur.h"
#include <stdio.h>

// Fonction qui évalue une opération
int evaluate(struct Operation operation){
    // On déclare les variables pour le résultat de l'opération
    int result;
    float resultFloat;

    // On évalue l'opération
    switch (operation.operateur){
        // On effectue l'opération en fonction de l'opérateur
        case PLUS:
        // On vérifie si le résultat doit être un float
            if (operation.floatResult == 1){
                // On effectue l'opération
                resultFloat = operation.operand1 + operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            // On effectue l'opération
            result = operation.operand1 + operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case MENUS:
        //On vérifie si le résultat doit être un float
            if (operation.floatResult == 1){
                // On effectue l'opération
                resultFloat = operation.operand1 - operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            // On effectue l'opération
            result = operation.operand1 - operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case MUL:
        //On vérifie si le résultat doit être un float
            if (operation.floatResult == 1){
                // On effectue l'opération
                resultFloat = operation.operand1 * operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            // On effectue l'opération
            result = operation.operand1 * operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case DIV:
        // On vérifie que l'opération est possible
            if (operation.operand2 == 0){
                printf("Division par 0 impossible\n\n");
                return 1;
            }
            // On vérifie si le résultat doit être un float
            if (operation.floatResult == 1){
                // On effectue l'opération
                resultFloat = operation.operand1 / operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            // On effectue l'opération
            result = operation.operand1 / operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        default:
            return 1;
    }
}