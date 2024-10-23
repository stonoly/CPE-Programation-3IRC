/* Fichier: repl_3-1.c
 * L'objectif du premier exercice est de comprendre le fonctionnement de l'interpréteur de commandes et de tester ses fonctionnalités.
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 3.1
 */
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */

int main()
{
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        // Traite la commande en fonction de son contenu
        if (strcmp(commande, "quit") == 0)
        {
            // Quitte le programme si la commande est "quit"
            printf("Arrêt...\n");
            continuer = 0;
        }
        // Traite la commande "date"
        else if (strcmp(commande, "date") == 0)
        {
            // Affiche la date et l'heure actuelles
            time_t localDate = time(NULL);
            printf("%s", ctime(&localDate));
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

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}