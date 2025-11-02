

## Vue d'Ensemble de la Solution

La solution est très simple : pour trouver un vecteur perpendiculaire à un vecteur `(x, y)`, il suffit d'inverser les composants et de négativer l'un d'eux.

---

## Implémentation

On crée un nouveau vecteur avec :  
- x du vecteur perpendiculaire = y du vecteur original  
- y du vecteur perpendiculaire = -x du vecteur original  

Cette transformation garantit que le vecteur résultant est perpendiculaire à l'original.

---

## Explication

On échange simplement les composants et on négative l'un d'eux pour respecter l'orientation et les quadrants.

---

## Terminologie

Ce vecteur perpendiculaire est parfois appelé **normal** par certains programmeurs.  
Il s'agit d'un vecteur formant un angle de 90° avec le vecteur original.

---

## Conclusion

En résumé, le vecteur perpendiculaire `(y, -x)` est simple à calculer et assure une orthogonalité parfaite avec le vecteur original.
