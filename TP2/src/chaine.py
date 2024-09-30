# Fichier: chaine.py
# Manipulation de Chaînes de Caractères
# auteur: Pierre MOLY / Maxence LERDA
# Exercice 2.4

def char_count(str):
    count = 0
    for char in str:
        count += 1
    return count

def str_concat(str1: str, str2: str) -> str:
    return str1 + str2

def main():
    str = input("Entrez une chaîne de caractères sans espace: ")
    print("La longueur de la chaîne est : ", char_count(str))
    str2 = input("Entrez une deuxième chaîne de caractères sans espace: ")
    print("La chaîne concaténée est : ", str_concat(str, str2))

if __name__ == "__main__":
    main()