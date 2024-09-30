import math
import dis

def calculer_aire(rayon: float) -> float:
    return math.pi * rayon * rayon

def calculer_aire_constante(rayon: float) -> float:
    return 12.56

def main() -> None:
    rayon : float = 5.0
    aire : float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_aire)
    print("--------------------------------------------------------------------------------------------------")
    dis.dis(calculer_aire_constante)
    main()

#--------------------------------------------------------------------------------------------------
#1.
# On remarque que dis affiche les détails de l'exécution de la fonction calculer_aire. Ou chaque instructions valeurs et operation est affiché et détaillé.
# 4           0 RESUME                   0
# 5           2 LOAD_GLOBAL              0 (math)
#             12 LOAD_ATTR                2 (pi)
#             32 LOAD_FAST                0 (rayon)
#             34 BINARY_OP                5 (*)
#             38 LOAD_FAST                0 (rayon)
#             40 BINARY_OP                5 (*)
#             44 RETURN_VALUE
#--------------------------------------------------------------------------------------------------
# 2.
#Les instructions du bytecode sont les suivantes :
# RESUME : Indique que la fonction a été appelée et commence à s'exécuter.
# LOAD_GLOBAL : Charge la constante math depuis l'espace global.
# LOAD_ATTR : Charge l'attribut pi de l'objet math.
# LOAD_FAST : Charge la variable rayon à partir de l'espace local.
# BINARY_OP : Effectue une opération binaire (multiplication ici).
# LOAD_FAST : Charge la variable rayon à partir de l'espace local.
# BINARY_OP : Effectue une opération binaire (multiplication ici).
# RETURN_VALUE : Retourne le résultat de l'opération.
#--------------------------------------------------------------------------------------------------
# 3. 
# Le bytecode avec une constante est plus simple et plus court. Toutes les opérations précédentes comme LOAD_GLOBAL, LOAD_ATTR, et les multiplications ont été supprimées. Le bytecode charge simplement une constante et la renvoie immédiatement.
#   7           0 RESUME                   0
#   8           2 RETURN_CONST             1 (12.56)
#--------------------------------------------------------------------------------------------------
# 4.
# Lorsqu'une constante est utilisée, Python optimise l'exécution en évitant des opérations inutiles. Il n’a plus besoin de charger math.pi ni d'effectuer de calculs de multiplication. Le résultat est directement connu, donc Python évite ces étapes.
#--------------------------------------------------------------------------------------------------
# Par exemple, les instructions comme LOAD_GLOBAL, LOAD_FAST, ou BINARY_MULTIPLY apparaîtront dans le bytecode. Que signifient-elles ?
# LOAD_GLOBAL : Cette instruction charge une variable globale dans la pile d'exécution. Par exemple, LOAD_GLOBAL 0 (math) charge le module math, permettant d'accéder à ses attributs, comme math.pi.

# LOAD_FAST : Charge une variable locale (comme rayon) dans la pile. Par exemple, LOAD_FAST 0 (rayon) permet d'accéder à la variable rayon déclarée dans la fonction.

# BINARY_MULTIPLY : Effectue une multiplication binaire entre les deux derniers éléments présents sur le sommet de la pile. Par exemple, si math.pi et rayon sont chargés sur la pile, BINARY_MULTIPLY multiplie ces deux valeurs.

# RETURN_VALUE : Renvoie la valeur située au sommet de la pile comme résultat de la fonction. C'est la dernière instruction avant que la fonction ne se termine.

#--------------------------------------------------------------------------------------------------
#Si vous remplacez l'expression math.pi * rayon * rayon par une valeur constante, par exemple 78.54, le bytecode devient plus court et plus simple.
# 4           0 RESUME                   0
# 5           2 RETURN_CONST             1 (78.54)
#--------------------------------------------------------------------------------------------------
# 5.
# La pile d'exécution stocke temporairement les valeurs pendant les calculs. Dans l'exemple original, math.pi et rayon sont chargés sur la pile et multipliés. Avec une constante, il n'y a qu'une seule valeur à charger, rendant l'exécution plus rapide et plus efficace.
