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
        printf("Vous pouvez aussi faire des operations aves les opérateurs +, -, *, / et des nombres entiers ou flottants, vous devez respecter la syntaxe A operateur B\n");
        printf("Vous pouver aussi faire des operations plus complexes en utilisant des parenthèses\n");
        printf("Vous pouvez aussi définir des variables avec le signe =, exemple: a = 5 et les afficher\n");
    }
    else{
        printf("Help: \n");
        printf("----------\n");
        printf("echo <text>: display the text\n");
        //printf("date: display the date\n");
        printf("help: display the help\n");
        printf("quit: quit the program\n");
        printf("version: display the shell version\n");
        printf("You can also do operations with the operators +, -, *, / and integers or floats, you must respect the syntax A operator B\n");
        printf("You can also do more complex operations using parentheses\n");
        printf("You can also define variables with the = sign, example: a = 5 and display them\n");
    }
    return 1;
}