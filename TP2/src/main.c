#include <stdio.h>
#include "sphere.h"

int main() {
    float rayon = 5.0;
    float volume = calculer_volume(rayon);
    float surface = calculer_surface(rayon);

    printf("Le volume de la sphère de rayon %.2f est %.2f\n", rayon, volume);
    printf("La surface de la sphère de rayon %.2f est %.2f\n", rayon, surface);

    return 0;
}

/*
Prétraitement : Les fichiers source .c sont transformés en fichiers prétraités .i en développant les macros, en incluant les en-têtes (#include), et en supprimant les commentaires.

Compilation : Les fichiers .i sont compilés avec des optimisations de haut niveau (-O3) pour générer des fichiers objets .o sans lier. Cette étape est utile lorsqu'on veut compiler plusieurs fichiers source séparément avant de les lier tous ensemble.

Édition de liens : Les fichiers objets .o sont liés avec la bibliothèque mathématique (-lm) pour créer l'exécutable final, dans notre cas nommé sphere.

Le programme main permet de faire appel à des fonctions situé dans d'autres fichiers sources (volume.c et surface.c).
*/
