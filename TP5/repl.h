#ifndef REPL_H
#define REPL_H

// Inclusion des fichiers necessaires
#include "quit.h"
#include "help.h"
#include "version.h"
#include "echo.h"
#include "error.h"
#include "operation.h"
#include "infixToPostFix.h"
#include "postFixToResult.h"
#include "variables.h"
#include "lambda.h"

// Inclusion des librairies
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

// Définition de la structure Programme
struct Programme{
    char nom[25];
    char lang[3];
    int (*fonction)(char cmd[1024], char lang[3]);
};

#endif