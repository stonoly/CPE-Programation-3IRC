/* Fichier: phrases.c
 * Recherche de phrases dans un fichier
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 2.7
 * https://koor.fr/C/cstdlib/rand.wp
 * https://stackoverflow.com/questions/12344814/how-to-print-unsigned-char-as-2-digit-hex-value-in-c
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure pour représenter une couleur
struct Couleur {
    int r;
    int g;
    int b;
    int a;
};

// Structure pour compter les occurrences des couleurs
struct Couleur_Count {
    struct Couleur couleur;
    int count;
};

// Fonction pour comparer deux couleurs
int compareColor(struct Couleur c1, struct Couleur c2) {
    // Comparaison des composantes RGB et alpha
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

int main() {

    srand(time(NULL));  // Initialisation du générateur de nombres aléatoires

    struct Couleur couleurs[100]; // Tableau de 100 couleurs
    struct Couleur_Count couleurs_count[100]; // Tableau de 100 couleurs et leurs occurrences
    int distinct_count = 0;  // Compteur de couleurs distinctes

    // Génération de 100 couleurs aléatoires
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            // Creation de couleurs égale pour tester le comptage
            couleurs[i].r = 12;
            couleurs[i].g = 12;
            couleurs[i].b = 12;
            couleurs[i].a = 255;
        } else {
            // Génération de couleurs aléatoires
            couleurs[i].r = rand() % 256;
            couleurs[i].g = rand() % 256;
            couleurs[i].b = rand() % 256;
            couleurs[i].a = 255;
        }
    }

    // Comptage des occurrences des couleurs distinctes
    for (int j = 0; j < 100; j++) {
        // Initialisation de la variable found
        int found = 0;

        // Chercher si la couleur existe déjà dans le tableau des couleurs distinctes
        for (int k = 0; k < distinct_count; k++) {
            if (compareColor(couleurs[j], couleurs_count[k].couleur)) {
                // Incrémenter le compteur de la couleur
                couleurs_count[k].count++;
                found = 1;
                // Sortir de la boucle
                break;
            }
        }

        // Si la couleur n'a pas été trouvée, l'ajouter au tableau des couleurs distinctes
        if (found == 0) {
            couleurs_count[distinct_count].couleur = couleurs[j];
            couleurs_count[distinct_count].count = 1;
            // Incrémenter le compteur de couleurs distinctes
            distinct_count++;
        }
    }

    // Affichage des couleurs distinctes et leurs occurrences
    for (int l = 0; l < distinct_count; l++) {
        // Affichage de la couleur et de son compteur en hexadécimal
        printf("%02X 0x%02X 0x%02X 0x%02X : %d \n", 
           couleurs_count[l].couleur.a, couleurs_count[l].couleur.r, 
           couleurs_count[l].couleur.g, couleurs_count[l].couleur.b, 
           couleurs_count[l].count);
    }

    return 0;
}
