# Intégration du Facteur de Biais (Bias Factor) pour la Stabilisation des Contraintes

## Introduction
Pour améliorer la **stabilité des contraintes** dans une simulation physique, il est essentiel d’introduire un **facteur de biais** (bias factor) utilisant la technique de **Baumgarte stabilization**.  
Cette approche permet de corriger progressivement les erreurs de position et de réduire l’étirement ou l’instabilité dans les chaînes de corps rigides.

---

## Définition du bias factor
Dans une contrainte de type **joint**, on ajoute un membre :  

```cpp
float bias; // Facteur de biais pour la stabilisation
```

- Initialisation dans le constructeur : `bias = 0.0f;`
    
- Le **bias factor** se calcule à chaque étape de simulation pour corriger l’erreur de position selon la formule :
    
$$
bias= \frac{\beta}{\Delta t} \cdot C
$$

où :

- $\beta$ ∈ [0,1] est le coefficient de lissage (smoothing factor) choisi par l’utilisateur,
- $\Delta t$ est le pas de temps de la simulation,
- $C$ est l’erreur de position, calculée comme la distance actuelle entre les points liés par la contrainte et leur position cible.
    

---

## Calcul de l’erreur de position

Pour une contrainte de distance entre deux points A et B :

```cpp
Vector3 delta = pointB - pointA;
float C = delta.dot(delta); // Erreur de position
C = std::max(0.0f, C - 0.01f); // Clamp pour éviter les valeurs trop faibles

```

- Le **dot product** permet d’obtenir la magnitude de l’écart projeté le long de la ligne de contrainte.
    
- On limite (`clamp`) la valeur minimale pour éviter des corrections insignifiantes ou instables.
    

---

## Intégration dans le solveur

1. **Pre-solve**
    
    - Calcul du **Jacobian** (une seule fois).
        
    - Application du **warm starting** (cached lambda).
        
    - Calcul du **bias factor** avec Baumgarte stabilization :

```cpp
bias = beta / deltaTime * C; // deltaTime passé en paramètre du pre-solve
```

2. **Solve**
    
    - Itération sur la résolution de la contrainte.
        
    - Application de l’impulsion corrigée par le bias factor pour ajuster les vitesses et positions.
        
    - Accumulation de λ dans **cached lambda** pour le prochain pas de simulation.
        
3. **Impact sur la simulation**
    
    - Les objets restent mieux alignés sur la distance cible.
        
    - Réduction du stretching dans les chaînes de joints.
        
    - Stabilité visuelle améliorée.
        

---

## Paramètres et recommandations

- **β (beta)** : généralement entre 0.05 et 0.2. Plus la valeur est élevée, plus la correction est rapide mais potentiellement instable.
    
- **Δt** : pas de temps de simulation, transmis au pre-solve.
    
- **Clamp de C** : éviter les valeurs trop petites pour que la correction soit significative.
    

---

## Résumé du flux complet

1. **Pre-solve** : Jacobian + warm start + bias factor
    
2. **Solve** : itérations pour appliquer les impulsions λ corrigées par le bias
    
3. **Cached lambda** : sauvegarde pour la prochaine étape de simulation
    

Avec cette approche combinée :

- Warm starting
    
- Iterative solve
    
- Baumgarte stabilization
    

…la simulation devient plus stable, les chaînes de corps rigides réagissent correctement à la gravité et aux forces externes, tout en conservant une performance acceptable.