# Matrices – Implémentation et rappel conceptuel  
_Cours ESGI – Physics Engine 2D_

---

## Rappel des objectifs

Nous travaillons désormais avec les **matrices**, c’est-à-dire des structures de données tabulaires organisées en **lignes** et **colonnes**.

Pour ce cours, l’objectif est volontairement **limité**.  
Nous n’implémentons que ce qui est strictement nécessaire :

- constructeurs / destructeur  
- mise à zéro de la matrice  
- transposition  
- opérateur d’affectation  
- multiplication :
  - matrice × vecteur
  - matrice × matrice  

Cela constitue **l’intégralité** de ce dont nous aurons besoin dans le moteur physique 2D.

Dans un contexte de physique 3D ou de rendu graphique avancé, les matrices deviendraient beaucoup plus complexes, mais ce n’est **pas le cas ici**.

---

## Vue d’ensemble de l’implémentation

La classe `MatrixMN` est définie par :
- $m$ : nombre de lignes
- $n$ : nombre de colonnes
- `rows` : tableau de vecteurs (`VEC<N>`)

Chaque ligne de la matrice est un vecteur contenant $n$ composantes.

Conceptuellement :
$$
\text{Matrix}_{m \times n} = \begin{bmatrix}
\text{VEC}_n \\
\text{VEC}_n \\
\vdots \\
\text{VEC}_n
\end{bmatrix}
$$

---

## Constructeur par défaut

Le constructeur sans paramètre initialise une matrice **vide** :

- $m = 0$
- $n = 0$
- `rows = nullptr`

Il ne crée aucune donnée en mémoire.  
C’est un état neutre, utile pour permettre des affectations ultérieures.

---

## Constructeur avec dimensions $(m, n)$

Ce constructeur est **fondamental**.

Étapes :
1. Initialiser le nombre de lignes $m$
2. Initialiser le nombre de colonnes $n$
3. Allouer dynamiquement un tableau de $m$ vecteurs
4. Initialiser chaque ligne comme un vecteur de $n$ composantes

Structure mémoire :
- `rows` → tableau de taille $m$
- chaque `rows[i]` → `VEC<n>`

Il est essentiel de bien comprendre cette organisation :
> **Une matrice est un tableau de lignes, et chaque ligne est un vecteur.**

Cette logique doit devenir **automatique**.

---

## Constructeur par copie

Le constructeur par copie permet de créer une nouvelle matrice à partir d’une matrice existante.

Principe :
- recopier $m$ et $n$
- allouer un nouveau tableau de lignes
- recopier chaque vecteur ligne par ligne

Il s’agit d’une **copie profonde**, pas d’un simple partage de pointeurs.

---

## Destructeur

Toute allocation effectuée avec `new` doit être libérée.

Responsabilités du destructeur :
- libérer le tableau `rows`
- garantir l’absence de fuite mémoire

C’est une règle fondamentale en C++ :
> **Celui qui alloue est responsable de désallouer.**

---

## Méthode `zero()`

La méthode `zero()` met **tous les éléments** de la matrice à $0$.

Stratégie :
- parcourir chaque ligne
- appeler `zero()` sur chaque vecteur

Mathématiquement :
$$
\forall i, j \quad A_{i,j} = 0
$$

Grâce à la méthode `VEC::zero()`, l’implémentation est simple et élégante.

---

## Transposition : rappel conceptuel

La transposition échange les lignes et les colonnes.

Si :
$$
A \in \mathbb{R}^{m \times n}
$$

Alors :
$$
A^T \in \mathbb{R}^{n \times m}
$$

Et :
$$
(A^T)_{j,i} = A_{i,j}
$$

Cette opération est **fondamentale** pour :
- la résolution de contraintes
- la manipulation des systèmes linéaires

L’implémentation nécessite une réflexion algorithmique claire, c’est pourquoi elle est laissée en `TODO` à ce stade.

---

## Opérateur d’affectation `=`

L’opérateur d’affectation permet d’écrire :
$$
M_1 = M_2
$$

Étapes :
1. copier $m$ et $n$
2. allouer un nouveau tableau de lignes
3. recopier chaque ligne depuis la matrice source
4. retourner une référence vers l’objet courant

Le retour par référence permet l’écriture chaînée et respecte les conventions C++.

---

## Multiplication matrice × vecteur

Cette opération est définie lorsque :
$$
A \in \mathbb{R}^{m \times n}, \quad v \in \mathbb{R}^{n}
$$

Résultat :
$$
A \cdot v \in \mathbb{R}^{m}
$$

Chaque composante du vecteur résultat est le **produit scalaire** entre une ligne de la matrice et le vecteur.

Cette opération est centrale dans le moteur physique.

---

## Multiplication matrice × matrice

La multiplication de matrices est définie lorsque :
$$
A \in \mathbb{R}^{m \times n}, \quad B \in \mathbb{R}^{n \times p}
$$

Résultat :
$$
C = A \cdot B \in \mathbb{R}^{m \times p}
$$

Chaque élément :
$$
C_{i,j} = \sum_{k=1}^{n} A_{i,k} \cdot B_{k,j}
$$

Cette opération est plus complexe et nécessite une compréhension précise des dimensions.

---

## Étape suivante

Avant d’implémenter :
- la transposition
- la multiplication matrice × vecteur
- la multiplication matrice × matrice  

Nous ferons un **rappel mathématique détaillé** de ces opérations.

L’objectif est clair :
> **Comprendre l’algorithme avant d’écrire la moindre ligne de code.**
