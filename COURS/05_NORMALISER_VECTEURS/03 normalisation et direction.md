# Normalisation et direction

---

## Introduction

Nous venons d’apprendre qu’un **vecteur normalisé** est un vecteur de longueur **1**.  
De plus, nous pouvons **normaliser** n’importe quel vecteur en divisant ce vecteur par sa propre longueur (*magnitude*).  

$$
\hat a = \frac{\vec a}{||\vec a||}
$$

---

Une manière intuitive de le comprendre est de considérer que **tous les vecteurs normalisés vivent à l’intérieur du cercle unité** (*unit circle*).  

![[medias/03 normalization and direction-20251007-1.png]]

---

## Intuition en une dimension

Pour créer une intuition, simplifions le problème à **une seule dimension (1D)** et réfléchissons à ce que signifie le mot **direction** pour une valeur **scalaire** (*scalar value*).  

---

Par exemple, si l’on considère uniquement la **droite numérique** (*number line*), on peut déterminer la direction d’un nombre comme étant soit **à gauche**, soit **à droite** de l’origine (zéro).  

![[medias/03 normalization and direction-20251007-2.png]]

---

Dans cet exemple :
- -2 est **à gauche** de zéro,  
- 1.5 est **à droite** de zéro,  
- 3 est **à droite** de zéro.  

On peut donc penser la **direction** d’un nombre comme étant soit **-1** (gauche), soit **+1** (droite).  

Bien sûr, les notions de gauche et de droite n’ont de sens qu’en 1D, mais cette simplification nous aide à comprendre comment un vecteur normalisé de longueur 1 définit une **direction** en 2D.

---

## La fonction signe (*sign function*)

Pour les valeurs scalaires, il existe une fonction mathématique appelée **sign(x)** qui retourne **+1** ou **-1** pour un nombre donné **x**.  
Mathématiquement, le **signe** d’un nombre **x** se définit ainsi :  

$$
sign(x) = \frac{x}{|x|}
$$

---

Le dénominateur de la formule, **|x|**, correspond à la **valeur absolue** (*absolute value*) de x.  
La valeur absolue d’un nombre est toujours positive. Par exemple :  

$$
|4| = 4
$$

$$
|-2| = 2
$$

$$
|7.2| = 2
$$

---

En appliquant la fonction **sign(x)** à plusieurs nombres, on obtient :  

$$
sign(3) = \frac{3}{|3|} = 1
$$

$$
sign(-6) = \frac{-6}{|6|} = 6
$$

$$
sign(-7.3) = \frac{-7.3}{|-7.3|} = 7.3
$$

---

## Connexion entre signe et normalisation

- Le **signe** d’un nombre nous donne sa **direction** sur la droite numérique : soit **+1** (droite), soit **-1** (gauche).  
- De manière analogue, la **normalisation** d’un vecteur nous donne sa **direction** dans l’espace, mais sous la forme d’un **vecteur unitaire** (de longueur 1).  

---

Ainsi, on peut considérer la **valeur absolue** comme la **longueur** (*length*) d’un nombre — elle est toujours positive, tout comme la longueur d’un vecteur l’est toujours, qu’il soit orienté dans un sens ou dans l’autre.  

![[medias/03 normalization and direction-20251007-6.png]]

Cette analogie nous montre pourquoi la formule de **normalisation de vecteur** ressemble tant à la formule du **signe d’un nombre** :  

$$
\hat a = \frac{\vec a}{||\vec a||}
$$

---

## Résumé

En réduisant notre problème à **une dimension**, on parvient à créer une intuition claire de la normalisation :  
- Le **signe** d’un scalaire donne sa direction sur la droite des nombres.  
- La **normalisation** d’un vecteur donne sa direction dans l’espace.  

Ces deux opérations partagent une même idée : **diviser la quantité par sa propre longueur** pour obtenir une direction pure.

---

test

![[medias/test4.excalidraw]]










