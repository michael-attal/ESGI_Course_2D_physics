# Transformations de vecteurs

---

Dans cette partie du cours, nous allons aborder la notion de **transformation de vecteurs**.  

Jusqu’à présent, nous avons vu les opérations fondamentales : addition, soustraction, produit scalaire (*dot product*), produit vectoriel (*cross product*) et magnitude (longueur).  


---

Il est maintenant temps de comprendre comment **transformer un vecteur** :  

- **Mise à l’échelle** (*scaling*)  
- **Translation**  
- **Rotation**

Ces trois opérations constituent la base de toute manipulation de vecteurs dans les moteurs graphiques, les simulations physiques et les jeux vidéo.

---

# Mise à l’échelle (*Scaling*)

Commençons par la plus simple : la **mise à l’échelle**.  

C’est une opération que nous connaissons déjà.

Si nous avons un vecteur représentant par exemple une vitesse, nous pouvons **augmenter ou diminuer** cette vitesse — c’est-à-dire sa longueur — en multipliant le vecteur par un **scalaire** (*scalar*).  

---

Autrement dit, si nous avons un vecteur  $\vec{v} = (x, y)$ et que nous appliquons un facteur de mise à l’échelle $s$, alors : 

$$\vec{v'} = s \cdot \vec{v} = (s \cdot x, s \cdot y)$$  

Cela revient à **étirer** ou **rétrécir** le vecteur le long de sa direction d’origine.  

Doubler ou tripler sa longueur revient à multiplier chaque composante par 2 ou 3 ; le réduire revient à multiplier par un facteur inférieur à 1.  

La mise à l’échelle est donc une transformation simple, linéaire et directe.

---

# Translation

La **translation** est une autre opération fondamentale, mais contrairement à la mise à l’échelle, **ce n’est pas une transformation linéaire**.  
Elle consiste à **déplacer** un vecteur (souvent une position) dans l’espace.  

---

Si nous avons un vecteur de position $\vec{p} = (x, y)$, et un vecteur de décalage $\vec{t} = (t_x, t_y)$, la translation se définit par :  
$$
\vec{p'} = \vec{p} + \vec{t}
$$  

---

Cette addition revient à **déplacer** le point de position $\vec{p}$ d’un certain **offset** en x et y (et z si on est en 3D).  

- Ajouter un nombre positif à x déplace le point vers la droite.  
- Ajouter un nombre positif à y déplace le point vers le haut.  
- Ajouter un nombre négatif déplace dans la direction opposée.  

C’est une opération très utilisée dans les moteurs de jeu, les animations et les simulations de mouvement.

---

# Rotation

La **rotation** est la plus intéressante et la plus mathématiquement riche des trois transformations.  
Elle consiste à faire tourner un vecteur autour de l’origine d’un certain **angle** $\beta$ (en radians ou degrés).  

---

Imaginons un vecteur position $\vec{v} = (x, y)$.  
Nous voulons trouver les nouvelles coordonnées $x'$ et $y'$ après rotation d’un angle $\beta$ autour de l’origine.  

La formule classique donnée dans la plupart des manuels est :  
$$
x' = x \cdot \cos(\beta) - y \cdot \sin(\beta) 
$$
$$
y' = x \cdot \sin(\beta) + y \cdot \cos(\beta)
$$ 

Cette transformation conserve la **longueur** du vecteur (elle est isométrique) et change uniquement sa **direction**.

---

### Dérivation de la formule de rotation

Essayons de comprendre **d’où viennent ces formules**.  

Nous savons que la rotation modifie les composantes du vecteur selon l’angle $\beta$.  

Si le vecteur initial est projeté sur les axes x et y, après rotation, ses projections changent proportionnellement aux fonctions trigonométriques **cosinus** et **sinus** de cet angle.  

---

Intuitivement :  
- Le **cosinus** représente la projection sur l’axe x.  
- Le **sinus** représente la projection sur l’axe y.  

Ainsi, la combinaison linéaire des deux donne les nouvelles coordonnées du vecteur après rotation.  
Cependant, au lieu d’accepter cette formule comme un axiome, nous allons la **démontrer géométriquement**.

---

### Démonstration de la formule de rotation

Nous allons **prouver** mathématiquement la validité de la formule de rotation.  
Nous verrons comment, à partir des définitions trigonométriques de $\cos$ et $\sin$, on peut démontrer ces équations.  

---

Cette démonstration nous permettra de comprendre en profondeur **comment les coordonnées changent lors d’une rotation**, et pourquoi cette transformation conserve la longueur du vecteur.  

Nous implémenterons ensuite une fonction de rotation dans notre code source, capable de retourner un vecteur correctement transformé.
