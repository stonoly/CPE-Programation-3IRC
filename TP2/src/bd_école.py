# Fichier: bd_école.py
# Gestion des données d'étudiant.e.s
# Auteur: Pierre MOLY / Maxence LERDA
# Exercice 2.5

# Définition de la classe Student pour stocker les informations d'un étudiant
class Student:
    def __init__(self) -> None:
        self.name = ''         
        self.firstname = ''   
        self.address = ''      
        self.note = []

def main():
    # Création de 5 instances de la classe Student pour stocker 5 étudiants
    students1 = Student()
    students2 = Student()
    students3 = Student()
    students4 = Student()
    students5 = Student()
    students = [students1, students2, students3, students4, students5]  # Liste des étudiants

    # Boucle pour saisir les informations des 5 étudiants
    for i in range(5):
        students[i].name = input("Entrez le nom de l'étudiant: ")      
        students[i].firstname = input("Entrez le prénom de l'étudiant: ") 
        students[i].address = input("Entrez l'adresse de l'étudiant: ")  
        # Boucle pour saisir les 3 notes de l'étudiant
        for j in range(3):
            note = int(input("Entrez la note " + str(j + 1) + " : "))  # Saisie de chaque note
            students[i].note.append(note)  # Ajout de la note à la liste des notes
        print("\n")

    # Boucle pour afficher les informations des 5 étudiants
    for i in range(5):
        print("Étudiant " + str(i + 1) + ":")
        print("Nom: " + students[i].name)        
        print("Prénom: " + students[i].firstname)
        print("Adresse: " + students[i].address) 
        # Boucle pour afficher les 3 notes de l'étudiant
        for j in range(3):
            print("Note " + str(j + 1) + ": " + str(students[i].note[j]))
        print("\n")


if __name__ == "__main__":
    main()
