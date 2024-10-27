#include "error.h"

int erreur(char commande[1024]){
    // Fonction qui affiche un message d'erreur si la commande n'est pas reconnue
    int stop = 0;
    int compteur = 0;
    char echo[5] = "echo";
    int erreur_echo = 0;

    while (stop == 0) {
        // Vérifie si la commande est "echo"
        if (strncmp(&commande[compteur], echo, 4) == 0) {
            compteur += 4;
            if (commande[compteur] != ' ') {
                stop = 1;
                erreur_echo = 1;
            }
        } else {
            // Arrête la boucle
            stop = 1;
        }
    }
    
    if (erreur_echo == 1) {
        // Affiche un message d'erreur si la commande "echo" n'est pas suivie d'un espace
        printf("Error: the echo command must be followed by a space and the text to display.\n");
        printf("Erreur: la commande echo doit être suivie d'un espace et du texte à afficher.\n");
    }else {
        // Affiche un message d'erreur si la commande n'est pas reconnue
        printf("Commande non reconnue. Essayez 'help' ou 'aide' pour afficher les commandes disponibles.\n");
        printf("Command not recognized. Try 'help' to display the available commands.\n");
    }

    return 0;
}