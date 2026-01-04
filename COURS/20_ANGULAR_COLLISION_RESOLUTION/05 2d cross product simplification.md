# Calcul du produit vectoriel 2D pour la vitesse angulaire

---

## Angular velocity comme vecteur 3D fictif

Dans notre moteur physique 2D :

- L’angular velocity $\omega$ est stockée comme un scalaire représentant la magnitude.
- On peut la représenter comme un vecteur 3D fictif pointant perpendiculairement au plan XY (axe Z) :

$$
\boldsymbol{\omega} = (0, 0, \omega)
$$

- Le vecteur distance au point de contact est $\mathbf{R} = (R_x, R_y, 0)$.

---

## Produit vectoriel 2D

Le produit vectoriel $\boldsymbol{\omega} \times \mathbf{R}$ s’écrit alors :

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

Ainsi, la vitesse angulaire dans le plan XY devient :

$$
\mathbf{V}_{\text{angular}} = (-\omega R_y, \, \omega R_x)
$$

---

## Application à A et B

Pour chaque corps :

$$
\mathbf{V}_A = \mathbf{v}_A + (-\omega_A R_{Ay}, \, \omega_A R_{Ax})
$$

$$
\mathbf{V}_B = \mathbf{v}_B + (-\omega_B R_{By}, \, \omega_B R_{Bx})
$$

La vitesse relative au point de contact est alors :

$$
\mathbf{V}_{\text{rel}} = \mathbf{V}_A - \mathbf{V}_B
$$

---

## Produit vectoriel 2D dans l’impulsion de collision

Pour des vecteurs 2D $\mathbf{a} = (a_x, a_y)$ et $\mathbf{b} = (b_x, b_y)$, le produit vectoriel 2D donne un scalaire correspondant à la composante Z :

$$
\mathbf{a} \times \mathbf{b} = a_x b_y - a_y b_x
$$

Ceci simplifie la formule de l’impulsion $\mathbf{J}$ dans notre moteur 2D, en évitant les produits vectoriels multiples :

$$
\mathbf{J} = - (1 + \epsilon) \, \frac{\mathbf{V}_{\text{rel}} \cdot \mathbf{n}}{\frac{1}{m_A} + \frac{1}{m_B} + \frac{(\mathbf{R}_A \times \mathbf{n})^2}{I_A} + \frac{(\mathbf{R}_B \times \mathbf{n})^2}{I_B}}
$$

où $(\mathbf{R} \times \mathbf{n})^2$ représente le carré du produit vectoriel scalaire dans le plan 2D. Cette simplification rend le calcul de $\mathbf{J}$ directement applicable dans le code.
