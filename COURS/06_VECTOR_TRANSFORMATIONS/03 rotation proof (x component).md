# Preuve de la formule de rotation

---

![[03 rotation proof (x component)-20251028.png]]

---

## Contexte et notation

Nous cherchons à déterminer les coordonnées d’un vecteur après **rotation** autour de l’origine.  
Soit un vecteur initial de composantes $(x, y)$. On note :
- $r$ la distance entre l’origine et l’extrémité du vecteur (le **rayon** du cercle de rotation),
- $\alpha$ l’angle formé par le vecteur initial avec l’axe $x$,
- $\beta$ l’angle de rotation que nous appliquons (nous voulons obtenir une rotation totale $\alpha + \beta$).

La raison d’appeler cette distance $r$ est géométrique : en faisant tourner le vecteur autour de l’origine, l’extrémité parcourt un cercle de rayon $r$.  

---

## Formules initiales (relation polaire ↔ cartésienne)

En coordonnées polaires / cartésiennes, les composantes du vecteur initial s’écrivent :
$$
x = r \cos(\alpha)
$$

$$
y = r \sin(\alpha)
$$

Ces relations proviennent directement des définitions trigonométriques sur le triangle rectangle formé par la projection du vecteur sur les axes.  

---

## Objectif : coordonnées après rotation

Après rotation de l’angle $\beta$ (sens trigonométrique positif), le vecteur garde la même distance à l’origine : le rayon reste $r$.  
Le nouvel angle est $\alpha + \beta$. Nous voulons exprimer les nouvelles composantes $x'$ et $y'$ en fonction de $x, y$ et $\beta$ (ou équivalemment en fonction de $r, \alpha$ et $\beta$).  
Formellement :

$$
x' = r \cos(\alpha + \beta)
$$

$$
y' = r \sin(\alpha + \beta)
$$

Notre but est de développer ces expressions pour obtenir une formule en termes de $x, y$ et $\beta$.  

---

## Projection et configuration géométrique

Pour la démonstration, on projette les points sur les axes et on trace les triangles rectangles utiles.  
En découpant la figure en triangles et rectangles, on peut identifier des longueurs qui se relient entre elles par des relations trigonométriques élémentaires.  
Il est commode d’étiqueter les sommets importants (A, B, C, D, E, F, …) pour référer les segments. La stratégie générale est :
1. exprimer certaines longueurs projetées en fonction de $r$ et d’angles ($\cos,\sin$);
2. remplacer $r\cos\alpha$ et $r\sin\alpha$ par $x$ et $y$ quand c’est utile ;
3. combiner les morceaux pour obtenir $x'$ et $y'$.  

---

## Calcul de $x'$ 

On part de la projection horizontale du vecteur après rotation. Géométriquement, on montre que :

$$
x' = \text{(une longueur positive)} - \text{(une autre longueur positive)}
$$

---

En découpant la figure on obtient (notations issues des projections) :
$$
x' = AF - CD
$$
où :
- $AF$ est la projection horizontale liée à l’angle $\alpha$ et à la rotation partielle,
- $CD$ vient d’un petit triangle situé en haut de la figure et dépend de $\alpha$ et $\beta$.

---

- Calcul de $AF$ :  
   Considérant le triangle impliquant $\alpha$ et la base $AF$, on a  
   $$
   \cos(\alpha) = \frac{AF}{AD}.
   $$
   
   Or $AD$ est une projection liée à $\beta$ et vaut $r\cos(\beta)$. Donc
   
   $$
   AF = AD \cdot \cos(\alpha) = r\cos(\beta)\cos(\alpha).
   $$
   
   En remplaçant $r\cos(\alpha)$ par $x$ (relation polaire → cartésienne), on obtient
   
   $$
   AF = x \cos(\beta).
   $$

---

- Calcul de $CD$ :  
   En considérant le petit triangle supérieur et en utilisant la similarité des triangles (les angles correspondants sont égaux), on établit que l’angle adjacent est $\alpha$ et que l’hypoténuse correspondante vaut $BD = r\sin(\beta)$.  
   Par la définition du sinus :
   
   $$
   \sin(\alpha) = \frac{CD}{BD} \quad\Rightarrow\quad CD = BD \cdot \sin(\alpha).
   $$
   
   En remplaçant $BD$ par $r\sin(\beta)$ et $r\sin(\alpha)$ par $y$, on obtient :
   
$$
   CD = y \sin(\beta).
$$

---

- Combinaison :  
   $$
   x' = AF - CD = x\cos(\beta) - y\sin(\beta).
   $$

Nous venons donc de démontrer la formule attendue pour la composante $x'$ :  

$$
\boxed{\,x' = x\cos(\beta) - y\sin(\beta)\,}
$$

---

## Calcul de $y'$

La démonstration complète du composant $y'$ suit un raisonnement analogue (projection verticale, découpage en longueurs exprimables avec $r,\alpha,\beta$ et substitution $r\cos\alpha=x,\;r\sin\alpha=y$).  

---

Voici les grandes étapes à suivre :

1. Identifier la projection verticale du vecteur après rotation : $y' =$ (sommes / différences de segments verticaux projetés).  
2. Exprimer chaque segment en fonction de $r$, $\alpha$, $\beta$ à l’aide des rapports trigonométriques ($\sin,\cos$).  
3. Remplacer systématiquement $r\cos(\alpha)$ par $x$ et $r\sin(\alpha)$ par $y$.  
4. Simplifier pour obtenir une expression en $x, y, \beta$.

Indice clé : vous obtiendrez finalement la formule suivante :

$$
\boxed{y' = x\sin(\beta) + y\cos(\beta)\}
$$

---

## Résultat final et interprétation matricielle

Les deux formules réunies sont :

$$
x' = x\cos(\beta) - y\sin(\beta)
$$

$$
y' = x\sin(\beta) + y\cos(\beta)
$$

En notation matricielle, la rotation autour de l’origine s’écrit :
$$
\begin{bmatrix} x' \\ y' \end{bmatrix} =
\begin{bmatrix}
\cos(\beta), & -\sin(\beta), \\
\sin(\beta), & \cos(\beta)
\end{bmatrix}
\begin{bmatrix} x \\ y \end{bmatrix}.
$$
Cette matrice de rotation 2D est orthogonale et préserve la longueur des vecteurs.  
