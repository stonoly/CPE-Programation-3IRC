#ifndef REPL_3_2_H
#define REPL_3_2_H

struct Programme{
    char nom[25];
    int (*fonction)(char cmd[1024]);
};


#endif