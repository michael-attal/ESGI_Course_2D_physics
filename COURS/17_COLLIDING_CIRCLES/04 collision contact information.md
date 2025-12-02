# Informations de collision pour la résolution

La détection des collisions cercle-cercle est simple : on vérifie la distance entre les corps rigides et on la compare à la somme de leurs rayons.  
Si la distance est inférieure à la somme des rayons, ils sont en collision ; sinon, non.  

---

# Au-delà de la détection : résolution des collisions

La détection seule ne suffit pas dans un moteur physique.  
Pour résoudre les collisions, il faut des informations détaillées issues du chevauchement.  
C’est ce qu’on appelle les **informations de collision**, un ensemble structuré de données décrivant le contact.

---

# Éléments des informations de collision

Les informations de collision incluent généralement :  

1. **Point de départ** – point de contact initial du corps rigide A par rapport à B.  
2. **Point d’arrivée** – point de contact final du corps rigide B par rapport à A.  
3. **Vecteur normal** – direction selon laquelle résoudre la collision.  
4. **Profondeur de pénétration** – magnitude du chevauchement entre les corps.  

```cpp
struct Contact {
    Body* A; // Pointeur vers le premier corps rigide
    Body* B; // Pointeur vers le second corps rigide
    Vec2 start; // Point de contact initial
    Vec2 end;   // Point de contact final
    Vec2 normal; // Vecteur normal de la collision
    float depth; // Profondeur de pénétration
};
```

- `A` et `B` pointent vers les corps rigides originaux causant la collision.
    
- `start` et `end` vont toujours de `A` vers `B`.
    
- `normal` indique la direction dans laquelle les objets doivent être déplacés pour résoudre la collision.
    
- `depth` indique l’importance du chevauchement.
    

---

# Objectif des informations de collision

- Permet la résolution des collisions en fournissant des détails précis sur le contact.
    
- Sépare la **détection** (spécifique à la forme) de la **résolution** (indépendante de la forme).
    
- Une fois les informations de contact calculées, les méthodes de résolution n’ont plus besoin de connaître les formes originales.
    

Flux de travail général :

1. **Détection de collision** – les corps rigides sont-ils en collision ? (spécifique à la forme)
    
2. **Calcul des informations de collision** – point de départ, point d’arrivée, normal, profondeur
    
3. **Résolution de collision** – déplacer les corps ou appliquer des impulsions en fonction de ces informations (indépendante de la forme)
    

---

# Généralisation à d’autres formes

- La structure `Contact` fonctionne pour toutes les combinaisons de formes : cercle-cercle, box-box, polygone-polygone, etc.
    
- La détection doit tenir compte des formes, mais une fois les informations de contact générées, la résolution peut être uniforme.
    
- Cela permet d’implémenter une seule méthode de résolution utilisant uniquement `start`, `end`, `normal` et `depth`.
    

---

# Étapes suivantes

- Implémenter la structure `Contact` dans le code source.
    
- Calculer les informations de collision pour les collisions **cercle-cercle** : point de départ, point d’arrivée, vecteur normal, profondeur de pénétration.
    
- Étendre plus tard ce calcul à d’autres formes (box-box, polygone-polygone, cercle-box).
    
- Ces informations sont essentielles pour résoudre les collisions de manière réaliste dans le moteur physique.






