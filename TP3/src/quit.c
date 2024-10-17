#include "quit.h"

int traiter_quit(char text[1024], char lang[3]){
    //Quitte le programme
    if (strcmp(lang, "fr") == 0){
        printf("Arrêt...\n");
    }
    else{
        printf("Exit...\n");
    }
    return 0;
}