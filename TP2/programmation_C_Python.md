# EXERCICE 2.8

## 1. **Débogage :**

### C :
En C, le débogage est effectué à l'aide de l'outil `gdb` (GNU Debugger). `gdb` est un outil en ligne de commande qui permet de **déboguer des programmes C** en exécutant le programme pas à pas, en inspectant les variables et en affichant les valeurs des variables. Pour déboguer un programme en C avec `gdb`, nous devons **compiler le programme avec l'option `-ggdb3`** pour inclure les informations de débogage dans le binaire. Ensuite, nous exécutons le programme avec `gdb` et utilisons des commandes telles que `r`, `bt`, `quit`.

### Python :
En Python, le débogage est effectué à l'aide de l'outil `pdb` (Python Debugger). `pdb` est un outil en ligne de commande qui permet de **déboguer des programmes Python** en exécutant le programme pas à pas, en inspectant les variables et en affichant les valeurs des variables. Pour déboguer un programme en Python avec `pdb`, nous devons **importer le module `pdb` et appeler la fonction `pdb.set_trace()`** à l'endroit où nous voulons démarrer le débogage. Ensuite, nous exécutons le programme et utilisons des commandes telles que `l`, `n`, `b`, `c`, `p`. Nous pouvons aussi lancer la commande `python3 -m pdb script.py` pour démarrer le débogage.

## 2. **Chaîne de Compilation :**

### C :
En C, le processus de compilation est effectué à l'aide de l'outil `gcc` (GNU Compiler Collection). Le processus de compilation en C comprend plusieurs étapes : **prétraitement, compilation, assemblage et édition des liens**. Lorsque nous compilons un programme en C avec `gcc`, le préprocesseur effectue le prétraitement, le compilateur génère le code objet, l'assembleur génère le code assembleur et l'éditeur de liens lie les fichiers objets pour créer l'exécutable final. IL est possible de choisir le niveau d'optimisation avec l'option `-O` et de spécifier le fichier de sortie avec l'option `-o`. Il est aussi possible de compiler un programme avec plusieurs fichiers source en spécifiant les fichiers source à compiler.

#### Exemple :
```bash
gcc -E aire.c -o aire.i;
gcc -S aire.i -o aire.s;
gcc -c aire.s -o aire.o;
gcc aire.o -o aire;
./aire;
```

## 3. **Inspection de Code :**

### Python :
En Python, nous pouvons inspecter le bytecode généré par l'interpréteur Python en utilisant le module `dis`. Le module `dis` nous permet d'**examiner le bytecode** généré pour une fonction ou une méthode Python. Nous pouvons importer le module `dis` et appeler la fonction `dis.dis()` pour afficher le bytecode d'une fonction. Le bytecode est une représentation intermédiaire du code source Python qui est exécutée par l'interpréteur Python. Il y a de nombreux opcodes différents qui correspondent à différentes instructions Python. Voici quelques exemples d'opcodes : `GET_ITER`, `FOR_ITER`, `SETUP_LOOP`, `POP_BLOCK`, `LOAD_GLOBAL`, `LOAD_FAST`, `BINARY_MULTIPLY`. La différence avec le C est que le code Python est interprété à la volée, tandis que le code C est compilé en code machine. Les outils pour inspecter le code compilé sont donc différents.


## 4. **Manipulation de Chaînes de Caractères :**
### C :
En C, la manipulation de chaînes de caractères est effectuée à l'aide de fonctions de la bibliothèque standard telles que `strlen`, `strcpy`, `strcat`. Les chaînes de caractères en C sont des tableaux de caractères terminés par un caractère nul (`\0`). Pour concaténer des chaînes de caractères en C, nous utilisons la fonction `strcat`. Si nous devions faire cette fonction à la main en C, nous devrions parcourir les deux chaînes de caractères et copier les caractères un par un dans une nouvelle chaîne de caractères. La manipulation de chaînes de caractères en C est plus complexe que Python en raison de la nécessité de gérer manuellement la mémoire et les terminaisons de chaîne.
#### Exemple :
```c
#include <stdio.h>

int str_count(char str[]){
    // Compter le nombre de caractères dans la chaîne
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return count;
}


char* copie_chaine(char destination[], char source[]) {
    int i = 0;

    // Copier source dans destination
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    // Ajouter le caractère nul '\0' pour terminer la chaîne
    destination[i] = '\0';

    return destination;
}

char* str_concat(char resultat[], char str1[], char str2[]){
    int i = 0;
    // recopier str1 dans resultat
    resultat = str1;
    // récupérer la taille de str1 avec str_count
    int size1 = str_count(str1);

    for (; str2[i] != '\0'; i++){
        // ajouter les caractères de str2 à la fin de str1
        resultat[size1 + i] = str2[i];
    }
    // ajouter le caractère nul '\0' pour terminer la chaîne
    resultat[size1 + i] = '\0';
    // retourner la chaîne concaténée
    return resultat;
}

```

