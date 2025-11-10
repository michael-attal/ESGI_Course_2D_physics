### Introduction à la Multiplication de Vecteurs

Nous avons appris l’addition, la soustraction et la mise à l’échelle de vecteurs.  

Mais qu’en est-il de la multiplication entre vecteurs ?  

Peut-on multiplier deux vecteurs pour obtenir un produit vectoriel ou scalaire ?

---

## Le Produit Scalaire (Dot Product)

La première forme de multiplication que nous rencontrons est le produit scalaire, aussi appelé *dot product*.  

Mathématiciens et programmeurs utilisent ces termes de manière interchangeable.  

Le **produit scalaire** retourne un nombre, pas un vecteur.

---

## Compréhension Visuelle du Produit Scalaire

Le *dot product* peut être compris comme la projection d’un vecteur $\vec B$ sur un vecteur $\vec A$.  

La valeur résultante est un scalaire (nombre), représentant combien $\vec B$ est aligné avec $\vec A$.

#TODO illustration

---

## Intuition de l’Alignement

- Si $\vec A$ et $\vec B$ pointent dans la même direction : dot product maximal ($1.0$ si vecteurs unitaires)  
- Si $\vec A$ et $\vec B$ sont perpendiculaires : dot product = $0$  
- Si $\vec A$ et $\vec B$ dépassent 90° : dot product négatif  

Le dot product mesure donc l’alignement relatif entre deux vecteurs.

---

## Propriété de l’Orthogonalité

Deux vecteurs perpendiculaires ont un produit scalaire nul, car il n’y a pas de projection de l’un sur l’autre.

---

### Formule du Dot Product en 2D

Pour deux vecteurs A et B :  
$$
\vec A \cdot \vec B = A_x \cdot B_x + A_y \cdot B_y
$$

Cette formule fournit directement la valeur scalaire du dot product.

---

## Généralisation à N Dimensions

En 3D :  
$$
\vec A \cdot \vec B = A_x \cdot B_x + A_y \cdot B_y + A_z \cdot B_z
$$

La règle est la même pour plus de dimensions : on additionne les produits des composantes correspondantes.

---

# Conclusion

Le produit scalaire est une mesure de l’alignement entre vecteurs :  
- Parfaitement alignés : $1.0$  
- Perpendiculaires : $0$  
- Plus de $90°$ : valeur négative  

Le dot product reste un scalaire et est utilisé pour évaluer la projection ou l’orientation relative de vecteurs.
