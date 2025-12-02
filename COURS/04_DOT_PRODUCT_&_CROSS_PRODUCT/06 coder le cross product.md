# Introduction à l’Implémentation du Produit Vectoriel

Nous avons appris comment calculer les composantes $x$, $y$ et $z$ du produit vectoriel.  
Pour l’implémenter, il faut créer une classe de vecteur 3D, car le produit vectoriel n’est pas défini pour deux dimensions.

---

## Configuration de la Classe Vecteur

Créer une classe `Vector` avec un constructeur recevant `x`, `y` et `z`.  
Les propriétés `x`, `y` et `z` sont initialisées avec ces valeurs.  
Nous voulons maintenant ajouter une méthode pour calculer le produit vectoriel entre ce vecteur et un autre vecteur.

---

## Type de Retour et Implémentation

Le produit vectoriel retourne un **nouveau vecteur**.  
En JavaScript, aucun type de retour n’est requis, mais il faut créer un nouvel objet vecteur.  
Exemple : `let result = new Vector3();`  
Puis assigner `result.x`, `result.y` et `result.z` avec les formules du produit vectoriel et retourner `result`.

---

## Calcul des Composantes

### Composante X
$$x = A_y \times B_z - A_z \times B_y$$  
`result.x = this.y * v.z - this.z * v.y`

### Composante Y
$$y = A_z \times B_x - A_x \times B_z$$  
`result.y = this.z * v.x - this.x * v.z`

### Composante Z
$$z = A_x \times B_y - A_y \times B_x$$  
`result.z = this.x * v.y - this.y * v.x`

Chaque composante est calculée à partir des deux autres composantes du produit vectoriel.

---

## Résumé et Étapes Suivantes

Le produit vectoriel entre un vecteur et un autre retourne un **vecteur normal** avec les composantes calculées selon les formules précédentes.  
Les prochaines activités consisteront à pratiquer et appliquer les concepts de produit scalaire et produit vectoriel dans des exemples concrets.
