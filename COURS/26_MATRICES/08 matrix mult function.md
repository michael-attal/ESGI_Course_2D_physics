# Implémentation de la multiplication de matrices

Nous avons déjà compris la théorie derrière la multiplication de matrices et l’intuition de l’algorithme. Il s’agit maintenant de traduire cela en code.

## Multiplication matrice × matrice

1. **Vérification des dimensions**  
   Avant de multiplier, il faut s’assurer que le nombre de colonnes de la première matrice est égal au nombre de lignes de la seconde. Sinon, la multiplication n’est pas possible et, dans cet exemple, la fonction retourne simplement la seconde matrice :

$$
\text{if } \text{cols}_A \neq \text{rows}_B \text{ then return } B
$$

2. **Transposition de la deuxième matrice**  
   Pour simplifier le calcul, on transpose la seconde matrice. Ainsi, au lieu de multiplier ligne × colonne, on peut effectuer un produit ligne × ligne :

$$
B^T = \text{transpose}(B)
$$

3. **Création de la matrice résultat**  
   Les dimensions de la matrice résultante sont définies par le nombre de lignes de la première matrice et le nombre de colonnes de la seconde matrice :

$$
C_{m \times p}, \quad m = \text{rows}_A, \quad p = \text{cols}_B
$$

4. **Calcul des éléments**  
   Pour chaque ligne $i$ et colonne $j$ :

$$
C_{i,j} = A_{\text{row } i} \cdot B^T_{\text{row } j}
$$

5. **Retourner la matrice résultat**  
   La fonction renvoie la nouvelle matrice $C$.

## Multiplication matrice × vecteur

1. **Vérification de compatibilité**  
   Le nombre d’éléments du vecteur doit être égal au nombre de colonnes de la matrice :

$$
\text{if } \text{len}(v) \neq \text{cols}_M \text{ then return } v
$$

2. **Création du vecteur résultat**  
   La multiplication produit un vecteur de $m$ composantes, où $m$ est le nombre de lignes de la matrice.

3. **Calcul de chaque composante**  
   Pour chaque ligne $i$ de la matrice :

$$
\text{result}[i] = M_{\text{row } i} \cdot v
$$

4. **Retourner le vecteur résultat**  
   La fonction renvoie le vecteur résultant.

> Ces étapes résument l’implémentation des opérations essentielles de notre classe `MatrixMN` : multiplication matrice × matrice et matrice × vecteur, avec toutes les vérifications nécessaires et en utilisant la transposition pour simplifier le produit scalaire.

