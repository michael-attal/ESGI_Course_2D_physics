# Classe Vecteur et Méthodes

---

Nous avons désormais un **blueprint** de classe `Vec2` :  
- Constructeur pour initialiser X et Y  
- Méthode `draw()` pour dessiner le vecteur  
- Méthode `magnitude()` pour calculer la longueur du vecteur  

---

Nous allons ajouter deux méthodes supplémentaires :  
- `add(v)` : ajoute le vecteur `v` au vecteur courant  
- `subtract(v)` : soustrait le vecteur `v` du vecteur courant  

Ces méthodes modifient **directement** les propriétés `x` et `y` de l’objet.

---

## Exemple Position et Vélocité

- Vecteur `position` : commence en (10, 20)  
- Vecteur `velocity` : (2, 1) → déplace 2 pixels à droite, 1 pixel vers le bas par frame  

Chaque frame, nous ajoutons `velocity` à `position` :  

```js
position.x += velocity.x
position.y += velocity.y
```

---

## Mise à Jour Frame et Modification In-Place

- Frame par frame, la position est mise à jour en ajoutant la vélocité
- Concept clé de la POO : **l’objet sait se modifier lui-même**
- Exemple :
  - Frame 1 : position (10, 20)
  - Frame 2 : position (12, 21)
  - Frame 3 : position (14, 22)
    

---

## Observations Pratiques

- On constate que `x` augmente plus vite que `y` si la vélocité est (2,1)
- Si la vélocité est `(0,1)`, l’objet se déplace uniquement vers le bas
- Cela permet de visualiser concrètement l’addition de vecteurs dans le contexte d’une simulation

---

### Boucle d’Intégration et Physique

- Concept fondamental de tout moteur physique : **mise à jour incrémentale de la position**
- À chaque frame : `position += velocity`
- Application :
    - Déplacement d’ennemis ou de projectiles
    - Intégration simple pour une physique naïve

