#ifndef POSTFIXTORESULT_H
#define POSTFIXTORESULT_H

#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fonction pour appliquer l'opérateur sur deux opérandes
int applyOperator(char operator, int operand1, int operand2);

int postFixToResult(char postfixExpression[100]);

#endif