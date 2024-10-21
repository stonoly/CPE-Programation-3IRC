#ifndef REPL_H
#define REPL_H

#include "quit.h"
#include "help.h"
#include "version.h"
#include "echo.h"
#include "error.h"
#include "operation.h"
#include "infixToPostFix.h"
#include "postFixToResult.h"
#include "variables.h"

#include <time.h>
#include <stdlib.h>
#include <ctype.h>

struct Programme{
    char nom[25];
    char lang[3];
    int (*fonction)(char cmd[1024], char lang[3]);
};

#endif