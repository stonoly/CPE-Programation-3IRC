#include "echo.h"

int traiter_echo(char text[1024], char lang[3]){
    //Affiche le texte
    printf("Echo: ");
    for (int i = 5; text[i] != '\0'; i++)
        {
            printf("%c", text[i]);
    }
    return 1;
}