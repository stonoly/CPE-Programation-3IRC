# Fichier: calculs.py
# Opérations mathématiques et bitwise avec structures de contrôle
# auteur: Pierre MOLY
# Exercice 1.8

def main():
    # lecture des valeurs saisies par l'utilisateur
    num1 = 14
    num2 = 6
    op = input(f"Entrez une opération entre {num1} et {num2}: ")

    result = None

    if op == '+':
        # addition des deux nombres
        result = num1 + num2
    elif op == '-':
        # soustraction des deux nombres
        result = num1 - num2
    elif op == '*':
        # multiplication des deux nombres
        result = num1 * num2
    elif op == '/':
        # vérification de la division par 0
        if num2 == 0:
            print("Division par 0 impossible")
            return
        # division des deux nombres
        result = num1 // num2
    elif op == '&':
        # opération bitwise AND
        result = num1 & num2
    elif op == '|':
        # opération bitwise OR
        result = num1 | num2
    elif op == '~':
        # opération bitwise NOT
        result = ~num1
    else:
        # opération non valide
        print("Opération non valide")
        return

    # affichage du résultat
    if op == '~':
        print(f"L'opération mathématique {op}{num1} = {result}")
    else:
        print(f"L'opération mathématique {num1} {op} {num2} = {result}")

if __name__ == "__main__":
    main()