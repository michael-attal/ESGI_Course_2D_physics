# Détermination de l’impulsion finale $\mathbf{J}$

---

## Rappel : vitesses au point de contact

Pour les corps $A$ et $B$, la vitesse au point $P$ est :

$$
\mathbf{V}_A = \mathbf{v}_A + \boldsymbol{\omega}_A \times \mathbf{R}_A
$$

$$
\mathbf{V}_B = \mathbf{v}_B + \boldsymbol{\omega}_B \times \mathbf{R}_B
$$

Après collision, elles deviennent :

$$
\mathbf{V}_A' = \mathbf{v}_A - \frac{\mathbf{J}}{m_A} + \left( \boldsymbol{\omega}_A - \frac{\mathbf{R}_A \times \mathbf{J}}{I_A} \right) \times \mathbf{R}_A
$$

$$
\mathbf{V}_B' = \mathbf{v}_B + \frac{\mathbf{J}}{m_B} + \left( \boldsymbol{\omega}_B + \frac{\mathbf{R}_B \times \mathbf{J}}{I_B} \right) \times \mathbf{R}_B
$$

---

## Vitesse relative après collision

La vitesse relative après collision le long de la normale $\mathbf{n}$ est :

$$
\mathbf{V}_{\text{rel}}' \cdot \mathbf{n} = -\epsilon \, (\mathbf{V}_{\text{rel}} \cdot \mathbf{n})
$$

où $\mathbf{V}_{\text{rel}} = \mathbf{V}_A - \mathbf{V}_B$ et $\epsilon$ est le coefficient de restitution.

---

## Subtraction des vitesses au point

On développe la vitesse relative post-collision :

$$
\begin{aligned}
\mathbf{V}_A' - \mathbf{V}_B' &= (\mathbf{V}_A - \mathbf{V}_B) - \mathbf{J} \left( \frac{1}{m_A} + \frac{1}{m_B} \right) \\
&\quad - \frac{(\mathbf{R}_A \times \mathbf{J}) \times \mathbf{R}_A}{I_A} - \frac{(\mathbf{R}_B \times \mathbf{J}) \times \mathbf{R}_B}{I_B}
\end{aligned}
$$

Prendre le produit scalaire avec $\mathbf{n}$ :

$$
(\mathbf{V}_A' - \mathbf{V}_B') \cdot \mathbf{n} = (\mathbf{V}_A - \mathbf{V}_B) \cdot \mathbf{n} - \mathbf{J} \cdot \mathbf{n} \left( \frac{1}{m_A} + \frac{1}{m_B} \right) - \left[ \frac{(\mathbf{R}_A \times \mathbf{J}) \times \mathbf{R}_A}{I_A} + \frac{(\mathbf{R}_B \times \mathbf{J}) \times \mathbf{R}_B}{I_B} \right] \cdot \mathbf{n}
$$

---

## Formule finale pour $\mathbf{J}$

En isolant $\mathbf{J}$ :

$$
\mathbf{J} = - (1 + \epsilon) \, \frac{(\mathbf{V}_A - \mathbf{V}_B) \cdot \mathbf{n}}{\frac{1}{m_A} + \frac{1}{m_B} + \frac{[(\mathbf{R}_A \times \mathbf{n}) \times \mathbf{R}_A] \cdot \mathbf{n}}{I_A} + \frac{[(\mathbf{R}_B \times \mathbf{n}) \times \mathbf{R}_B] \cdot \mathbf{n}}{I_B}}
$$

Cette impulsion $\mathbf{J}$ prend en compte :
- la translation linéaire,
- la rotation des corps rigides via les vecteurs $\mathbf{R}_A$ et $\mathbf{R}_B$,
- les moments d’inertie $I_A$ et $I_B$,
- le coefficient de restitution $\epsilon$.

---

## Application dans le code source

Cette formule permet de calculer l’impulsion finale à appliquer à $A$ et $B$ :

- Pour $A$ : appliquer $- \mathbf{J}$
- Pour $B$ : appliquer $+ \mathbf{J}$

Ainsi, la collision est résolue de manière physiquement réaliste, intégrant à la fois les effets linéaires et angulaires.
