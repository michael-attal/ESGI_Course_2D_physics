# Collision Cercle ↔ Polygone : Détermination de la région du centre du cercle

---

## Contexte

Après avoir identifié **l’arête la plus proche** du centre du cercle, il faut maintenant déterminer **la position relative du centre du cercle** par rapport à cette arête pour tester correctement la collision. Trois scénarios sont possibles :

1. **Région A** : Coin supérieur gauche de l’arête
2. **Région B** : Coin inférieur droit de l’arête
3. **Région C** : Zone centrale, le long de l’arête

Selon la région, le test de collision diffère.

---

## Algorithme de test

1. **Région A (coin supérieur gauche)**  
   - Calculer la distance entre le **centre du cercle** et le **sommet supérieur gauche** de l’arête.
   - Si cette distance est inférieure au rayon du cercle, il y a collision.

2. **Région B (coin inférieur droit)**  
   - Calculer la distance entre le **centre du cercle** et le **sommet inférieur droit** de l’arête.
   - Si cette distance est inférieure au rayon du cercle, il y a collision.

3. **Région C (zone centrale de l’arête)**  
   - Calculer la distance **perpendiculaire** entre le centre du cercle et l’arête.
   - Si cette distance est inférieure au rayon du cercle, il y a collision.

---

## Cas particuliers

- Si le **centre du cercle est à l’intérieur du polygone**, une autre logique sera nécessaire pour la résolution de la collision.
- Ces trois tests permettent de gérer toutes les positions possibles d’un cercle autour d’une arête.

---

## Étapes pour l’implémentation

1. Identifier la **région du centre du cercle** : A, B ou C
2. Calculer la distance appropriée selon la région
3. Déterminer si la distance est inférieure au rayon du cercle pour valider la collision
4. Prévoir un cas “else” si le centre est **à l’intérieur du polygone**

---

## Conseils

- Utiliser les **opérations vectorielles** : projection, différence de vecteurs, norme
- Dessiner les différentes régions sur papier peut aider à visualiser la logique
- Différentes implémentations sont possibles selon la stratégie choisie pour détecter la région

#tags: physics-engine/collision, physics-engine/polygon, physics-engine/circle, physics-engine/detection, physics-engine/2d, physics-engine/vector-operations
