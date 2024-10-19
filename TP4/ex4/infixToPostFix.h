#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Déclaration de la fonction pour convertir une expression infixée en postfixée
int infixToPostfix(const char infix[100], char postfix[100]);


// Déclaration de la fonction pour déterminer la priorité des opérateurs
int priority_operator(char op);

#endif // INFIXTOPOSTFIX_H