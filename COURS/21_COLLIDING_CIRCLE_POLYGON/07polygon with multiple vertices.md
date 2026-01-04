# Validation des polygones et évolution du moteur physique

---

## Vérification des vertices

- Les vertices du polygone doivent être choisis dans un **ordre antihoraire** autour de l’origine.
- Exemple de vertices utilisés : `(20, 60)`, `(-40, 20)`, `(-20, -60)`, `(20, -60)`, `(40, 20)`, puis retour au premier `(20, 60)`.
- Tant que le polygone est **convexe** et que les vertices respectent l’ordre antihoraire, la détection et la résolution des collisions fonctionnent correctement.

---

## Résultat visuel et comportement

- La création dynamique des polygones avec la souris fonctionne.
- La **collision**, la **rotation** et la **friction** sont correctement appliquées.
- La valeur temporaire du **moment d’inertie** (`5000`) est cohérente visuellement pour ces polygones.
- Les polygones se comportent comme des corps rigides réalistes, similaires à des rochers tombant et rebondissant.

---

## Algorithme SAT (Separating Axis Theorem)

- Le SAT est utilisé pour vérifier les collisions entre polygones.
- La fonction `findMinimumSeparation` boucle sur **tous les vertices** des polygones A et B, pas seulement quatre.
- Cette approche permet de gérer **n’importe quel polygone convexe**, indépendamment du nombre de côtés.
- Avec le mode debug activé, on peut visualiser :
  - Les normales
  - Les points de contact
  - L’application de la friction

---

## Bonnes pratiques

1. Définir les vertices **autour du centre de masse** du polygone à `(0,0)`.
2. Définir les vertices dans un **ordre antihoraire** pour garantir des calculs corrects des normales et produits vectoriels.
3. La valeur du moment d’inertie reste temporaire et sera calculée correctement ultérieurement.

---

## Prochaine étape : textures

- Objectif : remplacer le rendu en **fil de fer** par des textures sur les corps rigides.
- Possibilité d’appliquer des textures différentes aux cercles, boîtes et polygones.
- Utilisation de la **bibliothèque graphique** incluse et de l’extension SDL_image pour charger et afficher facilement des textures.
- Étape visuelle importante pour rendre le moteur physique plus attractif à l’écran.
