/*https://stackoverflow.com/questions/2413418/how-to-programatically-convert-a-time-from-one-timezone-to-another-in-c*/
/*https://www.developpez.net/forums/d77539/c-cpp/c/conversion-d-caractere-minuscule*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */

int afficher_aide(char lang[3]){
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
    return 0;
}

int traiter_quit(char lang[3]){
    //Quitte le programme
    if (strcmp(lang, "fr") == 0){
        printf("Arrêt...\n");
    }
    else{
        printf("Exit...\n");
    }
    return 0;
}

int afficher_version() 
{
    //Affiche la version du shell
   //char version = system("$SHELL --version");
    printf("Version: 1.3\n");
    return 0;
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

//Structure pour stocker les commandes
struct Programme{
    char nom[25];
    int fonction;
    //Ajout de la langue
    char lang[3];
};

int main()
{

    struct Programme help = {"help", 1, "en"};
    struct Programme quit = {"quit", 2, "en"};
    struct Programme version = {"version", 3, "all"};
    struct Programme echo = {"echo", 4, "all"};
    //Ajout des commandes en français
    struct Programme aide = {"aide", 1, "fr"};
    struct Programme quitter = {"quitter", 2, "fr"};


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

        // Variable pour stocker le numéro de la commande
        int commande_int = 0;
        char lang[3];

        for(int i = 0; i < sizeof(programmes) / sizeof(struct Programme); i++){
            if (strcmp(programmes[i].nom, commande) == 0){
                commande_int = programmes[i].fonction;
                strcpy(lang, programmes[i].lang);
            }
        }

        switch (commande_int)
            {
            case 1:
                afficher_aide(lang);
                break;
            case 2:
                return traiter_quit(lang);
                break;
            case 3:
                afficher_version();
                break;
            case 4:
                traiter_echo(commande);
                break;
            default:
                erreur(commande);
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
