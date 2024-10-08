# EXERCICE 1.10

## 1. **Bases de la programmation :**

### C :
Pour print une variable, on utilise la fonction `printf()` et **on spécifie le type de la variable** à afficher. De plus pour récupérer une variable en entrée, on utilise la fonction `scanf()` et **on spécifie le type de la variable** à récupérer. Au niveau de la syntaxe, on a besoin de mettre des `;` à la fin de chaque instruction. Concernant la gestion de la mémoire les **variables ne prennent pas beaucoup de places** car chaques types de variables ont des tailles définies.
#### Exemple :
```c
int age = 25;
printf("L'age est %d\n", age);
scanf("%d", &age);
```

### Python : 
Pour python, on utilise la fonction `print()` pour afficher une variable et on peut utiliser la fonction `input()` pour récupérer une variable en entrée. On pas besoin de spécifier le type de variable à afficher ou à récupérer. Au niveau de la syntaxe on pas besoin de mettre des `;` à la fin de chaque instruction. Concernant la gestion de la mémoire, **les variables prennent beaucoup de place** car les variables sont dynamiques. Et prennet toutes la même place dans la mémoire avant que l'on leur assigne une valeur.
#### Exemple :
```python
age = 25
print("L'age est", age)
age = input("Entrez un age : ")
```
## 2. **Manipulation des variables :**

### C :
En C, chaque **variable doit être déclarée avec un type spécifique** avant son utilisation. Cela signifie que le type de la variable est connu à la **compilation**, ce qui permet une gestion efficace de la mémoire et des performances optimisées. 
#### Exemple :
```c
int age = 25;
float temperature = 98.6;
char grade = 'A';
```

### Python :
En Python, les variables sont **dynamiques** et peuvent être utilisées sans déclaration explicite de type. Les variables sont **créées lorsqu'on leur assigne une valeur**, et le type de la variable est déterminé en fonction de la valeur assignée. Le type **peut changer au cours du programme**, si la valeur change. Il est aussi possible de donner des types mais cela a plus un interet pour la documentation et la clarté du code.
#### Exemple :
```python
age = 25
temperature = 98.6
grade = 'A'
```
## 3. **Opérateurs :**
### C :
En C, les opérateurs arithmétiques sont utilisés pour **effectuer des opérations mathématiques**. Les opérateurs logiques sont utilisés pour **effectuer des opérations booléennes**. Les opérateurs bit à bit sont utilisés pour **effectuer des opérations sur les bits**.
#### Exemple :
```c
int a = 10;
int b = 20;
int c = a + b; // c = 30
int d = a > b; // d = 0
int e = a & b; // e = 0
```

### Python :
En Python, les opérations sont effectuées de la même manière que en C. Les opérateurs arithmétiques sont utilisés pour **effectuer des opérations mathématiques**. Les opérateurs logiques sont utilisés pour **effectuer des opérations booléennes**. Les opérateurs bit à bit sont utilisés pour **effectuer des opérations sur les bits**.
#### Exemple :
```python
a = 10
b = 20
c = a + b // c = 30
d = a > b // d = False
e = a & b // e = 0
```

## 4. **Boucles et structures de contrôle :**

### C :
En C, les boucles et les structures de contrôle sont utilisées pour effectuer des opérations répétitives ou conditionnelles. Les boucles `for` et `while` sont utilisées pour effectuer des opérations répétitives. Les structures conditionnelles `if`, `else` et `switch` sont utilisées pour effectuer des opérations conditionnelles. Les accolades `{}` sont utilisées pour délimiter les blocs de code.
#### Exemple :
```c
for (int i = 0; i < 10; i++) {
    printf("i = %d\n", i);
}
```

### Python :
En Python, les boucles et les structures de contrôle sont utilisées de la même manière que en C. Les boucles `for` et `while` sont utilisées pour effectuer des opérations répétitives. Les structures conditionnelles `if`, `else` et `else if` sont utilisées pour effectuer des opérations conditionnelles. L'indentation est utilisée pour délimiter les blocs de code.
#### Exemple :
```python
for i in range(10):
    print("i =", i)
```

<!--Conversion et formatage : Compare les techniques de formatage et de conversion (comme la conversion en binaire) en C et Python, en mettant en évidence les différences entre les fonctions spécifiques en C et les f-strings en Python.--->

## 5. **Conversion et formatage :**

### C :
En C, pour afficher un nombre en format binaire, nous devons utiliser des **tableaux pour stocker les bits**, car le langage ne fournit pas de type de données intégré pour les chaînes de caractères dynamiques. Nous utilisons une boucle pour diviser le nombre par 2 et stocker le reste (`0` ou `1`) dans un tableau. Ensuite, nous **affichons les bits dans l'ordre inverse en refaisant une boucle**.
#### Exemple :
```c
int num = 10;
int bin[32];
int position_tab = 0;

for (int num_compt = num ; num_compt > 0; num_compt /= 2){
    bin[position_tab] = num_compt %2;
    position_tab++;
}
```

### Python :
En Python, nous pouvons utiliser des **chaînes de caractères** pour construire la représentation binaire d'un nombre. Le langage permet une manipulation plus simple des chaînes, et nous pouvons utiliser une boucle pour obtenir les bits de manière similaire à C. Cependant, nous pouvons directement utiliser la syntaxe des `f-strings` pour un **affichage formaté**.
#### Exemple :
```python
while num_compt > 0:
        bin += str(num_compt % 2)
        num_compt = num_compt // 2

    bin = bin[::-1]
    print(f"le binaire de {num} est : {bin}")
```