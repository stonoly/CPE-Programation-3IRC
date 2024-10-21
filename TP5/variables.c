/*
https://koor.fr/C/cstring/strchr.wp
*/

#include "variables.h"

void nameVariable(char commande[1024], char name[25]){
    int i = 0;
    while (commande[i] != '=' && commande[i] != '\0' && commande[i] != '\n'){
        name[i] = commande[i];
        i++;
    }
    if (name[i - 1] == ' '){
        name[i - 1] = '\0';
    } else {
        name[i] = '\0';
    }
}

int typeVariable(char valeur[100]){
    int i = 0;
    while (valeur[i] != '\0'){
        if ((!isdigit(valeur[i]) && valeur[i] != '.')){
            return STRING;
        }
        i++;
    }
    if (strchr(valeur, '.')){
        return FLOTTANT;
    } else {
        return ENTIER;
    }
}

void valueVariable(char commande[1024], char value[100]){
    int i = 0;
    while (commande[i] != '='){
        i++;
    }
    i++;
    while (commande[i] == ' '){
        i++;
    }
    int j = 0;
    while (commande[i] != '\0' && commande[i] != '\n'){
        value[j] = commande[i];
        i++;
        j++;
    }
    value[j] = '\0';
}

int searchVariable(char name[25], struct Variable variables[100], int positionVariable){
    int indexSearch = 0;

    for (int i = 0; i < positionVariable; i++){
        if (strcmp(name, variables[i].nom) == 0){
            return i;
        }
    }
    return -1;
}

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
            strcpy(name, "inconnu");
    }
}

int setVariables(char commande[1024], struct Variable variables[100], int positionVariable){
    struct Variable var = {"", 0, ""};
    char nameVar[25];
    char typeName[25];
    nameVariable(commande, nameVar);
    int varExist = searchVariable(nameVar, variables, positionVariable);

    if (strchr(commande, '=')){

        if (varExist == -1){
            strcpy(var.nom, nameVar);
            valueVariable(commande, var.valeur);
            var.type = typeVariable(var.valeur);

            variables[positionVariable] = var;

            displayVariableType(var.type, typeName);
            printf("Variable %s définie avec la valeur %s (%s)\n", var.nom, var.valeur, typeName);

            return 0;

        } else {
            char valuetemp[100];
            valueVariable(commande, valuetemp);

            if (variables[varExist].type == typeVariable(valuetemp)){
                strcpy(variables[varExist].valeur, valuetemp);
                displayVariableType(var.type, typeName);
                printf("Variable %s modifiée avec la valeur %s (%s)\n", variables[varExist].nom, variables[varExist].valeur, typeName);
                return 0;

            } else {
                printf("Erreur : changement de type non autorisé pour la variable %s\n\n", variables[varExist].nom);
                return 1;

            }
        }
    } else {

        if (varExist != -1){
            printf("%s\n", variables[varExist].valeur);
            return 0;

        } else {
            printf("Erreur : la variable %s n'est pas définie\n\n", nameVar);
            return 1;

        }
    }
}
