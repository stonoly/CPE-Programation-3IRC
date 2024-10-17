/*https://stackoverflow.com/questions/2413418/how-to-programatically-convert-a-time-from-one-timezone-to-another-in-c*/
/*https://www.developpez.net/forums/d77539/c-cpp/c/conversion-d-caractere-minuscule*/
#include "repl.h"


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
int main()
{

    struct Programme help = {"help", "en", afficher_aide};
    struct Programme quit = {"quit", "en", traiter_quit};
    struct Programme version = {"version", "all", afficher_version};
    struct Programme echo = {"echo", "all", traiter_echo};
    //Ajout des commandes en français
    struct Programme aide = {"aide", "fr", afficher_aide};
    struct Programme quitter = {"quitter", "fr", traiter_quit};


    struct Programme programmes[6];
    programmes[0] = help;
    programmes[1] = quit;
    programmes[2] = version;
    programmes[3] = echo;
    //Ajout des commandes en français
    programmes[4] = aide;
    programmes[5] = quitter;
    
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);
        
        for(int j = 0; j < sizeof(commande) / sizeof(char); j ++){
            commande[j] = tolower(commande[j]);
            // Enleve l'espace après la commande echo
            if (commande[4] == ' '){
                commande[4] = '\0';
            }
        }

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        int error = 1;

        for(int i = 0; i < sizeof(programmes) / sizeof(struct Programme); i++){
            if (strcmp(programmes[i].nom, commande) == 0){
                continuer = programmes[i].fonction(commande, programmes[i].lang);
                error = 0;
            }
        }
        if (error){
            erreur(commande);
        }

        printf("\n"); // Saut de ligne après la sortie
    }
    
    return 0;
}
