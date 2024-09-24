# Fichier: controle.py
# Afficher les nombres de 1 à 1000 qui répondent à une condition donnée
# auteur: Pierre MOLY
# Exercice 1.7

def main():
    div4_not6 = []
    div8_pairs = []
    div5_or7_not10 = []

    for i in range(1, 1001):
        if i % 4 == 0 and i % 6 != 0:
            div4_not6.append(i)
        if i % 8 == 0 and i % 2 == 0:
            div8_pairs.append(i)
        if (i % 5 == 0 or i % 7 == 0) and i % 10 != 0:
            div5_or7_not10.append(i)

    print("Les nombres de 1 à 1000 qui sont divisibles par 4 mais pas par 6 sont : ", div4_not6)
    print("Les nombres de 1 à 1000 qui sont divisibles par 8 et pairs sont : ", div8_pairs)
    print("Les nombres de 1 à 1000 qui sont divisibles par 5 ou 7 mais pas par 10 sont : ", div5_or7_not10)

if __name__ == "__main__":
    main()