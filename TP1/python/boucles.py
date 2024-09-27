# Fichier: boucles.py
# Affichage d'un triangle rectangle avec des boucles
# auteur: Pierre MOLY
# Exercice 1.6

def triangle(size):
    # boucle for pour afficher le triangle
    for i in range(size + 1):
        # initialisation du tableau de caractères
        pixels = ""
        # boucle for pour afficher les pixels
        for j in range(i):
            if j == i - 1 or j == 0 or i == size:
                pixels += "* "
            else :
                pixels += "# "
        # affichage du tableau de caractères
        print(pixels)

def triangle_while(size):
    # initialisation de la variable i
    i = 0
    # boucle while pour afficher le triangle
    while i <= size:
        # initialisation du tableau de caractères
        pixels = ""
        # initialisation de la variable j
        j = 0
        # boucle while pour afficher les pixels
        while j < i:
            if j == i - 1 or j == 0 or i == size:
                pixels += "* "
            else:
                pixels += "# "
            j += 1
        # affichage du tableau de caractères
        print(pixels)
        # incrémentation de la variable i
        i += 1

def main():
    # lecture de la valeur saisie par l'utilisateur
    s = int(input("Entrez une valeur pour taille (strictement inférieure à 10) pour voir le triangle rectangle: "))
    # vérification de la valeur saisie par l'utilisateur
    if s >= 10 or s <= 0:
        # affichage d'un message d'erreur si la valeur saisie n'est pas valide
        print("Erreur la taille doit être strictement inférieure à 10 et supérieur à 0")
    else:
        # appel de la fonction triangle_while avec la valeur saisie par l'utilisateur
        triangle_while(s)

if __name__ == "__main__":
    main()