# Fichier: variables.py
# Affectation et affichage des variables de types de base en Python
# auteur: Pierre MOLY
# Exercice 1.4

def main():
    integer = 3
    floater = 3.14
    string = "Python"
    boolean = True
    liste = [31, 5, 74, 13, 62]
    tupler = (31, "Texte", False)
    dictionnaire = {
        "int": 3,
        "float": 3.14,
        "string": "Python",
        "boolean": True,
    }

    print("Int :", integer)
    print("Float :", floater)
    print("String :", string)
    print("Boolean :", boolean)
    print("Liste :", liste)
    print("Tuple :", tupler)
    print("Dictionnaire :", dictionnaire)

if __name__ == "__main__":
    main()