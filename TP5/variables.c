/* Fichier: variables.c
 * Gérer les variables dans l'interpréteur
 * Auteur: Pierre MOLY / Maxence LERDA
 * Exercice 5.1
 */
#include "variables.h"

// Fonction pour extraire le nom d'une variable d'une commande
void nameVariable(char commande[1024], char name[25]){
    int i = 0;
    // Parcourt la commande jusqu'à trouver '=' ou la fin de la chaîne
    while (commande[i] != '=' && commande[i] != '\0' && commande[i] != '\n'){
        name[i] = commande[i];
        i++;
    }
    // Supprime l'espace à la fin du nom si présent
    if (name[i - 1] == ' '){
        name[i - 1] = '\0';
    } else {
        name[i] = '\0'; // Termine la chaîne
    }
}

// Fonction pour déterminer le type d'une variable
int typeVariable(char valeur[100]){
    int i = 0;
    // Vérifie si tous les caractères sont des chiffres ou un point
    while (valeur[i] != '\0'){
        if ((!isdigit(valeur[i]) && valeur[i] != '.')){
            return STRING; // Retourne STRING si un caractère non numérique est trouvé
        }
        i++;
    }
    // Vérifie si la valeur contient un point pour déterminer si c'est un flottant
    if (strchr(valeur, '.')){
        return FLOTTANT;
    } else {
        return ENTIER; // Retourne ENTIER si aucun point n'est trouvé
    }
}

// Fonction pour extraire la valeur d'une variable d'une commande
void valueVariable(char commande[1024], char value[100]){
    int i = 0;
    // Trouve le signe '=' dans la commande
    while (commande[i] != '='){
        i++;
    }
    i++; // Passe au caractère suivant
    // Ignore les espaces après '='
    while (commande[i] == ' '){
        i++;
    }
    int j = 0;
    // Copie la valeur jusqu'à la fin de la commande ou une nouvelle ligne
    while (commande[i] != '\0' && commande[i] != '\n'){
        value[j] = commande[i];
        i++;
        j++;
    }
    value[j] = '\0'; // Termine la chaîne
}

// Fonction pour rechercher une variable dans un tableau de variables
int searchVariable(char name[25], struct Variable variables[100], int positionVariable){
    int indexSearch = 0;

    // Parcourt le tableau de variables pour trouver une correspondance
    for (int i = 0; i < positionVariable; i++){
        if (strcmp(name, variables[i].nom) == 0){
            return i; // Retourne l'index si trouvé
        }
    }
    return -1; // Retourne -1 si non trouvé
}

// Fonction pour afficher le type d'une variable sous forme de chaîne
void displayVariableType(int type, char name[25]){
    switch (type){
        case ENTIER:
            strcpy(name, "entier");
            break;
        case FLOTTANT:
            strcpy(name, "nombre réel");
            break;
        case STRING:
            strcpy(name, "chaine de caractères");
            break;
        default:
            strcpy(name, "inconnu"); // Type inconnu
    }
}

// Fonction pour définir ou modifier une variable
int setVariables(char commande[1024], struct Variable variables[100], int positionVariable){
    struct Variable var = {"", 0, ""}; // Initialisation d'une nouvelle variable
    char nameVar[25];
    char typeName[25];
    nameVariable(commande, nameVar); // Récupère le nom de la variable
    int varExist = searchVariable(nameVar, variables, positionVariable); // Vérifie si la variable existe

    if (strchr(commande, '=')){ // Vérifie si la commande contient un '='
        if (varExist == -1){ // Si la variable n'existe pas
            strcpy(var.nom, nameVar); // Définit le nom de la variable
            valueVariable(commande, var.valeur); // Récupère la valeur
            var.type = typeVariable(var.valeur); // Détermine le type

            variables[positionVariable] = var; // Ajoute la variable au tableau

            displayVariableType(var.type, typeName); // Affiche le type
            printf("Variable %s définie avec la valeur %s (%s)\n", var.nom, var.valeur, typeName);

            return 0; // Succès
        } else {
            char valuetemp[100];
            valueVariable(commande, valuetemp); // Récupère la nouvelle valeur

            // Vérifie si le type de la nouvelle valeur correspond à l'ancien type
            if (variables[varExist].type == typeVariable(valuetemp)){
                strcpy(variables[varExist].valeur, valuetemp); // Met à jour la valeur
                displayVariableType(var.type, typeName);
                printf("Variable %s modifiée avec la valeur %s (%s)\n", variables[varExist].nom, variables[varExist].valeur, typeName);
                return 0; // Succès
            } else {
                printf("Erreur : changement de type non autorisé pour la variable %s\n\n", variables[varExist].nom);
                return 1; // Erreur de type
            }
        }
    } else {
        // Si la commande ne contient pas '=', affiche la valeur de la variable
        if (varExist != -1){
            printf("%s\n", variables[varExist].valeur);
            return 0; // Succès
        } else {
            printf("Erreur : la variable %s n'est pas définie\n\n", nameVar);
            return 1; // Erreur de variable non définie
        }
    }
}
