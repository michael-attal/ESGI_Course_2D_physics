# Implémentation de l’objet World en C++

---

## Inclusion des fichiers nécessaires

- `World.cpp` inclut :
  - `world.h` : définition de la classe World.
  - `constants.h` : pour les constantes comme `pixels_per_meter`.
  - `collision_detection.h` : fonctions de détection et résolution des collisions.
  - `<iostream>` : affichage de messages pour le constructeur et le destructeur.

---

## Constructeur et gestion de la gravité

- Constructeur `World(float gravity = 9.8f)` :
  - La gravité est un scalaire indiquant l’accélération vers le bas.
  - Dans l’espace écran, l’axe Y croît vers le bas, donc la gravité est inversée pour correspondre à l’espace utilisateur : `G = -gravity`.
  - Affichage `World constructor called` pour le suivi.
  
- Destructeur `~World()` :
  - Supprime tous les corps rigides dans le vecteur `bodies`.
  - Affichage `World destructor called` pour le suivi.
  - Prévention des fuites mémoire dues aux allocations manuelles sur le heap.

---

## Gestion des corps et forces

- `addBody(Body* body)` : ajoute un corps à la liste `bodies`.
- `getBodies()` : retourne une référence vers le vecteur `bodies`.
- `addForce(Vec2 force)` : ajoute une force linéaire appliquée à tous les corps.
- `addTorque(float torque)` : ajoute un torque appliqué à tous les corps.

---

## Mise à jour du monde (`update`)

- Boucle sur tous les corps du monde pour appliquer :
  - **Force gravitationnelle** : \( \vec{F}_{weight} = m \cdot G \cdot \text{pixels\_per\_meter} \)
  - Toutes les **forces linéaires** ajoutées.
  - Tous les **torques** ajoutés.
- Mise à jour de l’intégration physique pour chaque corps :
  - Vitesse, accélération, position, rotation.
  - Mise à jour des sommets des polygones si nécessaire.
- Appel à `checkCollisions()` pour détecter et résoudre toutes les collisions :
  - Correction positionnelle par la méthode de projection.
  - Application d’impulsions pour résoudre les collisions.

---

## Intégration dans l’application

- Création d’un objet `World` dans `Application.cpp` :

```cpp
  world = new World(-9.8f);
```

 - Ajout des corps rigides au World :

```cpp
world->addBody(floor);
world->addBody(leftWall);
world->addBody(rightWall);
world->addBody(bigBox);

```

- Ajout des forces globales, par exemple un vent :
```cpp
world->addForce(wind);
```

- Dans la boucle principale, mise à jour du World :

```cpp
world->update(deltaTime);
```

- Le World prend en charge l’intégration, la détection et la résolution des collisions pour tous les corps.
        

---

## Avantages et bonnes pratiques

- Centralisation de toute la logique physique dans l’objet `World`.
    
- Séparation nette entre :
    
    - Gestion physique.
    - Rendu graphique.
        
- Permet de visualiser et contrôler facilement toutes les interactions physiques.
- Gestion manuelle de la mémoire pour tous les corps créés sur le heap :
- Essentiel pour comprendre l’allocation et la libération en C++ avant d’utiliser des smart pointers.
        

---

## Limites et perspectives

- La stabilité de l’engine reste un point critique :
    
    - Jittering observé avec plusieurs objets.
    - Nécessité d’améliorer :
        - Détection et résolution des collisions.
        - Intégration physique.
            
- Approche utilisée : simplicité et compréhension pédagogique avant performance ou robustesse maximale.
- Prochaines étapes : discussion des techniques pour améliorer la stabilité d’un moteur physique 2D.
