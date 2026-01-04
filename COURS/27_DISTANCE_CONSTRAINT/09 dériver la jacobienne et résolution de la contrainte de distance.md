## 1. Contexte

Nous sommes dans la fonction `solve()` de la contrainte de distance (dans notre moteur physique, il s’agit d’une **joint constraint**).  

Objectif : résoudre la contrainte en calculant les impulsions nécessaires pour corriger la violation de distance entre deux corps A et B.

---

## 2. Éléments disponibles

Avant de charger la Jacobienne, nous disposons déjà de :

- la **matrice de masse inverse** $M^{-1}$ (pour A et B, incluant la masse et le moment d’inertie inverses)  
- le **vecteur des vitesses** $V$ (linéaires et angulaires des corps A et B)  
- un **facteur de biais** pour la stabilisation numérique, choisi arbitrairement entre 0 et 1  

Il reste donc **à définir la Jacobienne $J$**, qui est le cœur de la résolution.

---

## 3. Définition de la contrainte de position

Soient deux corps A et B et un point d’ancrage commun.  
Définissons :

$$
\mathbf{R}_A = \text{point d’ancrage} - \text{centre de masse de A} \\
$$
$$
\mathbf{R}_B = \text{point d’ancrage} - \text{centre de masse de B}
$$

La **fonction contrainte de position** peut s’écrire :

$$
C(\mathbf{R}_A, \mathbf{R}_B) = (\mathbf{R}_B - \mathbf{R}_A) \cdot (\mathbf{R}_B - \mathbf{R}_A)
$$

L’objectif est que $C = 0$ pour maintenir la distance fixée.

---

## 4. Passage à l’espace des vitesses

Pour appliquer les impulsions, nous travaillons dans le domaine des vitesses.  
On prend la **dérivée temporelle** :

$$
\dot{C} = \frac{d}{dt} \left[ (\mathbf{R}_B - \mathbf{R}_A) \cdot (\mathbf{R}_B - \mathbf{R}_A) \right]
$$

En utilisant la règle du produit scalaire :

$$
\frac{d}{dt}(\mathbf{R} \cdot \mathbf{S}) = \dot{\mathbf{R}} \cdot \mathbf{S} + \mathbf{R} \cdot \dot{\mathbf{S}}
$$

---

## 5. Dérivée temporelle détaillée

Après développement et regroupement des termes, on obtient :

$$
\dot{C} = 2 (\mathbf{R}_B - \mathbf{R}_A) \cdot (\dot{\mathbf{R}}_B - \dot{\mathbf{R}}_A)
$$

où les **vitesses des points d’ancrage** sont :

$$
\dot{\mathbf{R}}_A = \mathbf{v}_A + \boldsymbol{\omega}_A \times \mathbf{R}_A 
$$
$$
\dot{\mathbf{R}}_B = \mathbf{v}_B + \boldsymbol{\omega}_B \times \mathbf{R}_B
$$

avec $\mathbf{v}$ les vitesses linéaires et $\boldsymbol{\omega}$ les vitesses angulaires.

---

## 6. Factorisation pour isoler les vitesses

En remplaçant les dérivées dans $\dot{C}$ et en regroupant :

$$
\dot{C} = 2 (\mathbf{R}_B - \mathbf{R}_A) \cdot \mathbf{v}_A + 2 (\mathbf{R}_B - \mathbf{R}_A) \cdot (\boldsymbol{\omega}_A \times \mathbf{R}_A) - 2 (\mathbf{R}_B - \mathbf{R}_A) \cdot \mathbf{v}_B - 2 (\mathbf{R}_B - \mathbf{R}_A) \cdot (\boldsymbol{\omega}_B \times \mathbf{R}_B)
$$

En appliquant la propriété du produit mixte des vecteurs :  

$$
\mathbf{A} \cdot (\mathbf{B} \times \mathbf{C}) = \mathbf{B} \cdot (\mathbf{C} \times \mathbf{A}) = \mathbf{C} \cdot (\mathbf{A} \times \mathbf{B})
$$

on peut réorganiser pour isoler les vitesses $V$.

---

## 7. Forme matricielle et Jacobienne

Après factorisation, l’équation prend la forme :

$$
\dot{C} = J V
$$

où :

- $V = [ \mathbf{v}_A, \boldsymbol{\omega}_A, \mathbf{v}_B, \boldsymbol{\omega}_B]^T$
- $J$ est la **matrice Jacobienne** :

$$
J = 
\begin{bmatrix}
2 (\mathbf{R}_B - \mathbf{R}_A) & 2 (\mathbf{R}_A \times (\mathbf{R}_B - \mathbf{R}_A)) & -2 (\mathbf{R}_B - \mathbf{R}_A) & -2 (\mathbf{R}_B \times (\mathbf{R}_B - \mathbf{R}_A))
\end{bmatrix}
$$

Cette Jacobienne sert à **combiner linéairement les vitesses** pour calculer l’impulsion $\lambda$.

---

## 8. Application dans le moteur physique

1. Charger la Jacobienne $J$ dans la classe de contrainte.
2. Calculer le multiplicateur de Lagrange $\lambda$ via :

$$
\lambda = -(J M^{-1} J^T)^{-1} (\dot{C} + \text{bias})
$$

3. Appliquer l’impulsion :
   - $+\lambda$ à A
   - $-\lambda$ à B

4. Vérifier que la contrainte de distance est respectée après application.

---

## 9. Conclusion

La Jacobienne est la **clé de la résolution de contraintes** :  

- elle encode comment chaque composante de vitesse influence la violation de contrainte  
- elle permet de transformer la correction de vitesse en impulsions physiques  

Une fois calculée et appliquée, la contrainte de distance est validée, ce qui constitue un jalon critique dans le moteur physique.
