# Application pratique de l’impulsion $\mathbf{J}$

---

## Mise en place de la simulation

Dans notre moteur physique 2D, nous avons :

- Un corps statique "floor" avec $\epsilon = 0.2$
- Un obstacle "big box" avec $\epsilon = 0.5$ et rotation initiale $1.4$
- Des petites boîtes créées à la position du curseur avec dimensions $50 \times 50$
- La force de gravité appliquée à chaque boîte

La détection de collision utilise l’algorithme SAT pour obtenir :

- Les corps en contact : $A$ et $B$
- La profondeur et la normale de collision
- Les points de début et de fin du contact

---

## Vecteurs de distance du centre de masse au point de contact

Pour chaque corps, on définit :

$$
\mathbf{R}_A = \mathbf{P}_{\text{end}} - \mathbf{x}_A
$$

$$
\mathbf{R}_B = \mathbf{P}_{\text{start}} - \mathbf{x}_B
$$

où $\mathbf{x}_A$ et $\mathbf{x}_B$ sont les positions des centres de masse, et $\mathbf{P}_{\text{start/end}}$ sont les points de contact déterminés par SAT.

---

## Vitesse relative au point de contact

La vitesse au point de contact pour chaque corps combine la translation et la rotation :

$$
\mathbf{V}_A = \mathbf{v}_A + \boldsymbol{\omega}_A \times \mathbf{R}_A
$$

$$
\mathbf{V}_B = \mathbf{v}_B + \boldsymbol{\omega}_B \times \mathbf{R}_B
$$

avec $\mathbf{v}_A$ et $\mathbf{v}_B$ les vitesses linéaires au centre de masse et $\boldsymbol{\omega}_A$, $\boldsymbol{\omega}_B$ les vitesses angulaires.

La vitesse relative est alors :

$$
\mathbf{V}_{\text{rel}} = \mathbf{V}_A - \mathbf{V}_B
$$

---

## Problématique 2D / 3D pour le produit vectoriel

Dans un moteur 2D :

- $\mathbf{R}$ est un vecteur 2D dans le plan de l’écran $(x, y)$
- $\omega$ est un scalaire représentant la magnitude de la rotation autour de l’axe $z$ perpendiculaire à l’écran

Le produit vectoriel $\boldsymbol{\omega} \times \mathbf{R}$ doit être interprété comme :

$$
\boldsymbol{\omega} \times \mathbf{R} =
\begin{pmatrix}
0 \\
0 \\
\omega
\end{pmatrix}
\times
\begin{pmatrix}
R_x \\
R_y \\
0
\end{pmatrix}
=
\begin{pmatrix}
-\omega R_y \\
\omega R_x \\
0
\end{pmatrix}
$$

Ainsi, la vitesse angulaire dans le plan 2D devient :

$$
\mathbf{V}_{\text{angular}} = (-\omega R_y, \, \omega R_x)
$$

---

## Calcul de l’impulsion $\mathbf{J}$

L’impulsion finale à appliquer pour résoudre la collision, intégrant la translation et la rotation, est donnée par :

$$
\mathbf{J} = - (1 + \epsilon) \, \frac{(\mathbf{V}_A - \mathbf{V}_B) \cdot \mathbf{n}}{\frac{1}{m_A} + \frac{1}{m_B} + \frac{[(\mathbf{R}_A \times \mathbf{n}) \times \mathbf{R}_A] \cdot \mathbf{n}}{I_A} + \frac{[(\mathbf{R}_B \times \mathbf{n}) \times \mathbf{R}_B] \cdot \mathbf{n}}{I_B}}
$$

Cette impulsion est ensuite appliquée :

- $A$ : $-\mathbf{J}$
- $B$ : $+\mathbf{J}$

Ce calcul permet de résoudre la collision de manière réaliste, prenant en compte les effets angulaires et la restitution des corps.
