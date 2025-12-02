# Implémentation des informations de contact

Pour gérer les informations de contact lors des collisions, nous créons une structure dédiée `Contact` dans `contact.h` et `contact.cpp`.  
Cette structure contient des pointeurs vers les corps rigides originaux, les points de contact de début et de fin, la direction normalisée de la collision (**normal**) et la profondeur de pénétration.  
Un constructeur par défaut initialise ces valeurs. Bien qu’une classe avec des membres privés et des getters/setters soit possible, une simple structure est suffisante pour la clarté et l’accessibilité.

---

# Remplissage des données de contact

À chaque détection de collision, il faut calculer et remplir :  

- **Point de départ** : position sur le bord du corps B le long de la normale allant de A vers B.  
- **Point de fin** : position sur le bord du corps A le long de la normale.  
- **Vecteur normal** : direction de A vers B, normalisée.  
- **Profondeur de pénétration** : amplitude du chevauchement.  

Cette opération est réalisée dans les méthodes de détection de collision, garantissant que la détection calcule elle-même les informations de contact.

---

# Exemple : collision cercle-cercle

Pour deux cercles en chevauchement :

1. **Normal** : vecteur de A vers B normalisé  
```cpp
contact.normal = (b.position - a.position).normalize();
```

2. **Point de départ** (sur le bord de B)
    
```cpp
contact.start = b.position - contact.normal * bCircleShape->radius;
```

3. **Point de fin** (sur le bord de A)

```cpp
contact.end = a.position + contact.normal * aCircleShape->radius;
```

4. **Profondeur de pénétration**

```cpp
contact.depth = (contact.end - contact.start).magnitude();
```

Les points de départ, de fin et la normale pointent toujours de A vers B.

---

# Mise à jour de l’application

- Le cercle principal peut être déplacé avec la souris tandis que le petit cercle reste statique.
    
- La détection de collision remplit la structure `Contact`.
    
- L’objet `contact` est passé par référence pour être mis à jour directement dans la fonction.
    
- Si aucune collision n’a lieu, la fonction retourne `false` immédiatement.
    
- Sinon, elle retourne `true` et l’objet `Contact` contient toutes les données pertinentes.
    

---

# Rendu de débogage des informations de contact

Pour visualiser les données de contact :

- Dessiner de petits cercles aux points de début et de fin du contact.
    
- Dessiner une ligne représentant la direction de la normale (avec une échelle pour la visibilité).

```cpp
graphics.drawCircle(contact.start.x, contact.start.y, 3, magenta);
graphics.drawCircle(contact.end.x, contact.end.y, 3, magenta);
graphics.drawLine(contact.start, contact.start + contact.normal * 15, magenta);
```

- Veiller à ce que le dessin se fasse après le nettoyage de l’écran, idéalement dans la fonction `update` pour le débogage.
    
- Les points de début et de fin ainsi que la normale fournissent une représentation visuelle claire de la collision.
    

---

# Étapes suivantes : résolution des collisions

Avec les informations de contact disponibles :

1. **Résolution des contraintes de position** : déplacer les objets en chevauchement le long de la normale pour éliminer la pénétration.
    
2. **Résolution de la réponse physique** : appliquer éventuellement des impulsions pour des collisions élastiques réalistes.
    

Le vecteur normal, les points de début/fin et la profondeur de pénétration sont essentiels pour calculer à la fois la correction positionnelle et les réponses basées sur les impulsions.
