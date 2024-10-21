#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ENTIER 0
#define FLOTTANT 1
#define STRING 2

struct Variable{
    char nom[25];
    int type;
    char valeur[100];
};

int setVariables(char commande[1024], struct Variable variables[100], int positionVariable);

void nameVariable(char commande[1024], char name[25]);

#endif