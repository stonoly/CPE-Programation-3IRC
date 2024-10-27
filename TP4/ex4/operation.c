/* Fichier: operation.c
 * Créer un tokenizeur, un parseur et un évaluateur capable d'évaluer des expressions arithmétiques (A opération B)
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 3.4
 */

#include "operation.h"

// Fonction qui évalue une opération
int operation(char operation[1024]){

    // On initialise le tableau de tokens
    struct Token tokens[3];  // Tableau statique de 3 tokens
    // On tokenize l'opération
    struct Token* returnedTokens = tokenize(operation, tokens); 

    // On initialise la structure Operation
    struct Operation operationStruct;
    // On parse l'opération
    struct Operation returnedOperation = parsing(returnedTokens, operationStruct);

    // On évalue l'opération
    int resultFinal = evaluate(returnedOperation);
    
    // On retourne le résultat de l'opération
    return resultFinal;
}
