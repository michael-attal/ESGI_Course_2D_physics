# Calcul explicite de la matrice jacobienne

## Rappel de l’objectif
On étudie une transformation non linéaire du plan, et l’on a montré que, lorsqu’on zoome autour d’un point donné, cette transformation ressemble de plus en plus à une transformation linéaire. Cette transformation linéaire locale est décrite par une matrice obtenue à partir des dérivées partielles de la fonction : la matrice jacobienne.

L’objectif ici est de calculer explicitement ces dérivées partielles et de construire la matrice correspondante.

---

## Rappel de la fonction
La fonction considérée est définie par :
$$
f(x,y) =
\begin{pmatrix}
x + \sin(y) \\
y + \sin(x)
\end{pmatrix}
$$
On identifie à nouveau les deux composantes scalaires :
$$
f_1(x,y) = x + \sin(y), \quad f_2(x,y) = y + \sin(x)
$$

---

## Calcul des dérivées partielles
On calcule successivement toutes les dérivées partielles nécessaires à la construction de la matrice jacobienne.

- Dérivée partielle de $f_1$ par rapport à $x$ :
$$
\frac{\partial f_1}{\partial x} = 1
$$
Le terme $x$ donne 1, et $\sin(y)$ est constant par rapport à $x$.

- Dérivée partielle de $f_2$ par rapport à $x$ :
$$
\frac{\partial f_2}{\partial x} = \cos(x)
$$
Le terme $y$ est constant, et la dérivée de $\sin(x)$ est $\cos(x)$.

- Dérivée partielle de $f_1$ par rapport à $y$ :
$$
\frac{\partial f_1}{\partial y} = \cos(y)
$$
Le terme $x$ disparaît, et la dérivée de $\sin(y)$ est $\cos(y)$.

- Dérivée partielle de $f_2$ par rapport à $y$ :
$$
\frac{\partial f_2}{\partial y} = 1
$$
Le terme $y$ donne 1, et $\sin(x)$ est constant par rapport à $y$.

---

![[medias/04 calcul explicite de la matrice jacobienne-20260102.png]]

---

## Jacobienne générale
En regroupant ces dérivées partielles, on obtient la matrice jacobienne générale, valable pour tout point $(x,y)$ :
$$
J_f(x,y) =
\begin{pmatrix}
1 & \cos(y) \\
\cos(x) & 1
\end{pmatrix}
$$

---

## Évaluation au point $(-2,1)$
Pour comprendre la transformation linéaire locale autour du point étudié, on évalue cette matrice en $(-2,1)$ :
$$
J_f(-2,1) =
\begin{pmatrix}
1 & \cos(1) \\
\cos(-2) & 1
\end{pmatrix}
$$

Numériquement :
$$
\cos(-2) \approx -0.42, \quad \cos(1) \approx 0.54
$$

On obtient donc la matrice :
$$
J_f(-2,1) \approx
\begin{pmatrix}
1 & 0.54 \\
-0.42 & 1
\end{pmatrix}
$$

---

## Interprétation géométrique
Cette matrice décrit la transformation linéaire qui approxime la fonction originale lorsqu’on zoome autour du point $(-2,1)$.

- La première colonne indique l’image locale du premier vecteur de base $(1,0)$. On observe une composante horizontale de taille 1 et une composante verticale négative d’environ $-0.42$.
- La seconde colonne indique l’image locale du second vecteur de base $(0,1)$. Sa composante verticale reste de taille 1, tandis que sa composante horizontale est d’environ $0.54$.

Ces valeurs sont cohérentes avec l’observation visuelle de la déformation locale du quadrillage autour du point considéré.

---

## Conclusion
Le calcul de la matrice jacobienne est une procédure directe : il suffit de calculer toutes les dérivées partielles des composantes de la fonction et de les organiser dans une matrice. Cette matrice fournit une description précise de la transformation linéaire locale associée à une fonction non linéaire, et constitue un outil central de l’analyse multivariée.
