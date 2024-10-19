#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fonction pour vérifier si un caractère est un opérateur
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct Token* tokenize(char operation[1024], struct Token tokens[3]) {
    int i = 0;
    int positionList = 0;
    while (i < strlen(operation)){
        if (operation[i] == ' '){
            i++;
            continue;
        }
        else{
            if (!isOperator(operation[i]) && (operation[i] < '0' || operation[i] > '9') && operation[i] != '.' && operation[i] != ' ') {
                tokens[0].type = 'e';
                printf("Erreur: caractère non autorisé '%c'\n", operation[i]);
                return tokens;
            }

             if (isOperator(operation[i])){
                struct Token operator = {OPERATEUR, {operation[i]}};
                tokens[positionList] = operator;
                positionList++;
            } else {
                int j = i;
                char operand[100] = "";
                int floatFlag = 0;
                while (operation[j] != ' ' && operation[j] != '\0'){
                    if (operation[j] == '.'){
                        floatFlag = 1;
                    }
                    operand[strlen(operand)] = operation[j];
                    operand[strlen(operand) + 1] = '\0';
                    j++;
                    i = j;
                }
                struct Token operandToken = {floatFlag ? FLOAT : INTEGER, ""};
                strcpy(operandToken.value, operand);
                tokens[positionList] = operandToken;
                positionList++;
            }
            i++;
        }   
    }

    if (positionList != 3) {
        tokens[0].type = 'e';
    }

    return tokens;
}