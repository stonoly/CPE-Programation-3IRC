# Fichier: chaine.py
# Manipulation de Chaînes de Caractères
# auteur: Pierre MOLY / Maxence LERDA
# Exercice 2.4

def str_count(str: str) -> int:
    # Compter le nombre de caractères dans la chaîne
    count = 0
    for char in str:
        count += 1
    return count

def str_copy(str: str) -> str:
    # Copier la chaîne
    str_copy = ""
    for char in str:
        # Ajouter chaque caractère à la chaîne copiée
        str_copy += char
    return str_copy

def str_concat(str1: str, str2: str) -> str:
    # Concaténer les deux chaînes
    str_concat = ""
    for char in str1:
        str_concat += char
    for char in str2:
        str_concat += char
    return str_concat

def main():
    # Demander à l'utilisateur de saisir une chaîne de caractères sans espace
    str = input("Entrez une chaîne de caractères sans espace: ")
    copy_str = str_copy(str)
    # Afficher la longueur de la chaîne
    print("La longueur de la chaîne est : ", str_count(str))
    # Copier la chaîne
    print("La chaîne copiée est : ", copy_str)
    # Demander à l'utilisateur de saisir une deuxième chaîne de caractères sans espace
    str2 = input("Entrez une deuxième chaîne de caractères sans espace: ")
    # Afficher la chaîne concaténée
    print("La chaîne concaténée est : ", str_concat(str, str2))

if __name__ == "__main__":
    main()