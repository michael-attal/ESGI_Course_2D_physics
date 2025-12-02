# Implémentation de la détection de collision

## Mise en place des objets

Nous commençons par créer notre scène avec deux cercles pour tester la détection de collision cercle-cercle.  
- Un **gros cercle** : rayon 100, position initiale (100, 100), masse 1.0  
- Un **petit cercle** : rayon 50, position initiale (500, 100), masse 1.0  

Ces objets sont ajoutés à notre vecteur de rigid bodies.  
#collision/setup, #rigid-body, #circle

---

## Application des forces

Pour que la simulation fonctionne, nous appliquons des forces aux objets :  
- **Gravité** : force descendante  
- **Vent** : force horizontale subtile vers la droite  

Pas de couple (torque) pour l’instant.  
#physics/forces, #gravity, #wind

---

## Intégration et mise à jour

- Intégration linéaire et angulaire des corps  
- Mise à jour des vertices si nécessaire  
- Vérification de collision avec les limites de la fenêtre  

Rendu : deux cercles visibles, actuellement en chevauchement.  
#physics/integration, #update, #render

---

## Détection de collision pour plusieurs objets

Pour N objets, il faut vérifier chaque corps rigide avec tous les autres.  
- Pour l’instant, seulement deux objets  
- À l’avenir, cela pourra concerner des centaines ou milliers de cercles  

Approche : **double boucle imbriquée** pour comparer chaque corps avec tous les autres.  
#collision/multiple-objects, #nested-loop

---

## Structure de la boucle imbriquée

```cpp
for (int i = 0; i < bodies.size() - 1; i++) {
    for (int j = i + 1; j < bodies.size(); j++) {
        // vérification de collision entre body[i] et body[j]
    }
}
```

- ite de comparer deux fois le même couple
    
- Évite de tester un objet avec lui-même  
    #cpp/nested-loop, #collision-check
    

---

## Classe de détection de collision

Création d’une classe `CollisionDetection` :

- Fournit des méthodes pour détecter les collisions
    
- Retourne `true` ou `false` selon que les corps se chevauchent ou non  
    #collision/class, #cpp/design
    

---

## Appel de méthode

```cpp
if (CollisionDetection::isColliding(a, b)) {
    // gérer la collision
}
```


- `a` et `b` sont des pointeurs vers les corps rigides issus du vecteur
    
- Permet de centraliser la logique de détection  
    #cpp/method-call, #collision-detection
    

---

## Structure de la classe

```cpp
struct CollisionDetection {
    static bool isColliding(Body* a, Body* b);
    static bool isCollidingCircleCircle(Body* a, Body* b);
    // TODO: box-box, box-circle, polygon-polygon, polygon-circle
};
```

- Méthodes statiques pour simplifier l’appel
    
- Extension future possible pour d’autres formes  
    #cpp/class-structure, #collision/methods
    

---

## Fichier d’implémentation

- `CollisionDetection.cpp` contiendra le corps des méthodes
    
- Implementation des vérifications et logiques de collision  
    #cpp/implementation, #collision












