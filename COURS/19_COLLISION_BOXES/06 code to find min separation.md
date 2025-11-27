---
# Implémentation du SAT : calcul de la séparation entre polygones

Cette section détaille **l’implémentation pas à pas du théorème de l’axe séparateur (SAT)** pour la détection de collision entre polygones.  
L’idée principale est de **calculer la séparation** le long de tous les axes définis par les arêtes de polygon A et polygon B, en projetant les sommets sur ces axes, et en déterminant le **chevauchement minimal** (ou la séparation maximale) pour détecter les collisions.

---
# Initialisation

1. **Variable de séparation** : un `float separation` est initialisé à la plus petite valeur possible avec `std::numeric_limits<float>::lowest()`.  
   Cette variable va suivre la plus grande séparation trouvée sur tous les axes testés.  
2. **Inclusion de l’en-tête** : pour utiliser `numeric_limits`, inclure `#include <limits>`.

---
# Parcours des sommets de polygon A

- Itérer sur tous les **sommets mondiaux** de polygon A (sommets transformés par rotation et translation).  
- Pour chaque sommet, calculer le **vecteur arête** reliant le sommet courant au suivant.  
- Utiliser le modulo pour gérer la dernière arête reliant le dernier sommet au premier.

```cpp
int current = index;
int next = (index + 1) % polygon.worldVertices.size();
Vector edge = polygon.worldVertices[next] - polygon.worldVertices[current];
```

# Vecteur normal de chaque arête

- Calculer la **normale (vecteur perpendiculaire)** de l’arête avec une fonction helper `normal()`.  
    Cette normale définit l’**axe de projection**.
    
- Chaque arête de polygon A fournit un axe à tester.
    

---

# Parcours des sommets de polygon B

- Pour chaque axe (normale des arêtes de A), parcourir tous les sommets de polygon B.
    
- Projeter les vecteurs des sommets de B par rapport à un sommet de A sur l’axe normal à l’aide du **produit scalaire** :

```cpp
Vector v = VB - VA;
float projection = dot(v, normal);
```

- Suivre la **séparation minimale** pour cet axe en comparant toutes les projections :

```cpp
float minSeparation = std::numeric_limits<float>::max();
minSeparation = std::min(minSeparation, projection);
```

# Mise à jour de la meilleure séparation

- Après avoir testé tous les sommets de B sur l’axe courant, mettre à jour la **meilleure séparation** :

```cpp
separation = std::max(separation, minSeparation);
```

- Répéter pour tous les axes de polygon A.
    
- Effectuer la même procédure pour les axes de polygon B contre les sommets de A afin de compléter le test SAT.
    

---

# Décision de collision

- Si **une séparation est supérieure à zéro**, les polygones **ne se touchent pas**, retourner `false`.
    
- Si toutes les séparations sont ≤ 0, les polygones se chevauchent → collision, retourner `true`.
    

---

# Résumé des fonctions

- **`findMinimumSeparation`** : calcule la **séparation maximale** le long de tous les axes d’un polygone par rapport aux sommets de l’autre.
    
- **`isCollidingPolygonPolygon`** : appelle `findMinimumSeparation` pour A→B et B→A. Retourne `true` si les deux tests indiquent un chevauchement.
    

---

# Test dynamique

- Les boîtes A et B tournent à des vitesses angulaires différentes ; la boîte A suit la souris.
    
- La collision est visualisée par un **changement de couleur**.
    
- L’algorithme se généralise à tout polygone convexe, pas seulement les boîtes.
    

---

# Notes pour le développement futur

- L’implémentation actuelle **ne fait que détecter les collisions**.
    
- Pour résoudre les collisions, il est nécessaire de calculer les **informations de contact** : normale de collision, profondeur de pénétration, points de contact de début/fin.
    
- Ces informations sont essentielles pour **implémenter la réponse physique**, y compris la résolution par impulsion et les effets de rotation.




