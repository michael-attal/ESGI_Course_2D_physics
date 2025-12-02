---
# Implémentation du SAT appliquée à la collision de polygones

L’approche présentée met l’accent sur **l’apprentissage de l’algorithme SAT ligne par ligne** plutôt que de copier du code pré-écrit.  
Cela permet de comprendre le fonctionnement interne de l’algorithme.  
L’exemple porte sur deux boîtes, Boîte A et Boîte B, chacune de 200×200 pixels, avec une vitesse angulaire de 0.4 pour A et 0.1 pour B.  
La Boîte A est contrôlée par la souris, illustrant une **interaction dynamique**.  
Les forces comme la gravité ou le vent sont désactivées pour simplifier le scénario.

---
# Configuration de la collision de polygones

Pour tester la collision de polygones via SAT, la fonction `isCollidingPolygonPolygon` est introduite.  
- Cette fonction reçoit les références de deux polygones (ou boîtes) et éventuellement une structure de contact pour les informations de collision.  
- Les polygones incluent les **formes polygonales générales** et les boîtes, traitées comme des **polygones convexes à quatre côtés**.  
- La logique de détection se concentre uniquement sur l’**identification du chevauchement** sans résolution immédiate de la collision.

---
# Logique de détection

1. **Identifier les formes des polygones** : caster les corps en type `PolygonShape` pour A et B. Les boîtes sont également considérées comme des polygones.  
2. **Vérification bidirectionnelle de séparation** : utiliser la fonction `findMinimumSeparation` pour tester tous les axes dérivés des arêtes de A sur les sommets de B, et inversement.  
3. **Détermination de la collision** : si les deux tests de séparation retournent des valeurs ≤ 0, les polygones se chevauchent → collision. Une séparation positive indique **pas de collision**.

---
# Structure des fonctions

- **`findMinimumSeparation`** : calcule la **séparation maximale** le long de tous les axes (normales des arêtes) du premier polygone par rapport au second.  
  - Parcourt tous les sommets de A pour calculer les normales des arêtes.  
  - Projette tous les sommets de B sur chaque axe normal.  
  - Suit la projection minimale pour chaque axe.  
  - Retourne la plus grande valeur de séparation parmi tous les axes testés.  
- **`isCollidingPolygonPolygon`** : utilise `findMinimumSeparation` bidirectionnellement (A→B, B→A) pour déterminer la collision.  
  - Retourne `true` si les deux séparations indiquent un chevauchement.

---
# Test dynamique

- La Boîte A suit la souris, illustrant la **détection de collision SAT en temps réel**.  
- Les collisions sont indiquées visuellement par un **changement de couleur dynamique** du polygone.  
- Les forces sont désactivées, permettant de se concentrer sur la rotation et la mécanique de détection.

---
# Résumé

Cette implémentation pratique montre comment le SAT peut détecter des collisions entre **polygones convexes**, y compris les boîtes.  
En testant toutes les normales des deux polygones, en calculant les projections et en évaluant les valeurs de séparation, l’algorithme **identifie les collisions de manière fiable** sans les résoudre.  
Cette approche renforce la compréhension du SAT en construisant la fonction **pas à pas**, assurant que chaque étape est explicitement comprise.

