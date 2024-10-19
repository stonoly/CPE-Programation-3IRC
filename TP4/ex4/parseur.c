#include "parseur.h"
#include <stdio.h>
#include <stdlib.h>



char defineOperateur(char c){
    if (c == '+'){
        return PLUS;
    } else if (c == '-'){
        return MENUS;
    } else if (c == '*'){
        return MUL;
    } else if (c == '/'){
        return DIV;
    } else {
        return ERROR;
    }
}

struct Operation parsing(struct Token* tokens, struct Operation operation){
    int firstOperand = 0;
    operation.floatResult = 0;
    if (tokens[0].type == 'e'){
        operation.operateur = ERROR;
        return operation;
    }
    for (int i = 0; i < 3; i++){
        if (tokens[i].type == INTEGER || tokens[i].type == FLOAT){
            if (tokens[i].type == FLOAT){
                operation.floatResult = 1;
            }
            if (firstOperand == 0){
                operation.operand1 = atof(tokens[i].value);
                firstOperand = 1;
            } else {
                operation.operand2 = atof(tokens[i].value);
            }
        } else {
            operation.operateur = defineOperateur(*tokens[i].value);
        }
    }
    return operation;
}