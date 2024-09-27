/* Fichier: calculs.c
* Opérations mathématiques et bitwise avec structures de contrôle
* auteur: Pierre MOLY
* Exercice 1.8
*/

#include <stdio.h>

int main(){

    // lecture des valeurs saisies par l'utilisateur
    int num1 = 14;
    int num2 = 6;
    char op;
    printf("Entrez une opération entre %d et %d: ", num1, num2);
    scanf("%c", &op);
    int result;

    // switch pour déterminer l'opération à effectuer
    switch (op){
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0){
            printf("Division par 0 impossible\n");
            return 1;
        }
        result = num1 / num2;
        break;
    case '&':
        result = num1 & num2;
        break;
    case '|':
        result = num1 | num2;
        break;
    case '~':
        result = ~num1;
        break;
    default:
        printf("Opération non valide\n");
        return 1;
    }

    // affichage du résultat
    if (op ==  '~'){
        printf("L'operation mathématiqe %c%d = %d\n", op, num1, result);
    }
    else{
        printf("L'operation mathématiqe %d %c %d = %d\n", num1, op, num2, result);
    }
    return 0;
}