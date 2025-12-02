# Mise à jour de la position d’une particule

---

## Introduction

Nous affichons actuellement une particule à une certaine position dans notre canvas, et nous observons bien les messages de la console :  
« particle constructor called » et « particle destructor called ».  

Cela confirme qu’aucune fuite de mémoire (*memory leak*) n’a lieu : l’objet créé dans `application.h` et `application.cpp` est correctement détruit.  
Cependant, cette particule **ne bouge pas encore**. Nous n’avons pas encore implémenté la notion de **mouvement** (*motion*).  

---

L’idée est de partir des bases et de déterminer où et comment mettre à jour la position de la particule selon sa vitesse.  
De manière intuitive, la fonction `update()` semble être l’endroit idéal pour effectuer cette mise à jour.  

---

## Définition du vecteur de vitesse

Dans la fonction `update()`, nous allons définir un vecteur de **vitesse** (*velocity vector*).  
Ce vecteur représente le **changement de position** de la particule à chaque image (*frame*) :  

- La composante `x` indique combien de pixels la particule se déplace **horizontalement** (vers la droite) par frame.  
- La composante `y` indique combien de pixels elle se déplace **verticalement** (vers le bas) par frame.  

---

Ainsi, la vitesse exprime un déplacement en pixels par frame.  

Par exemple, si nous voulons que la particule se déplace de **2 pixels à droite** à chaque frame, nous définissons :  

```cpp
particle.velocity = Vector2(2.0f, 0.0f);
```


Cela signifie que la position en `x` augmentera de 2 pixels à chaque frame, tandis que `y` restera inchangé.

---

## Mise à jour de la position

Une fois la vitesse définie, il suffit de mettre à jour la position de la particule en ajoutant la vitesse à la position précédente :

```cpp
particle.position.x += particle.velocity.x;
particle.position.y += particle.velocity.y;
```

Ce processus correspond à **l’intégration de la vitesse** (_velocity integration_).  
Autrement dit, à chaque frame, la position est mise à jour en fonction de la vitesse actuelle.

Ainsi, si la vitesse vaut `(2, 0)`, la particule se déplacera de **2 pixels vers la droite** à chaque mise à jour, créant un mouvement uniforme.

---

## Addition vectorielle

Nous pouvons simplifier encore davantage cette logique grâce à la fonction d’**addition vectorielle** (_vector addition_).  
En effet, la mise à jour précédente correspond simplement à :

```cpp
particle.position.add(particle.velocity);
```

Cette expression ajoute directement le vecteur de vitesse au vecteur de position, sans séparer les composantes `x` et `y`.  
C’est une manière plus élégante et plus lisible de représenter le déplacement.

Nous obtenons ainsi un **mouvement rectiligne uniforme**, c’est-à-dire à vitesse constante, sans accélération.

---

## Contrôle du temps et des frames

Jusqu’ici, notre simulation met à jour la position **à chaque frame**, mais sans lien explicite avec le **temps réel** (_real-world time_).  
Cela signifie que la vitesse du mouvement peut différer d’une machine à l’autre.

En effet :

- Si un ordinateur exécute la boucle d’update à 30 images par seconde (fps), la particule se déplacera deux fois moins vite que sur un autre tournant à 60 fps.
- Rien ne garantit que le mouvement soit identique d’une machine à l’autre.

---

Pour résoudre ce problème, il est nécessaire d’introduire une **relation entre le temps et les frames**, en définissant un **delta time (Δt)**.  
Celui-ci représentera le temps écoulé entre deux frames, permettant de rendre le mouvement **indépendant du nombre de frames par seconde**.

C’est le sujet de la prochaine étape : mettre en place un **contrôle du temps d’exécution** (_frame timing control_) pour garantir une simulation cohérente, quel que soit le matériel.