/* Fichier: phrases.c
 * Recherche de phrases dans un fichier
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 2.6
 * 
 * Références :
 * https://koor.fr/C/cstring/strlen.wp
 * https://koor.fr/C/cstdio/fopen.wp
 * https://koor.fr/C/cstdio/fgets.wp
 */

#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    char search_phrase[100];

    // Demande à l'utilisateur d'entrer le nom du fichier
    printf("Entrez le nom du fichier :");
    scanf("%s", filename);

    // Demande à l'utilisateur d'entrer la phrase à rechercher
    printf("Entrez la phrase que vous souhaitez rechercher :");
    scanf("%s", search_phrase);
    printf("\n");

    // Ouvre le fichier en mode lecture
    FILE * file = fopen(filename, "r");
    char line[100];
    int found = 1;

    // Vérifie si le fichier a été ouvert correctement
    if(file == NULL) {
        printf("Le fichier n'existe pas \n");
        return 1;
    }

    // Utilise fgets pour lire chaque ligne du fichier et donner le nombre de fois que la phrase est trouvée dans la ligne
    printf("Résultat de la recherche : \n");
    int i = 0;
    int found_line = 1;
    // Parcourt le fichier ligne par ligne
    while(fgets(line, sizeof(line), file) != NULL) {
        int count = 0;
        // Parcourt la ligne caractère par caractère
        for (int j = 0; j < strlen(line); j++) {
            if (line[j] == search_phrase[0]) {
                int count_letter = 0;
                // Parcourt la phrase caractère par caractère
                for (int k = 0; k < strlen(search_phrase); k++) {
                    if (line[j + k] == search_phrase[k]) {
                        count_letter++;
                    }
                    // Si la phrase est trouvée dans la ligne
                    if (count_letter == strlen(search_phrase)) {
                        found_line = 0;
                        count++;
                    }
                }
            }
        }
        // Si la phrase est trouvée dans la ligne
        if (found_line == 0) {
            printf("Phrase '%s' trouvée %d fois à la ligne %d\n", search_phrase, count, i + 1);
            found = 0;
        }
        found_line = 1;
        i++;
    }

    // Si la phrase n'a pas été trouvée dans le fichier
    if(found == 1) {
        printf("La phrase '%s' n'a pas été trouvée dans le fichier %s\n", search_phrase, filename);
    }

    // Ferme le fichier
    fclose(file);

    return 0;
}