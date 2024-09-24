# Fichier: boucles.py
# Affichage d'un triangle rectangle avec des boucles
# auteur: Pierre MOLY
# Exercice 1.6

def triangle(size):
    for i in range(size + 1):
        pixels = ""
        for j in range(i):
            if j == i - 1 or j == 0 or i == size:
                pixels += "* "
            else :
                pixels += "# "
        print(pixels)

def triangle_while(size):
    i = 0
    while i <= size:
        pixels = ""
        j = 0
        while j < i:
            if j == i - 1 or j == 0 or i == size:
                pixels += "* "
            else:
                pixels += "# "
            j += 1
        print(pixels)
        i += 1

def main():
    s = int(input("Entrez une valeur pour taille (strictement inférieure à 10) pour voir le triangle rectangle: "))
    if s >= 10 or s <= 0:
        print("Erreur la taille doit être strictement inférieure à 10 et supérieur à 0")
    else:
        triangle_while(s)

if __name__ == "__main__":
    main()