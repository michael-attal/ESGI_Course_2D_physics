# Détection de collision : Broad Phase et Narrow Phase

Dans les simulations physiques en temps réel, la détection et la résolution des collisions sont effectuées plusieurs fois par seconde pour chaque corps rigide du système.  
Vérifier chaque objet par rapport à tous les autres peut devenir coûteux en calcul, d’où l’importance de l’optimisation des performances.

---

## Broad Phase (Phase large)

La **broad phase** est l’étape de filtrage initiale permettant d’identifier rapidement les paires d’objets susceptibles de se heurter :  

- Utilise des algorithmes simples et rapides, peu coûteux en calcul.  
- S’appuie souvent sur des **volumes englobants** (bounding volumes), comme des cercles ou des boîtes, pour approximer des formes complexes.  
- Produit une liste de paires d’objets potentiellement en collision, réduisant significativement le nombre de vérifications détaillées nécessaires.  

Exemple : un polygone complexe ou une forme étoilée peut être englobé dans un cercle. Seules les intersections entre ces cercles déclenchent des vérifications plus précises.

---

## Narrow Phase (Phase étroite)

La **narrow phase** effectue la détection précise des collisions pour les paires identifiées lors de la broad phase :  

- Vérifie la géométrie exacte, par exemple collision vertex-à-vertex ou edge-à-edge.  
- Plus coûteuse en calcul, mais nécessaire pour déterminer si les objets sont réellement en collision.  
- Ne s’applique qu’aux paires d’objets signalées par la broad phase.  

Cette phase garantit la précision tout en évitant des calculs inutiles pour des objets éloignés.

---

## Détection multi-niveaux

Certaines moteurs physiques implémentent plusieurs niveaux de vérifications :  

1. Filtrage broad phase (vérification simple des volumes englobants).  
2. Narrow phase intermédiaire (vérification simplifiée des polygones ou arêtes).  
3. Narrow phase finale (détail géométrique complet, vérification vertex/triangle).  

Cette hiérarchie permet d’éliminer rapidement les objets non-collidants et de concentrer le calcul sur les collisions probables.

---

## Application en 2D et 3D

- **Moteurs 2D** : broad phase avec cercles ou boîtes, narrow phase avec polygones exacts.  
- **Moteurs 3D** : broad phase avec sphères ou boîtes englobantes, narrow phase avec triangles ou maillages.  
- Principe : filtrer rapidement les objets éloignés et réserver les vérifications détaillées aux collisions probables.

---

## Implications pratiques

- La plupart des objets dans une scène ne sont pas en collision ; les optimisations de broad phase réduisent les calculs inutiles.  
- Pour les implémentations actuelles cercle-à-cercle, broad et narrow phases ne sont pas nécessaires.  
- Pour les implémentations futures impliquant des polygones, boîtes ou maillages complexes, séparer broad et narrow phases améliorera l’efficacité.
