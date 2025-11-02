# Trouver y′ et démontrer la formule

Présentons étape par étape le raisonnement suivi.  
L’objectif est de déterminer la composante $y$ du vecteur après rotation.  

---

## Identifier la composante y sur le graphique

Sur le graphique, la composante y correspond à $BE$.  
Elle s’étend verticalement de B à E, et c’est précisément cette portion que nous cherchons à exprimer.  
Ainsi, $y' = BE$.  
Il est nécessaire de décomposer cette longueur en parties plus simples.  

---

## Décomposer B–E

On remarque que l’ensemble $BE$ peut s’écrire comme la somme des deux segments $BC$ et $CE$ :  
$$
BE = BC + CE
$$

Ainsi, $y' = BC + CE$.  
Cette expression est correcte, mais elle peut être simplifiée pour la démonstration.  

---

## Relier les côtés du rectangle

Dans la figure, le côté gauche $CE$ du rectangle est égal au côté droit $DF$, car ce sont des côtés opposés.  
Ainsi, $CE = DF$, et donc :  
$$
y' = BC + DF
$$

Notre tâche est maintenant de déterminer les valeurs de $BC$ et $DF$.  

---

## Trouver B–C

Concentrons-nous sur le segment $BC$.  
Dans le triangle correspondant, $BC$ est le côté adjacent à l’angle $\alpha$ et l’hypoténuse est $BD$.  
Donc :  
$$
\cos(\alpha) = \frac{BC}{BD}
$$

---

## Substituer avec les relations trigonométriques

Nous savons que $BD = r \sin(\beta)$.  
En remplaçant, on obtient :  
$$
\cos(\alpha) = \frac{BC}{r \sin(\beta)}
$$

---

## Résoudre pour B–C

En isolant $BC$ :  
$$
BC = r \cos(\alpha) \sin(\beta)
$$

Mais $x = r \cos(\alpha)$ (composante x originale).  
Donc :  
$$
BC = x \sin(\beta)
$$

---

## Résultat pour B–C

Nous avons trouvé que $BC = x \sin(\beta)$, le premier terme de notre expression pour $y'$.  

---

## Trouver D–F

Regardons maintenant le segment $DF$.  
Il est opposé à l’angle $\alpha$ dans le triangle concerné, avec l’hypoténuse $AD$ :  
$$
\sin(\alpha) = \frac{DF}{AD}
$$

---

## Utiliser le sinus de alpha

On sait que $AD = r \cos(\beta)$.  
En remplaçant :  
$$
\sin(\alpha) = \frac{DF}{r \cos(\beta)}
$$

---

## Résoudre pour D–F

En isolant $DF$ :  
$$
DF = r \sin(\alpha) \cos(\beta)
$$

Et puisque $y = r \sin(\alpha)$, on obtient :  
$$
DF = y \cos(\beta)
$$

---

## Résultat pour D–F

Nous avons maintenant notre deuxième terme : $DF = y \cos(\beta)$.  
En combinant les deux résultats :  
$$
y' = BC + DF = x \sin(\beta) + y \cos(\beta)
$$

---

## Formule finale pour y'

Ainsi, la formule finale est :  
$$
\boxed{y' = x \sin(\beta) + y \cos(\beta)}
$$

C’est la composante $y$ d’un vecteur après rotation d’un angle $\beta$.  

---

## Conclusion

Nous avons maintenant les deux formules fondamentales pour la rotation d’un vecteur dans le plan :  
$$
x' = x \cos(\beta) - y \sin(\beta)
$$

$$
y' = x \sin(\beta) + y \cos(\beta)
$$

Cette démonstration illustre comment les composantes d’un vecteur changent sous rotation en utilisant uniquement des relations trigonométriques élémentaires.  

---

## Réflexion

Comprendre cette dérivation est essentiel pour tout programmeur manipulant des transformations géométriques — jeux, physique ou 3D.  
Maîtriser ces bases renforce l’intuition mathématique et permet d’appréhender les transformations spatiales.  
La rotation d’un vecteur par un angle $\beta$ s’exprime naturellement par ces équations harmonieuses reliant cosinus et sinus.  
