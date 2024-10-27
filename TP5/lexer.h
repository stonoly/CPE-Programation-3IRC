#ifndef LEXER_H
#define LEXER_H

// Définition des types de token
#define INTEGER 'i'
#define FLOAT 'f'
#define OPERATEUR 'o'

// Définition de la structure Token
struct Token {
    char type;
    char value[100];
};

// Déclaration de la fonction pour tokenizer une opération
struct Token* tokenize(char operation[1024], struct Token tokens[3]);

// Déclaration de la fonction pour vérifier si un caractère est un opérateur
int isOperator(char c);

#endif