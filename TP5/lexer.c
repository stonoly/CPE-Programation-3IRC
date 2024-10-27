/* Fichier: lexer.c
 * Créer un tokenizeur, un parseur et un évaluateur capable d'évaluer des expressions arithmétiques (A opération B)
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 3.4
 */

// include des fichiers nécessaires
#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fonction pour vérifier si un caractère est un opérateur
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct Token* tokenize(char operation[1024], struct Token tokens[3]) {
    // On initialise le tableau de tokens
    int i = 0;
    int positionList = 0;
    // On parcourt la chaine de caractères
    while (i < strlen(operation)){
        if (operation[i] == ' '){
            // On ignore les espaces
            i++;
            continue;
        }
        else{
            // On vérifie si le caractère est un opérateur ou un nombre
            if (!isOperator(operation[i]) && (operation[i] < '0' || operation[i] > '9') && operation[i] != '.' && operation[i] != ' ') {
                // On retourne une erreur si le caractère n'est pas autorisé
                tokens[0].type = 'e';
                printf("Erreur: caractère non autorisé '%c'\n\n", operation[i]);
                return tokens;
            }
             if (isOperator(operation[i])){
                // On ajoute l'opérateur à la liste
                struct Token operator = {OPERATEUR, {operation[i]}};
                tokens[positionList] = operator;
                // On incrémente la position dans la liste
                positionList++;
            
            } else {
                // On ajoute l'opérande à la liste
                int j = i;
                char operand[100] = "";
                int floatFlag = 0;
                // On récupère l'opérande
                while (operation[j] != ' ' && operation[j] != '\0'){
                    if (operation[j] == '.'){
                        floatFlag = 1;
                    }
                    // On ajoute le caractère à l'opérande
                    operand[strlen(operand)] = operation[j];
                    operand[strlen(operand) + 1] = '\0';
                    // On incrémente la position
                    j++;
                    i = j;
                }
                // On ajoute l'opérande à la liste
                struct Token operandToken = {floatFlag ? FLOAT : INTEGER, ""};
                // On copie l'opérande dans le token
                strcpy(operandToken.value, operand);
                // On ajoute le token à la liste
                tokens[positionList] = operandToken;
                positionList++;
            }
            // On incrémente la position
            i++;
        }   
    }

    // On retourne la liste de tokens
    return tokens;
}