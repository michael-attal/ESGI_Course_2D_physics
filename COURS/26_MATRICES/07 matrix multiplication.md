# Multiplication de matrices

Nous allons maintenant aborder la multiplication de matrices. Contrairement à ce que certains pourraient penser, **la multiplication de matrices n’est pas une opération élément par élément**. L’algorithme est plus subtil et élégant.

## Algorithme de multiplication

Soient deux matrices $A$ et $B$, et nous voulons calculer $C = A \times B$. Chaque élément $c_{i,j}$ de la matrice résultat est calculé en effectuant le produit scalaire (*dot product*) entre la $i$-ième ligne de $A$ et la $j$-ième colonne de $B$ :

$$
c_{i,j} = \sum_{k=1}^{n} A_{i,k} \cdot B_{k,j}
$$

### Exemple concret

Pour des matrices $2 \times 2$ :

$$
A = 
\begin{pmatrix}
1 & 2 \\
3 & 4
\end{pmatrix}, \quad
B = 
\begin{pmatrix}
5 & 6 \\
7 & 8
\end{pmatrix}
$$

Le produit $C = A \times B$ est calculé comme suit :

$$
\begin{aligned}
c_{1,1} &= 1\cdot5 + 2\cdot7 = 19 \\
c_{2,1} &= 3\cdot5 + 4\cdot7 = 43 \\
c_{1,2} &= 1\cdot6 + 2\cdot8 = 22 \\
c_{2,2} &= 3\cdot6 + 4\cdot8 = 50
\end{aligned}
$$

Ainsi, la matrice résultante est :

$$
C =
\begin{pmatrix}
19 & 22 \\
43 & 50
\end{pmatrix}
$$

> Remarque : chaque élément est obtenu par un **produit scalaire** entre une ligne de la première matrice et une colonne de la seconde.

## Règles de dimensions

Pour que la multiplication soit définie :

- Le nombre de colonnes de la matrice de gauche doit être égal au nombre de lignes de la matrice de droite.  
- La matrice résultante aura pour dimensions : **nombre de lignes de la première matrice × nombre de colonnes de la seconde matrice**.

Si ces conditions ne sont pas respectées, la multiplication n’est pas possible.

$$
A_{m \times n} \times B_{n \times p} = C_{m \times p}
$$

## Propriétés importantes

- La multiplication de matrices **n’est pas commutative** : $A \times B \neq B \times A$ en général.
- Il s’agit uniquement d’une opération associative et distributive, mais l’ordre est crucial.

## Implémentation conceptuelle

En C++ pour notre classe `MatrixMN` :

1. Vérifier les dimensions : `if (cols_A != rows_B) return erreur`.
2. Créer la matrice résultat `C` avec les dimensions appropriées.
3. Parcourir toutes les lignes `i` de `A` et toutes les colonnes `j` de `B`.
4. Calculer $c_{i,j}$ par produit scalaire entre la ligne `i` de `A` et la colonne `j` de `B`.
5. Retourner la matrice résultante.

> Ce processus sera la base de l’implémentation dans `MatrixMN::operator*`.

