#ifndef OPERATION_H
#define OPERATION_H

// include des librairies nécessaires
#include <stdio.h>

// include des fichiers nécessaires
#include "lexer.h"
#include "parseur.h"
#include "evaluation.h"

// Fonction qui évalue une opération
int operation(char operation[1024]);

#endif