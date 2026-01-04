
## Définition de la transposition

La **transposition** d’une matrice consiste à échanger ses **lignes** et ses **colonnes**.

Formellement, si :
$$
A \in \mathbb{R}^{m \times n}
$$

alors sa transposée est :
$$
A^T \in \mathbb{R}^{n \times m}
$$

avec la relation fondamentale :
$$
(A^T)_{j,i} = A_{i,j}
$$

Autrement dit :
> **les lignes de la matrice originale deviennent les colonnes de la matrice transposée**.

---

## Effet sur les dimensions

La transposition modifie toujours les dimensions de la matrice :

- nombre de lignes $\rightarrow$ nombre de colonnes
- nombre de colonnes $\rightarrow$ nombre de lignes

Si la matrice originale est de taille :
$$
m \times n
$$

alors la matrice transposée est de taille :
$$
n \times m
$$

---

## Exemple concret

Soit la matrice originale :
$$
A =
\begin{bmatrix}
6 & 4 & 24 \\
1 & -9 & 8
\end{bmatrix}
$$

Cette matrice est de dimension $2 \times 3$.

Sa transposée est :
$$
A^T =
\begin{bmatrix}
6 & 1 \\
4 & -9 \\
24 & 8
\end{bmatrix}
$$

Dimensions :
$$
A^T \in \mathbb{R}^{3 \times 2}
$$

On observe clairement que :
- la **première ligne** de $A$ devient la **première colonne** de $A^T$
- la **seconde ligne** de $A$ devient la **seconde colonne** de $A^T$

---

## Intuition algorithmique

Transposer une matrice revient simplement à :
- parcourir chaque élément $(i, j)$ de la matrice originale
- copier sa valeur dans la position $(j, i)$ de la matrice résultat

Il ne s’agit **pas** d’une transformation complexe, mais d’un **réarrangement systématique** des données.

---

## Implémentation conceptuelle en code

Dans notre classe `MatrixMN`, la méthode `transpose()` :

1. crée une **nouvelle matrice**
2. dont les dimensions sont inversées :
   - nouvelles lignes = $n$
   - nouvelles colonnes = $m$
3. remplit la matrice résultat en échangeant indices de lignes et de colonnes
4. retourne cette nouvelle matrice

Schéma logique :
$$
\text{result}[j][i] = \text{original}[i][j]
$$

La transposition **ne modifie pas** la matrice courante :  
elle produit une **nouvelle instance**.

---

## Pourquoi la transposition est-elle utile ?

Une application très fréquente consiste à convertir :
- une **matrice ligne** en **matrice colonne**
- ou l’inverse

Cela est souvent nécessaire pour :
- rendre une multiplication valide
- adapter la forme des données aux opérations algébriques

Par exemple :
- un vecteur ligne $1 \times n$
- peut être transformé en vecteur colonne $n \times 1$ via une transposition

---

## Contexte du moteur physique

Dans le moteur physique 2D :
- la transposition est utilisée lors de la résolution des contraintes
- notamment pour manipuler des systèmes d’équations linéaires

Même si l’utilité n’est pas encore totalement visible à ce stade, elle deviendra **évidente** lorsque nous aborderons :
- les impulsions de contraintes
- la résolution matricielle des systèmes physiques

---

## Transition vers la multiplication matricielle

La transposition est une brique essentielle avant d’aborder un autre concept fondamental :
- la **multiplication de matrices**
- la **multiplication matrice × vecteur**

Ces opérations constituent le cœur mathématique de notre moteur physique.

👉 Prochaine étape : **comprendre en détail la multiplication matricielle avant de l’implémenter**.
