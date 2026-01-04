# Introduction à l'utilisation des matrices et vecteurs pour les contraintes de vitesse

Dans ce chapitre, nous allons relier les concepts de **matrices** et **vecteurs** à la résolution des contraintes de vitesse dans un moteur physique. L'objectif est de comprendre comment dériver les **impulsions** nécessaires pour modifier les vitesses des corps impliqués dans une contrainte.

## Vecteur d'état

On définit un **vecteur d'état** $\mathbf{v}$ regroupant les positions et rotations des corps impliqués, par exemple deux corps $A$ et $B$ :

$$
\mathbf{v} =
\begin{bmatrix}
x_A \\ y_A \\ \theta_A \\ x_B \\ y_B \\ \theta_B
\end{bmatrix}
$$

où $x, y$ sont les positions linéaires et $\theta$ la rotation en radians par seconde.

## Contrainte générique et dérivée temporelle

Pour une fonction de contrainte générique $C$, sa **dérivée temporelle** doit être nulle pour satisfaire la contrainte :

$$
\frac{dC}{dt} = \frac{\partial C}{\partial \mathbf{p}} \cdot \frac{d\mathbf{p}}{dt} = 0
$$

- $\frac{\partial C}{\partial \mathbf{p}}$ : **Jacobian** (matrice des coefficients de la contrainte)  
- $\frac{d\mathbf{p}}{dt}$ : **vecteur des vitesses** des corps

Ainsi, on obtient une relation linéaire :

$$
\mathbf{J} \cdot \mathbf{V} = 0
$$

où $\mathbf{J}$ est la **matrice Jacobienne** et $\mathbf{V}$ le **vecteur des vitesses**.

## Ajout d'un facteur de biais

Pour stabiliser la simulation et introduire une approche progressive, on ajoute un **terme de biais** $\mathbf{b}$ :

$$
\mathbf{J} \cdot \mathbf{V} + \mathbf{b} = 0
$$

Ce facteur permet de contrôler la convergence des contraintes sur plusieurs étapes de simulation, par exemple via **Baumgarte stabilization**.

## Structure des matrices et vecteurs

Pour deux corps $A$ et $B$, la Jacobian est représentée comme un **row matrix** à six coefficients :

$$
\mathbf{J} = [J_{Ax}, J_{Ay}, J_{A\theta}, J_{Bx}, J_{By}, J_{B\theta}]
$$

Le vecteur des vitesses correspond :

$$
\mathbf{V} = 
\begin{bmatrix}
v_{Ax} \\ v_{Ay} \\ \omega_A \\ v_{Bx} \\ v_{By} \\ \omega_B
\end{bmatrix}
$$

où $v$ sont les vitesses linéaires et $\omega$ les vitesses angulaires. Le produit $\mathbf{J} \cdot \mathbf{V}$ donne une combinaison linéaire qui doit être compensée par le biais pour satisfaire la contrainte.

## Application dans le code

Dans la classe **Constraint**, on ajoute :

- Un **pointeur sur chaque corps** $A$ et $B$  
- Une **matrice Jacobienne** $M \times N$ (row matrix)  
- Une fonction `getVelocities()` qui retourne le vecteur $\mathbf{V}$ à six composants.

Chaque contrainte peut ainsi :

1. Remplir la Jacobian avec les coefficients appropriés selon la contrainte  
2. Récupérer le vecteur des vitesses des corps  
3. Calculer la combinaison linéaire $\mathbf{J} \cdot \mathbf{V} + \mathbf{b}$  
4. Déterminer les **impulsions** à appliquer pour corriger les vitesses et respecter la contrainte.

---

Cette approche générale, **velocity-based equality constraint**, permet de résoudre toute contrainte linéaire dépendant des vitesses, qu’il s’agisse de distance, de position ou de joint.

# Tags
#physics/constraint, #matrix/jacobian, #vector/velocity, #esgi/game-physics, #simulation/rigid-body
