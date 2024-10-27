#ifndef REPL_H
#define REPL_H

// Inclusion des fichiers d'en-tête
#include "quit.h"
#include "help.h"
#include "version.h"
#include "echo.h"
#include "error.h"
#include "operation.h"

// Inclusion des librairies
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

// Structure Programme
struct Programme{
    char nom[25];
    char lang[3];
    int (*fonction)(char cmd[1024], char lang[3]);
};

#endif