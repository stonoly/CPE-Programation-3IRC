# Fichier: binaire.py
# Affichage d'un nombre en format binaire
# auteur: Pierre MOLY
# Exercice 1.9

def main():
    num = int(input("Entrez un nombre: "))
    bin = ""

    if num == 0:
        print(f"le binaire de {num} est : 0")
        return

    num_compt = num
    while num_compt > 0:
        bin += str(num_compt % 2)
        num_compt = num_compt // 2

    bin = bin[::-1]
    print(f"le binaire de {num} est : {bin}")

if __name__ == "__main__":
    main()