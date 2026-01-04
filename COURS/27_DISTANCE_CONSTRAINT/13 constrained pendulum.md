# Application des impulsions aux corps rigides

---

## 1. Préparation des impulsions

- Le vecteur `λ` contient **les magnitudes** des impulsions.  
- La **direction** est définie par la transposée de la Jacobienne `Jᵀ`.  
- Les impulsions finales sont calculées en combinant direction et magnitude :

$$
\text{impulses} = J^\top \cdot \lambda
$$

- Chaque vecteur dans `impulses` représente l'impulsion à appliquer aux corps A et B.

---

## 2. Initialisation de la Jacobienne

- Avant de peupler la Jacobienne, s'assurer qu'elle est **initialisée à zéro** :

$$
J_{ij} = 0 \quad \forall i,j
$$

- Charger ensuite tous les coefficients correctement.

---

## 3. Méthodes d’application d’impulsions

Trois méthodes distinctes pour gérer les types d’impulsions :

1. **Impulse linéaire** (`applyImpulseLinear`) :  
   - Applique un vecteur d’impulsion à la vitesse linéaire :

   $$
   \mathbf{v} \gets \mathbf{v} + \frac{\mathbf{J}}{m}
   $$

2. **Impulse angulaire** (`applyImpulseAngular`) :  
   - Applique un scalaire d’impulsion à la vitesse angulaire :

   $$
   \omega \gets \omega + \frac{J}{I}
   $$

3. **Impulse à un point** (`applyImpulseAtPoint`) :  
   - Applique l’impulsion à une position spécifique (utilisé pour la résolution de collisions).

---

## 4. Application des impulsions aux corps A et B

- **Corps A :**
  - Impulsion linéaire : `impulses[0], impulses[1]`  
  - Impulsion angulaire : `impulses[2]`

- **Corps B :**
  - Impulsion linéaire : `impulses[3], impulses[4]`  
  - Impulsion angulaire : `impulses[5]`

- Les trois méthodes sont combinées pour gérer chaque type de modification de la vitesse.

---

## 5. Résultat visuel

- Ajout des corps au monde physique : `world.addBody(A)`, `world.addBody(B)`  
- Création d’un **joint de distance** entre les deux corps.  
- Application des impulsions calculées à chaque frame pour respecter la contrainte.

- Effet obtenu : **pendule** :
  - Le corps central reste statique.  
  - Le second corps oscille selon la distance fixe définie par le joint.  
  - Les mouvements angulaires et linéaires sont correctement gérés.  

- Optimisations possibles pour limiter les pertes d’énergie, mais la **résolution de contrainte fondamentale est fonctionnelle**.

---

## 6. Conclusion

- L’ensemble du processus repose sur :
  - Jacobienne (`J`)  
  - Matrice de masse inverse (`M⁻¹`)  
  - Résolution de `AX = B` pour obtenir λ  
  - Application des impulsions linéaires et angulaires aux corps

- La complexité derrière une **simple oscillation de pendule** illustre l’importance des calculs mathématiques sous-jacents dans la simulation physique.
