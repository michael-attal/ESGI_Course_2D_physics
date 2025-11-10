# Création d’une classe Particule

---

## Introduction

Commençons la mise en place du concept de **classe Particule** (*Particle Class*).  
L’idée est d’intégrer cette structure dans le dossier `physics`, puisque tout ce qui concerne le moteur physique (*physics engine*) s’y trouve.  
Si l’on se souvient bien, nous avons déjà les fichiers `particle.h` et `particle.cpp`.  
La **déclaration** de notre classe Particule doit se trouver dans `particle.h`.  
C’est une règle de base : toutes les déclarations de classes et prototypes de fonctions doivent se situer dans les fichiers d’en-tête (*header files*).  

---

## Définition de la structure Particule

Nous allons commencer par définir une classe, ou plutôt une **structure Particule** (*struct Particle*).  
Chaque particule possède trois vecteurs essentiels : **position**, **vitesse** (*velocity*), et **accélération** (*acceleration*).  
Ces trois vecteurs représentent le mouvement linéaire (*linear motion*) de la particule.  

À cela, nous ajoutons une **masse** (*mass*), qui est une valeur scalaire, c’est-à-dire un nombre flottant (*float*).  
Pour le moment, il n’est pas nécessaire de se soucier des unités de mesure.  
Nous nous contenterons donc d’un attribut `float mass` dans la structure.  

---

## Constructeur et inclusions nécessaires

Créons maintenant un **constructeur** pour initialiser la particule.  
Ce constructeur prendra en paramètres les coordonnées `x` et `y` de la position initiale, ainsi que la masse `mass`.  

Il faut également inclure le fichier `vector.h`, puisque la particule utilise des objets `Vector2` ou `Vector3`.  
Ainsi, dans `particle.h`, on ajoutera l’inclusion du fichier `vector`.  

---

Le constructeur initialisera les attributs :  
- `position` avec un nouveau vecteur à partir de `x` et `y`,  
- `mass` avec la valeur fournie en paramètre.  

Enfin, pour faciliter le débogage, le constructeur affichera un message dans la console :  
`"Particle constructor called"`. 

De même, le **destructeur** affichera : `"Particle destructor called"`.  
Cela permettra de vérifier la création et la libération correcte des objets (éviter les *memory leaks*).  

---

## Approche d’encapsulation

On utilise une **structure (`struct`)** au lieu d’une **classe (`class`)** classique, car dans un `struct`, les membres sont **publics par défaut**.  

En programmation orientée objet (*OOP*), la bonne pratique consiste à **cacher les données** (*data hiding*) derrière des attributs privés et à y accéder par des *getters* et *setters*.  
Cependant, dans un contexte académique ou expérimental, il n’y a **aucune nécessité fonctionnelle** d’ajouter ces méthodes si elles ne contiennent aucune logique particulière.  

---

Ainsi, on pourra directement accéder aux attributs :  
`particle.position = newPosition;`  sans passer par des accesseurs.  

Cette approche simplifie le code et rend les exemples plus clairs pour la démonstration, même si elle n’est pas recommandée dans un contexte industriel.  

---

## Implémentation dans `particle.cpp`

Dans le fichier `particle.cpp`, nous allons définir le constructeur de la structure :  

- Le constructeur prend `float x`, `float y`, et `float mass` en paramètres.  
- Il initialise `position` avec le vecteur correspondant à `x` et `y`.  
- Il affecte la valeur de `mass` à l’attribut correspondant.  
- Il affiche le message `"Particle constructor called"` sur la sortie standard avec `std::cout`.  

---

Le destructeur fera de même :  
`"Particle destructor called"`, ce qui permet de vérifier la destruction correcte des objets.  

---

## Utilisation dans la classe Application

Dans le fichier `application.h`, qui contient la logique principale du programme, nous ajoutons un **pointeur vers une particule** :  
`Particle* particle;`  

Il faut inclure `physics/particle.h` pour que le compilateur reconnaisse le type.  

---

Dans `application.cpp`, au sein de la méthode `setup()`, on crée dynamiquement une particule :  

```cpp
particle = new Particle(50.0f, 100.0f, 1.0f);
```

Ici, la particule est initialisée à la position (50, 100) avec une masse de 1.0.  
Puisqu’elle est allouée dynamiquement dans le **tas** (_heap_), il est indispensable de **libérer la mémoire** à la fin du programme :

```cpp
delete particle;
```

Cela sera fait dans la méthode `destroy()` de la classe `Application`, appelée à la fin de l’exécution.

---

## Représentation visuelle de la particule

Pour **visualiser la particule**, on dessine un **cercle rempli** (_filled circle_) à sa position :

```cpp
drawCircle(particle->position.x, particle->position.y, 4, Color::White);
```

Le rayon choisi est de **4 pixels**, ce qui donne une petite marque blanche sur l’écran.  
Même si les particules n’ont pas encore de forme physique réelle (elles sont des points abstraits), cette représentation graphique permet de **suivre leur position dans l’espace**.

---

## Conclusion

En compilant et exécutant le programme, on observe une particule affichée à la position $(50, 100)$.  
Aucune mise à jour de sa position n’est encore effectuée, mais la **structure de base du système de particules** est désormais en place.

Dans la prochaine étape, nous pourrons commencer à introduire les **idées de mouvement** (_motion_), c’est-à-dire la mise à jour dynamique de la position à partir de la vitesse et de l’accélération.