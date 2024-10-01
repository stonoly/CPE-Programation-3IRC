# Fichier: phrases.py
# Programme permettant de rechercher une phrase dans un fichier
# Auteur: [Ton nom]

def main():
    # Demander à l'utilisateur de saisir le nom du fichier
    filename = input("Entrez le nom du fichier : ")

    # Demander à l'utilisateur de saisir la phrase à rechercher
    search_phrase = input("Entrez la phrase que vous souhaitez rechercher : ")

    try:
        # Ouvrir le fichier en mode lecture
        with open(filename, 'r', encoding='utf-8') as file:
            lines = file.readlines()  # Lire le contenu du fichier ligne par ligne

        # Initialiser un compteur pour les résultats
        found = False

        # Parcourir chaque ligne du fichier
        for line_number, line in enumerate(lines, start=1):
            # Compter le nombre d'occurrences de la phrase dans la ligne actuelle
            count = line.count(search_phrase)

            # Si la phrase est trouvée dans la ligne
            if count > 0:
                print(f"Ligne {line_number}, {count} fois")
                found = True

        # Si la phrase n'a été trouvée dans aucune ligne
        if not found:
            print("La phrase n'a pas été trouvée dans le fichier.")

    except FileNotFoundError:
        # Si le fichier n'existe pas ou n'est pas trouvé
        print(f"Erreur : Le fichier '{filename}' n'existe pas.")

if __name__ == "__main__":
    main()
