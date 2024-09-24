# Fichier: sizeof_types.py
# Donne les tailles des variables de différents types en Python
# auteur: Pierre MOLY
# Exercice 1.3

import sys

def main():
    print(sys.getsizeof(int))
    print(sys.getsizeof(float))
    print(sys.getsizeof(bool))
    print(sys.getsizeof(str))
    print(sys.getsizeof(list))
    print(sys.getsizeof(tuple))
    print(sys.getsizeof(dict))

if __name__ == "__main__":
    main()