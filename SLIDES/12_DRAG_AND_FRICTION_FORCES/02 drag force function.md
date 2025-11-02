## Force de traînée et fichiers utilitaires

Nous avons abordé la **force de traînée** (*drag force*) et évoqué la création de fichiers **utilitaires** destinés à générer les forces physiques les plus courantes — friction, traînée, ressort, etc.  
Ces fichiers permettent d’isoler la logique de calcul des forces et de la rendre réutilisable dans l’ensemble de la simulation.

---

## Création de `force.h`

Dans le dossier `physics/`, créons un fichier intitulé `force.h`.  
Ce fichier contiendra une structure `Force` au sein de laquelle seront définies des **fonctions statiques**, dont `generateDragForce()`.  
Cette fonction nécessitera l’inclusion de `Vec.h` (pour les opérations vectorielles) et de `particle.h` (afin d’accéder aux propriétés des particules).  

---

La fonction prendra deux paramètres :  
- Un pointeur vers une particule (`Particle*`), dont on utilisera la vitesse.  
- Une constante `float k`, représentant l’intensité de la traînée en fonction du fluide simulé.  

Cette constante `k` est un **paramètre empirique** : elle traduit la résistance du fluide à travers lequel se déplace la particule.

---

## Implémentation de `force.cpp`

Dans le fichier `force.cpp`, on inclut `force.h`.  
On y définit la fonction `generateDragForce()` telle que présentée précédemment :  
1. Calcul de la direction de la traînée (opposée à la vitesse).  
2. Calcul de la magnitude (proportionnelle à $k \times \|\vec{v}\|^2$).  
3. Combinaison des deux pour obtenir le vecteur final de traînée.  
4. Renvoi de la force à appliquer.  

---

Cette approche est suffisante pour produire une traînée réaliste à partir de la vitesse de la particule et du coefficient $k$ choisi.

---

## Mise en place dans l’application

Ouvrons `application.cpp` et `application.h`.  
Nous allons ajouter un concept de **fluide** dans notre scène : la moitié inférieure de l’écran représentera une zone de fluide, tandis que la moitié supérieure simulera le vide.  

Le fluide sera représenté par un **rectangle** positionné en bas de l’écran.

---

## Utilisation d’un rectangle STL

La bibliothèque STL propose une structure `Rectangle` pratique, contenant déjà les champs `x`, `y`, `width`, et `height`.  
Nous allons déclarer une variable globale `liquid` de ce type.  

---

Dans la fonction `setup()`, initialisons-la :  
```cpp
liquid.x = 0;
liquid.y = graphics.height / 2;
liquid.width = graphics.width;
liquid.height = graphics.height / 2;
```

Ainsi, la partie inférieure de l’écran correspond à la zone de fluide, tandis que la partie supérieure reste libre.

---

## Rendu du fluide

Pour afficher ce fluide, utilisons la fonction `drawFilledRectangle()` de notre moteur graphique.  
Attention : le système de coordonnées du moteur utilise le **centre** du rectangle comme origine, et non le coin supérieur gauche.

---

Nous devons donc ajuster les positions :

```cpp
float centerX = liquid.x + liquid.width / 2;
float centerY = liquid.y + liquid.height / 2;
graphics.drawFilledRectangle(centerX, centerY, liquid.width, liquid.height, 0x6E3713);
```

La couleur hexadécimale `0x6E3713` correspond à un bleu foncé, simulant l’eau.  
Une fois cette opération effectuée, la moitié inférieure de la scène devient visuellement notre fluide.

---

## Application de la force de traînée

Nous souhaitons maintenant appliquer une force de traînée **uniquement** lorsque la particule entre dans la zone du fluide.

---

Dans la boucle de mise à jour (`update()`), pour chaque particule :

```cpp
if (particle->position.y >= liquid.y) {
    glm::vec2 drag = force::generateDragForce(particle, 0.01f);
    particle->addForce(drag);
}
```

La condition vérifie si la particule est **immergée dans le fluide**.  
Si oui, on calcule la traînée avec un coefficient initial de $k=0.01$, que l’on pourra ajuster selon le comportement souhaité.

---

### Observation du comportement

Lors de l’exécution, on observe :

- Aucune résistance dans la partie supérieure de l’écran.
- Une résistance croissante dès que la particule entre dans le fluide.
    
Plus la particule est rapide, plus la traînée appliquée est importante.  
Le comportement est réaliste : la direction de la traînée est **opposée** à la vitesse, et sa magnitude dépend du carré de celle-ci.

---

## Ajustement du coefficient

On peut expérimenter avec différentes valeurs de k :

```cpp
glm::vec2 drag = force::generateDragForce(particle, 0.004f);
```

Une valeur plus élevée rend le fluide plus visqueux (comme de la boue ou de l’huile), tandis qu’une valeur plus faible simule un fluide léger (comme l’air).

---

## Interaction dynamique avec la souris

Proposons une amélioration interactive :  
Créer des particules dynamiquement via des **clics de souris**.  
À chaque clic, une particule est créée à la position du curseur, avec une masse et une taille aléatoires.

---

Cet exercice vous invite à explorer la gestion des événements de souris avec la bibliothèque **SDL** :

- Récupérez les coordonnées du clic.
- Créez une particule à cette position.
- Affectez-lui éventuellement une masse et une taille aléatoires.
    
Ce mécanisme rendra votre simulation plus vivante, vous permettant de **créer et manipuler** des particules en temps réel.
