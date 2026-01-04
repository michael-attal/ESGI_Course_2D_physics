# Résolution du système AX = B en C++ avec Gauss-Seidel

---

## 1. Traduction de MATLAB vers C++

Pour résoudre le système de type :

$$
A X = B
$$

où $A$ est la matrice de gauche et $B$ le vecteur de droite, l’idée est de traduire le script MATLAB en C++.

- Une **méthode statique** est créée dans la classe `MN` (matrice) : `SolGaussSeidel`.
- Elle reçoit deux paramètres :  
  - `A` : référence vers une matrice MN (matrice gauche)  
  - `B` : vecteur colonne de N composantes (vecteur droit)  
- Elle retourne un vecteur `X` de N composantes correspondant à $\lambda$.

---

## 2. Initialisation

- Déterminer la taille N à partir de B :  

$$
N = \text{taille}(B)
$$

- Créer un vecteur `X` de N composantes initialisé à zéro :  

$$
X_i = 0 \quad \forall i \in [0, N-1]
$$

---

## 3. Itérations Gauss-Seidel

Pour chaque itération, mettre à jour chaque composante de X selon :

$$
X_i \gets \frac{B_i - \sum_{j \neq i} A_{ij} X_j}{A_{ii}}
$$

- Boucler sur toutes les composantes de X autant de fois que nécessaire (N itérations minimum).  
- Ajouter une **protection contre la division par zéro** : vérifier que $A_{ii} \neq 0$ avant de diviser.  
- Accumuler les contributions à chaque itération.

---

## 4. Traduction exacte de MATLAB

Le code MATLAB de départ effectuait :

- Initialisation de X à zéro  
- Boucle sur les lignes de la matrice  
- Calcul de $X_i$ par itération selon la formule de Gauss-Seidel  
- Vérification de la convergence après quelques itérations  

En C++, cela se traduit par une fonction `SolGaussSeidel(A, B)` :

1. Créer le vecteur `X` initialisé à zéro  
2. Pour `iterations` de 0 à N :
   - Pour chaque composante `i` :
     - Si $A_{ii} \neq 0$ :
       $$
       X_i \mathrel{+}= \frac{B_i - \text{dot}(A_i, X)}{A_{ii}}
       $$
3. Retourner `X` comme solution approximative de $\lambda$

---

## 5. Utilisation dans la résolution des contraintes

- Le vecteur $\lambda = X$ obtenu contient les **magnitudes des impulsions** à appliquer aux corps A et B.  
- Il reste à récupérer ces valeurs et les appliquer aux corps pour valider la contrainte de distance.  

Cette approche complète le passage de MATLAB à C++ pour la résolution du système linéaire via Gauss-Seidel.
