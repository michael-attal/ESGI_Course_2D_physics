
## 1. Conversion des points d’ancrage en coordonnées mondiales

Soient les points d’ancrage pour les corps A et B :  

- $\mathbf{P}_A = \text{Anchor point en espace local de A → espace mondial}$  
- $\mathbf{P}_B = \text{Anchor point en espace local de B → espace mondial}$  

Ces points correspondent aux vecteurs $\mathbf{R}_A$ et $\mathbf{R}_B$ dans nos formules théoriques.

---

## 2. Vecteurs relatifs au centre de masse

On définit :

$$
\mathbf{R}_A = \mathbf{P}_A - \text{position du centre de masse de A} 
$$
$$
\mathbf{R}_B = \mathbf{P}_B - \text{position du centre de masse de B}
$$

Ces vecteurs seront utilisés pour les composantes angulaires de la Jacobienne.

---

## 3. Chargement de la Jacobienne – corps A

### 3.1 Composante linéaire

Pour la vitesse linéaire de A :

$$
J_1 = 2 (\mathbf{P}_A - \mathbf{P}_B)
$$

On décompose en coordonnées :

- $J[0,0] = J_1.x$ → vitesse linéaire X de A  
- $J[0,1] = J_1.y$ → vitesse linéaire Y de A  

### 3.2 Composante angulaire

Pour la vitesse angulaire de A :

$$
J_2 = 2 (\mathbf{R}_A \times (\mathbf{P}_A - \mathbf{P}_B))
$$

- $J[0,2] = J_2$ → coefficient pour $\omega_A$

---

## 4. Chargement de la Jacobienne – corps B

### 4.1 Composante linéaire

Pour la vitesse linéaire de B :

$$
J_3 = 2 (\mathbf{P}_B - \mathbf{P}_A)
$$

On décompose en coordonnées :

- $J[0,3] = J_3.x$ → vitesse linéaire X de B  
- $J[0,4] = J_3.y$ → vitesse linéaire Y de B  

### 4.2 Composante angulaire

Pour la vitesse angulaire de B :

$$
J_4 = 2 (\mathbf{R}_B \times (\mathbf{P}_B - \mathbf{P}_A))
$$

- $J[0,5] = J_4$ → coefficient pour $\omega_B$

---

## 5. Résultat

La Jacobienne $J$ est maintenant correctement **chargée avec toutes les composantes** (linéaires et angulaires) de A et B.  
Elle peut être multipliée par le vecteur des vitesses $V$ pour obtenir :

$$
\dot{C} = J V
$$

où $\dot{C}$ est la dérivée temporelle de la contrainte.  

---

## 6. Étapes suivantes

1. Récupérer le vecteur des vitesses $V$ via la fonction `get_velocity()`  
2. Récupérer la matrice inverse de masse $M^{-1}$ via `get_inv_mass()`  
3. Calculer le multiplicateur de Lagrange $\lambda$ avec :

$$
\lambda = -(J M^{-1} J^T)^{-1} (\dot{C} + \text{bias})
$$

4. Appliquer l’impulsion à A et B pour corriger la contrainte.  

Cette étape complète la préparation pour la **résolution numérique de la contrainte de distance**.
