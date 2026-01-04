# Calcul de l’impulsion de collision et application sur un corps rigide

---

## Impulsion le long de la normale

Pour calculer la magnitude de l’impulsion $J$ le long de la normale $\mathbf{n}$ de collision :

$$
J = -(1 + \epsilon) \frac{\mathbf{V}_{\text{rel}} \cdot \mathbf{n}}
{\frac{1}{m_A} + \frac{1}{m_B} + \frac{(\mathbf{R}_A \times \mathbf{n})^2}{I_A} + \frac{(\mathbf{R}_B \times \mathbf{n})^2}{I_B}}
$$

- $\epsilon$ : coefficient de restitution (restitution coefficient)
- $\mathbf{V}_{\text{rel}}$ : vitesse relative au point de contact
- $m_A, m_B$ : masses des corps
- $I_A, I_B$ : moments d’inertie
- $\mathbf{R}_A, \mathbf{R}_B$ : vecteurs distance du centre de masse au point de contact
- $(\mathbf{R} \times \mathbf{n})^2$ : produit vectoriel 2D au carré (scalaire)

---

## Conversion en vecteur d’impulsion

L’impulsion vectorielle appliquée sur chaque corps est :

$$
\mathbf{J}_A = J \mathbf{n}, \quad \mathbf{J}_B = -J \mathbf{n}
$$

- $\mathbf{J}_A$ appliquée sur A au point de contact
- $\mathbf{J}_B$ appliquée sur B au point de contact

---

## Application d’une impulsion angulaire

Pour appliquer correctement l’impulsion à un point autre que le centre de masse :

- La variation de la vitesse linéaire : 

$$
\Delta \mathbf{v} = \frac{\mathbf{J}}{m}
$$

- La variation de la vitesse angulaire : 

$$
\Delta \omega = \frac{\mathbf{R} \times \mathbf{J}}{I}
$$

- $\mathbf{R}$ : vecteur distance du centre de masse au point d’application de l’impulsion

---

## Implémentation dans le code

Deux fonctions `applyImpulse` :

1. **Impulsion linéaire** : appliquée au centre de masse

```cpp
void applyImpulse(const Vector2& J) {
    if (!static) velocity += J * invMass;
}
```

2. **Impulsion linéaire + angulaire** : appliquée à un point spécifique

```cpp
void applyImpulse(const Vector2& J, const Vector2& R) {
    if (!static) {
        velocity += J * invMass;
        angularVelocity += cross(R, J) * invInertia;
    }
}

```

- Cette fonction met à jour à la fois la vitesse linéaire et angulaire.
    
- La magnitude de l’impulsion est calculée selon la formule précédente.
    
- Les vecteurs $\mathbf{R}_A$ et $\mathbf{R}_B$ sont utilisés pour chaque corps.
    

---

## Résultat attendu

- Les corps réagissent à la collision en :
    
    - Se déplaçant selon l’impulsion normale
        
    - Tournant selon l’impulsion angulaire
        
    - La restitution et l’inertie sont respectées
        
- La prochaine étape : ajout de la **friction** pour simuler l’interaction tangentielle entre les corps.