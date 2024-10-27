#include "repl.h"


int main()
{

    // Définition des commandes disponibles
    struct Programme help = {"help", "en", afficher_aide};
    struct Programme quit = {"quit", "en", traiter_quit};
    struct Programme version = {"version", "all", afficher_version};
    struct Programme echo = {"echo", "all", traiter_echo};
    //Ajout des commandes en français
    struct Programme aide = {"aide", "fr", afficher_aide};
    struct Programme quitter = {"quitter", "fr", traiter_quit};


    // Tableau des commandes disponibles
    struct Programme programmes[6];
    programmes[0] = help;
    programmes[1] = quit;
    programmes[2] = version;
    programmes[3] = echo;
    //Ajout des commandes en français
    programmes[4] = aide;
    programmes[5] = quitter;
    
    int continuer = 1; // Variable pour contrôler la boucle principale
    
    struct Variable variables[100];
    int positionVariable = 0;

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);
        char commande_cpy[1024];
        // Copie de la commande pour les opérations
        strcpy(commande_cpy, commande);
        int operation = 0;
        // Copie de la commande pour les commandes echo
        char cmdEcho[4]; 
        
        // Convertit la commande en minuscules
        for(int j = 0; j < strlen(commande); j ++){
            commande[j] = tolower(commande[j]);
            if (commande[j] == '+' || commande[j] == '-' || commande[j] == '*' || commande[j] == '/'){
                operation = 1;
            }

            // Copie de la commande pour les commandes echo
            if (j < 5){
                if (j == 4){
                    cmdEcho[j] = '\0';
                } else {
                    cmdEcho[j] = commande[j];
                }
            }
            // Enleve l'espace après la commande echo
        }

        if (strcmp(cmdEcho, "echo") == 0){
            commande[4] = '\0';
        }

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        int error = 1;
        int comandefind = 0;

        // Boucle pour chercher la commande dans le tableau de commandes
        for(int i = 0; i < sizeof(programmes) / sizeof(struct Programme); i++){
            // Si la commande est trouvée, on appelle la fonction associée
            if (strcmp(programmes[i].nom, commande) == 0){
                continuer = programmes[i].fonction(commande, programmes[i].lang);
                error = 0;
                comandefind = 1;
            }
        }
        if (!comandefind){

            // Si la commande n'est pas trouvée, on vérifie si c'est une opération, une affectation de variable ou une lambda
            if (isLambda(commande)) {
                // Si c'est une lambda, on appelle la fonction lambda
                error = lambda(commande, variables, positionVariable);
            } else if (operation == 1){
                // Si c'est une opération, on appelle les fonctions pour la résoudre
                char postFix[100] = "";
                error = infixToPostfix(commande_cpy, postFix);
                if (!error){
                    // On affiche le résultat de l'opération
                    error = postFixToResult(postFix);
                }
            } else {
                // Sinon, on vérifie si c'est une affectation de variable
                error = setVariables(commande_cpy, variables, positionVariable);
                if (error == 0){
                    positionVariable++;
                }
            }
        }
        if (error){
            // Si une erreur est survenue, on affiche un message d'erreur
            erreur(commande);

        }

        printf("\n"); // Saut de ligne après la sortie
    }
    
    return 0;
}
