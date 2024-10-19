#include "error.h"

int erreur(char commande[1024]){
    int stop = 0;
    int compteur = 0;
    char echo[5] = "echo";
    int erreur_echo = 0;

    while (stop == 0) {
        if (strncmp(&commande[compteur], echo, 4) == 0) {
            compteur += 4;
            if (commande[compteur] != ' ') {
                stop = 1;
                erreur_echo = 1;
            }
        } else {
            stop = 1;
        }
    }
    
    if (erreur_echo == 1) {
        printf("Error: the echo command must be followed by a space and the text to display.\n");
        printf("Erreur: la commande echo doit être suivie d'un espace et du texte à afficher.\n");
    }else {
        printf("Commande non reconnue. Essayez 'help' ou 'aide' pour afficher les commandes disponibles.\n");
        printf("Command not recognized. Try 'help' to display the available commands.\n");
    }

    return 0;
}