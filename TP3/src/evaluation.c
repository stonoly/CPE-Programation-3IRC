#include "evaluation.h"
#include "parseur.h"
#include <stdio.h>

int evaluate(struct Operation operation){
    int result;
    float resultFloat;

    switch (operation.operateur){
        case PLUS:
            if (operation.floatResult == 1){
                resultFloat = operation.operand1 + operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            result = operation.operand1 + operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case MENUS:
            if (operation.floatResult == 1){
                resultFloat = operation.operand1 - operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            result = operation.operand1 - operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case MUL:
            if (operation.floatResult == 1){
                resultFloat = operation.operand1 * operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            result = operation.operand1 * operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        case DIV:
            if (operation.operand2 == 0){
                printf("Division par 0 impossible\n");
                return 1;
            }
            if (operation.floatResult == 1){
                resultFloat = operation.operand1 / operation.operand2;
                printf("Resultat : %f\n", resultFloat);
                return 0;
            }
            result = operation.operand1 / operation.operand2;
            printf("Resultat : %d\n", result);
            return 0;
        default:
            return 1;
    }
}