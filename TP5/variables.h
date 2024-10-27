#ifndef VARIABLES_H
#define VARIABLES_H

// Inclusion des librairies
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Définition des types de variables
#define ENTIER 0
#define FLOTTANT 1
#define STRING 2

// Définition de la structure Variable
struct Variable{
    char nom[25];
    int type;
    char valeur[100];
};

// Fonction pour définir ou modifier une variable
int setVariables(char commande[1024], struct Variable variables[100], int positionVariable);

// Fonction pour afficher le type d'une variable
void nameVariable(char commande[1024], char name[25]);

// Fonction pour récupérer la valeur d'une variable
int typeVariable(char valeur[100]);

// Fonction pour rechercher une variable dans un tableau de variables
int searchVariable(char name[25], struct Variable variables[100], int positionVariable);

#endif