from typing import List
import pdb

def double_values(tableau: List[int]) -> None:
    for compteur in range(len(tableau)):
        #À chaque indice pair (compteur % 2 == 0), on multiplie par 2,
        # mais à chaque indice impair, on multiplie par 3.
        # La condition entraîne une multiplication par 3 pour les indices impairs.

        # Correction : toujours multiplier par 2
        tableau[compteur] *= 2
        # Point d'arrêt pour observer la valeur de 'tableau' à chaque étape
        pdb.set_trace()

    return tableau

# Créer un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appeler la fonction et stocker le résultat
resultat = double_values(tableau)

# Afficher le résultat final
print(resultat)

