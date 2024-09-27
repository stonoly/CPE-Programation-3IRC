# Fichier: cercle.py
# calcule l'aire et le périmètre d'un cercle
# auteur: Pierre MOLY
# Exercice 1.2

# importation de la bibliothèque mathématique
from math import pi

def main():
    # affichage d'un message pour demander le rayon du cercle
    rayon = float(input("Tapez le rayon du cercle : "))

    # calcul de l'aire du cercle
    aire = pi * rayon ** 2
    # calcul du périmètre du cercle
    perimetre = 2 * pi * rayon

    # affichage de l'aire du cercle
    print("Aire =", aire)
    print("Perimetre = ", perimetre)

if __name__ == "__main__":
    main()
