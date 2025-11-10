# Introduction au Dot Product et sa Commutativité

Avant de passer à autre chose, il est utile de se demander : que se passe-t-il si on inverse l’ordre des vecteurs dans le produit scalaire ?  
Autrement dit, si au lieu de $\vec A \cdot \vec B$ on calcule $\vec B \cdot \vec A$, le résultat change-t-il ?

---

## Commutativité du Produit Scalaire

Le produit scalaire est commutatif :  
$$
A \cdot B = B \cdot A
$$

En effet, la multiplication et l’addition utilisées dans le calcul sont toutes deux commutatives.  
Ainsi, l’ordre des vecteurs n’affecte pas le résultat du *dot product*.

---

## Implémentation dans le Code

On peut implémenter une méthode `dot` dans notre classe vecteur :  
- Elle reçoit un vecteur en paramètre  
- Calcule le produit scalaire avec le vecteur courant : $x_1 \cdot x_2 + y_1 \cdot y_2$  
- Retourne un scalaire (nombre flottant)

---

## Applications du Dot Product

Le produit scalaire est largement utilisé en :  
- Graphismes informatiques : calcul des projections et éclairages  
- Simulations physiques : forces, orientations  
- Analyse d’alignement entre vecteurs  

Ces applications seront détaillées dans des exemples pratiques.

---

## Expression Mathématique

Pour deux vecteurs A et V :  
$$
\vec A \cdot \vec V = A_x \cdot V_x + A_y \cdot V_y
$$

La valeur retournée est un scalaire représentant le résultat du dot product.

---

## Conclusion

La méthode `dot` renvoie simplement la valeur $x_1 \cdot x_2 + y_1 \cdot y_2$, confirmant la simplicité numérique derrière le concept mathématique du produit scalaire.
