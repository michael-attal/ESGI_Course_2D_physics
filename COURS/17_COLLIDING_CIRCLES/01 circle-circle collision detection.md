# Introduction

- Après avoir abordé l’application des forces et le comportement des rigid bodies, il est naturel de tester les collisions entre ces corps rigides.  
- Avec des cercles et des boîtes en rotation, du torque et d’autres effets, il devient crucial de vérifier si des collisions se produisent.

---

# Discrete Simulation

- Dans une simulation discrète, les objets se déplacent étape par étape, frame par frame.  
- La position des rigid bodies est mise à jour en fonction des forces, de l’accélération et de la vitesse, mais le mouvement reste discret.  
- Les objets se rapprochent progressivement les uns des autres.

---

# Collision Scenario

- À un moment donné, deux corps rigides peuvent entrer en collision, c’est-à-dire que leurs formes se superposent.  
- Il est nécessaire de comprendre et gérer cette situation.

---

# Two Parts of Collision Handling

- La gestion des collisions se divise en deux parties :  
  1. Détection de collision : déterminer si deux objets se chevauchent (true/false).  
  2. Résolution de collision : séparer les objets ou appliquer des impulsions pour un effet réaliste.

---

# Focus on Collision Detection

- La détection de collision dépend de la géométrie des rigid bodies et peut varier en complexité et en performance.  
- Des techniques spécifiques peuvent améliorer l’efficacité des vérifications de collision.

---

# Starting Simple: Circle vs Circle

- Le cas le plus simple est la collision cercle-cercle.  
- Si la distance entre les centres des deux cercles est inférieure à la somme de leurs rayons, il y a collision.  
- Cette approche permet une vérification booléenne simple et efficace.

---

# High-Level Algorithm

- Algorithme : si `distance(A, B) < rayonA + rayonB`, alors collision détectée.

---

# Implementation Plan

- Création d’une nouvelle struct ou classe pour la détection de collisions.  
- Méthode principale `isColliding` recevant deux pointers vers des rigid bodies, A et B.  
- Vérification préalable du type de forme : cercle, boîte, polygone, etc.

---

# Circle-to-Circle Collision

- Si A et B sont des cercles, appeler une méthode dédiée `isCollidingCircleCircle(A, B)` pour vérifier la collision cercle-cercle.  
- Cette méthode ne gère que les collisions entre cercles.

---

# Inside the Implementation

- Calcul du vecteur distance `AB = B.position - A.position`.  
- Ce vecteur est utilisé pour comparer la distance avec la somme des rayons.

---

# Radius Sum and Magnitude Check

- Calculer `radiusSum = A.radius + B.radius`.  
- Vérifier si `AB.magnitudeSquared <= radiusSum^2` pour éviter la racine carrée coûteuse.  
- Retourner true si collision détectée, false sinon.

---

# Boolean Collision Test

- Le résultat booléen détermine si les cercles sont en collision.  
- La fonction renvoie ce résultat à la méthode principale de détection.

---

# Future Work

- Étendre la détection aux autres combinaisons : boîte-boîte, boîte-cercle, polygone-cercle, etc.  
- Chaque type de collision aura sa méthode spécifique.

---

# Implementation in Code

- La classe de détection de collision servira de point d’entrée.  
- La méthode principale agit comme un multiplexeur, redirigeant vers la fonction appropriée selon les types de shapes.

---

# Conclusion

- Cette structure permet de vérifier les collisions de manière organisée.  
- La prochaine étape sera la résolution des collisions, c’est-à-dire déplacer les objets pour qu’ils ne se chevauchent plus.