### Python :
En Python tout est plus simple, la manipulation de chaine de caractère se fait comme une liste de caractère. Il suffit juste d'additionner les chaines pour les concaténer. On peut aussi utiliser les f-strings pour formater les chaines de caractères. Les f-strings sont des chaînes de caractères préfixées par la lettre `f` ou `F` qui permettent d'insérer des variables ou des expressions Python dans une chaîne de caractères. Les f-strings sont plus lisibles et plus faciles à utiliser que les anciennes méthodes de formatage de chaînes de caractères en Python.

#### Exemple :
```python
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
```


## 5. **Gestion des Données et Recherche dans les Fichiers :**
### C :
En C, la gestion des données est effectuée à l'aide de structures. Les structures en C nous permettent de regrouper des données de types différents sous un même nom. Par exemple, pour stocker les données d'un étudiant en C, nous pourrions définir une structure `Etudiant` avec des champs tels que `nom`, `prénom`, `âge`, `note`. 
#### Exemple :
```c
struct Student {
    char name[50];      
    char firstname[25]; 
    char address[100];  
    short note[3];    
};
```

Pour rechercher des phrases dans des fichiers en C, nous devons ouvrir le fichier, lire le contenu du fichier ligne par ligne, puis rechercher la phrase dans chaque ligne. En parcourant lettre par lettre chaque ligne, nous pouvons rechercher la phrase dans le fichier. Nous utilisons des fonctions telles que `fopen`, `fgets`, `strstr` pour rechercher des phrases dans des fichiers en C.

#### Exemple :

```c
#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    char search_phrase[100];

    // Demande à l'utilisateur d'entrer le nom du fichier
    printf("Entrez le nom du fichier :");
    scanf("%s", filename);

    // Demande à l'utilisateur d'entrer la phrase à rechercher
    printf("Entrez la phrase que vous souhaitez rechercher :");
    scanf("%s", search_phrase);
    printf("\n");

    // Ouvre le fichier en mode lecture
    FILE * file = fopen(filename, "r");
    char line[100];
    int found = 1;

    // Vérifie si le fichier a été ouvert correctement
    if(file == NULL) {
        printf("Le fichier n'existe pas \n");
        return 1;
    }

    // Utilise fgets pour lire chaque ligne du fichier et donner le nombre de fois que la phrase est trouvée dans la ligne
    printf("Résultat de la recherche : \n");
    int i = 0;
    int found_line = 1;
    // Parcourt le fichier ligne par ligne
    while(fgets(line, sizeof(line), file) != NULL) {
        int count = 0;
        // Parcourt la ligne caractère par caractère
        for (int j = 0; j < strlen(line); j++) {
            if (line[j] == search_phrase[0]) {
                int count_letter = 0;
                // Parcourt la phrase caractère par caractère
                for (int k = 0; k < strlen(search_phrase); k++) {
                    if (line[j + k] == search_phrase[k]) {
                        count_letter++;
                    }
                    // Si la phrase est trouvée dans la ligne
                    if (count_letter == strlen(search_phrase)) {
                        found_line = 0;
                        count++;
                    }
                }
            }
        }
        // Si la phrase est trouvée dans la ligne
        if (found_line == 0) {
            printf("Phrase '%s' trouvée %d fois à la ligne %d\n", search_phrase, count, i + 1);
            found = 0;
        }
        found_line = 1;
        i++;
    }

    // Si la phrase n'a pas été trouvée dans le fichier
    if(found == 1) {
        printf("La phrase '%s' n'a pas été trouvée dans le fichier %s\n", search_phrase, filename);
    }

    // Ferme le fichier
    fclose(file);

    return 0;
}
```
### Python :
En Python, la gestion des données est effectuée à l'aide de classes. Les classes en Python nous permettent de regrouper des données et des méthodes sous un même nom. Par exemple, pour stocker les données d'un étudiant en Python, nous pourrions définir une classe `Etudiant` avec des attributs tels que `nom`, `prénom`, `âge`, `note`.

#### Exemple :
```python
class Student:
    def __init__(self) -> None:
        self.name = ''         
        self.firstname = ''   
        self.address = ''      
        self.note = []
```

Pour rechercher des phrases dans des fichiers en Python, nous pouvons ouvrir le fichier, lire le contenu du fichier ligne par ligne, puis rechercher la phrase dans chaque ligne. En Python, nous pouvons utiliser des méthodes de chaîne telles que `count` pour rechercher des phrases dans des fichiers. Pour ouvrir le fichier, nous utilisons la fonction `open` avec le mode de lecture `r`. Ensuite, nous utilisons la méthode `readlines` pour lire le contenu du fichier ligne par ligne.

#### Exemple :
```python
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
```