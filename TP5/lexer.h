#ifndef LEXER_H
#define LEXER_H

#define INTEGER 'i'
#define FLOAT 'f'
#define OPERATEUR 'o'

struct Token {
    char type;
    char value[100];
};

struct Token* tokenize(char operation[1024], struct Token tokens[3]);

// Déclaration de la fonction pour vérifier si un caractère est un opérateur
int isOperator(char c);

#endif