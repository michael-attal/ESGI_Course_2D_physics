# Calcul de la valeur de lambda pour la contrainte

---

## 1. Mise en place de la formule de lambda

La valeur de $\lambda$ correspond à la magnitude de l’impulsion à appliquer pour valider la contrainte entre les corps A et B.  
La formule générale est :

$$
\lambda = \frac{-J \mathbf{V} + \mathbf{b}}{J M^{-1} J^T}
$$

où :  
- $J$ est la Jacobienne (matrice des coefficients)  
- $\mathbf{V}$ est le vecteur des vitesses linéaires et angulaires des corps  
- $M^{-1}$ est la matrice inverse de masse  
- $\mathbf{b}$ est un petit facteur de biais (*bias factor*)  
- $J^T$ est la transposée de la Jacobienne  

---

## 2. Numérateur et dénominateur

### 2.1 Numérateur

Le numérateur correspond à :

$$
\text{num} = - J \mathbf{V} + \mathbf{b}
$$

Dans un premier temps, on peut ignorer le facteur de biais pour simplifier :

$$
\text{num} = - J \mathbf{V}
$$

### 2.2 Dénominateur

Le dénominateur correspond à :

$$
\text{den} = J M^{-1} J^T
$$

Cette opération donne une matrice qui multiplie le vecteur $\lambda$ dans le système linéaire.

---

## 3. Résolution du système linéaire

Le calcul de $\lambda$ n’est pas une simple division scalaire, mais la résolution d’un système de la forme :

$$
A X = B
$$

où :  
- $A = J M^{-1} J^T$ (matrice)  
- $X = \lambda$ (vecteur inconnu)  
- $B = - J \mathbf{V}$ (vecteur du numérateur)

Ceci est un problème classique de **résolution d’équations linéaires**.

---

## 4. Méthodes de résolution

Plusieurs méthodes peuvent être utilisées pour résoudre $AX = B$ :  

- Méthode de Cramer  
- Méthode de Jacobi  
- Méthode de Gauss-Seidel (itérative)  

Pour notre contexte, on privilégie une **méthode itérative** comme Gauss-Seidel, adaptée aux matrices peu denses et à la nature des contraintes de physique.

---

## 5. Exemple de solution itérative (Gauss-Seidel)

1. Initialiser le vecteur $\lambda$ à zéro :  

$$
\lambda = \mathbf{0}
$$

2. Pour chaque itération, mettre à jour chaque composante :

$$
\lambda_i \gets \frac{B_i - \sum_{j \neq i} A_{ij} \lambda_j}{A_{ii}}
$$

3. Répéter plusieurs fois (6 à 10 itérations suffisent pour converger).

---

## 6. Vérification

Une fois $\lambda$ calculé, vérifier que :

$$
A \lambda \approx B
$$

L’écart dû à l’approximation diminue avec le nombre d’itérations. La solution approchée correspond à la valeur de l’impulsion à appliquer aux corps pour satisfaire la contrainte.

---

## 7. Étapes suivantes

1. Implémenter une fonction `solve_gauss_seidel(A, B)` pour résoudre $AX = B$.  
2. Passer la matrice $A = J M^{-1} J^T$ et le vecteur $B = -J \mathbf{V}$.  
3. Récupérer le vecteur $\lambda$ obtenu et appliquer les impulsions correspondantes sur A et B.  

Cette approche complète le calcul numérique de $\lambda$ pour la **résolution de contraintes de distance**.
