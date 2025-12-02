# Vitesse Constante et Limites

---

Notre objectif était de modifier le comportement de la vitesse pour que la particule ne sorte pas des limites de la fenêtre.  
Si elle va à droite, elle rebondit à gauche ; si elle va vers le bas, elle rebondit vers le haut.  
Voici le résultat obtenu : la particule descend et rebondit dès qu’elle atteint le bas.  
La vitesse s’inverse selon les directions, et nous devons prendre en compte non seulement la largeur et la hauteur de la fenêtre, mais aussi le **rayon** de la particule.  
Le code utilisé est un petit hack dur, pas une véritable simulation physique, juste pour maintenir la particule à l’intérieur des limites.

---

## Logique d’Inversion de Vitesse

Après avoir intégré la vitesse et l’accélération et mis à jour la position,  
on effectue une inversion de la vitesse si la particule touche les limites de l’écran.  
Pour inverser une composante, on multiplie la valeur par `-1` :

```cpp
velocity.x *= -1;
velocity.y *= -1;
```

La même opération s’applique à la composante `y`, avec les tests sur la hauteur de la fenêtre.

---

## Collisions Horizontales

Premier test : si `position.x - radius <= 0` (limite gauche),  
on inverse la vitesse horizontale et on repositionne la particule sur le bord gauche :

```cpp
particle.position.x = particle.radius;
particle.velocity.x *= -1;
```

Ainsi, si la particule dépasse la limite, elle est replacée exactement sur le mur.

---

## Limite Droite et Tests Verticaux

Si `position.x + radius >= windowWidth` (limite droite),  
on repositionne la particule sur le bord droit :

```cpp
particle.position.x = windowWidth - particle.radius;
particle.velocity.x *= -1;
```

et on inverse la vitesse `x`.

---

## Tests des Limites Verticales

Pour la limite haute :

```cpp
if (particle.position.y - particle.radius < 0) {
    particle.position.y = particle.radius;
    particle.velocity.y *= -1;
}
```

Pour la limite basse :

```cpp
if (particle.position.y + particle.radius > windowHeight) {
    particle.position.y = windowHeight - particle.radius;
    particle.velocity.y *= -1;
}
```

---

## Élasticité et Restitution

Ce hack simple permet de maintenir la particule dans les limites de la fenêtre.  
Pour plus de réalisme, certains développeurs utilisent un **facteur d’élasticité** (par exemple `0.9` ou `0.95`) au lieu de `-1`,  
simulant une perte d’énergie à chaque rebond.

Ainsi, la particule perd progressivement de l’énergie et finit par se stabiliser.  
Cette approche simule l’accélération, la gravité et la restitution de manière approximative.



