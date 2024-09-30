import math
import dis

def calculer_aire(rayon: float) -> float:
    return math.pi * 3 * 3

def main() -> None:
    rayon : float = 5.0
    aire : float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_aire)
    main()

#--------------------------------------------------------------------------------------------------
#1.
# Je  remarque que dis affiche les détails de l'exécution de la fonction calculer_aire. Ou chaque instructions valeurs et operation est affiché et détaillé.
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
# Cette fois ci ces différents instructions LOAD_FAST sont remplacés par LOAD_CONST qui charge une constante et non une variable de l'espace local.
#  4           0 RESUME                   0
#  5           2 LOAD_GLOBAL              0 (math)
#             12 LOAD_ATTR                2 (pi)
#             32 LOAD_CONST               1 (3)
#             34 BINARY_OP                5 (*)
#             38 LOAD_CONST               1 (3)
#             40 BINARY_OP                5 (*)
#             44 RETURN_VALUE
#--------------------------------------------------------------------------------------------------




