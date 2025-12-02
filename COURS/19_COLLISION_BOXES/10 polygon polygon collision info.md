---
# Remplissage de l’Information de Contact pour les Collisions de Polygones

Après avoir calculé les séparations minimales entre deux polygones (A et B), l’étape suivante consiste à **remplir l’information de contact** utilisée pour la résolution des collisions. Cela garantit que tous les vecteurs et points nécessaires sont disponibles pour le calcul des impulsions.

---
# Deux Scénarios : AB vs BA

Lors de la détermination de l’information de contact, deux scénarios sont possibles :

1. **Séparation AB plus grande**  
   - La meilleure arête appartient au polygone **A**.  
   - La profondeur du contact est dérivée de la **séparation AB** :

   $$
   \text{contact.depth} = - \text{separation}_{AB}
   $$

   - La normale du contact provient de **l’axe retourné par le test AB**, converti en perpendiculaire pour assurer la bonne direction :

   $$
   \text{contact.normal} = \text{axis}_{AB}^{\perp}
   $$

   - Le point de départ du contact est le sommet sur **B** ayant produit la projection minimale (`pointA`).  
   - Le point de fin du contact est calculé par :

   $$
   \text{contact.end} = \text{contact.start} + (\text{contact.normal} \cdot \text{contact.depth})
   $$

2. **Séparation BA plus grande**  
   - La meilleure arête appartient au polygone **B**.  
   - La profondeur du contact est dérivée de la **séparation BA** :

   $$
   \text{contact.depth} = - \text{separation}_{BA}
   $$

   - La normale du contact doit être **inversée** pour pointer de A vers B :

   $$
   \text{contact.normal} = -\text{axis}_{BA}^{\perp}
   $$

   - Le point de départ du contact est le sommet sur **A** ayant produit la projection minimale (`pointB`).  
   - Le point de fin est :

   $$
   \text{contact.end} = \text{contact.start} + (\text{contact.normal} \cdot \text{contact.depth})
   $$

---
# Mise à Jour des Objets Contact

- Assigner les références aux **rigid bodies** impliqués dans la collision :

```cpp
contact.a = bodyA;
contact.b = bodyB;
```

- Choisir le scénario correct (AB ou BA) selon la séparation la plus grande.
    
- Remplir les champs suivants :

```cpp
contact.depth = ...;
contact.normal = ...;
contact.start = ...;
contact.end = contact.start + contact.normal * contact.depth;
```

# Notes d’Implémentation

- La **normale de collision** doit toujours pointer de **A vers B** pour maintenir une résolution de collision cohérente.
    
- Le **point de départ** correspond toujours au sommet du polygone opposé à l’arête produisant la séparation maximale.
    
- Le **point de fin** est dérivé à partir de la normale et de la profondeur de pénétration.
    
- Une attention particulière est nécessaire pour inverser la normale et permuter les points de départ/fin dans le cas BA.
    

---

# Visualisation et Débogage

- Lors de l’exécution de la simulation, vérifier que les normales de contact pointent systématiquement de A vers B.
    
- Les points de contact et les profondeurs de pénétration doivent s’aligner avec la région de recouvrement des polygones.
    
- Utiliser papier/crayon peut être utile pour raisonner sur les vecteurs et leurs directions.
    

---

# Étapes Suivantes

- Une fois l’information de contact entièrement remplie, l’étape suivante est la **résolution des collisions** par impulsions.
    
- Considérations futures : gérer les **effets de rotation**, les **impulsions angulaires**, et le **moment d’inertie** pour une simulation physique précise.
