---
# Calcul de l’Information de Contact à partir du SAT

Dans cette section, nous étendons l’implémentation SAT pour non seulement détecter les collisions, mais aussi **calculer l’information de contact**, essentielle pour résoudre les collisions dans une simulation physique.

---
# Profondeur de Pénétration (Penetration Depth)

- La **profondeur de pénétration** correspond au **recouvrement** entre deux polygones.  
- Elle est dérivée directement de la **séparation minimale** retournée par l’algorithme SAT :  

$$
\text{penetrationDepth} = - \text{separation}
$$

- Une séparation négative indique une collision, et multiplier par -1 convertit cela en profondeur de pénétration positive.  

---
# Normale de Collision (Collision Normal)

- La **normale de la collision** correspond à la normale de l’arête qui a généré la **projection de séparation maximale**.  
- C’est la même normale utilisée dans le test SAT pour cette arête :  
  - Pour le polygone A, la normale de l’arête testée est utilisée.  
  - Cette normale est renvoyée dans l’information de contact.

---
# Point de Contact de Départ (Contact Start Point)

- Le **point de contact de départ** provient du **sommet du polygone B** qui a produit la **projection minimale** le long de l’axe de séparation.  
- En parcourant tous les sommets de B, le sommet avec la **projection la plus petite** est stocké comme `meanVertex`.  
- Ce sommet sert de **point de départ du contact**.  
- Le **point de fin** peut ensuite être calculé en le décalant le long de la normale de collision :

$$
\text{endPoint} = \text{startPoint} + (\text{penetrationDepth} \cdot \text{normal})
$$

---
# Retour d’Informations Supplémentaires depuis `findMinimumSeparation`

- Précédemment, `findMinimumSeparation` ne retournait que la valeur de séparation.  
- Maintenant, elle est modifiée pour retourner des informations supplémentaires via des **paramètres de sortie (out parameters)** :  
  1. `axis` – l’arête qui a généré la meilleure séparation (normale de collision).  
  2. `point` – le sommet du polygone B qui a produit la projection minimale (point de contact de départ).  

```cpp
float PolygonShape::findMinimumSeparation(
    const PolygonShape* other,
    Vec2& outAxis,
    Vec2& outPoint
) const;
```

À l’intérieur de la fonction :

- Suivre la **séparation minimale** et le **sommet correspondant sur B** (`meanVertex`).
    
- Suivre la **meilleure axe** correspondant à l’arête du polygone A.
    
- Mettre à jour `outAxis` et `outPoint` à chaque fois qu’une nouvelle meilleure séparation est trouvée.

---

# Intégration dans la Détection de Collision

- Dans `collisionDetection.cpp`, on gère maintenant ces paramètres de sortie supplémentaires :

```cpp
Vec2 axisA, axisB;
Vec2 pointA, pointB;

float separationAB = polygonA->findMinimumSeparation(polygonB, axisA, pointA);
if (separationAB > 0) return false;

float separationBA = polygonB->findMinimumSeparation(polygonA, axisB, pointB);
if (separationBA > 0) return false;
```

- Cela permet de calculer :
    
    - `contact.startPoint` ← `pointA`
        
    - `contact.normal` ← `axisA.normal()`
        
    - `contact.penetrationDepth` ← `-separationAB`
        

---

# Résumé

- Le test SAT retourne désormais **à la fois la détection de collision et l’information de contact**.
    
- Éléments clés retournés :
    
    1. **Séparation** (pour la profondeur de pénétration)
        
    2. **Axe/Normale** (direction de collision)
        
    3. **Sommet de B** (point de contact de départ)
        
- Cette information est essentielle pour la **résolution de collision**, comme l’application d’impulsions ou la gestion de rotations.

