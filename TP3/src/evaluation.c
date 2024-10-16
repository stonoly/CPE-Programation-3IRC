#include "evaluation.h"
#include "parseur.h"
#include <stdio.h>

int evaluate(struct Operation operation){
    int result;
    switch (operation.operateur){
        case PLUS:
            result = operation.operand1 + operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case MENUS:
            result = operation.operand1 - operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case MUL:
            result = operation.operand1 * operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case DIV:
            if (operation.operand2 == 0){
                printf("Division par 0 impossible\n");
                return 1;
            }
            result = operation.operand1 / operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        default:
            return 1;
    }
}