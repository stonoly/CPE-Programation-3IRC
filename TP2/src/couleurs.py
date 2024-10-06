# Fichier: couleurs.py
# Gestion des couleurs et comptage des occurrences
# Auteur: Pierre MOLY / Maxence LERDA
# Exercice 2.7

# Références:
# http://www.science-du-numerique.fr/comment-convertir-un-nombre-decimal-en-hexadecimal-en-python#:~:text=Pour%20convertir%20un%20nombre%20d%C3%A9cimal,repr%C3%A9sentant%20le%20nombre%20en%20hexad%C3%A9cimal.

from random import randint

class Couleur:
    # Classe pour stocker les informations d'une couleur
    def __init__(self, r: str, g: str, b: str, a:str) -> None:
        self.r = r
        self.g = g
        self.b = b
        self.a = a

def main():
    # Création d'une liste de 99 couleurs aléatoires
    color_list = []

    for i in range(100):

        if (i > 30 and i < 35):
            r = hex(212)
            g = hex(42)
            b = hex(78)
        else:
            # Génération de valeurs aléatoires pour les composantes R, G et B
            r = hex(randint(0, 255))
            g = hex(randint(0, 255))
            b = hex(randint(0, 255))
            # Création d'une instance de la classe Couleur
        couleur = Couleur(r, g, b, 'ff')
        # Ajout de la couleur à la liste
        color_list.append(couleur)

    dict_colors = {}
    # Comptage des occurrences de chaque couleur
    for color in color_list:
    # Si la couleur n'est pas dans le dictionnaire, on l'ajoute avec une occurrence de 1
        if dict_colors.get(f'{color.a} {color.r} {color.g} {color.b}') == None:
            dict_colors[f'{color.a} {color.r} {color.g} {color.b}'] = 1
        else:
            # Sinon, on incrémente l'occurrence de 1
            dict_colors[f'{color.a} {color.r} {color.g} {color.b}'] += 1
    
    for i in dict_colors:
        # Affichage des couleurs et de leur occurrence
        print(f"{i} : {dict_colors[i]}")


if __name__ == "__main__":
    main()
        

