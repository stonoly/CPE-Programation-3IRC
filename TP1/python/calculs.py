# Fichier: calculs.py
# Opérations mathématiques et bitwise avec structures de contrôle
# auteur: Pierre MOLY
# Exercice 1.8

def main():
    num1 = 14
    num2 = 6
    op = input(f"Entrez une opération entre {num1} et {num2}: ")

    result = None

    if op == '+':
        result = num1 + num2
    elif op == '-':
        result = num1 - num2
    elif op == '*':
        result = num1 * num2
    elif op == '/':
        if num2 == 0:
            print("Division par 0 impossible")
            return
        result = num1 // num2
    elif op == '&':
        result = num1 & num2
    elif op == '|':
        result = num1 | num2
    elif op == '~':
        result = ~num1
    else:
        print("Opération non valide")
        return

    if op == '~':
        print(f"L'opération mathématique {op}{num1} = {result}")
    else:
        print(f"L'opération mathématique {num1} {op} {num2} = {result}")

if __name__ == "__main__":
    main()