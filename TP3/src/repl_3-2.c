/*https://stackoverflow.com/questions/2413418/how-to-programatically-convert-a-time-from-one-timezone-to-another-in-c*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */

int afficher_aide(){
    //Affiche l'aide
    printf("Aide: \n");
    printf("----------\n");
    printf("echo <text>: affiche le texte\n");
    printf("date: affiche la date\n");
    printf("help: affiche l'aide\n");
    printf("quit: quitte le programme\n");
    printf("version: affiche la version du shell\n");
    return 0;
}

int traiter_quit(){
    //Quitte le programme
    printf("Arrêt...\n");
    return 0;
}

int afficher_version() 
{
    //Affiche la version du shell
    char version = system("$SHELL --version");
}

int traiter_echo(char text[1024]){
    //Affiche le texte
    printf("Echo: ");
    for (int i = 5; text[i] != '\0'; i++)
        {
            printf("%c", text[i]);
    }
    return 0;
}

//Structure pour stocker les commandes
struct Programme{
    char nom[25];
    int fonction;
};

int main()
{

    struct Programme help = {"help", 1};
    struct Programme quit = {"quit", 2};
    struct Programme version = {"version", 3};
    struct Programme echo = {"echo", 4};

    struct Programme programmes[4];
    programmes[0] = help;
    programmes[1] = quit;
    programmes[2] = version;
    programmes[3] = echo;
    
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
            // Remplace les espaces par des caractères de fin de chaîne
            if (commande[j] == ' '){
                commande[j] = '\0';
            }
        }

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        // Variable pour stocker le numéro de la commande
        int commande_int = 0;

        for(int i = 0; i < sizeof(programmes) / sizeof(struct Programme); i++){
            if (strcmp(programmes[i].nom, commande) == 0){
                commande_int = programmes[i].fonction;
            }
        }

        switch (commande_int)
            {
            case 1:
                afficher_aide();
                break;
            case 2:
                return traiter_quit();
                break;
            case 3:
                afficher_version();
                break;
            case 4:
                traiter_echo(commande);
                break;
            default:
                printf("Commande non reconnue. Essayez 'help' pour afficher les commandes disponibles.\n");
                break;
            }
        
        printf("\n"); // Saut de ligne après la sortie
    }
        /*
        // Traite la commande en fonction de son contenu
        if (strcmp(commande, "quit") == 0)
        {
            // Appelle la fonction traiter_quit
            return traiter_quit();
        }
        // Traite la commande "date"
        else if (strcmp(commande, "date") == 0)
        {
            // Affiche la date et l'heure actuelles
            time_t localDate = time(NULL);
            printf("%s", ctime(&localDate));
        }
        // Traite la commande "help"
        else if (strcmp(commande, "help") == 0)
        {
            // Appelle la fonction afficher_aide
            afficher_aide();
        }
        else if (strncmp(commande, "echo ", 5) == 0)
        {
            // Traite la commande "echo" pour afficher du texte
            printf("Echo: ");

            // Imprime la chaîne
            for (int i = 5; commande[i] != '\0'; i++)
            {
                printf("%c", commande[i]);
            }
            printf("\n"); // Saut de ligne après la sortie
        }
        else
        {
            // Affiche un message d'erreur si la commande est inconnue
            printf("Commande non reconnue. Essayez 'echo <text>' pour afficher du texte. Essayez 'date' pour afficher la date, ou tapez 'quit' pour quitter.\n");
        }
        */
    return 0;
}
