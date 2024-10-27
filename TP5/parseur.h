#ifndef PARSEUR_H
#define PARSEUR_H

// include des fichiers nécessaires
#include "lexer.h"

// Définition des opérateurs
#define PLUS 'p'
#define MENUS 'm'
#define MUL 'x'
#define DIV 'd'
#define ERROR 'e'

// Définition de la structure Operation
struct Operation {
    float operand1;
    float operand2;
    char operateur;
    int floatResult;
};

// Déclaration de la fonction pour définir l'opérateur
char defineOperateur(char c);


// Déclaration de la fonction pour parser une opération
struct Operation parsing(struct Token* tokens, struct Operation operation);

#endif