# Introduction aux fichiers `Vec2` en C++

La classe `Vector2` possède toutes les méthodes et attributs nécessaires pour l’implémentation C++ que nous utiliserons bientôt dans notre moteur physique 2D.  

---

## Comprendre la structure des fichiers

En C++, lorsqu’on crée une classe ou une structure, on n’utilise pas un seul fichier : il y a toujours deux fichiers.  
Un fichier avec l’extension `.h`, appelé fichier *header*, et un fichier avec l’extension `.cpp` contenant l’implémentation réelle des méthodes et fonctions.  

---

## Fichiers header et d’implémentation

Comme vous pouvez le voir en haut à gauche, j’ai deux onglets ouverts : `Vec2.h` pour le header et `Vec2.cpp` pour l’implémentation.  
Pour notre moteur physique 2D, nous allons nous concentrer uniquement sur les fichiers VEC2.  

---

## Le fichier header (vec2.h)

Commençons par analyser `Vec2.h`.  
Ce fichier header contient la déclaration des classes, structures et variables.  
Ici, `struct Vec2` est presque équivalent à une classe.  

Il contient deux attributs flottants publics, ainsi que la signature des constructeurs.  
Un constructeur permet d’initialiser les attributs `X` et `Y`, et il y a également un destructeur pour gérer la mémoire, indispensable en C++.  

---

## Déclarations des fonctions

Ce fichier contient uniquement les prototypes des fonctions : `add`, `subtract`, `scale`, `rotate`, `magnitude`, `normalized`, `normal`, `dot product`, `crossProduct`, etc.  

Il n’y a pas encore le corps des fonctions.  

`normalized` retourne un nouveau vecteur normalisé sans modifier le vecteur original, tandis que `normal` calcule le vecteur perpendiculaire normalisé.  

---

## Récapitulatif du fichier header

En résumé, le header contient exclusivement la déclaration des méthodes et la signature des fonctions.  
Le corps (implémentation) des fonctions se trouve dans le fichier `.cpp` et n’est pas présent ici.  

---

## Le fichier d’implémentation (Vec2.cpp)

Le fichier `Vec2.cpp` contient le corps des fonctions déclarées dans le header.  
C’est ici que se trouvent l’implémentation de l’addition, de la soustraction, de la mise à l’échelle, de la rotation, etc.  
C’est la méthode classique en C++ : header pour la déclaration, cpp pour l’implémentation.  

---

## Préparation pour la prochaine leçon

Maintenant que nous avons compris qu’il y a un fichier header et un fichier cpp, dans la prochaine leçon nous détaillerons la syntaxe C++ pour la classe `Vec2` : types `float`, `void`, références, guards (`#ifndef/#define`), etc.  
Ensuite, nous verrons la surcharge d’opérateurs (*operator overloading*), qui sera essentielle pour manipuler les vecteurs dans notre moteur physique.  
