/* Fichier: parseur.c
 * Créer un tokenizeur, un parseur et un évaluateur capable d'évaluer des expressions arithmétiques (A opération B)
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 3.4
 */

#include "parseur.h"
#include <stdio.h>
#include <stdlib.h>



// Fonction pour définir l'opérateur
char defineOperateur(char c){
    // On retourne l'opérateur correspondant
    if (c == '+'){
        return PLUS;
    } else if (c == '-'){
        return MENUS;
    } else if (c == '*'){
        return MUL;
    } else if (c == '/'){
        return DIV;
    } else {
        // On retourne une erreur si l'opérateur n'est pas reconnu
        return ERROR;
    }
}

// Fonction pour parser une opération
struct Operation parsing(struct Token* tokens, struct Operation operation){
    // On initialise les variables de l'opération
    int firstOperand = 0;
    // On initialise le résultat de l'opération
    operation.floatResult = 0;
    // On vérifie si l'opération est une erreur
    if (tokens[0].type == 'e'){
        operation.operateur = ERROR;
        return operation;
    }
    // On parcourt les tokens
    for (int i = 0; i < 3; i++){
        // On vérifie le type du token
        if (tokens[i].type == INTEGER || tokens[i].type == FLOAT){
            // On vérifie si l'opérande est un float
            if (tokens[i].type == FLOAT){
                operation.floatResult = 1;
            }
            // On ajoute l'opérande à l'opération
            if (firstOperand == 0){
                // Si c'est le premier opérande, on l'ajoute à l'opération
                operation.operand1 = atof(tokens[i].value);
                firstOperand = 1;
            } else {
                // Sinon, on ajoute le deuxième opérande
                operation.operand2 = atof(tokens[i].value);
            }
        } else {
            // On ajoute l'opérateur à l'opération
            operation.operateur = defineOperateur(*tokens[i].value);
        }
    }
    // On retourne l'opération
    return operation;
}