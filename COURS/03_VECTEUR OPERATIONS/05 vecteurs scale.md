### Introduction à la Mise à l'Échelle des Vecteurs

Nous avons déjà parlé de l’**addition** et de la **soustraction** de vecteurs. Une autre opération très courante en programmation est la **mise à l’échelle d’un vecteur**.

---

## Concept de Mise à l'Échelle

La mise à l’échelle consiste à **agrandir ou réduire** un vecteur.  

Concrètement, on multiplie chaque composante du vecteur par un **scalaire** (un nombre).  

Ainsi, la taille du vecteur change sans modifier sa direction.

---

### Multiplication par un Scalaire

Si mon vecteur original est $(10, 10)$ et que je le multiplie par un scalaire $2.0$, je double sa taille : $(20, 20)$.  

De la même manière, multiplier par $0.1$ réduit le vecteur à $10\%$ de sa taille originale.  

Multiplier par des scalaires plus grands ou plus petits permet d’**agrandir ou de réduire** le vecteur à volonté.

---

### Mise à l'Échelle Négative (Inversion de Vecteur)

Multiplier un vecteur par un scalaire négatif **inverse sa direction**.  

Exemple : $(10, 10)$ multiplié par $-1$ devient $(-10, -10)$.  

On peut ainsi **inverser ou retourner un vecteur** facilement.

---

## Exemple d'Implémentation

Dans une classe `Vector`, on peut créer une méthode `scale(scalar)` qui multiplie `x` et `y` par ce scalaire.  

Ainsi, `position.scale(3.0)` multiplie chaque composante de `position` par $3$.

---

## Exemple Pratique

Si le vecteur initial est $(10, 20)$ et que l’on applique `scale(2)`, on obtient $(20, 40)$.  

Appliquer successivement `scale(3)` puis `scale(5)` augmente progressivement la taille du vecteur.

---

## Applications de la Mise à l'Échelle

- Agrandir ou réduire la **vitesse** d’un objet.  
- Ajuster des forces dans une simulation physique.  
- Inverser la direction d’un vecteur via un scalaire négatif.  

Ces opérations sont fondamentales pour manipuler des vecteurs dans la programmation graphique et les moteurs physiques.
