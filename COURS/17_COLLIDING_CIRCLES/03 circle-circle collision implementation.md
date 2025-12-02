# Implémentation de la collision cercle-cercle

## Début de l’implémentation

Nous créons la méthode `isColliding` qui reçoit deux pointeurs vers des `Body`, `a` et `b`.  
L’objectif : retourner `true` si les deux corps se chevauchent, sinon `false`.  
#collision/circle-circle, #cpp/basics, #rigid-body

---

## Vérification du type de forme

Nous devons détecter le type de chaque corps pour appeler la méthode adaptée :  
- Cercle-cercle  
- Cercle-box  
- Box-polygone  
- Polygone-cercle  

Exemple pour les cercles :  

```cpp
bool aIsCircle = (a->shape->getType() == ShapeType::Circle);
bool bIsCircle = (b->shape->getType() == ShapeType::Circle);

if (aIsCircle && bIsCircle) {
    return isCollidingCircleCircle(a, b);
}
```

- Si les deux corps sont des cercles, on appelle la méthode spécialisée `isCollidingCircleCircle`.  
    #collision/type-check, #cpp/boolean, #shape-detection
    

---

## Détection cercle-cercle

Implémentation de la méthode spécialisée :

```cpp
bool CollisionDetection::isCollidingCircleCircle(Body* a, Body* b) {
    CircleShape* aCircle = static_cast<CircleShape*>(a->shape);
    CircleShape* bCircle = static_cast<CircleShape*>(b->shape);

    // Vecteur de a vers b
    Vec2 ab = b->position - a->position;

    // Somme des rayons
    float radiusSum = aCircle->radius + bCircle->radius;

    // Vérification de collision avec la magnitude au carré
    return ab.magnitudeSquared() <= (radiusSum * radiusSum);
}

```

- Extraction des `CircleShape` depuis les `Body`.
    
- Calcul du vecteur `ab` reliant les centres.
    
- Somme des rayons pour déterminer la distance critique.
    
- Comparaison de la magnitude au carré pour éviter le calcul coûteux de racine carrée.
    
- Retourne `true` si collision, `false` sinon.  
    #collision/circle-circle, #cpp/vector, #math/optimization
    

---

## Indicateur de collision dans les corps

Pour le rendu visuel, ajoutons un champ `bool isColliding` dans la classe `Body`, initialisé à `false` :

```cpp
// Mise à jour après détection
if (CollisionDetection::isColliding(a, b)) {
    a->isColliding = true;
    b->isColliding = true;
} else {
    a->isColliding = false;
    b->isColliding = false;
}
```

- Permet de savoir quels corps sont en collision.  
    #collision/flag, #cpp/class, #debug
    

---

## Rendu avec retour visuel

Modification de la couleur selon l’état de collision :

```cpp
Color color = body.isColliding ? Color(1.0f, 0.0f, 0.0f) : Color(1.0f, 1.0f, 1.0f);
drawCircle(body.position, body.shape->radius, color);
```

- Rouge : collision
- Blanc : pas de collision
- Permet de visualiser immédiatement le fonctionnement de la détection.  

---

## Résumé

- La classe `CollisionDetection` centralise l’entrée (`isColliding`) et appelle les méthodes spécialisées (`isCollidingCircleCircle`).
    
- `isCollidingCircleCircle` calcule la distance entre centres et la compare à la somme des rayons.
    
- D’autres combinaisons de formes (box-circle, polygon-circle, polygon-polygon, etc.) seront implémentées ultérieurement.
    
- Le champ `isColliding` de chaque `Body` fournit un retour visuel utile pour le débogage.
    

Prochaine étape : préparer le moteur physique pour **résoudre les collisions**, en extrayant les informations détaillées de chevauchement.  





