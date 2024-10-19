#include "operation.h"

int operation(char operation[1024]){

    struct Token tokens[3];  // Tableau statique de 3 tokens
    struct Token* returnedTokens = tokenize(operation, tokens); 

    struct Operation operationStruct;
    struct Operation returnedOperation = parsing(returnedTokens, operationStruct);

    int resultFinal = evaluate(returnedOperation);
    
    return resultFinal;
}
