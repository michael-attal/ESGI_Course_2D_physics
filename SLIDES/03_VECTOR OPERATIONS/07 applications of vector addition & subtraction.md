# Comprendre la Soustraction de Vecteurs

Nous avons appris à additionner des vecteurs et à les soustraire.  
L'addition est intuitive : si l'on considère les vecteurs $\vec A$ et $\vec B$ comme des mouvements linéaires, on effectue le mouvement $\vec A$, puis $\vec B$, et on obtient le vecteur résultant $A\vec  + \vec B$.

---

## Pourquoi la Soustraction est Plus Complexe

La soustraction de vecteurs est moins intuitive.  
Elle devient pertinente lorsqu'on cherche le vecteur reliant deux positions, par exemple dans un programme ou un moteur de jeu.

---

## Exemple en 2D

Dans un espace 2D, on peut avoir les positions de deux vecteurs : $\vec A$ et $\vec C$.  
Ces vecteurs peuvent représenter la position d’un joueur, d’un ennemi ou d’un projectile.

---

## De la Caméra à l’Objet

Pour obtenir le vecteur allant de la caméra ($C$) vers un objet ($A$), on calcule $A - C.$  
Ce vecteur résultant indique la direction et la distance entre les deux positions.

---

## Généralisation en 3D

Les mêmes principes s’appliquent en 3D.  
Chaque objet dans un moteur 3D a une position, et l’on peut soustraire la position de la lumière de celle d’un objet pour obtenir un vecteur directionnel.

---

## Exemple avec Lumière et Objet

Si l’objet est à `object_position` et la lumière à `light_position`, alors le vecteur directionnel est `object_position - light_position`.  
Cette opération retourne le vecteur allant de la source lumineuse vers l’objet dans l’espace 3D.

---

## Généralisation Dimensionnelle

Ces opérations sont valides pour des vecteurs de $n$ dimensions.  
En 3D, on soustrait $x$, $y$ et $z$ ; en 4D, $x$, $y$, $z$ et $w$, etc.  
La règle de l’addition et de la soustraction des composantes reste la même.

---

## Mise à l’Échelle

De même, la mise à l’échelle d’un vecteur par multiplication par un scalaire fonctionne pour des vecteurs 2D, 3D, 4D ou plus.

---

## Résumé

La soustraction de vecteurs est principalement utilisée pour obtenir le vecteur allant d’une position de départ à une position finale.  
Exemples : ennemi - joueur, caméra - ennemi, balle - ennemi.  
Ces opérations permettent de déterminer direction et distance dans des systèmes 2D, 3D ou plus.
