#ifndef LAMBDA_H
#define LAMBDA_H

// Inclusion des librairies
#include <stdio.h>
#include <string.h>

// Inclusion des fichiers nécessaires
#include "variables.h"
#include "infixToPostFix.h"
#include "postFixToResult.h"

// Fonction pour vérifier si une commande commence par "(lambda x."
int isLambda(char commande[1024]);

// Fonction pour extraire un nombre d'une commande
void nombreRemplacement(char commande[1024], char nombre[100]);

// Fonction pour inverser une chaîne de caractères
void strrev(char* str);

// Fonction pour extraire une opération d'une commande temporaire
void operationTemp(char commande[1024], char op[100]);

// Fonction pour vérifier si une variable est définie et de type correct
int verificationVar(char nombre[100], struct Variable variables[100], int positionVariable);

// Fonction pour effectuer la dernière opération
void finalOperation(char op[100], char nombre[100]);

// Fonction pour effectuer une lambda
int lambda(char commande[1024], struct Variable variables[100], int positionVariable);


#endif