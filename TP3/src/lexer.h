#ifndef LEXER_H
#define LEXER_H

enum TokenTypes {
    /* data */
    INT,
    FLOAT,
    PLUS,
    MINUS,
    MULT,
    DIV,
    ERROR,
    END
};

struct Token {
    enum TokenTypes type;
    float value;
};

struct Token* tokenize(char* operation);


#endif