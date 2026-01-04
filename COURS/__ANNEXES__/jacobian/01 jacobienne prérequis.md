# Rappels de base : matrices et transformations linéaires

## Objectif et prérequis conceptuels
Dans cette partie du cours, on introduit la notion de Jacobien (Jacobian), et plus précisément la matrice jacobienne (Jacobian matrix), ainsi que, dans certains contextes, son déterminant (Jacobian determinant). La compréhension de ces notions suppose une base solide en algèbre linéaire (linear algebra), en particulier sur l’interprétation géométrique des matrices comme transformations de l’espace (space transformations).

---

## Une matrice comme transformation de l’espace
Une matrice peut être vue non seulement comme un objet de calcul, mais surtout comme une application linéaire (linear transformation) agissant sur des vecteurs. Considérons par exemple la matrice suivante :
$$
A =
\begin{pmatrix}
2 & -3 \\
1 & 1
\end{pmatrix}
$$
Multiplier cette matrice par un vecteur $(x,y)$ produit un nouveau vecteur :
$$
A
\begin{pmatrix}
x \\
y
\end{pmatrix}
=
\begin{pmatrix}
2x - 3y \\
x + y
\end{pmatrix}
$$
Ce résultat correspond à un nouveau point du plan, obtenu par transformation du point initial.

---

## Interprétation géométrique de la transformation
Au-delà du calcul algébrique, il est essentiel d’en avoir une lecture géométrique (geometric interpretation). Lorsqu’on applique cette transformation à l’ensemble des points d’une grille régulière, on observe que les droites restent des droites, que les droites initialement parallèles demeurent parallèles, et que l’espacement entre les lignes reste constant.

Cette propriété caractérise précisément une transformation linéaire : la structure de la grille est conservée.

---

![[medias/jaco00.gif]]

---

## Les vecteurs de base canonique
Pour comprendre entièrement l’action d’une matrice, on observe son effet sur les vecteurs de base canonique (canonical basis vectors) :
$$
\mathbf{e}_1 = (1,0), \quad \mathbf{e}_2 = (0,1)
$$
Dans notre exemple :
$$
A(1,0) = (2,1), \quad A(0,1) = (-3,1)
$$
Ces images correspondent exactement aux colonnes de la matrice. La première colonne encode l’image de $(1,0)$, la seconde encode l’image de $(0,1)$.

---

## Justification algébrique
Cette correspondance découle directement du produit matriciel. Multiplier une matrice par $(1,0)$ annule toutes les contributions liées à la seconde colonne, tandis que multiplier par $(0,1)$ annule celles de la première colonne. Ainsi, les colonnes de la matrice définissent entièrement la transformation linéaire associée.

---

## Définition formelle d’une transformation linéaire
Une fonction $L$ est dite linéaire (linear) si elle satisfait deux propriétés fondamentales :
1. Homogénéité :
$$
L(\lambda \mathbf{v}) = \lambda L(\mathbf{v})
$$
2. Additivité :
$$
L(\mathbf{u} + \mathbf{v}) = L(\mathbf{u}) + L(\mathbf{v})
$$
Ces propriétés garantissent que la transformation commute avec les combinaisons linéaires.

---

## Décomposition d’un vecteur quelconque
Tout vecteur $(x,y)$ peut être décomposé comme une combinaison linéaire des vecteurs de base :
$$
(x,y) = x(1,0) + y(0,1)
$$
Grâce à la linéarité, appliquer la transformation à $(x,y)$ revient à :
$$
x\,A(1,0) + y\,A(0,1)
$$
Il suffit donc de connaître l’image des vecteurs de base pour reconstruire l’image de n’importe quel point du plan.

---

## Exemple géométrique
Considérons le vecteur $(2,1)$. Géométriquement, il correspond à deux fois le premier vecteur de base plus une fois le second. Après transformation, ce vecteur devient la même combinaison linéaire des images des vecteurs de base, ce qui explique la position finale du point transformé.

---

## Lien avec la matrice jacobienne
L’idée centrale à retenir est qu’une matrice représente une transformation de l’espace qui préserve la structure linéaire de la grille. Cette interprétation est essentielle pour comprendre la matrice jacobienne, qui généralise cette approche aux fonctions non linéaires en décrivant leur comportement local comme une transformation linéaire.
