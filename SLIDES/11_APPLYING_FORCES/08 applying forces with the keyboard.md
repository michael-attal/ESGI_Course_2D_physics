## Forces contrôlées par le clavier

Nous allons commencer à explorer les forces, comme la friction et la traînée, très communes en physique pour les jeux vidéo.  
Pour nous préparer à appliquer ces forces, nous allons mettre en place un mécanisme simple de contrôle par clavier.

---

## Configuration de la force de poussée

Nous avons une balle et une grosse balle ; pour l’instant, nous allons commenter la grosse balle.  
Dans `application.h`, en plus de notre tableau de particules, nous créons une **force de poussée** globale.  
Cette force pourra être contrôlée avec les flèches du clavier.

---

## Interaction clavier

Si la flèche haut est pressée, la force sera dirigée vers le haut, flèche bas vers le bas, etc.  
La force de poussée initiale est `(0, 0)`.  
Il faut gérer les événements clavier dans la fonction d’entrée pour détecter les touches appuyées.

---

## Gestion des événements clavier

Pour chaque touche :  
- `SDL_KEYUP` : force vers le haut `y = -50`  
- `SDL_KEYRIGHT` : force vers la droite `x = +50`  
- `SDL_KEYDOWN` : force vers le bas `y = +50`  
- `SDL_KEYLEFT` : force vers la gauche `x = -50`  

Ces valeurs sont ajustées en fonction du facteur pixels par mètre.

---

## Réinitialisation des forces à la libération des touches

Lorsqu’une touche est relâchée (`SDL_KEYUP`), la force correspondante est remise à zéro :  
- `y = 0` pour haut/bas  
- `x = 0` pour gauche/droite  

Ainsi, nous gérons à la fois `SDL_KEYDOWN` et `SDL_KEYUP` pour appliquer et stopper la force.

---

## Application de la force de poussée

Dans la boucle d’update des forces, après avoir appliqué le vent et le poids, nous ajoutons la force de poussée :  
```cpp
particle.addForce(pushForce);
```

Chaque particule reçoit la force définie par le clavier.

---

## Test du résultat

En testant, la particule se déplace dans la direction des touches appuyées.  
Cette force fonctionne comme une impulsion continue tant que la touche est maintenue.

---

## Conclusion : préparation pour les forces spéciales

Ce mécanisme permet de visualiser directement l’effet des forces appliquées.  
Il sera très utile pour expérimenter avec des forces spéciales comme la friction, la traînée, ou les ressorts, et pour tester des interactions dans différents environnements (air, liquide, etc.).


