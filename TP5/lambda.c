#include "lambda.h"

// Fonction pour vérifier si une commande commence par "(lambda x."
int isLambda(char commande[1024]){
    int i = 0;
    char lambda[10] = "(lambda x.";
    // Compare chaque caractère de la commande avec la chaîne lambda
    while (i < 10 && commande[i] != '\0'){
        if (commande[i] == lambda[i]){
            i++;
        } else {
            return 0; // Retourne 0 si la commande ne correspond pas
        }
    }
    return 1; // Retourne 1 si la commande correspond
}

// Fonction pour inverser une chaîne de caractères
void strrev(char* str) {
    int i, j;
    char temp;
    int len = strlen(str);

    // Inverse les caractères de la chaîne
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Fonction pour extraire un nombre d'une commande
void nombreRemplacement(char commande[1024], char nombre[100]){
    int i = strlen(commande) - 1;

    // Parcourt la commande à l'envers pour extraire le nombre
    while ( i > 0 && commande[i] != ' '){
        char temp[2] = { commande[i], '\0' };
        strncat(nombre, temp, 1); // Ajoute le caractère au nombre
        i--;
    }
    strrev(nombre); // Inverse le nombre extrait
}

// Fonction pour extraire une opération d'une commande
void operationTemp(char commande[1024], char op[100]){
    int positionEnd = strlen(commande) - 1;
    // Trouve la position de la parenthèse fermante
    while (commande[positionEnd] != ')'){
        positionEnd--;
    }
    int i = 10; // Commence après "(lambda x."
    // Extrait l'opération jusqu'à la parenthèse fermante
    while (i < positionEnd){
        char temp[2] = { commande[i], '\0' };
        strncat(op, temp, 1); // Ajoute le caractère à l'opération
        i++;
    }
}

// Fonction pour vérifier si une variable est définie et de type correct
int verificationVar(char nombre[100], struct Variable variables[100], int positionVariable){
    int typeNombre = typeVariable(nombre);
    if (typeNombre == STRING){
        int varExist = searchVariable(nombre, variables, positionVariable);
        // Vérifie si la variable existe et si son type est correct
        if(varExist != -1 && variables[varExist].type != STRING){
            strcpy(nombre, variables[varExist].valeur); // Remplace par la valeur de la variable
        } else {
            printf("Erreur : la variable z n'est pas définie ou de mauvais type\n\n");
            return 1; // Retourne une erreur
        }
    }
    return 0; // Retourne 0 si tout est correct
}

// Fonction pour finaliser l'opération en remplaçant 'x' par le nombre
void finalOperation(char op[100], char nombre[100]){
    char finalOp[100] = "";
    // Parcourt l'opération et remplace 'x' par le nombre
    for (int i = 0; i < strlen(op); i++){
        if (op[i] == 'x'){
            strcat(finalOp, nombre); // Ajoute le nombre à l'opération finale
        } else {
            char temp[2] = { op[i], '\0' };
            strcat(finalOp, temp); // Ajoute le caractère à l'opération finale
        }
    }
    strcpy(op, finalOp); // Met à jour l'opération
    strcat(op, "\n"); // Ajoute une nouvelle ligne à la fin
}

// Fonction principale pour traiter une commande lambda
int lambda(char commande[1024], struct Variable variables[100], int positionVariable){
    char nombre[100] = ""; // Initialise le nom
    char op[100] = ""; // Initialise l'opération
    nombreRemplacement(commande, nombre); // Extrait le nombre
    operationTemp(commande, op); // Extrait l'opération
    int error = verificationVar(nombre, variables, positionVariable); // Vérifie la variable
    if (!error){
        finalOperation(op, nombre); // Finalise l'opération
        char postFix[100] = "";
        error = infixToPostfix(op, postFix); // Convertit l'opération en notation postfixe
        if (!error){
            error = postFixToResult(postFix); // Calcule le résultat à partir de la notation postfixe
        }
    }
    return error; // Retourne l'erreur (0 si succès)
}
