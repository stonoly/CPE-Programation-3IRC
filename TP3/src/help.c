#include "help.h"

int afficher_aide(char text[1024], char lang[3]){
    //Affiche l'aide
    if (strcmp(lang, "fr") == 0){
        printf("Aide: \n");
        printf("----------\n");
        printf("echo <text>: affiche le texte\n");
        //printf("date: affiche la date\n");
        printf("help: affiche l'aide\n");
        printf("quit: quitte le programme\n");
        printf("version: affiche la version du shell\n");
    }
    else{
        printf("Help: \n");
        printf("----------\n");
        printf("echo <text>: display the text\n");
        //printf("date: display the date\n");
        printf("help: display the help\n");
        printf("quit: quit the program\n");
        printf("version: display the shell version\n");
    }
    return 1;
}