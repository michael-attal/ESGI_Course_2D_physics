# De la Vitesse Constante à l'Accélération Constante

---

Nous avons discuté des notions de vitesse constante, de delta time, tout est clair.  
Il est temps maintenant de faire évoluer notre approche : au lieu d'avoir un mouvement à vitesse constante, que se passe-t-il si notre vitesse change, augmente au fur et à mesure que notre simulation pas-à-pas avance ?  
Commençons donc à parler de l’accélération constante.

---

## Définir l’Accélération Constante

Au lieu d’une vitesse constante, notre vitesse va maintenant changer, elle aura un taux de variation et pourra augmenter ou diminuer au fil de la simulation pas-à-pas.  
Comprendre l’implémentation du code pour l’accélération constante est assez simple.  

---

Au lieu que notre vitesse soit un vecteur constant, nous voulons que notre **accélération** soit un vecteur constant.  
Ainsi, nous définissons quelque chose comme `particle.acceleration` et commençons à lui donner une valeur.

---

## Implémenter l’Accélération

Pour accélérer notre particule, imaginons une simulation de chute libre, similaire à 9,8 m/s².  
Si nous avons cette accélération due à la gravité, nous pourrions définir `X = 0.0` et `Y = 9.8` m/s² vers le bas.  
Nous pourrons ajuster ces valeurs selon l’apparence sur l’écran.

---

## Intégrer Accélération et Vitesse

Avec l’accélération constante, notre vitesse va évoluer.  
La vitesse se met à jour ainsi :  
```cpp
velocity += acceleration * deltaTime;
position += velocity * deltaTime;
```

Ces deux lignes correspondent à l’intégration de l’accélération pour déterminer la nouvelle position.

---

## Mise à Jour de la Vitesse et de la Position

Nous utilisons l’accélération pour calculer la nouvelle vitesse, puis la nouvelle vitesse pour calculer la nouvelle position.  
L’accélération est le taux de changement de la vitesse par unité de temps.

---

## Concept d’Intégration

Ces deux lignes représentent l’**intégration**.  
La première met à jour la vitesse en fonction de l’accélération, la seconde met à jour la position en fonction de la vitesse.  
C’est ainsi que nous déterminons la nouvelle position de la particule dans notre simulation.

---

## Tester la Simulation

En exécutant la simulation, on observe que la vitesse augmente progressivement à chaque étape.  
La particule commence lentement, puis accélère selon l’accélération définie.

---

## Adapter à l’Espace de l’Écran

Pour que notre simulation ait du sens à l’écran, nous devons définir une correspondance entre unités physiques et pixels :

```cpp
pixelsPerMeter = 50;
```

Ainsi, 1 mètre dans le monde réel correspond à 50 pixels à l’écran.  
La valeur de l’accélération est alors multipliée par `pixelsPerMeter` pour le rendu.

---

## Observer le Résultat

Après ajustement, la particule chute de manière réaliste, représentant un objet en chute libre à 9,8 m/s².

---

## Activité : Rebondir à l’Intérieur de la Fenêtre

Pour éviter que la particule disparaisse, nous allons ajouter des **contraintes** sur sa position pour la maintenir à l’intérieur de la fenêtre.  
Si la particule touche le bas, elle rebondit vers le haut ; si elle touche un côté, elle rebondit dans la direction opposée.

---

## Ajouter des Contraintes

Il est nécessaire de vérifier la position de la particule par rapport à la largeur et la hauteur de l’écran.  
Nous devons aussi tenir compte du **rayon** de la particule pour les rebonds.

---

## Ajouter un Rayon à la Particule

Pour rendre les particules visibles, chaque particule possède un rayon (`particle.radius`).  
Lors de la création d’une particule, on initialise ce rayon, par exemple:

```cpp
radius = 4;
```

Lors de la vérification des rebonds, on considère le centre de la particule et son rayon.

---

## Conclusion et Exercice

L’exercice consiste à maintenir la particule à l’intérieur des limites de la fenêtre et à gérer les rebonds correctement.  
Comparez ensuite votre approche avec la solution proposée pour valider votre compréhension.