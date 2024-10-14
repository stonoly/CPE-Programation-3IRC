#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Token* tokenize(char* operation){
    struct Token* tokens[2];
    printf("Tokenizing: %s\n", operation);
    char operande[100];
    int compteurListe = 0;
    int floatFlag = 0;
    for (int i = 0; i < strlen(operation) - 1; i++){
        printf("Operation[%d]: %c\n", i, operation[i]);
        if (operation[i] != ' '){
            if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/'){
                struct Token operatorToken;
                switch (operation[i]) {
                    case '+':
                        operatorToken.type = PLUS;
                        break;
                    case '-':
                        operatorToken.type = MINUS;
                        break;
                    case '*':
                        operatorToken.type = MULT;
                        break;
                    case '/':
                        operatorToken.type = DIV;
                        break;
                }
                tokens[compteurListe] = &operatorToken;
                compteurListe++;
            } else {
                if (operation[i] == '.'){
                    floatFlag = 1;
                }
                strncat(operande, &operation[i], 1);
                printf("Operande : %s\n", operande);
            }
        } else {
            printf("Operande espace: %s\n", operande);
            struct Token operandeToken;
            float value = atof(operande);
            operandeToken.value = value;
            printf("Value: %f\n", value);
            if (floatFlag == 1){
                operandeToken.type = FLOAT;
            } else {
                operandeToken.type = INT;
            }
            tokens[compteurListe] = &operandeToken;
            printf("Token[%d]: %f\n", compteurListe, tokens[compteurListe]->value);
            strcpy(operande, "");
            compteurListe++;
            floatFlag = 0;
        }
    }
    printf("Token[1]: %f\n", tokens[1]->value);
    printf("sizeof(tokens): %ld\n", sizeof(tokens));
    for (int i = 0; i < 2; i++){
        printf("Token[%d]: %d\n", i, tokens[i]->type);
        printf("Token[%d]: %f\n", i, tokens[i]->value);
    }
    return *tokens;
}

int main(){
    char operation[5] = "1 + 2";
    struct Token* tokens = tokenize(operation);
    return 0;
}