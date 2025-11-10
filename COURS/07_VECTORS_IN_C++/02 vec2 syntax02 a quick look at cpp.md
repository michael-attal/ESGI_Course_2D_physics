# Introduction à Vec2.h

Nous allons examiner le fichier `Vec2.h` et expliquer ce que signifient tous ces détails du langage C++.  

---

## Protection du fichier header (Header Guards)

Au début du fichier header, on trouve les lignes `#ifndef VEC2_H`, `#define VEC2_H` et en fin de fichier `#endif`.  
Il s’agit de ce que l’on appelle des *header guards*.  
Ils permettent d’inclure le fichier header une seule fois dans tout le projet, évitant ainsi les inclusions multiples.  

---

## Structures en C++

Ensuite, nous déclarons une `struct`.  
Une `struct` est comme une classe où toutes les variables membres et méthodes sont publiques par défaut.  

---

## Constructeurs et destructeur

Le fichier contient un constructeur vide, un constructeur avec paramètres et un destructeur.  
La syntaxe `Vec2::~Vec2() = default;` demande au compilateur de générer un destructeur par défaut, ce qui est la manière moderne en C++ de gérer cela.  

---

## Vue d’ensemble des opérations sur les vecteurs

Nous passons maintenant aux opérations sur les vecteurs : addition, soustraction, mise à l’échelle (*scale*) et rotation.  
Par exemple, la méthode `add` retourne `void` car elle modifie le vecteur courant avec le vecteur passé en paramètre.  

---

## Comprendre const et références

Le mot-clé `const` indique que le paramètre ne sera pas modifié.  
La référence (`&`) permet de passer le paramètre sans copier la structure, ce qui est plus efficace en termes de performances.  

---

## Const dans les méthodes

On utilise `const` à la fin d’une signature de méthode pour indiquer que la méthode ne modifiera pas l’état interne de l’objet.  
Exemples : `magnitude()` et `magnitudeSquared()` sont des méthodes `const` car elles ne modifient pas `x` et `y`.  
`normalize()` n’est pas `const` car elle modifie le vecteur en place, tandis que `unitVector()` retourne un nouveau vecteur normalisé sans modifier l’original.  

---

## Vecteurs normaux et perpendiculaires

La méthode `normal()` calcule le vecteur perpendiculaire normalisé, équivalent à l’ancienne fonction `perpendicular()` que nous avions en JavaScript.  

---

## Produit scalaire et produit vectoriel

Le produit scalaire (`dot`) retourne un `float` représentant un scalaire.  
Le produit vectoriel 2D (`cross`) retourne la magnitude de la composante Z, simulant une projection du vecteur dans l’espace 3D imaginaire perpendiculaire à l’écran.  

---

## Fichiers header et cpp ensemble

Le header contient les prototypes et la structure de la classe, tandis que le fichier `.cpp` contient l’implémentation réelle des méthodes.  

---

## Inclusion des bibliothèques

Dans le fichier `.cpp`, on inclut `vec2.h` et `math.h` pour accéder aux fonctions mathématiques comme `cos`, `sin` ou `sqrt`.  

---

## Implémentation des constructeurs

Le constructeur sans paramètre initialise `x` et `y` à 0.  
Le constructeur avec paramètres assigne les valeurs passées aux attributs `x` et `y`.  

---

## Implémentation de add, subtract, scale et rotate

Les méthodes `add` et `subtract` modifient les attributs `x` et `y` directement.  
La méthode `scale` multiplie par un scalaire.  
La méthode `rotate` crée un nouveau vecteur résultant de la rotation.  

---

## Magnitude et magnitudeSquared

`magnitude()` calcule la longueur du vecteur avec la racine carrée.  
`magnitudeSquared()` retourne $x^{2} + y^{2}$ sans racine carrée, utile pour comparer des magnitudes sans calcul coûteux.  

---

## Normalize et unitVector

`normalize()` modifie le vecteur en place.  
`unitVector()` retourne un nouveau vecteur normalisé, sans modifier l’original.  

---

## Normal et vecteurs perpendiculaires

La méthode `normal()` retourne le vecteur perpendiculaire normalisé.  

---

## Produits scalaire et vectoriel

Le produit scalaire est simple : $x_1*x_2 + y_1*y_2$.  
Le produit vectoriel en 2D retourne la magnitude de la composante Z simulée.  

---

## Préparation à la surcharge d’opérateurs

Après cette revue de syntaxe, nous aborderons la surcharge d’opérateurs (*operator overloading*) pour faciliter l’addition, la soustraction, la mise à l’échelle et la division des vecteurs.  
Ces notions sont essentielles pour l’implémentation de notre moteur physique 2D, où les vecteurs seront omniprésents.  
