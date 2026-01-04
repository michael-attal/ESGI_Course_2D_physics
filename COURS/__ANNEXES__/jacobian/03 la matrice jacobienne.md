# Construction de la matrice jacobienne par linéarisation locale

## Rappel du contexte
On considère la fonction non linéaire suivante, déjà étudiée précédemment, interprétée comme une transformation de l’espace :
$$
f(x,y) =
\begin{pmatrix}
x + \sin(y) \\
y + \sin(x)
\end{pmatrix}
$$
Cette fonction transforme chaque point $(x,y)$ du plan en un nouveau point, avec une déformation globale fortement non linéaire. Lors de l’analyse précédente, on s’est focalisé sur le comportement de cette transformation autour du point spécifique $(-2,1)$.

---

## Observation de la linéarité locale
Bien que la transformation soit globalement complexe, on observe qu’au voisinage immédiat du point $(-2,1)$, elle se comporte comme une transformation linéaire. Autrement dit, lorsqu’on zoome suffisamment autour de ce point, la transformation ressemble de plus en plus à celle produite par une matrice $2 \times 2$. Cette propriété est appelée linéarité locale.

L’objectif est alors d’identifier explicitement la matrice qui décrit cette approximation linéaire locale.

---

## Décomposition de la fonction en composantes scalaires
Pour analyser précisément les effets de petits déplacements, il est utile de séparer la fonction vectorielle en deux fonctions scalaires :
$$
f_1(x,y) = x + \sin(y), \quad f_2(x,y) = y + \sin(x)
$$
La fonction $f_1$ correspond à la composante horizontale de la transformation, tandis que $f_2$ correspond à la composante verticale.

---

## Effet d’un petit déplacement selon l’axe $x$
Considérons un déplacement infinitésimal $dx$ vers la droite dans l’espace d’entrée. Après transformation, ce petit déplacement n’est plus purement horizontal : il possède une composante horizontale et une composante verticale dans l’espace de sortie.

- La composante horizontale de ce déplacement correspond à la variation de $f_1$ induite par $dx$.
- La composante verticale correspond à la variation de $f_2$ induite par ce même $dx$.

En divisant chacune de ces variations par $dx$, on obtient des quantités indépendantes de l’échelle du zoom, à savoir les dérivées partielles $\partial f_1 / \partial x$ et $\partial f_2 / \partial x$. Ces deux valeurs constituent la première colonne de la matrice linéaire locale.

---

![[medias/03 la matrice jacobienne-20260102.png]]


---

## Effet d’un petit déplacement selon l’axe $y$
De manière analogue, on considère un déplacement infinitésimal $dy$ vers le haut. Après transformation, ce déplacement possède également deux composantes :

- une composante horizontale, donnée par la variation de $f_1$ induite par $dy$,
- une composante verticale, donnée par la variation de $f_2$ induite par $dy$.

En divisant par $dy$, on obtient les dérivées partielles $\partial f_1 / \partial y$ et $\partial f_2 / \partial y$. Ces deux quantités forment la seconde colonne de la matrice associée à la transformation linéaire locale.

---

![[medias/03 la matrice jacobienne-20260102-1.png]]


---

## Évaluation au point considéré
Toutes ces dérivées partielles doivent être évaluées au point précis autour duquel on effectue le zoom, ici $(-2,1)$. Chaque dérivée partielle devient alors un nombre réel, ce qui permet de construire une matrice numérique $2 \times 2$ représentant l’approximation linéaire de la fonction en ce point.

---

## Définition de la matrice jacobienne
La matrice formée par l’ensemble de ces dérivées partielles porte un nom spécifique : la matrice jacobienne. Elle s’écrit, de manière générale,
$$
J_f(x,y) =
\begin{pmatrix}
\frac{\partial f_1}{\partial x} & \frac{\partial f_1}{\partial y} \\
\frac{\partial f_2}{\partial x} & \frac{\partial f_2}{\partial y}
\end{pmatrix}
$$
Cette matrice regroupe toute l’information différentielle locale de la fonction.

---

## Interprétation conceptuelle
La matrice jacobienne ne se limite pas à être un simple tableau de dérivées partielles. Son organisation reflète directement l’interprétation géométrique de la transformation : chaque colonne décrit l’image locale d’un vecteur de base, et la matrice dans son ensemble représente la transformation linéaire qui approxime la fonction lorsqu’on zoome autour d’un point donné.

Comprendre cette interprétation en termes de linéarité locale est essentiel pour donner du sens à la matrice jacobienne et à ses usages en analyse, en physique et en informatique graphique.

---

## Transition vers le calcul explicite
La prochaine étape consiste à calculer explicitement ces dérivées partielles pour la fonction considérée et à construire la matrice jacobienne associée. Cela permettra de relier concrètement le calcul analytique à l’interprétation géométrique observée.
