#ifndef REPL_H
#define REPL_H

// Inclusion des fichiers nécessaires
#include "quit.h"
#include "help.h"
#include "version.h"
#include "echo.h"
#include "error.h"
#include "operation.h"
#include "infixToPostFix.h"
#include "postFixToResult.h"

// Inclusion des librairies nécessaires
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

// Structure pour les commandes
struct Programme{
    char nom[25];
    char lang[3];
    int (*fonction)(char cmd[1024], char lang[3]);
};

#endif