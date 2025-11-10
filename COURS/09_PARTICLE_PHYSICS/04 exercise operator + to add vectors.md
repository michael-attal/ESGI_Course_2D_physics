# Exercice : Utiliser l’opérateur + pour additionner des vecteurs

---
Voici un petit exercice pratique :  
remplacez l’appel à la méthode `add()` par l’opérateur **+** afin d’ajouter le vecteur vitesse à la position de la particule.  

Autrement dit, si vous aviez précédemment :  

```cpp
particle.position.add(particle.velocity);
```

Vous devez maintenant pouvoir écrire :

```cpp
particle.position = particle.position + particle.velocity;
```

---

Cet exercice permet de **tester la surcharge d’opérateur** (_operator overloading_) dans la classe `Vec2` et de vérifier que l’addition de vecteurs fonctionne comme prévu.

L’objectif est de rendre le code plus lisible et naturel, en utilisant les opérateurs arithmétiques directement sur vos objets vecteurs.