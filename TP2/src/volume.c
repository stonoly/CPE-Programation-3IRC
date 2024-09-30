#include <math.h>
#include "sphere.h"

// Fonction pour calculer le volume d'une sphère
float calculer_volume(float rayon) {
    return (4.0 / 3.0) * M_PI * pow(rayon, 3);
}

/*
Prétraitement : Les fichiers source .c sont transformés en fichiers prétraités .i en développant les macros, en incluant les en-têtes (#include), et en supprimant les commentaires.

Compilation : Les fichiers .i sont compilés avec des optimisations de haut niveau (-O3) pour générer des fichiers objets .o sans lier. Cette étape est utile lorsqu'on veut compiler plusieurs fichiers source séparément avant de les lier tous ensemble.

Édition de liens : Les fichiers objets .o sont liés avec la bibliothèque mathématique (-lm) pour créer l'exécutable final, dans notre cas nommé sphere.
*/