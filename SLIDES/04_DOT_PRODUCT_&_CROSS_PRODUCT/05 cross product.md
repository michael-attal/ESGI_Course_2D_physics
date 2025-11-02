# Introduction à la Multiplication de Vecteurs

Nous avons appris qu’il existe plusieurs façons d’interpréter la multiplication de vecteurs.  
Une de ces façons est le **produit scalaire (dot product)**, que nous avons déjà étudié, donnant un résultat scalaire.

---

## Le Produit Vectoriel (Cross Product)

L’autre interprétation est le **produit vectoriel (cross product)**.  
Contrairement au produit scalaire qui donne un scalaire, le produit vectoriel produit un **vecteur**.  
Si nous faisons $\vec A × \vec B$, le résultat est un nouveau vecteur.

---

## Définition et Dimension

Le produit vectoriel est défini uniquement en **trois dimensions** avec les composantes x, y et z.  
Il n’existe pas de définition formelle pour des vecteurs à deux composantes.

---

## Le Plan Délimité par Deux Vecteurs

Si nous avons les vecteurs $\vec A$ et $\vec B$, on peut former un **plan** entre eux.  
Le vecteur résultat du produit vectoriel est **perpendiculaire** à ce plan et à $\vec A$ et $\vec B$.  
C’est ce que l’on appelle le **vecteur normal**.

---

## Magnitude et Signification Géométrique

La **longueur** (magnitude) du vecteur résultant correspond à **l’aire du parallélogramme** formé par $\vec A$ et $\vec B$.

---

## Calcul des Composantes

Pour le produit vectoriel $\vec A × \vec B$, les composantes sont :  

Pour $x$ :  
$$x = A_y \times B_z - A_z \times B_y$$  

Pour $y$ :  
$$y = A_z \times B_x - A_x \times B_z$$  

Pour $z$ :  
$$z = A_x \times B_y - A_y \times B_x$$  

Chaque composante est calculée à partir des deux autres composantes, avec **soustraction**.

---

## Note d’Implémentation

Le produit vectoriel se calcule par une fonction qui retourne un **nouveau vecteur normal** entre A et B.

---

## Non-Commutativité

L’ordre des vecteurs est important :  
$$\vec A × \vec B ≠ \vec B × \vec A$$  
La direction du vecteur normal dépend de l’ordre de $\vec A$ et $\vec B$.

---

## Intuition Visuelle

Le vecteur normal (produit vectoriel) est perpendiculaire au plan formé par $\vec A$ et $\vec B$.  
Si $\vec A$ et $\vec B$ sont parallèles ou opposés, le produit vectoriel est nul.  
La magnitude dépend de l’aire du parallélogramme :  
$$\|\vec A × \vec B\| = \|\vec A\| \times \|\vec B\| \times \sin(\theta)$$  
où $$\theta$$ est l’angle entre $\vec A$ et $\vec B$.

---

## Résumé

Le **produit vectoriel (cross product)** entre $\vec A$ et $\vec B$ :  
- est perpendiculaire à $\vec A$ et $\vec B$,  
- a une magnitude proportionnelle à l’aire du parallélogramme formé par $\vec A$ et $\vec B$,  
- et sa direction dépend de l’ordre des vecteurs.

---

## Étape Suivante

Implémenter la méthode **cross product** dans notre classe de vecteurs.
