# Fichier: binaire.py
# Affichage d'un nombre en format binaire
# auteur: Pierre MOLY
# Exercice 1.9

def main():
    # lecture du nombre saisi par l'utilisateur
    num = int(input("Entrez un nombre: "))
    bin = ""

    # vérification si le nombre est 0
    if num == 0:
        print(f"le binaire de {num} est : 0")
        return

    
    # conversion en binaire
    num_compt = num
    while num_compt > 0:
        bin += str(num_compt % 2)
        num_compt = num_compt // 2

    bin = bin[::-1]

    # affichage du résultat
    print(f"le binaire de {num} est : {bin}")

if __name__ == "__main__":
    main()