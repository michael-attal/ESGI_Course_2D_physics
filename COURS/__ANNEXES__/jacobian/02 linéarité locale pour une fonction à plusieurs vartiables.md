# Fonctions non linéaires et linéarité locale

## Du linéaire au non linéaire en calcul multivarié
De nombreux concepts du calcul différentiel multivarié (multivariable calculus) consistent à reprendre des idées issues de l’algèbre linéaire (linear algebra) et à les adapter à des situations non linéaires. Alors que l’algèbre linéaire étudie principalement des transformations simples et globales, le calcul multivarié s’intéresse à des fonctions beaucoup plus complexes, dont le comportement ne peut pas être décrit par une simple matrice à l’échelle globale.

---

## Exemple de fonction vectorielle non linéaire
Considérons une fonction qui prend en entrée un vecteur du plan et renvoie également un vecteur du plan :
$$
f(x,y) =
\begin{pmatrix}
x + \sin(y) \\
y + \sin(x)
\end{pmatrix}
$$
Il s’agit d’un exemple arbitraire de fonction non linéaire, choisie ici pour sa forme symétrique, mais les raisonnements qui suivent restent valables pour des fonctions beaucoup plus générales.

---

## Interprétation comme transformation de l’espace
On peut interpréter cette fonction comme une transformation de l’espace : à chaque point $(x,y)$ de la grille initiale, on associe le point $(x+\sin(y),\, y+\sin(x))$. Contrairement aux transformations linéaires, l’image d’une grille régulière par cette fonction devient fortement déformée : les lignes se courbent, perdent leur parallélisme et leur espacement régulier.

Cette observation montre que la transformation n’est pas linéaire : elle nécessite bien plus d’information qu’une simple matrice $2 \times 2$ pour être décrite globalement.

---

![[medias/jaco01.gif]]

---

## Étude du comportement en un point
Pour mieux comprendre une telle transformation, il est utile de se concentrer sur un point particulier. Considérons par exemple le point $(\pi/2,\,0)$. En évaluant la fonction en ce point :
$$
f\left(\frac{\pi}{2},0\right)
=
\begin{pmatrix}
\frac{\pi}{2} + \sin(0) \\
0 + \sin\left(\frac{\pi}{2}\right)
\end{pmatrix}
=
\begin{pmatrix}
\frac{\pi}{2} \\
1
\end{pmatrix}
$$
Géométriquement, ce point est donc déplacé verticalement d’une unité, sans modification de sa coordonnée horizontale.

---

![[medias/jaco02.gif]]

---

## Complexité globale et intuition locale
Même si le déplacement d’un point isolé peut être simple à analyser, la transformation complète reste très complexe, car chaque point du plan subit une déformation différente. Il devient alors difficile d’avoir une description globale compacte de la fonction.

Cependant, cette fonction possède une propriété essentielle en calcul différentiel : elle est localement linéaire (locally linear).

---

## Notion de linéarité locale
Dire qu’une fonction est localement linéaire signifie que, lorsqu’on se place dans un voisinage suffisamment petit autour d’un point $(x_0,y_0)$, la transformation ressemble de plus en plus à une transformation linéaire. Autrement dit, si l’on “zoome” autour d’un point donné, les lignes localement redeviennent presque droites, parallèles et régulièrement espacées.

Plus le voisinage considéré est petit, plus l’approximation par une transformation linéaire devient précise.

---

## Interprétation géométrique du zoom local
Lorsque l’on observe une zone très réduite autour du point étudié, la déformation non linéaire devient négligeable à cette échelle. La transformation locale ressemble alors à celle d’une grille par une matrice, comme dans le cas des transformations linéaires étudiées en algèbre linéaire.

Ce phénomène est une conséquence directe de la différentiabilité de la fonction.

---

## Vers la matrice jacobienne
Cette observation soulève une question fondamentale : quelle est la transformation linéaire qui approxime au mieux la fonction autour d’un point $(x_0,y_0)$ donné ? La réponse à cette question est fournie par la matrice jacobienne, qui encode cette approximation linéaire locale à l’aide des dérivées partielles de la fonction.

La construction explicite de cette matrice sera abordée dans la suite du cours.
