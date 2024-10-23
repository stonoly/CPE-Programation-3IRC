#ifndef REPL_3_3_H
#define REPL_3_3_H

// Structure Programme
struct Programme{
    char nom[25];
    char lang[3];
    int (*fonction)(char cmd[1024], char lang[3]);
};


#endif