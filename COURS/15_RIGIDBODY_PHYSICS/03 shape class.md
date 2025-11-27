# Implementing Shape Classes in C++

Nous avons déjà discuté de la logique générale des *rigid bodies*, de la classe `Body` et de la nécessité d’y attacher une forme géométrique.  
Dans cette partie, nous passons de la théorie à l’implémentation pratique en C++.  
Même si le diagramme de classes est relativement simple, la syntaxe C++ demande une structure rigoureuse, notamment concernant l’héritage, les méthodes virtuelles, les énumérations et la séparation `.h` / `.cpp`.

Nous allons donc commencer par écrire le fichier `shape.h` et poser l’architecture de base.

---

## Protection Guards and Base Structure

Dans `shape.h`, la première étape consiste à ajouter un *include guard* classique.  
Nous déclarons ensuite la classe/structure de base `Shape`.  
Cette classe possède :

- un destructeur virtuel (pour permettre l’héritage propre),  
- une énumération `ShapeType` définissant les types de formes (Circle, Polygon, Box),  
- une méthode virtuelle `GetType() const` dont les classes dérivées devront fournir une implémentation.

L’objectif est de créer une base polymorphique permettant à chaque forme d’exposer son type sans modifier son état interne, d’où le mot-clé `const`.  
Cette structure sera la racine de toutes les formes géométriques utilisées par les rigid bodies.

---

## Circle Shape

Nous déclarons ensuite `CircleShape`, qui hérite de `Shape`.  
Cette structure représente un cercle et comporte un seul attribut spécifique : son **rayon**.

Elle possède :

- un constructeur permettant d’initialiser le rayon,  
- un destructeur par défaut virtuel (hérité de `Shape`),  
- une méthode `GetType()` qui retourne `ShapeType::CIRCLE`.

L’implémentation souligne la verbosité du C++ :  
il faut spécifier l’héritage, le `override`, les constructeurs explicites, etc.  
Cette structure servira de première implémentation concrète, notamment pour les premières collisions.

---

## Polygon Shape

Nous introduisons ensuite `PolygonShape`, également dérivé de `Shape`.  
Cette forme stocke une liste de sommets en 2D :

- un `std::vector<Vec2> vertices`.

Le fichier devra inclure le type `Vec2`.  
`PolygonShape` fournit :

- un constructeur par défaut,  
- un constructeur prenant directement une liste de sommets en paramètre,  
- un destructeur,  
- une méthode `GetType()` surchargée,  
- et plus tard, une méthode `GetMomentOfInertia()` propre aux polygones.

Nous ne définissons pas encore la logique interne (calculs, validation de convexité), mais établissons l'interface.

---

## Box Shape

Enfin, nous implémentons `BoxShape`, qui **hérite de `PolygonShape`**.  
Une boîte est un **polygone convexe à quatre sommets**.  
Elle possède :

- une largeur,  
- une hauteur,  
- un constructeur qui initialise automatiquement les quatre sommets du rectangle,  
- une méthode `GetType()` retournant `ShapeType::BOX`.

Cette structure est un cas particulier de polygone, mais suffisamment courant pour justifier une classe dédiée.

---

## Summary

Nous avons désormais un schéma complet :

- une énumération `ShapeType`,  
- une classe de base `Shape`,  
- une classe dérivée `CircleShape` (avec rayon),  
- une classe dérivée `PolygonShape` (avec liste de sommets),  
- une classe dérivée `BoxShape` (spécialisation d’un polygone rectangulaire).

Il reste à ajouter :

- la méthode `GetMomentOfInertia()` pour chaque forme,  
- les implémentations dans `shape.cpp`.

L’objectif était de créer un **squelette clair et complet** de l’architecture.  
Tout ce qui concerne les formes (`shape.h` et `shape.cpp`) est regroupé dans deux fichiers uniques afin de simplifier l’organisation du projet.

