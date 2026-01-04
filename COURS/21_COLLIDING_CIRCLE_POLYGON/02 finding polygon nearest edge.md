# Détection de collision Cercle ↔ Polygone : Arête la plus proche

---

## Rappel du contexte

L’objectif est de détecter la collision entre :

- Un polygone avec plusieurs sommets
- Un cercle avec centre et rayon

Nous avons besoin de :

- Identifier l’arête du polygone la plus proche du centre du cercle
- Déterminer la normale de contact pour la future résolution

---

## Étapes de la solution

1. **Récupérer la forme du polygone**  
   - On cast le rigid body en `PolygonShape`.
   - On récupère les **vertices mondiaux** (`worldVertices`) du polygone.

2. **Boucler sur toutes les arêtes**  
   - Pour chaque sommet `i` :
     - Déterminer le sommet suivant `i+1` en utilisant le modulo pour boucler (`(i+1) % vertexCount`).
     - Former l’arête entre `vertex[i]` et `vertex[i+1]`.

3. **Calculer la normale de l’arête**  
   - La normale est perpendiculaire à l’arête.
   - Elle servira pour projeter le vecteur allant du sommet vers le centre du cercle.

4. **Projeter le vecteur cercle → sommet sur la normale**  
   - Vecteur : `circleCenter - vertex[i]`
   - Projection : `dot(vecteur, normale)`  
   - On cherche **la projection positive la plus petite**, ce qui correspond à l’arête la plus proche pour un cercle situé à l’extérieur du polygone.

5. **Stocker l’arête minimale**  
   - Conserver les indices `minCurrentVertex` et `minNextVertex`.
   - Dès qu’on trouve une projection positive valide, cette arête devient candidate pour la plus proche.

6. **Visualisation (optionnelle)**  
   - Dessiner de petits cercles sur les sommets de l’arête sélectionnée pour vérifier visuellement l’arête la plus proche.

---

## Résultat attendu

- Lorsque le cercle se déplace autour du polygone, l’arête la plus proche est détectée dynamiquement.
- Cette information servira pour la prochaine étape : **calcul de la profondeur de pénétration et de la normale de collision**.

---

## Notes importantes

- Cette méthode fonctionne pour des polygones à **n sommets** (pas seulement des rectangles).
- On ne considère ici que les cercles **à l’extérieur** du polygone.
- La fonction retourne `false` pour l’instant, car la détection complète et la résolution de collision ne sont pas encore implémentées.

