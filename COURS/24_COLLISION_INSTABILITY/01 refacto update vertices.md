# Gestion de la mise à jour des vertices pour la stabilité

---

## Problème initial

- Lors de la résolution des collisions, la correction de position déplace les corps rigides :
  - `resolvePenetration` calcule le déplacement de A et B selon la normale de collision.
  - Les corps sont déplacés mais **les vertices des shapes ne sont pas mis à jour**.
- Fonctionne correctement pour les cercles (pas de vertices), mais pose problème pour :
  - Box, polygones, triangles — toutes ces formes ont des vertices locales à transformer en coordonnées globales.

---

## Solution proposée

### Ajout d’une méthode virtuelle `updateVertices` dans la classe `Shape`

- Objectif : uniformiser la mise à jour des vertices pour toutes les formes.
- Signature de la méthode :
  ```cpp
  virtual void updateVertices(float angle, const Vec2& position) = 0;
```
Chaque forme héritant de `Shape` doit implémenter cette méthode :

- **PolygonShape** : recalcul des vertices à partir des vertices locales transformées par la rotation et la position.
    
- **CircleShape** : implémentation vide, car les cercles n’ont pas de vertices.
    
- **BoxShape** : hérite de PolygonShape, donc pas de réimplémentation nécessaire.

---

### Intégration dans `Body.cpp`

- Au lieu de vérifier à chaque fois le type de la shape, on appelle :
```cpp
shape->updateVertices(rotation, position);
```

Les vertices sont ainsi automatiquement mises à jour après :

- Translation.
- Rotation.
- Correction de position due aux collisions.


### Avantages

- Évite la multiplication des tests `if (isPolygon) ... else if (isBox) ...`.
- Centralise la logique de transformation des vertices dans la classe `Shape`.
- Assure que la projection et la correction positionnelle sont cohérentes pour tous les types de formes.
- Maintient la compatibilité avec les cercles sans surcharge inutile.
    

---

### Conséquences sur la stabilité

- Mise à jour des vertices à chaque changement de position ou rotation.
- Permet d’éviter des artefacts visuels lors des résolutions de collision.
- Prépare le terrain pour des améliorations futures de la stabilité du moteur physique 2D.