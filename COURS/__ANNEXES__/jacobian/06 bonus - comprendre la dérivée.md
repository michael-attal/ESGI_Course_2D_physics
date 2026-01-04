## Derivatives, Linear Maps, and Change of Variables — Detailed Explanation

### 1. Limites de l’intuition classique
Lorsqu’on introduit les **dérivées** (*derivatives*), elles sont souvent associées à la **pente d’une tangente** à une courbe.  
Pour une fonction $f : \mathbb{R} \to \mathbb{R}$, la dérivée en un point $a$, notée $f'(a)$, est la pente de la tangente au graphe de $f$ en $a$.  

Cette intuition fonctionne bien en 1D, mais elle devient **inapplicable** pour les fonctions multivariables.  
Si $f : \mathbb{R}^2 \to \mathbb{R}^2$, il faudrait quatre dimensions pour représenter le graphe.  
La notion classique de "pente" n’a donc plus de sens.  

De même, les **intégrales** sont souvent vues comme des **aires sous une courbe**.  
En plusieurs dimensions, cette intuition devient insuffisante car il faut considérer **des volumes ou des surfaces**.

Pour généraliser dérivées et intégrales, il est essentiel de passer par le concept de **linear maps** (*applications linéaires*).

---

### 2. Applications linéaires en 2D
Une application linéaire $L : \mathbb{R}^2 \to \mathbb{R}^2$ doit vérifier trois propriétés :

1. **Parallélisme préservé** : les lignes parallèles restent parallèles.  
2. **Espacements uniformes** : des lignes équidistantes restent équidistantes après transformation.  
3. **Origine fixe** : le point $(0,0)$ reste invariant.

Ces applications sont entièrement déterminées par l’image des vecteurs de base $(1,0)$ et $(0,1)$ :  
$$
L(1,0) = (x_{1,0}, y_{1,0}), \quad L(0,1) = (x_{0,1}, y_{0,1})
$$

On peut représenter ces informations par une **matrice** :
$$
A = 
\begin{pmatrix}
x_{1,0} & x_{0,1} \\
y_{1,0} & y_{0,1}
\end{pmatrix}
$$

Le **déterminant** de cette matrice, $\det(A)$, correspond au **facteur de mise à l’échelle des aires**.  
Si la transformation inclut une **réflexion**, le déterminant est négatif, indiquant un **changement d’orientation**.

En 1D, les applications linéaires deviennent des **scalings**, et le déterminant correspond simplement au facteur de mise à l’échelle des longueurs.

---

### 3. Dérivée comme approximation linéaire
Pour une fonction 1D $f : \mathbb{R} \to \mathbb{R}$ et un point $a$, on peut **zoomer** sur un voisinage de $a$.  
Le comportement de $f$ devient alors **approximativement linéaire** :  
$$
f(x) \approx f(a) + f'(a)(x-a)
$$  
La dérivée $f'(a)$ représente le **facteur de mise à l’échelle local**.  

Exemple : si $f$ multiplie les distances par $3$ près de $a$, alors $f'(a) = 3$.  
Si $f$ inverse la direction, $f'(a)$ peut être négatif.

---

### 4. Matrice jacobienne pour fonctions multivariables
Pour $f : \mathbb{R}^2 \to \mathbb{R}^2$, $f(x,y) = (f_1(x,y), f_2(x,y))$, le **voisinage de $(a,b)$** peut être approximé par une application linéaire.  

La **matrice jacobienne** (*Jacobian matrix*) est :
$$
J_f(a,b) =
\begin{pmatrix}
\frac{\partial f_1}{\partial x}(a,b) & \frac{\partial f_1}{\partial y}(a,b) \\
\frac{\partial f_2}{\partial x}(a,b) & \frac{\partial f_2}{\partial y}(a,b)
\end{pmatrix}
$$

- Chaque dérivée partielle indique **l’effet local d’une variable sur une composante** de $f$.  
- Les colonnes correspondent aux images des vecteurs de base sous l’approximation linéaire locale.

Le **déterminant jacobien** :
$$
\det(J_f(a,b))
$$
mesure la **dilatation ou contraction des aires locales** autour de $(a,b)$.

---

### 5. Calcul des dérivées partielles pour la jacobienne
Pour chaque colonne de $J_f(a,b)$ :
1. Fixer l’une des variables et considérer la variation de l’autre.  
2. Calculer la **dérivée 1D correspondante** pour obtenir les entrées de la colonne.  

Ainsi, le jacobien généralise le concept de **dérivée en 1D** à plusieurs dimensions.

---

### 6. Intégrales multivariables et densité
Pour une densité $f(x)$ sur une tige 1D, la **masse** est :
$$
M = \int_a^b f(x) \, dx
$$
En découpant en petits segments $\Delta x$, on approxime la masse par :
$$
f(x^*) \Delta x
$$
et on somme.

En 2D, pour une région $D$ avec densité $f(x,y)$ :
$$
M = \iint_D f(x,y) \, dx\, dy
$$
On découpe la région en **petits rectangles** et on somme les masses locales.

---

### 7. Changement de variables en 1D
Si $x = g(u)$ :
$$
\int_a^b f(x) \, dx = \int_{u_1}^{u_2} f(g(u)) g'(u) \, du
$$
Le facteur $g'(u)$ ajuste la **longueur des segments**.

---

### 8. Changement de variables en 2D
Pour $G(u,v) = (x,y)$ :
$$
\iint_{G(D')} f(x,y) \, dx\, dy = \iint_{D'} f(G(u,v)) \, |\det(J_G(u,v))| \, du\, dv
$$
- $|\det(J_G)|$ ajuste la **surface des petits éléments**.  
- La **valeur absolue** corrige l’orientation : un déterminant négatif signifie une **réflexion locale**.  
- La transformation $G$ doit être **injective** pour éviter que certaines régions soient comptées deux fois.

---

### 9. Exemple : passage aux coordonnées polaires
Pour $G(r,\theta) = (r \cos\theta, r \sin\theta)$, un petit rectangle $(\Delta r, \Delta \theta)$ devient un secteur d’anneau :  
- Longueur radiale : $\Delta r$  
- Longueur circulaire : $r \Delta \theta$  

Surface approximative : $r \Delta r \Delta \theta$  
Le **Jacobian determinant** est donc $r$ et la formule de changement de variables devient :
$$
\iint_D f(x,y) \, dx\, dy = \iint_T f(r\cos\theta, r\sin\theta) \, r \, dr \, d\theta
$$

---

### 10. Synthèse
- La **dérivée** en 1D = **meilleure approximation linéaire locale** et **facteur de mise à l’échelle**.  
- La **matrice jacobienne** = généralisation multidimensionnelle.  
- Le **déterminant jacobien** = facteur de **dilatation/contration des aires**.  
- Ces notions sont essentielles pour **changer de variables dans les intégrales multivariées** et pour la **visualisation de transformations locales**.
