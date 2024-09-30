import dis

def calculer_somme(n: int) -> int:
    somme = 0
    for i in range(n):
        somme += i
    return somme 


"""def calculer_somme(n: int) -> int:
       somme = 0
       i = 0
       while i < n:
           somme += i
           i += 1
       return somme
"""
       
def main() -> None:
    n = 10
    resultat = calculer_somme(n)
    print(f"La somme des entiers de 0 à {n-1} est {resultat}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_somme)
    main()

#--------------------------------------------------------------------------------------------------
#1.
# Les instructions suivantes sont liées à la gestion de la boucle :
# - LOAD_FAST : charge la variable 'i' et 'somme' sur la pile.
# - FOR_ITER : prépare l'itération sur la plage de 'n'.
# - BINARY_ADD : ajoute 'i' à 'somme'.
# - STORE_FAST : stocke le résultat de la somme mise à jour dans 'somme'.
#--------------------------------------------------------------------------------------------------
#2.
# - SETUP_LOOP : prépare le début d'une boucle, en créant un bloc pour le contrôle de la boucle.
# - GET_ITER : récupère un itérateur à partir de l'objet de la boucle (ici, range(n)).
# - FOR_ITER : gère l'itération sur l'objet itéré et avance au prochain élément.
# - POP_BLOCK : termine le bloc de la boucle en cours lorsque la boucle est terminée.
#--------------------------------------------------------------------------------------------------
"""
Avec la boucle for : 
  3           0 RESUME                   0

  4           2 LOAD_CONST               1 (0)
              4 STORE_FAST               1 (somme)

  5           6 LOAD_GLOBAL              1 (NULL + range)
             16 LOAD_FAST                0 (n)
             18 CALL                     1
             26 GET_ITER
        >>   28 FOR_ITER                 7 (to 46)
             32 STORE_FAST               2 (i)

  6          34 LOAD_FAST                1 (somme)
             36 LOAD_FAST                2 (i)
             38 BINARY_OP               13 (+=)
             42 STORE_FAST               1 (somme)
             44 JUMP_BACKWARD            9 (to 28)

  5     >>   46 END_FOR

  7          48 LOAD_FAST                1 (somme)
             50 RETURN_VALUE


Moins de code de contrôle explicite, car l'itération est gérée par l'itérateur FOR_ITER.
La gestion de l'itérateur simplifie le bytecode, ce qui peut conduire à des exécutions plus rapides dans certains cas.

"""

"""
Avec la boucle while : 
 10           0 RESUME                   0

 11           2 LOAD_CONST               1 (0)
              4 STORE_FAST               1 (somme)

 12           6 LOAD_CONST               1 (0)
              8 STORE_FAST               2 (i)

 13          10 LOAD_FAST                2 (i)
             12 LOAD_FAST                0 (n)
             14 COMPARE_OP               2 (<)
             18 POP_JUMP_IF_FALSE       16 (to 52)

 14     >>   20 LOAD_FAST                1 (somme)
             22 LOAD_FAST                2 (i)
             24 BINARY_OP               13 (+=)
             28 STORE_FAST               1 (somme)

 15          30 LOAD_FAST                2 (i)
             32 LOAD_CONST               2 (1)
             34 BINARY_OP               13 (+=)
             38 STORE_FAST               2 (i)

 13          40 LOAD_FAST                2 (i)
             42 LOAD_FAST                0 (n)
             44 COMPARE_OP               2 (<)
             48 POP_JUMP_IF_FALSE        1 (to 52)
             50 JUMP_BACKWARD           16 (to 20)

 16     >>   52 LOAD_FAST                1 (somme)
             54 RETURN_VALUE

La condition de boucle (i < n) doit être explicitement vérifiée à chaque itération avec COMPARE_OP.
Bien que le code soit plus détaillé et moins optimisé, il offre plus de flexibilité pour des conditions de boucle complexes.
"""