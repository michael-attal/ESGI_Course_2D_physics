## Jacobian Determinant — Geometric and Computational Interpretation

### 1. Rappel : déterminant en algèbre linéaire (determinant)
En algèbre linéaire classique, le **déterminant** (*determinant*) d’une matrice carrée $2\times2$ se calcule à partir des produits diagonaux.  
Pour une matrice :
$$
\begin{pmatrix}
a & b \\
c & d
\end{pmatrix}
$$
le déterminant vaut $ad - bc$.  

Au-delà du calcul formel, le déterminant possède une **interprétation géométrique fondamentale**.  
Il mesure le **facteur de changement d’aire** (*area scaling factor*) induit par la transformation linéaire associée à la matrice.  
Si l’on applique cette transformation au **carré unité** (*unit square*), d’aire égale à $1$, l’aire du parallélogramme obtenu est égale à la valeur absolue du déterminant.  

Ainsi, le déterminant encode la manière dont une transformation **étire** (*stretch*) ou **écrase** (*squish*) l’espace.  

---

![[medias/jaco03.gif]]

---

### 2. Passage aux fonctions de plusieurs variables (multivariable functions)
Considérons une fonction à deux variables :
$$
F(x,y) = \big(F_1(x,y), F_2(x,y)\big)
$$
avec, dans l’exemple étudié :
$$
F_1(x,y) = x + \sin(y), \quad F_2(x,y) = y + \sin(x)
$$
Cette fonction est **non linéaire** (*non-linear*). Elle déforme l’espace de manière courbe et complexe.  
Cependant, lorsqu’on **zoome localement** autour d’un point donné, la transformation devient **approximativement linéaire** (*locally linear*).  

Cette approximation locale est décrite par la **matrice jacobienne** (*Jacobian matrix*).  

---

### 3. La matrice jacobienne (Jacobian matrix)
La **matrice jacobienne** regroupe toutes les **dérivées partielles** (*partial derivatives*) de la fonction :
$$
J_F(x,y) =
\begin{pmatrix}
\frac{\partial F_1}{\partial x} & \frac{\partial F_1}{\partial y} \\
\frac{\partial F_2}{\partial x} & \frac{\partial F_2}{\partial y}
\end{pmatrix}
$$

Dans notre cas :
- $\frac{\partial F_1}{\partial x} = 1$
- $\frac{\partial F_1}{\partial y} = \cos(y)$
- $\frac{\partial F_2}{\partial x} = \cos(x)$
- $\frac{\partial F_2}{\partial y} = 1$

La jacobienne est donc une **fonction à valeurs matricielles** (*matrix-valued function*), dépendant de $x$ et $y$.  
Évaluée en un point précis, elle devient une matrice numérique décrivant la transformation linéaire locale.  

![[medias/05 le déterminant jacobien-20260102.png]]


---

### 4. Déterminant jacobien (Jacobian determinant)
Le **déterminant de la matrice jacobienne**, appelé **déterminant jacobien** (*Jacobian determinant*), mesure le **facteur de variation locale des aires** (*local area scaling*).  

Dans notre exemple :
$$
\det(J_F)(x,y) = 1 \cdot 1 - \cos(x)\cos(y) = 1 - \cos(x)\cos(y)
$$

Ce déterminant répond à une question centrale du calcul différentiel multivarié :  
> *Localement, la transformation dilate-t-elle ou contracte-t-elle l’espace, et dans quelle proportion ?*  

---

### 5. Évaluation en un point : cas $(-2,1)$
En évaluant au point $(x,y)=(-2,1)$ :
- $\cos(-2) \approx -0.42$
- $\cos(1) \approx 0.54$

On obtient :
$$
\det(J_F)(-2,1) = 1 - (-0.42 \times 0.54) \approx 1.227
$$

Cela signifie que, **localement**, les aires sont **agrandies** (*expanded*) d’un facteur d’environ $1.227$.  
Visuellement, on observe effectivement une légère dilatation de la région étudiée.  

---

### 6. Évaluation en un point : cas $(0,1)$
Si l’on évalue maintenant au point $(x,y)=(0,1)$ :
- $\cos(0) = 1$
- $\cos(1) \approx 0.54$

On obtient :
$$
\det(J_F)(0,1) = 1 - (1 \times 0.54) = 0.46
$$

Le déterminant est **strictement inférieur à $1$**, ce qui indique une **contraction locale des aires** (*area contraction*).  
Les régions proches de ce point sont donc **écrasées** par la transformation, ce qui correspond à l’observation visuelle.  

---

### 7. Interprétation globale
Le **déterminant jacobien** fournit une mesure synthétique du comportement local d’une transformation non linéaire.  
Il permet de déterminer :
- si l’espace est localement **dilaté** ou **contracté**,
- et **dans quelle proportion** les aires sont modifiées.

C’est un outil central du **calcul différentiel multivarié**, notamment pour :
- les changements de variables,
- l’analyse géométrique des transformations,
- et les applications en sciences de l’image et en calcul scientifique.  


