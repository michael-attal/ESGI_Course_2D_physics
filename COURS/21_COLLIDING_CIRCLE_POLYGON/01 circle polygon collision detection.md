# Collision Cercle ↔ Polygone : Détection de l’arête la plus proche

---

## Contexte

Nous avons déjà :

- Cercle ↔ Cercle
- Polygone ↔ Polygone (OBB ou polygones complexes)

Il reste à gérer :

- Cercle ↔ Polygone
- Polygone ↔ Cercle

Objectif : détecter la collision et obtenir les informations nécessaires pour la résolution, notamment la **profondeur de pénétration** et la **normale de contact**.

---

## Première étape : trouver l’arête la plus proche

Pour un polygone avec ses sommets et arêtes, et un cercle avec son centre et son rayon, il faut déterminer **l’arête du polygone la plus proche du centre du cercle**. Cette information servira pour calculer :

- La normale de collision
- La pénétration

### Méthodologie proposée

1. Boucler sur toutes les arêtes du polygone.
2. Pour chaque arête, calculer la distance entre le centre du cercle et l’arête.
3. Identifier l’arête avec la **distance minimale**.
4. Retourner cette arête comme la plus proche du centre du cercle.

Cette arête sera utilisée pour déterminer la direction de la normale de collision et le point de contact.

---

## Préparation du test dans le code

1. Supprimer les murs statiques et le plancher pour se concentrer sur la collision **cercle ↔ polygone**.
2. Ajouter un objet statique (ex. grand rectangle) au centre de l’écran.
3. Ajouter un cercle dynamique que l’on peut déplacer avec la souris.
   - Position du cercle = coordonnées du curseur
   - Masse et restitution définies pour l’exercice
4. Désactiver la gravité et toutes forces dans la mise à jour (`update()`) afin de manipuler uniquement la position du cercle.

---

## Fonction à implémenter

- `isCollidingPolygonCircle(Polygon* polygon, Circle* circle, Contact& contact)`  
  - Retourne `true` si collision détectée, sinon `false`.
  - Remplit `contact` avec les informations de collision.
  - Utilise la méthode de l’arête la plus proche pour déterminer le contact.

### Intégration à la détection globale

- Dans `isColliding(A, B, Contact& contact)` :
  1. Si `A` = polygone et `B` = cercle → appeler `isCollidingPolygonCircle(A, B, contact)`
  2. Si `A` = cercle et `B` = polygone → appeler `isCollidingPolygonCircle(B, A, contact)`

---

## Objectif pédagogique

Cet exercice permet de pratiquer :

- Les opérations vectorielles
- Les projections sur les arêtes
- La détermination des distances
- La formalisation d’un algorithme de détection de collision cercle ↔ polygone

Le but est de trouver la **prochaine arête de contact**, première étape avant la résolution complète de la collision.

#tags: physics-engine/collision, physics-engine/polygon, physics-engine/circle, physics-engine/2d, physics-engine/detection, physics-engine/exercise
