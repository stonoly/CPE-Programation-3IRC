# Fichier: operateurs.py
# Utilisation des opérateurs arithmétiques et logiques en Python
# auteur: Pierre MOLY
# Exercice 1.5

def main():
    a = 16
    b = 3

    calcul = a + b
    print("a + b = ", calcul)

    calcul = a - b
    print("a - b = ", calcul)

    calcul = a * b
    print("a * b = ", calcul)

    calcul = a / b
    print("a / b = ", calcul)

    calcul = a % b
    print("a % b = ", calcul)

    boolean = a == b
    print("a == b = ", boolean)

    boolean = a > b
    print("a > b = ", boolean)

if __name__ == "__main__":
    main()