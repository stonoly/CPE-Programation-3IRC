/* Fichier: bd_école.c
 * Gestion des données d'étudiant.e.s
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 2.5
 */

#include <stdio.h>
#include <string.h>

// Définition de la structure Student pour stocker les informations d'un étudiant
struct Student {
    char name[50];      
    char firstname[25]; 
    char address[100];  
    short note[3];    
};

int main() {
    // Déclaration d'un tableau de 5 étudiants
    struct Student students[5];
    char name[50], 
    firstname[25], 
    address[100];
    short note[3];

    // Boucle pour saisir les informations de 5 étudiants
    for (int i = 0; i < 5; i++) {
        // Saisie du nom
        printf("Entrez le nom de l'étudiant %d: ", i + 1);
        scanf("%s", name); // Le nom est saisi et stocké dans 'name'
        strcpy(students[i].name, name); // Le nom est copié dans la structure de l'étudiant

        // Saisie du prénom
        printf("Entrez le prénom de l'étudiant %d: ", i + 1);
        scanf("%s", firstname); // Le prénom est saisi et stocké dans 'firstname'
        strcpy(students[i].firstname, firstname); // Le prénom est copié dans la structure de l'étudiant

        // Saisie de l'adresse (sans espace dans ce cas)
        printf("Entrez l'adresse de l'étudiant tout attaché %d: ", i + 1);
        scanf("%s", address); // L'adresse est saisie et stockée dans 'address'
        strcpy(students[i].address, address); // L'adresse est copiée dans la structure de l'étudiant

        // Saisie des 3 notes
        for (int j = 0; j < 3; j++) {
            printf("Entrez la note %d de l'étudiant %d: ", j + 1, i + 1);
            scanf("%hd", &note[j]); // La note est saisie et stockée dans le tableau temporaire
            students[i].note[j] = note[j]; // La note est copiée dans la structure de l'étudiant
        }
    }

    // Boucle pour afficher les informations des 5 étudiants
    for (int i = 0; i < 5; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("Nom: %s\n", students[i].name); // Affichage du nom
        printf("Prénom: %s\n", students[i].firstname); // Affichage du prénom
        printf("Adresse: %s\n", students[i].address); // Affichage de l'adresse
        // Affichage des 3 notes
        printf("Note 1: %d\n", students[i].note[0]);
        printf("Note 2: %d\n", students[i].note[1]);
        printf("Note 3: %d\n", students[i].note[2]);
        printf("\n"); 
    }

    return 0;
}
