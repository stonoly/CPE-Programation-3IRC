#ifndef LAMBDA_H
#define LAMBDA_H

#include <stdio.h>
#include <string.h>
#include "variables.h"
#include "infixToPostFix.h"
#include "postFixToResult.h"

int isLambda(char commande[1024]);

void nombreRemplacement(char commande[1024], char nombre[100]);

void strrev(char* str);

void operationTemp(char commande[1024], char op[100]);

int verificationVar(char nombre[100], struct Variable variables[100], int positionVariable);

void finalOperation(char op[100], char nombre[100]);

int lambda(char commande[1024], struct Variable variables[100], int positionVariable);


#endif