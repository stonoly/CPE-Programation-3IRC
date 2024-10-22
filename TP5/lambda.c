#include "lambda.h"

int isLambda(char commande[1024]){
    int i = 0;
    char lambda[10] = "(lambda x.";
    while (i < 10 && commande[i] != '\0'){
        if (commande[i] == lambda[i]){
            i++;
        } else {
            return 0;
        }
    }
    return 1;
}

void strrev(char* str) {
    int i, j;
    char temp;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
 
void nombreRemplacement(char commande[1024], char nombre[100]){
    int i = strlen(commande) - 1;

    while ( i > 0 && commande[i] != ' '){
        char temp[2] = { commande[i], '\0' };
        strncat(nombre, temp, 1);
        i--;
    }
    strrev(nombre);
}

void operationTemp(char commande[1024], char op[100]){
    int positionEnd = strlen(commande) - 1;
    while (commande[positionEnd] != ')'){
        positionEnd--;
    }
    int i = 10;
    while (i < positionEnd){
        char temp[2] = { commande[i], '\0' };
        strncat(op, temp, 1);
        i++;
    }

}

int verificationVar(char nombre[100], struct Variable variables[100], int positionVariable){
    int typeNombre = typeVariable(nombre);
    if (typeNombre == STRING){
        int varExist = searchVariable(nombre, variables, positionVariable);
        if(varExist != -1 && variables[varExist].type != STRING){
            strcpy(nombre, variables[varExist].valeur);
        } else {
            printf("Erreur : la variable z n'est pas définie ou de mauvais type\n\n");
            return 1;
        }
    }
    return 0;

}

void finalOperation(char op[100], char nombre[100]){
    char finalOp[100] = "";
    for (int i = 0; i < strlen(op); i++){
        if (op[i] == 'x'){
            strcat(finalOp, nombre);
        } else {
            char temp[2] = { op[i], '\0' };
            strcat(finalOp, temp);
        }
    }
    strcpy(op, finalOp);
    strcat(op, "\n");

}

int lambda(char commande[1024], struct Variable variables[100], int positionVariable){
    char nombre[100] = "";
    char op[100] = "";
    nombreRemplacement(commande, nombre);
    operationTemp(commande, op);
    int error = verificationVar(nombre, variables, positionVariable);
    if (!error){
        finalOperation(op, nombre);
        char postFix[100] = "";
        error = infixToPostfix(op, postFix);
        if (!error){
            error = postFixToResult(postFix);
        }
    }
    return error;
}
