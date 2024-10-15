#ifndef EX2_H
#define EX2_H

// Déclaration de la fonction pour convertir une expression infixée en postfixée
void infixToPostfix(const char* infix, char* postfix);

// Déclaration de la fonction pour vérifier si un caractère est un opérateur
int isOperator(char c);

// Déclaration de la fonction pour déterminer la priorité des opérateurs
int priority_operator(char op);

#endif // EX2_H