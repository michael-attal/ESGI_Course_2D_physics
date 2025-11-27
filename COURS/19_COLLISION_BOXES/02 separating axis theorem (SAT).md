---
# Introduction

La détection de collision entre AABB est extrêmement simple et peu coûteuse. C’est pourquoi cette méthode est très utilisée pour le **broad-phase** et dans le contexte des niveaux de jeux vidéo pour détecter les collisions entre objets simples de l’UI ou du gameplay. La majorité d’entre vous avez déjà utilisé les AABB dans vos projets précédents.  

Aujourd’hui, nous allons aborder des formes plus complexes : les **Oriented Bounding Boxes (OABB)**.

---
# Oriented Bounding Boxes (OABB)

Les **OABB** sont des boîtes dont les arêtes **ne sont pas alignées avec les axes du système de coordonnées**. En d’autres termes, ces boîtes sont **tournées**. Dans un moteur physique, une OABB implique donc une rotation de la boîte par rapport aux axes X et Y.

---
# Vue d’ensemble de l’algorithme SAT

L’algorithme que nous allons étudier pour détecter la collision entre OABB fonctionne pour **tout polygone convexe** : triangles, boîtes, pentagones, hexagones.  

- Une OABB est un polygone à 4 sommets.  
- Le même algorithme SAT peut être appliqué à des polygones convexes de n’importe quel nombre de sommets.  

**Principe du SAT (Separating Axis Theorem)** :  
Si **au moins un axe** sépare les deux polygones, alors il n’y a pas de collision entre eux.  

---
# Intuition humaine vs algorithme

Visuellement, il est facile de repérer un axe séparateur. Mathématiquement, il faut formaliser cette détection via un algorithme :

- Pour AABB, nous avions seulement deux axes : X et Y.  
- Pour OABB et polygones convexes, il y a plusieurs axes possibles.  
- Chaque axe testable provient de la **normale d’une arête** du polygone.  
- Si au moins un axe sépare les deux polygones, il n’y a pas de collision.

---
# Popularité du SAT

Le SAT est l’un des algorithmes les plus utilisés pour la détection de collision entre corps rigides polygonaux, avec le **GJK** (*Gilbert-Johnson-Keerthi*). Pour ce cours, nous allons nous concentrer sur le SAT, car il est plus intuitif et directement lié à la logique des axes séparateurs.

---
# Polygones convexes

Le SAT **ne fonctionne que pour des polygones convexes**.  

- **Polygone convexe** : pour tous points A et B à l’intérieur du polygone, la ligne AB est entièrement contenue dans le polygone.  
- **Polygone concave** : il existe au moins une ligne AB reliant deux points internes qui sort du polygone.  
- Les polygones convexes ont tous leurs angles internes < 180°  
- Les polygones concaves ont au moins un angle > 180°  

> Pour les polygones concaves, il est possible de les découper en plusieurs polygones convexes, souvent des triangles.

---
# Simplification avec des triangles

Pour mieux comprendre le SAT, nous pouvons remplacer les OABB par des **triangles**.  
- La logique reste la même : un triangle est un polygone convexe à trois sommets.  
- Cela simplifie la démonstration et permet de visualiser plus facilement les axes séparateurs.

---
# Test avec les normales

L’algorithme SAT utilise les **normales des arêtes** de chaque polygone :

1. Chaque normale définit un **axe de test**.  
2. On projette tous les sommets des deux polygones sur cet axe.  
3. On récupère les valeurs minimales et maximales de chaque projection.  
4. Si les projections **se chevauchent**, cet axe **ne sépare pas** les polygones.  
5. Si au moins un axe **ne chevauche pas**, il s’agit de l’axe séparateur, et les polygones **ne sont pas en collision**.  

Ce processus est répété pour toutes les normales jusqu’à trouver un axe séparateur ou jusqu’à ce que tous les axes soient testés.

---
# Résumé

En résumé, le **Separating Axis Theorem (SAT)** stipule que **la présence d’un axe séparateur garantit l’absence de collision**.  

- Fonctionne pour tout polygone convexe : triangle, boîte, pentagone, hexagone, etc.  
- Pour un polygone à N côtés, on teste N axes (un par arête).  
- C’est l’algorithme fondamental pour la détection de collision entre polygones convexes.  

Dans la suite du cours, nous implémenterons cet algorithme en C++ pour détecter la séparation entre corps rigides polygonaux.

