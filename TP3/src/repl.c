/*https://stackoverflow.com/questions/2413418/how-to-programatically-convert-a-time-from-one-timezone-to-another-in-c*/
/*https://www.developpez.net/forums/d77539/c-cpp/c/conversion-d-caractere-minuscule*/
#include "repl.h"


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
        char commande_cpy[1024];
        strcpy(commande_cpy, commande);
        
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
        int comandefind = 0;

        for(int i = 0; i < sizeof(programmes) / sizeof(struct Programme); i++){
            if (strcmp(programmes[i].nom, commande) == 0){
                continuer = programmes[i].fonction(commande, programmes[i].lang);
                error = 0;
                comandefind = 1;
            }
        }
        if (!comandefind){
            error = operation(commande_cpy);
        }
        if (error){
            erreur(commande);
        }

        printf("\n"); // Saut de ligne après la sortie
    }
    
    return 0;
}
