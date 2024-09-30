#include <stdio.h>

int main() {

   int tableau[100];

   for (int compteur = 0; compteur < sizeof(tableau) / sizeof(int); compteur++) { //Erreur
   //  La taille utilisée ici est incorrecte car sizeof(tableau) retourne
   // la taille en octets, pas le nombre d'éléments. Cela peut mener à un dépassement de mémoire. Pour avoir le nombre d'léément il faut faire sizeof(tableau) / sizeof(int)
       tableau[compteur] = tableau[compteur] * 2;
   }

   return (0);

}

