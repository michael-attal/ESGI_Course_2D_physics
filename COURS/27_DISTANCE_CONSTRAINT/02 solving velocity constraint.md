# Résolution des contraintes de vitesse  
_Cours ESGI – Physique / Moteur physique_

---

## 1. Rappel : contrainte de vitesse

Une contrainte de vitesse s’écrit sous la forme générale :

$$
J \, \mathbf{v} + b = 0
$$

- $J$ : matrice jacobienne de la contrainte  
- $\mathbf{v}$ : vecteur des vitesses  
- $b$ : terme de biais (stabilisation, correction d’erreur)

Objectif : trouver une nouvelle vitesse qui satisfait l’égalité.

---

## 2. Vitesses avant et après correction

On distingue deux vitesses :

- $\mathbf{v}_1$ : vitesse initiale (viole la contrainte)
- $\mathbf{v}_2$ : vitesse corrigée (satisfait la contrainte)

On définit la variation de vitesse :

$$
\Delta \mathbf{v} = \mathbf{v}_2 - \mathbf{v}_1
$$

---

## 3. Impulsion et matrice de masse

La variation de vitesse est liée à l’impulsion appliquée :

$$
M \, \Delta \mathbf{v} = \mathbf{J}
$$

- $M$ : matrice de masse
- $\mathbf{J}$ : impulsion appliquée pour corriger la contrainte

---

## 4. Décomposition de l’impulsion

On décompose l’impulsion en :

$$
\mathbf{J} = L \, \lambda
$$

- $L$ : direction de l’impulsion
- $\lambda$ : magnitude de l’impulsion (multiplicateur de Lagrange)

---

## 5. Direction de l’impulsion

La direction de l’impulsion est donnée par la Jacobienne transposée :

$$
L = J^T
$$

Intuition :
- Le Jacobien est une généralisation du gradient
- Il indique la direction des positions ou vitesses illégales
- L’impulsion corrective agit dans cette direction

---

## 6. Nouvelle vitesse corrigée

À partir de :

$$
M (\mathbf{v}_2 - \mathbf{v}_1) = J^T \lambda
$$

On isole $\mathbf{v}_2$ :

$$
\mathbf{v}_2 = \mathbf{v}_1 + M^{-1} J^T \lambda
$$

---

## 7. Substitution dans la contrainte

On remplace $\mathbf{v}$ par $\mathbf{v}_2$ dans la contrainte :

$$
J (\mathbf{v}_1 + M^{-1} J^T \lambda) + b = 0
$$

En regroupant les termes :

$$
(J M^{-1} J^T)\lambda = -(J \mathbf{v}_1 + b)
$$

---

## 8. Calcul de la magnitude de l’impulsion

On obtient la formule finale :

$$
\lambda = \frac{-(J \mathbf{v}_1 + b)}{J M^{-1} J^T}
$$

---

## 9. Interprétation physique

- $J^T$ : direction de correction (où appliquer l’impulsion)
- $\lambda$ : intensité de correction (combien appliquer)
- $M^{-1}$ : tient compte des masses et inerties

La résolution de contrainte consiste à :
1. Calculer $\lambda$
2. Appliquer l’impulsion $J^T \lambda$
3. Mettre à jour les vitesses

---

## 10. À retenir

- Une contrainte de vitesse est une égalité à satisfaire
- Le Jacobien encode la géométrie de la contrainte
- Le Jacobien transposé donne la direction de l’impulsion
- Le multiplicateur de Lagrange $\lambda$ donne sa magnitude
- Toute la résolution repose sur des produits, sommes et inverses de matrices
