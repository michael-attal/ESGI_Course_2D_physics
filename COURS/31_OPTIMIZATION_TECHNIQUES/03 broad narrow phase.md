# Broad Phase et Narrow Phase  
## Notes de cours – ESGI (Physique pour moteurs de jeu)

### 1. Contexte : limitations actuelles et optimisations rapides
Dans la continuité des **limitations du moteur physique** et des *low-hanging fruits* (optimisations simples à mettre en œuvre), il est pertinent d’aborder la **séparation entre Broad Phase et Narrow Phase** en détection de collisions.

Il s’agit d’une **optimisation structurelle classique**, présente dans la quasi-totalité des moteurs physiques professionnels, visant à :
- réduire la complexité algorithmique,
- améliorer les performances,
- préparer le moteur à une montée en complexité (formes plus complexes, scènes plus denses).

---

### 2. Situation actuelle du moteur
Dans l’état actuel du moteur :
- La fonction `update()` (par exemple dans `world.cpp`) contient une **double boucle imbriquée**,
- Chaque corps rigide est testé **contre tous les autres**,
- Les tests de collision sont **directement détaillés** (formes réelles).

Cela correspond à une approche **brute force** :
- Complexité en `O(n²)`,
- Acceptable pour peu d’objets,
- Rapidement problématique dès que le nombre de corps augmente.

---

### 3. Principe de la séparation Broad Phase / Narrow Phase

#### 3.1 Broad Phase (phase large)
La **Broad Phase** a pour objectif :
- d’éliminer rapidement la majorité des paires qui **ne peuvent pas entrer en collision**,
- en utilisant des **tests très simples et peu coûteux**.

Approche typique :
- Associer à chaque objet une **forme englobante simple** (*bounding volume*),
  - cercle englobant (*bounding circle*),
  - boîte englobante (*AABB*).
- Tester uniquement ces volumes simplifiés.

Résultat :
- Une **liste de paires potentiellement en collision** (*potentially colliding pairs*).

👉 Cette phase ne cherche pas la précision, mais la **rapidité**.

---

#### 3.2 Narrow Phase (phase fine)
La **Narrow Phase** intervient ensuite :
- uniquement sur les paires issues de la Broad Phase,
- avec des **tests de collision précis**.

Exemples de tests détaillés :
- polygone ↔ polygone,
- cercle ↔ polygone,
- boîte ↔ boîte,
- sommets, arêtes, normales, etc.

Objectif :
- déterminer si la collision est **réelle**,
- calculer les **points de contact**, normales et profondeurs de pénétration.

👉 Cette phase est plus coûteuse, mais appliquée à **beaucoup moins de paires**.

---

### 4. Application concrète dans le moteur

#### 4.1 Réorganisation des boucles
L’idée proposée est de :
1. Remplacer la double boucle unique par **deux étapes distinctes**.
2. Première boucle (Broad Phase) :
   - tester tous les corps entre eux,
   - uniquement avec des **bounding circles**,
   - générer un vecteur de paires candidates.
3. Deuxième boucle (Narrow Phase) :
   - parcourir uniquement ce vecteur,
   - effectuer les tests géométriques précis.

Schématiquement :
- Avant :  
  `for bodies × for bodies → tests complets`
- Après :  
  `for bodies × for bodies → tests simples`  
  puis  
  `for candidate pairs → tests détaillés`

---

### 5. Gains attendus
La séparation Broad / Narrow Phase permet :
- une **réduction significative du nombre de tests coûteux**,
- une meilleure **scalabilité** du moteur,
- une architecture plus proche des moteurs professionnels.

Même avec une Broad Phase simple (cercles englobants), le gain est réel dès que la scène devient plus dense.

---

### 6. Limites et choix pédagogiques
Dans le cadre du moteur étudié :
- les formes restent simples,
- il n’y a pas encore de polygones complexes ni de maillages 3D,
- la charge actuelle ne justifie pas une implémentation immédiate.

Pour ces raisons :
- la séparation Broad / Narrow Phase **ne sera pas implémentée en cours**,
- afin de ne pas alourdir inutilement le code.

---

### 7. Perspective d’évolution
Cette séparation constitue néanmoins :
- une **évolution naturelle** du moteur,
- un excellent exercice d’architecture logicielle.

L’implémentation reste conceptuellement simple :
- création d’une structure de données pour stocker les paires candidates,
- deux boucles bien distinctes,
- réutilisation du code de collision existant pour la Narrow Phase.

---

### 8. Conclusion
- La détection Broad Phase / Narrow Phase est un **standard industriel**.
- Elle répond directement aux limites de performance de la détection brute force.
- Même si elle n’est pas implémentée ici, elle :
  - prépare le moteur à grandir,
  - clarifie l’architecture,
  - rapproche l’implémentation des moteurs physiques professionnels.

Cette notion constitue donc une **brique essentielle de compréhension**, et une étape logique pour toute évolution future du moteur physique.
