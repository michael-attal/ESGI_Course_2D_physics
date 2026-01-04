
## De VECN à la matrice

De la même manière que nous avons créé un vecteur à $n$ composantes, nous allons maintenant introduire une nouvelle structure fondamentale : **la matrice**.

Une matrice est une **organisation rectangulaire de valeurs** disposées en **lignes** et en **colonnes**.  
C’est un objet mathématique essentiel, très utilisé en informatique graphique, en physique et en simulation.

---

## Définition intuitive

Une matrice est définie par :
- un nombre de **lignes** $m$
- un nombre de **colonnes** $n$

On parle alors d’une matrice de dimension $m \times n$.

Exemple : une matrice à 2 lignes et 3 colonnes :
$$
A =
\begin{bmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23}
\end{bmatrix}
$$

---

## Dimensions possibles

Les dimensions d’une matrice sont **arbitraires** :
- $2 \times 3$
- $3 \times 2$
- $5 \times 7$
- $1000 \times 3000$

Les valeurs stockées peuvent être :
- entiers
- flottants
- positifs ou négatifs

Dans notre moteur physique, nous utiliserons **des flottants**.

---

## Analogie : l’écran (pixels)

On peut voir un écran comme une matrice :
- les **lignes** correspondent à la hauteur
- les **colonnes** correspondent à la largeur
- chaque case contient une couleur (valeur)

C’est une excellente intuition pour comprendre les matrices comme une **structure tabulaire**.

---

## Indices : accéder aux éléments

Un élément d’une matrice est identifié par :
- son **indice de ligne**
- son **indice de colonne**

Notation :
$$
A_{i,j}
$$

Exemples :
- $A_{2,2}$ → ligne 2, colonne 2
- $A_{3,1}$ → ligne 3, colonne 1

Nous utiliserons cette logique constamment dans le code.

---

## Pourquoi utiliser des matrices ?

Les matrices permettent de représenter des données **multidimensionnelles**.

Exemple :
- « J’ai 2 voitures » → scalaire (1 dimension)
- Un concessionnaire automobile :
  - modèles
  - carburant
  - nombre de portes  
→ nécessite plusieurs dimensions → **matrice**

C’est exactement le principe d’un **tableur** (lignes / colonnes).

---

## Lien avec les systèmes d’équations

Les matrices sont historiquement utilisées pour représenter des **systèmes d’équations linéaires** :

$$
\begin{aligned}
ax + by &= c \\
dx + ey &= f
\end{aligned}
$$

Ce système peut être représenté sous forme matricielle.  
Dans notre moteur physique, cela apparaîtra lors de la **résolution de contraintes**.

---

## Matrices en informatique graphique et physique

Applications majeures :
- transformations de vecteurs
- changements de repère
- projections 2D / 3D
- rotations, échelles, translations

En 3D, les matrices sont omniprésentes.  
En 2D, elles restent très utiles, mais nous allons volontairement **limiter leur usage**.

---

## Objectif du cours

Dans ce moteur physique 2D :
- pas d’usage avancé des matrices de transformation
- pas de pipeline graphique complexe

Nous utiliserons les matrices pour :
- stocker des données tabulaires
- résoudre des systèmes d’équations
- effectuer des multiplications matrice–vecteur et matrice–matrice

---

## Représentation en mémoire

Pour une matrice $m \times n$, nous devons stocker :
- le nombre de lignes $m$
- le nombre de colonnes $n$
- les **valeurs**

Choix d’implémentation :
- une matrice = **tableau de vecteurs**
- chaque ligne est un `VEC<n>`

Conceptuellement :
$$
\text{Matrix} = \text{Array<VEC>}
$$

---

## Structure interne

- tableau de $m$ lignes
- chaque ligne est un vecteur de $n$ composantes

Cela permet :
- un accès clair par ligne
- une réutilisation directe de la classe `VEC`

---

## Interface de la classe `MatrixMN`

Fonctionnalités nécessaires :

- constructeurs :
  - par défaut
  - avec dimensions $(m, n)$
  - par copie
- destructeur
- remise à zéro :
  $$
  A_{i,j} = 0
  $$

---

## Transposition

La **transposition** échange lignes et colonnes :

$$
A \in \mathbb{R}^{m \times n}
\quad \Rightarrow \quad
A^T \in \mathbb{R}^{n \times m}
$$

- méthode `transpose()`
- ne modifie pas la matrice originale
- retourne une **nouvelle matrice**

---

## Opérateurs nécessaires

Pour le cours, nous limiterons volontairement les opérations :

- affectation :
$$
A = B
$$

- multiplication matrice–vecteur :
$$
A \cdot v = v'
$$

- multiplication matrice–matrice :
$$
A \cdot B = C
$$

Aucune addition ou soustraction de matrices n’est requise.

---

## Justification pédagogique

Ces opérations suffisent pour :
- représenter des contraintes
- résoudre des systèmes linéaires
- structurer les calculs du moteur physique

Objectif : **simplicité, robustesse, clarté**.

---

## Étape suivante

- création de `MatrixMN.h`
- déclaration de l’interface
- implémentation dans `MatrixMN.cpp`
- implémentation détaillée des multiplications

Nous reviendrons pas à pas sur chaque opération mathématique lors du codage.
