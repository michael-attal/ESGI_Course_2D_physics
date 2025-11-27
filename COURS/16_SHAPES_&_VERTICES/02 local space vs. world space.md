# Transforming Vertices from Local to World Space

- Objectif : transformer les vertices d’un polygone de l’espace local (local space) vers l’espace mondial (world space) en appliquant rotation et translation.

---

## Creating the Update Vertices Method

- Créer une méthode `updateVertices()` pour tous les polygones.  
- Mise à jour des vertices à chaque étape de la simulation physique pour appliquer rotation et translation.

---

## Determining When to Update

- Les vertices doivent être mises à jour à chaque itération de la simulation.  
- Meilleur endroit : fonction `update()` de la simulation.  

---

## Checking the Shape Type

- Vérifier si la forme est un polygone ou un box (puisque `BoxShape` hérite de `PolygonShape`).  
- Définir une variable `isPolygon` pour simplifier la condition.

---

## Casting and Updating Polygon Shapes

- Récupérer le polygone via cast :  
```cpp
PolygonShape* poly = static_cast<PolygonShape*>(body->shape);

```

- Permet de manipuler les vertices pour les polygones et les boxes.
    

---

## Defining the Update Vertices Function

- La fonction `updateVertices(float angle, Vector2 position)` reçoit :
    
    - `angle` : rotation du corps en radians
        
    - `position` : position du corps dans le monde
        

---

## Passing Rotation and Translation

- Rotation et translation appliquées sur les vertices locales.
    
- Translation = déplacement du centre du polygone dans le monde.
    

---

## Implementing in Polygon Shape

- La méthode `updateVertices()` est définie dans `PolygonShape`.
    
- Transforme les vertices locales en vertices mondiales (world vertices).
    

---

## Adding Prototype in shape.h

- Prototype à ajouter dans `shape.h` pour les polygones et boxes :

```cpp
void updateVertices(float angle, const Vector2& position);
```

## Commenting the Function

- Fonction : faire passer les vertices de l’espace local à l’espace mondial en appliquant rotation et translation.
    

---

## Implementation in shape.cpp

- Implémentation dans `shape.cpp` pour `PolygonShape`.
    
- Nouvelle méthode : `updateVertices()`.
    

---

## Handling Local and World Vertices

- Dupliquer les vertices :
    
    - `localVertices` : vertices originales en local space
        
    - `worldVertices` : vertices transformées en world space
        

---

## Local vs World Space Explanation

- `localVertices` : coordonnées relatives à l’origine.
    
- `worldVertices` : coordonnées finales après rotation et translation.
    

---

## Example of Box Shape

- Box avec origine au centre : `localVertices` centrées sur (0,0).
    
- Transformation → `worldVertices` pour affichage correct dans le monde.
    

---

## Initialization of Local Vertices

- Initialisation des vertices locales lors de la création de la box dans `shape.cpp`.
    

---

## Updating Vertices During Simulation

- À chaque étape de simulation, mettre à jour les vertices : rotation + translation.
    

---

## Rotating and Translating Vertices

- Parcourir toutes les vertices locales :
    
    1. Appliquer rotation autour de l’origine
        
    2. Appliquer translation vers la position du corps
        

---

## Order of Operations

- Important : rotation **avant** translation.
    
- Rotation autour de l’origine, puis translation dans le monde.
    

---

## Rotation Around Origin

- Rotation doit être effectuée autour de l’origine locale pour préserver la forme.
    

---

## Initializing World Vertices

- Initialiser `worldVertices` au moment de la création : même valeurs que `localVertices`.
    

---

## Copying Local to World Vertices

- Copie initiale pour avoir un vecteur prêt à transformer à chaque simulation step.
    

---

## Constructor Setup

- Constructeur : `localVertices` et `worldVertices` initialisées identiques.
    
- Pendant la simulation, `updateVertices()` modifie `worldVertices`.
    

---

## Applying Rotation and Translation

- Rotation et translation appliquées dans `updateVertices()` pour chaque vertex.
    

---

## Rotating Vectors

- Utiliser la fonction de rotation de la classe Vector2 :

```cpp
worldVertices[i] = localVertices[i].rotate(angle);
```

## Rotate Then Translate

- Après rotation : translation par ajout vectoriel :

```cpp
worldVertices[i] += position;
```

## Translating Vertices

- Translation = addition de vecteurs (`worldVertices[i] += position`).
    

---

## Translation as Vector Addition

- Chaque vertex : nouvelle position = rotation + translation.
    

---

## Updating World Vertices Each Step

- Boucle à chaque étape de simulation :
    1. Rotation
    2. Translation
- Résultat : vertices correctement positionnées dans world space.
    
---
## Drawing Updated Vertices
- Pour le rendu : utiliser `worldVertices` et non `localVertices`.

---

## Integration and Final Output

- Dans la boucle principale : intégrer linéairement et angular, puis `updateVertices()` pour polygons/boxes.
    
- Vertices prêtes pour le rendu final.
    

---

## Visual Confirmation

- Vérification : rectangle correctement positionné et centré sur le canvas.
    

---

## Applying Torque

- Ajout de torque : la rotation appliquée est visible sur les `worldVertices`.
    

---

## Final Result

- Résultat : box tournante correctement transformée de local space à world space.
    

---

## Next Steps

- Prochaine étape : déplacer cette logique dans une méthode `update()` de `Body` qui intègre linéaire, angular et update des vertices.
    

---

## Exercise Proposal

- Exercice : créer la méthode `body.update()` intégrant :
    
    - Linear integration
        
    - Angular integration
        
    - Mise à jour des vertices du polygone.

