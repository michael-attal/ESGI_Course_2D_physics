# Contraintes dans les moteurs physiques : théorie et types

---

## Introduction aux contraintes

- Les contraintes permettent de **limiter le mouvement des corps rigides** dans une simulation physique.
- Exemples pratiques :
  - Points d’ancrage (*anchor points*) reliant plusieurs objets.
  - Chaînes d’objets (*joints*) où chaque objet peut pivoter autour d’un point fixe.
  - Contraintes de non-pénétration pour éviter que deux corps se chevauchent.

- Objectif : améliorer la **stabilité de la simulation**, notamment lors de la résolution des collisions.

---

## Définition formelle

- Une **fonction de contrainte** \(C\) est définie pour chaque paire de corps rigides.
- Entrée : **vecteur d’état** comprenant position, orientation, masse, vitesse et vitesse angulaire des corps.
- Sortie : un **scalaire** indiquant la violation de la contrainte ou la quantité à corriger.
- À chaque étape de simulation :
  - Vérifier si \(C\) est dans la plage acceptable.
  - Appliquer forces, impulsions ou modifications de position pour respecter la contrainte.

---

## Types de contraintes

### 1. Contraintes d’égalité (Equality Constraints)
- Exemple : points de deux corps rigides doivent **coïncider** (joints, chaînes, ragdolls, cordes).
- Résolution :
  - Système d’équations linéaires :
  $$
  A \cdot x = B
  $$
  - Matrice \(A\) représente les coefficients de la contrainte.
  - Vecteur \(x\) contient les inconnues à résoudre (vitesse, impulsion, position, etc.).
- But : **s’assurer que les corps restent connectés** comme défini par la contrainte.

### 2. Contraintes d’inégalité (Inequality Constraints)
- Exemple : **non-pénétration** entre deux corps.
- Condition : 
  $$
  C \ge 0
  $$
  (distance minimale à respecter).
- Résolution :
  - Peut être convertie en système linéaire ou résolue via des méthodes spécifiques d’inégalité.
- Utilisée principalement pour la **stabilité des collisions**.

---

## Application et utilité

- Les moteurs physiques modernes (Box2D, Bullet, Chipmunk) utilisent systématiquement ces contraintes pour :
  - Maintenir la cohérence des chaînes, joints et ragdolls.
  - Garantir la non-pénétration entre objets.
  - Améliorer la stabilité globale du moteur, au-delà des méthodes simples de projection de position.

- Les contraintes permettent de **réduire les degrés de liberté** des objets, contrôlant ainsi leur mouvement selon les règles définies.

---

## Concepts clés pour l’implémentation

- **Vecteur d’état** : position, orientation, masse, vitesse linéaire et angulaire.
- **Fonction de contrainte $C$ : évalue la violation ou la satisfaction d’une contrainte.
- **Résolution** :
  - Forces ou impulsions appliquées pour remettre $C$ dans la plage acceptable.
  - Utilisation de **systèmes linéaires** pour résoudre simultanément plusieurs contraintes.

- Exemple pratique :
  - Distance entre deux corps ≤ 3 unités → contrainte de distance.
  - Deux points doivent toujours coïncider → contrainte de position/joint.

