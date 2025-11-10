# Introduction

Nous avons vu de nombreuses formules et dérivations simplement pour faire tourner des vecteurs autour de l’origine.  
Nous comprenons désormais pourquoi la formule pour les composantes $x$ et $y$ d’un vecteur après rotation est : cosinus, moins sinus, sinus, cosinus.  
En termes théoriques, nous maîtrisons maintenant les deux formules pour les composantes $x$ et $y$ après rotation.  

---

## Mettre la théorie en pratique

Passons à l’application pratique.  
Nous allons faire tourner un vecteur 2D en utilisant ses deux composantes.  
La fonction a déjà été implémentée dans notre code source et nous allons en analyser le fonctionnement.  

---

## Vue d’ensemble de la fonction de rotation

La fonction applique directement les formules cosinus et sinus que nous avons démontrées.  
Après le travail théorique, la fonction est concise et efficace.  

---

## Explication ligne par ligne du code

Nous avons une classe `Vector2` avec ses méthodes habituelles.  
Après la méthode de normalisation, j’ai ajouté une méthode `rotate`.  

---

## Définition de la fonction rotate

La méthode `rotate` prend un angle en paramètre et fait tourner le vecteur de cette quantité.  
Le vecteur original n’est pas modifié ; un nouveau vecteur est créé et retourné.  

---

## Retourner un vecteur rotaté

La fonction crée un vecteur vide pour stocker le résultat et retourne ce nouveau vecteur.  
Les coordonnées du vecteur original restent inchangées.  

---

## Calcul des nouvelles composantes

Le nouveau $x$ du vecteur rotaté est calculé avec :  
$$
x' = x \cos(\theta) - y \sin(\theta)
$$  
où $x$ et $y$ sont les composantes originales et $\theta$ l’angle passé en paramètre.  

---

## La composante Y (y′)

La nouvelle composante $y$ est :  
$$
y' = x \sin(\theta) + y \cos(\theta)
$$  
Ces formules sont exactement celles que nous avons dérivées précédemment.  

---

## Limitation à des vecteurs 2D

La méthode `rotate` est actuellement implémentée pour `Vector2` uniquement, ce qui permet de faire tourner des vecteurs en 2D.  

---

## Tester la fonction de rotation

Pour tester :  
- Position initiale : $\vec{p} = (100, 0)$  
- Angle initial très petit, par exemple 0.01 rad  
Dans la fonction `draw`, on crée un vecteur rotaté à partir de la position initiale et on incrémente l’angle à chaque frame.  

---

## Application de la rotation dans la fonction draw

À chaque frame :  
1. Créer un vecteur rotaté à partir de la position initiale et de l’angle courant  
2. Dessiner ce vecteur  
3. Incrémenter l’angle pour la frame suivante  

---

## Rotation continue sur les frames

L’angle est incrémenté progressivement (par ex. 0.03 ou 0.05 rad par frame), permettant une rotation continue.  
Le vecteur initial reste inchangé, seul le vecteur rotaté est utilisé pour le dessin.  

---

## Déplacement de l’origine au centre du canvas

Pour mieux visualiser la rotation, on utilise `translate()` de P5.js :  

```js
translate(width/2, height/2);
```
Cela déplace l’origine du canvas vers le centre de l’écran.  

---

## Confirmation visuelle

Après translation, le vecteur rotaté tourne correctement autour du centre du canvas.  
L’incrément de l’angle détermine la vitesse de rotation.  

---

## Comprendre les unités d’angle

Les angles sont en radians, pas en degrés.  
Un incrément de 0.05 correspond à un petit pas dans l’intervalle $[0, 2\pi]$ pour une rotation complète (360°).  

---

## Remarques finales

En résumé :  
- Utilisation des formules trigonométriques dérivées pour calculer les nouvelles composantes  
- Le vecteur original reste inchangé, un nouveau vecteur rotaté est retourné  
- L’origine peut être déplacée au centre du canvas pour meilleure visualisation  
- Les angles sont en radians, avec un incrément progressif pour rotation fluide  
