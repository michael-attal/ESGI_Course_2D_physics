# Prochaine étape : collision cercle-polygone

---

## Contexte

Nous avons désormais une résolution correcte des collisions pour :

- Boîtes ↔ Boîtes (OBB, oriented bounding boxes)
- Cercle ↔ Cercle

Cependant, il reste encore des interactions **non traitées** :

- Cercle ↔ Boîte
- Cercle ↔ Polygone complexe (plus de 4 sommets)
- Polygone ↔ Polygone complexe

Jusqu’ici, seules les collisions **box-box** ont été testées avec succès via le **Separating Axis Theorem (SAT)**.

---

## Nettoyage du code : suppression du hack

Précédemment, nous avions un bloc de code destiné à empêcher les objets de sortir de l’écran :

- Vérification des limites pour les cercles
- Ajustement de la position
- Inversion de la vitesse avec un facteur `-0.9` pour simuler un rebond

Ce bloc était **un hack**, nécessaire uniquement parce que nous n’avions pas encore introduit de **murs ou de plancher statiques** pour contenir les objets.

### Solution propre

- Ajouter des objets statiques (floor, murs, plafond) pour contenir tous les corps dynamiques
- Ces obstacles peuvent être **hors écran**, mais ils empêchent les objets de quitter la zone de simulation
- Cette approche est similaire à celle utilisée dans de nombreux jeux pour limiter l’espace de mouvement du joueur ou des corps physiques

---

## Étapes suivantes

1. **Détection des collisions** :  
   - Actuellement, la fonction `isColliding()` traite :
     - Cercle ↔ Cercle (`isCollidingCircleCircle`)
     - Polygone ↔ Polygone (`isCollidingPolygonPolygon` via SAT)
   - Les collisions entre **cercles et polygones** ne sont pas encore implémentées.

2. **Résolution des collisions** :  
   - Une fois détectée, il faudra calculer :
     - L’impulsion normale
     - L’impulsion tangentielle (friction/rotation)
   - Appliquer ces impulsions aux corps A et B en fonction du point de contact et des vecteurs $\mathbf{R}_A$, $\mathbf{R}_B$

---

## Prochaine étape pédagogique

- Étudier et implémenter **l’algorithme de collision cercle-polygone**
- Vérifier les collisions pour des polygones avec **plus de 4 sommets**
- Généraliser le moteur physique pour gérer toutes les interactions dynamiques

