# Transition de JavaScript vers C++

Maintenant que nous avons couvert toute la théorie sur les vecteurs, il est temps de passer de JavaScript à C++, car nous savons que nous allons utiliser C++ comme langage principal pour notre moteur physique.  

---

## Traduction de la classe Vector

Il est judicieux de traduire tout ce que nous avons fait en JavaScript.  
La classe `Vector`, prototype JavaScript de preuve de concept, doit maintenant être transposée en code C++.  

---

## Pas de compilation pour l’instant

Nous n’allons rien compiler pour le moment, ni apprendre à construire le projet.  
L’objectif est uniquement de traduire la logique JavaScript en code C++ fonctionnel.  

---

## Implémentation de la classe Vector2

Nous allons commencer par implémenter la classe `Vector2`, car notre moteur physique 2D utilisera principalement des vecteurs 2D.  
Cette classe permettra d’ajouter, de soustraire, de scaler, de faire tourner, et d’autres opérations vectorielles comme le produit vectoriel.  

---

## Similarités de syntaxe entre JavaScript et C++

Si vous avez compris les concepts en JavaScript, la syntaxe C++ est assez similaire.  
Il faut juste prêter attention à quelques détails propres au C++, et surtout comprendre la surcharge d’opérateurs (*operator overloading*).  

---

## Surcharge d’opérateurs

La surcharge d’opérateurs sera très utile.  
Elle permettra d’additionner, de soustraire, de multiplier et de scaler des vecteurs en utilisant les symboles mathématiques classiques (`+, -, *, /`), au lieu d’appeler des méthodes comme `dot`, `add`, `sub` ou `scale`.  

---

## Préparation du code C++

Ouvrons maintenant le code C++ de la classe `Vector2`.  
Nous allons passer rapidement en revue les lignes et les aspects les plus importants.  
Le fichier `Vector2.cpp` contient toutes les implémentations des fonctions de `Vector2` et servira tout au long du cours.  

---

## Implémentation principale et prochaines étapes

Cette implémentation sera au cœur de notre moteur physique.  
Pour l’instant, nous n’allons pas compiler. L’objectif est de visualiser la traduction de JavaScript vers C++.  
