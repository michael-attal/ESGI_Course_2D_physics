## Introduction

Nous venons d’apprendre comment ajouter une force à un objet.  
Maintenant, il est important de comprendre **le rôle de la masse** dans le mouvement : elle influence la difficulté à accélérer un objet.  
Pour cela, nous allons passer d’un objet particule unique à un **vecteur de particules** dans notre application.

---

## À propos des vecteurs en C++

En C++, le mot **vector** désigne une liste d’objets (array dynamique).  
Nous avons donc une collision de noms : notre `Vector2` représente un vecteur mathématique 2D, tandis que `std::vector` est une structure de liste de particules.

---

## Création et gestion des particules

Dans `application.h`, nous créons un **vecteur de particules** : chaque particule est instanciée et ajoutée à ce vecteur via `push_back`.  
Exemple pour une petite particule : masse = 1.0, rayon = 4 pixels.

---

## Ajout d’une autre particule

Nous ajoutons maintenant une **particule plus grosse** : masse = 3.0, rayon = 12 pixels, position différente.  
Ainsi, nous commençons à gérer plusieurs masses et tailles dans notre simulation.

---

## Gestion de la mémoire

En C++, chaque objet créé avec `new` doit être **supprimé** pour éviter les fuites mémoire.  
Nous parcourons notre vecteur de particules et faisons un `delete` pour chaque objet dans `application.destroy`.

---

## Mise à jour et rendu des particules

Nous appliquons les forces et intégrons chaque particule dans **des boucles for** pour itérer sur toutes les particules.  
Même chose pour vérifier les collisions avec les limites.

---

## Correction de la boucle de rendu

Nous plaçons le rendu (`draw`) **en dehors des boucles de mise à jour** pour éviter des erreurs graphiques et afficher correctement toutes les particules.

---

## Test de la simulation

Deux particules avec des masses différentes : la masse influence l’accélération sous l’effet d’une force appliquée (vent).

---

## Construire un moteur physique robuste

Avec un vecteur de particules, nous pouvons gérer des centaines ou milliers d’objets, chacun avec des masses différentes et des vitesses d’accélération distinctes.

---

## Constructeurs et destructeurs

Nous vérifions que les **constructeurs** et **destructeurs** fonctionnent correctement pour éviter les fuites mémoire.

---

## Ajout de la force de poids (gravité)

Nous appliquons maintenant une **force de gravité** à toutes les particules :

```cpp
Vector weight(0.0, 9.8 * pixelsPerMeter);
particle.addForce(weight);
```


Chaque frame, nous appliquons d’abord le vent, puis la gravité.

---

## Observation et conclusion

Nous voyons l’effet combiné du vent et du poids.  
Les particules de masses différentes accélèrent différemment sous le vent, mais **la gravité devrait les faire tomber au même rythme**.

---

## Expérience de Galilée

Galilée a montré que **tous les objets tombent à la même vitesse**, indépendamment de leur masse.  
Dans notre simulation actuelle, la masse influence encore la gravité, ce qui n’est pas correct.

---

## Remarque finale

Nous devons maintenant corriger l’implémentation de la **force de poids** pour que la masse n’influence pas la chute verticale.