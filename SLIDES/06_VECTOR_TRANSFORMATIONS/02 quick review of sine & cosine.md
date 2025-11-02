# Vers la démonstration de la rotation vectorielle

---

Nous avons commencé à parler des **transformations de vecteurs**, et l’une des plus importantes est la **rotation**.  
L’objectif est de prendre un vecteur initial et de le faire **tourner d’un certain angle**, noté ici $\beta$.  

Rappelons les **formules de rotation** que nous avons déjà vues :  
$
x' = x \cdot \cos(\beta) - y \cdot \sin(\beta)
$  
$
y' = x \cdot \sin(\beta) + y \cdot \cos(\beta)
$  

Ces deux équations définissent les nouvelles composantes $x'$ et $y'$ du vecteur après rotation d’un angle $\beta$.  
Notre objectif est de **comprendre et démontrer** pourquoi ces formules sont correctes.

---

# Simplification du problème

Avant de plonger dans la démonstration, simplifions le problème.  
Dans le plan cartésien, nous avons un vecteur initial caractérisé par ses composantes $x$ et $y$.  
Ce vecteur forme déjà un angle $\alpha$ avec l’axe des abscisses.  

Nous voulons maintenant **faire tourner ce vecteur d’un angle supplémentaire** $\beta$.  
Ainsi, l’angle total du vecteur après rotation devient $\alpha + \beta$.  

---

Notre but est donc de **déterminer les nouvelles coordonnées** du vecteur après rotation, que nous noterons $x'$ et $y'$.  

Schématiquement :  
- Angle initial : $\alpha$  
- Rotation appliquée : $\beta$  
- Nouvel angle : $\alpha + \beta$  

Nous cherchons à exprimer $x'$ et $y'$ en fonction de $x$, $y$ et $\beta$.

---

# Rappel de trigonométrie

Avant d’aller plus loin, faisons un **rapide rappel de trigonométrie**, car les fonctions **sinus**, **cosinus** et **tangente** sont au cœur de cette démonstration.

---

## Le triangle rectangle

Considérons un **triangle rectangle** — un polygone à trois côtés dont l’un des angles mesure $90^\circ$.  

Imaginons un angle quelconque dans ce triangle.  
Les côtés de ce triangle sont nommés de la façon suivante :  

- **Côté opposé** (*opposite side*) : le côté situé en face de l’angle étudié.  
- **Côté adjacent** (*adjacent side*) : le côté formant l’angle avec la base.  
- **Hypoténuse** (*hypotenuse*) : le côté le plus long, opposé à l’angle droit.  

Ces trois côtés constituent la base de la définition des fonctions trigonométriques.

---

## Fonctions trigonométriques fondamentales

Les trois principales fonctions trigonométriques sont :

1. **Sinus (sine)** :  
   $
   \sin(\theta) = \frac{\text{opposé}}{\text{hypoténuse}}
   $

2. **Cosinus (cosine)** :  
   $
   \cos(\theta) = \frac{\text{adjacent}}{\text{hypoténuse}}
   $

3. **Tangente (tangent)** :  
   $
   \tan(\theta) = \frac{\text{opposé}}{\text{adjacent}}
   $

---

Ces **rapports** permettent de relier les longueurs des côtés d’un triangle rectangle à ses angles.  
Ils jouent un rôle fondamental dans la géométrie des vecteurs, puisque la position d’un point $(x, y)$ dans le plan peut être exprimée à l’aide de $r \cos(\theta)$ et $r \sin(\theta)$, où $r$ est la longueur du vecteur et $\theta$ son angle.

---

## Mnémonique : SOH-CAH-TOA

Pour se souvenir facilement de ces définitions, on utilise souvent la règle **SOH-CAH-TOA** :  

- **SOH** → *Sine = Opposite / Hypotenuse*  
- **CAH** → *Cosine = Adjacent / Hypotenuse*  
- **TOA** → *Tangent = Opposite / Adjacent*  

Cette astuce mnémotechnique aide à retenir les rapports trigonométriques de base et nous sera utile pour la démonstration de la rotation vectorielle.

---

# Conclusion

Nous avons maintenant les bases nécessaires :  
- Un vecteur initial défini par son angle $\alpha$,  
- Une rotation d’un angle $\beta$,  
- Et les définitions trigonométriques nécessaires pour exprimer les coordonnées du vecteur avant et après rotation.  

Dans la prochaine partie, nous utiliserons ces notions pour **dériver la formule complète de la rotation vectorielle** à partir des identités trigonométriques.
