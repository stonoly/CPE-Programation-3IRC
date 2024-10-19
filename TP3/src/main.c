#include <stdio.h>
#include "lexer.h"
#include "parseur.h"
#include "evaluation.h"

int main(){
    char operation[1024];
    printf("Entrez une opération : ");
    fgets(operation, sizeof(operation), stdin);

    struct Token tokens[3];  // Tableau statique de 3 tokens
    struct Token* returnedTokens = tokenize(operation, tokens); 

    struct Operation operationStruct;
    struct Operation returnedOperation = parsing(returnedTokens, operationStruct);

    int resultFinal = evaluate(returnedOperation);
    return resultFinal;
}
