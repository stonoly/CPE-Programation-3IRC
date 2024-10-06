# Fichier: phrases.py
# Recherche de phrases dans un fichier
# Auteur: Pierre MOLY / Maxence LERDA
# Exercice 2.6

#Références:
# https://www.tutorialspoint.com/python/file_readlines.htm
# https://www.programiz.com/python-programming/methods/built-in/open

def main():
    # Demander à l'utilisateur de saisir le nom du fichier
    filename = input("Entrez le nom du fichier : ")

    # Demander à l'utilisateur de saisir la phrase à rechercher
    search_phrase = input("Entrez la phrase que vous souhaitez rechercher : ")

    try: # On tente d'ouvrir le fichier
        file = open(filename, 'r')
    
        lines = file.readlines()  # Lire le contenu du fichier ligne par ligne
        contains = False
        print("\nRésultats de la recherche :")

        for i, line in enumerate(lines): # On parcourt les lignes du fichier
            if search_phrase in line: # Si la phrase est dans la ligne
                contains = True # On met à True
                count = line.count(search_phrase)
                print(f"Phrase '{search_phrase}' {count} fois à la ligne {i + 1}")
    
        if not contains: # Si la phrase n'est pas dans le fichier
            print(f"Le fichier ne contient pas la phrase {search_phrase}")

    except FileNotFoundError:
        print("Le fichier n'existe pas")


if __name__ == "__main__":
    main()
