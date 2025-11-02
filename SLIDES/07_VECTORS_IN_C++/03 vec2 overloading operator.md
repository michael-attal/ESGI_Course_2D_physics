# Surcharge d’opérateurs en C++

## Introduction

Nous arrivons au dernier sujet avant de plonger dans notre moteur physique.  
La surcharge d’opérateurs (*operator overloading*) est un outil puissant de C++ qui nous permet de réaliser des opérations comme l’addition, la soustraction ou la mise à l’échelle de vecteurs directement avec les symboles `+`, `-`, `*`, `/`.  

---

## Des méthodes aux opérateurs

Au lieu d’appeler une méthode pour ajouter deux vecteurs (`v1.add(v2)`), nous pouvons utiliser la surcharge d’opérateurs pour écrire simplement `v1 + v2`.  
Cela fonctionne de la même manière pour la soustraction et la mise à l’échelle.  

---

## Définir le comportement des opérateurs

Par défaut, C++ ne sait pas comment additionner des vecteurs avec `+` ou soustraire avec `-`.  
La surcharge d’opérateurs permet d’indiquer au compilateur comment effectuer ces opérations pour nos vecteurs.  

---

## Prototypes des opérateurs dans le header

Dans le fichier header `Vec2.h`, nous ajoutons les prototypes des opérateurs que nous souhaitons surcharger pour nos vecteurs.  

---

## Surcharge de l’égalité et de l’assignation

Pour assigner un vecteur à un autre (`=`) ou comparer deux vecteurs (`==`, `!=`), nous définissons des opérateurs retournant un booléen.  
Exemple : `v1 == v2` retourne true si `x` et `y` sont égaux pour les deux vecteurs.  

---

## Surcharge des opérateurs arithmétiques

Nous pouvons surcharger `+`, `-`, `*` et `/` pour additionner, soustraire ou scaler des vecteurs.  
Le `-` unaire permet d’inverser un vecteur (`-v1`).  

---

## Opérateurs d’assignation combinés

Les opérateurs `+=`, `-=`, `*=`, `/=` permettent de combiner l’opération avec l’affectation pour accumuler directement les valeurs dans un vecteur.  

---

## Comprendre les paramètres des opérateurs

Dans `v1 + v2`, `v2` est le paramètre passé à l’opérateur, représentant le côté droit de l’opération.  
Cela s’applique de la même manière pour tous les opérateurs binaires.  

---

## Opérateurs unaires

Pour les opérateurs unaires, comme la négation (`-v`), aucun paramètre n’est nécessaire. L’opération agit directement sur l’objet courant.  

---

## Implémentation dans le fichier `.cpp`

La déclaration dans le header indique simplement la signature.  
L’implémentation dans `Vec2.cpp` définit comment l’opération est effectuée sur les attributs `x` et `y`.  

---

## Détails de l’implémentation

Pour l’assignation (=), on copie `v.x` et `v.y` dans l’objet courant et on retourne une référence à celui-ci.  
Pour l’égalité (`==`), on compare `x` et `y` et retourne un booléen.  
Le `!=` est simplement la négation de `==`.  

---

## Addition et soustraction

L’addition crée un nouveau vecteur résultat avec la somme des composantes `x` et `y`.  
La soustraction fonctionne de la même manière.  

---

## Opérations scalaires

La multiplication (`*`) et la division (`/`) appliquent un facteur sur chaque composante `x` et `y` et retournent un nouveau vecteur.  

---

## Implémentation des opérateurs combinés

`+=`, `-=`, `*=`, `/=` modifient le vecteur courant en accumulant ou divisant les composantes avec celles passées en paramètre.  

---

## Négation unaire

Le `-` unaire crée un nouveau vecteur dont les composantes sont multipliées par `-1`.  

---

## Application dans le moteur physique

La surcharge d’opérateurs facilite les calculs de forces : addition de forces, inversion de vecteurs, multiplication par un scalaire.  
Exemple : `wind + weight` retourne directement la force résultante.  
Cette approche rend le code plus lisible et plus intuitif pour manipuler les vecteurs dans notre moteur 2D.  
