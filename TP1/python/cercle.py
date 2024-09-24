# Fichier: cercle.py
# calcule l'aire et le périmètre d'un cercle
# auteur: Pierre MOLY
# Exercice 1.2

from math import pi

def main():
    rayon = float(input("Tapez le rayon du cercle : "))

    aire = pi * rayon ** 2
    perimetre = 2 * pi * rayon

    print("Aire =", aire)
    print("Perimetre = ", perimetre)

if __name__ == "__main__":
    main()
