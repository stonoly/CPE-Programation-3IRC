#ifndef PARSEUR_H
#define PARSEUR_H

#include "lexer.h"

#define PLUS 'p'
#define MENUS 'm'
#define MUL 'x'
#define DIV 'd'
#define ERROR 'e'

struct Operation {
    float operand1;
    float operand2;
    char operateur;
    int floatResult;
};

char defineOperateur(char c);


struct Operation parsing(struct Token* tokens, struct Operation operation);

#endif