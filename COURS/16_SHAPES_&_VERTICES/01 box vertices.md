# Introduction

- Objectif : manipuler des formes avec vertices (polygones) et comprendre la gestion des vertices dans un moteur 2D.  
- Problématiques :  
  - Comment dessiner les vertices via la bibliothèque graphique (`graphics.h` / `graphics.cpp`)?  
  - Comment transformer ces vertices pour la position et la rotation dans le monde (world space)?  

#tags/graphics/polygons, #physics/2d, #implementation/vertices

---

# Creating a Box Shape

- Création d’un `Body` avec `BoxShape` au lieu de `CircleShape`.  
- Paramètres : `width`, `height`, `position`, `mass`.  
- Exemple : `BoxShape box(200, 100)` au centre de l’écran, masse = 1.0.  

#tags/physics/2d, #implementation/box, #cpp/construction

---

# Implementing Box Vertices

- La `BoxShape` est un polygone : héritage de `PolygonShape`.  
- Nécessité de remplir le vecteur `vertices` avec les sommets du polygone.  
- Chaque vertex est calculé en fonction de `width` et `height` : coordonnées locales centrées sur l’origine.  

#tags/graphics/vertices, #physics/polygons, #cpp/implementation

---

# Initializing Width and Height

- Initialisation des attributs :  
```cpp
this->width = width;
this->height = height;
```

- Chargement manuel des vertices basé sur le centre de masse comme origine.
    

#tags/graphics/vertices, #physics/box, #cpp/initialization

---

# Loading Vertices of the Polygon

- Définition des vertices du rectangle :
    
    - Top Left : $(-\frac{w}{2}, -\frac{h}{2})$
        
    - Top Right : $(\frac{w}{2}, -\frac{h}{2})$
        
    - Bottom Right : $(\frac{w}{2}, \frac{h}{2})$
        
    - Bottom Left : (-\frac{w}{2}, \frac{h}{2}))
        
- Ordre : **top-left → clockwise**.

# Manual Vertex Definition

- Les vertices sont définis dans le **local space** (model space).
    
- Coordonnées relatives au centre de masse (origine du système local).
    

#tags/graphics/local-space, #physics/model-space, #implementation/concepts

---

# Implementing the Vertex Pushback

- Ajout manuel dans le vecteur `vertices` :

```cpp
vertices.push_back({x, y});
```

- Chaque vertex est calculé en fonction de `width` et `height`, en respectant l’ordre **clockwise**.
    

#tags/graphics/vertices, #cpp/vector, #implementation/box

---

# Shape Configuration and Inertia

- Méthodes importantes :
    
    - `getType()` → retourne le type `Box`.
        
    - `clone()` → copie du `BoxShape` avec mêmes dimensions.
        
    - `getMomentOfInertia()` → I=112(w2+h2)∗mI = \frac{1}{12} (w^2 + h^2) * mI=121​(w2+h2)∗m
        

#tags/physics/inertia, #cpp/methods, #graphics/box

---

# Rendering the Box

- Pour afficher le rectangle :
    
    - On passe la liste des vertices au moteur graphique.
        
    - Utiliser `drawPolygon(x, y, vertices, color)` plutôt que `drawRectangle()` pour supporter rotation future.
        

#tags/graphics/rendering, #cpp/drawing, #physics/visualization

---

# Casting and Drawing

- Récupération de la `BoxShape` via casting :


```cpp
BoxShape* box = static_cast<BoxShape*>(body->shape);
graphics::drawPolygon(body->position.x, body->position.y, box->vertices, white);
```

- Permet de dessiner n’importe quel polygone (triangles, pentagones, etc.)
    

#tags/graphics/drawing, #cpp/casting, #implementation/polygons

---

# Testing and Debugging

- Résultat attendu : rectangle centré sur l’origine du canvas.
    
- Attention : vertices en **local space**, pas encore transformées en **world space**.
    

#tags/testing/debugging, #graphics/vertices, #physics/2d

---

# Local Space vs World Space

- **Local space** : coordonnées des vertices relatives à l’origine du modèle (centre de masse).
    
- **World space** : coordonnées finales pour l’affichage après translation et rotation.
    
- Transformation nécessaire :
    
    - Translation en fonction de la position du corps
        
    - Rotation en fonction de l’angle de rotation du corps
        

#tags/graphics/transformation, #physics/world-space, #implementation/concepts

---

# Transformations and Rendering

- Processus :
    
    1. Définir vertices dans **local space**.
        
    2. Appliquer **rotation** et **translation** → obtenir world space.
        
    3. Passer les vertices transformés à la fonction de rendu.
        

#tags/graphics/transformation, #physics/vertices, #cpp/rendering

---

# Conclusion and Next Steps

- Étape suivante : implémenter la transformation **local → world space**.
    
- Objectif : afficher correctement les polygones dans le moteur 2D avec position et rotation.
    

#tags/conclusion, #graphics/2d, #physics/implementation
