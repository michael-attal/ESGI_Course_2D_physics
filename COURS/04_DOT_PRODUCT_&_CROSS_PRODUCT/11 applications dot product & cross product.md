# Exemples d’Utilisation du Produit Scalaire et du Produit Vectoriel

Je souhaite rapidement contextualiser et montrer quelques exemples où le produit scalaire (*dot product*) et le produit vectoriel (*cross product*) peuvent être utiles pour les programmeurs.

---

## Jeu Vidéo 2D : Optimisation du Rendu

Par exemple, imaginons que nous devons développer un jeu où un joueur se déplace sur une carte 2D.  

En tant que programmeurs de jeux, nous devons toujours garder un œil sur les performances. Il est judicieux d’éviter de rendre inutilement des objets qui ne devraient pas être affichés pour améliorer la vitesse du jeu.  

Par exemple, si un ennemi est derrière un mur, il ne faut **pas** dessiner cet ennemi.  
Ces techniques font partie de ce que l’on appelle la “suppression des surfaces cachées” (*hidden-surface removal*).

---

## Détermination des Murs Visibles

Une technique consiste à ignorer le rendu des murs tournés “à l’opposé” du joueur.  
Pour cela, on calcule le vecteur **normal** (perpendicular) de chaque mur, puis on le compare au vecteur représentant la direction du joueur.  

Une fois que nous avons un vecteur normal pour chaque mur et un vecteur pour la direction du joueur, comment déterminer quels murs sont tournés à l’opposé du joueur ?  

---

La réponse réside dans le **produit scalaire**.  
En calculant le produit scalaire du vecteur normal du mur avec le vecteur de direction du joueur, nous pouvons déterminer à quel point ces vecteurs sont “alignés”.  

Si le produit scalaire est positif ou négatif, nous savons si les vecteurs se font face ou sont opposés, ce qui permet de décider quels murs **ne doivent pas** être rendus.

Cette technique est applicable en 2D comme en 3D.  
Dans les moteurs 3D, on parle souvent de **back-face culling**, où les faces triangulaires orientées à l’opposé de la caméra sont ignorées.

---

## Produit Vectoriel pour les Objets 3D

Pour les objets 3D, le **produit vectoriel** est très utile.  
Les maillages 3D complexes sont souvent constitués de triangles.  

Une tâche courante consiste à calculer le vecteur normal de chaque face triangulaire du maillage.  
On peut obtenir ce vecteur normal en calculant le **produit vectoriel** entre les vecteurs $\vec B- \vec A$ et $\vec C- \vec A$ pour un triangle formé par les sommets $A$, $B$ et $C$.  
Le résultat est un vecteur perpendiculaire (90 degrés) à la surface du triangle.

---

## Conclusion

Ces exemples illustrent comment le produit scalaire et le produit vectoriel sont utiles pour les programmeurs.  
Au fur et à mesure du cours, nous verrons de nombreuses autres applications, notamment dans le contexte des moteurs physiques.
