# Stabilité des collisions et serveurs locaux vs globaux

---

## Observation du problème

- Lorsqu’on empile plusieurs objets, des comportements instables apparaissent :
  - Déplacements imprévus.
  - Jittering et oscillations.
- Cause principale : **la résolution des collisions est effectuée localement** pour chaque paire d’objets.

---

## Solver local (local solver)

- Résout les collisions **une paire d’objets à la fois**.
- Exemple : deux corps A et B en collision :
  - `resolvePenetration` applique une correction positionnelle.
  - Impulsion appliquée pour séparer les corps.
- Limitation : lorsqu’il y a plusieurs corps en contact, chaque résolution locale peut interférer avec les autres collisions, créant des effets de rebond et de jittering.
- C’est ce qui explique les instabilités observées dans notre moteur.

---

## Solver global (global solver)

- Concept : résoudre **toutes les collisions simultanément** en prenant en compte :
  - Les masses et moments d’inertie de tous les corps.
  - Les positions globales.
  - L’ensemble des contraintes de collision.
- Théoriquement optimal, mais coûteux en temps de calcul :
  - Nécessite de construire et résoudre un **système global d’équations ou d’inégalités**.
  - Non adapté aux simulations temps réel comme les jeux vidéo.

---

## Solutions pratiques pour le moteur temps réel

- On continue d’utiliser un serveur local pour sa performance.
- Techniques pour améliorer la stabilité :
  - **Sequential Impulses** : méthode popularisée par Box2D (Airing Cattles).
    - Résout les collisions par itérations successives.
    - Approche itérative pour se rapprocher d’une solution stable.
  - **Contraintes physiques (constraints)** :
    - Position, contact et distances minimales entre objets.
    - Considérer les collisions comme des contraintes à résoudre avec des inégalités.
  - Augmenter le **nombre d’itérations par frame** pour améliorer la précision de la solution locale.
  - Optimiser certains calculs pour réduire le jittering.

---

## Conclusion

- Impossible de résoudre toutes les collisions de façon globale en temps réel.
- Le serveur local, associé à des techniques itératives et à la gestion de contraintes, reste la solution la plus pragmatique pour les moteurs physiques 2D temps réel.
- L’objectif : **estimer une solution stable et robuste**, sans atteindre la perfection absolue mais en améliorant significativement la stabilité des objets empilés ou en interaction multiple.
