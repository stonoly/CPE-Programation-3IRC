/* Fichier: repl.c
 * Créer un tokenizeur, un parseur et un évaluateur capable d'évaluer des expressions arithmétiques (A opération B)
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 3.4
 */
#include "repl.h"


int main()
{

    // Définition des structures Programme
    struct Programme help = {"help", "en", afficher_aide};
    struct Programme quit = {"quit", "en", traiter_quit};
    struct Programme version = {"version", "all", afficher_version};
    struct Programme echo = {"echo", "all", traiter_echo};
    //Ajout des commandes en français
    struct Programme aide = {"aide", "fr", afficher_aide};
    struct Programme quitter = {"quitter", "fr", traiter_quit};


    // Tableau de programmes
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

        // variable pour vérifier si la commande est reconnue
        int error = 1;
        int comandefind = 0;

        for(int i = 0; i < sizeof(programmes) / sizeof(struct Programme); i++){
            // Vérifie si la commande est reconnue
            if (strcmp(programmes[i].nom, commande) == 0){
                // Appelle la fonction associée à la commande
                continuer = programmes[i].fonction(commande, programmes[i].lang);
                error = 0;
                comandefind = 1;
            }
        }
        if (!comandefind){
            // Appelle la fonction operation
            error = operation(commande_cpy);
        }
        if (error){
            // Affiche un message d'erreur si la commande n'est pas reconnue
            erreur(commande);
        }

        printf("\n"); // Saut de ligne après la sortie
    }
    
    return 0;
}
