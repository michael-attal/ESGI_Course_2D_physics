## Implémentation de la Force de Ressort

La dernière force étudiée est la force de ressort (*spring force*).  
L'objectif est de l'implémenter dans l'application.  

---

## Prototype dans force.h

Dans le fichier `force.h` :  
- Premier paramètre : référence vers une particule (*particle*)  
- Deuxième paramètre : `Vector2` de l’ancrage (*anchor*), position fixe où la particule est attachée  
- Troisième paramètre : longueur au repos (*rest length*)  
- Quatrième paramètre : constante de raideur du ressort (*spring constant* k)  

---

Toutes les fonctions du fichier d’aide sont statiques, ce qui permet de les appeler directement via `Force::generateSpringForce(...)`.  

De futures fonctions générant d’autres forces peuvent suivre le même modèle : flottabilité, force magnétique, force électrique, etc.  

Ce fichier centralise des fonctions utilitaires pour générer des forces connues et éprouvées.  

---

## Configuration de l’Application

Dans `application.h` :  
- Vecteur de particules  
- Force de poussée contrôlée par les touches fléchées  
- Curseur de souris et suivi des clics pour appliquer des impulsions aux particules  
- Booléen pour le bouton gauche de la souris (*isLeftMouseDown*)  

---

## Déclaration des Variables Globales

Variables supplémentaires :  
- `anchor` : position de l’ancrage, initialisée à `(0,0)`  
- `k` : constante globale du ressort, réglable (ex. $44$)  
- `restLength` : longueur au repos du ressort en pixels, par exemple $200$  

---

## Définition de l’Ancrage et du Bob

Dans `application.cpp` :  
- Ancrage fixé au milieu horizontal de l’écran et à 30 pixels du haut :  

```cpp
anchor.x = graphics.width / 2.0f;
anchor.y = 30.0f;
```

- Création du bob, particule tenue par le ressort :

```cpp
Particle bob(graphics.width / 2.0f, graphics.height / 2.0f, mass=2.0f, radius=10);
particles.push_back(bob);
```

Le bob représente la particule soumise au ressort.  

---

## Application des Forces

Pour chaque particule :

- Traînée (_drag_) : simuler l’arrêt progressif du mouvement, ex. `0.01`
- Poids (_weight_) : gravité appliquée à chaque particule, $m \cdot g \cdot pixelsPerMeter$
- Force de ressort : appliquée uniquement à la particule connectée à l’ancrage

---

Exemple d’application de la force de ressort :

```cpp
Vector2 springForce = Force::generateSpringForce(bob, anchor, restLength, k);
bob.addForce(springForce);
```

---

## Rendu des Éléments

Pour visualiser le système :

- Dessiner l’ancrage : petit cercle rouge
- Dessiner le bob : cercle blanc
- Dessiner le ressort : ligne reliant l’ancrage et le bob, couleur gris foncé


```cpp
graphics.drawLine(anchor.x, anchor.y, bob.position.x, bob.position.y, color=darkGray);
graphics.drawCircle(anchor.x, anchor.y, 5, color=red);
graphics.drawCircle(bob.position.x, bob.position.y, bob.radius, color=white);
```

L’ancrage et le bob doivent être dessinés au-dessus de la ligne du ressort.  

---

## Simulation Finale

Ajuster les constantes pour obtenir l’effet désiré :

- Longueur au repos : $400$ pixels
- Constante du ressort : $100$
- Masse du bob : $2.0$

La simulation montre le bob se déplaçant sous l’effet du ressort, de la gravité et de la traînée.  
Le ressort se comporte comme attendu : compression et extension vers l’équilibre.  

---

## Travaux Futurs et Extensions

L’extension consiste à créer un système complexe :

- Plusieurs particules connectées par des ressorts
- Ressorts pouvant avoir différentes constantes
- Particules pouvant avoir différentes masses
- Application de forces externes pour générer des interactions complexes

Cette approche permet de simuler un réseau de particules et ressorts avec les lois de Hooke.