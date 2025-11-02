# Fixer le Time Step

---

Nous venons de discuter de l’importance de **fixer le time step**.  
C’est essentiel car toute la simulation physique se déroule en éléments discrets, étape par étape : **step update, step update**.  
Entre ces mises à jour, la simulation physique met à jour les positions, les accélérations, les forces, vérifie les collisions, etc.  
Comprendre le time step fixe est donc fondamental pour la cohérence de la simulation.  

---

## Mouvement à Vitesse Constante

Revenons à la physique : l’idée de base est le **mouvement à vitesse constante**.  
Si nous considérons une timeline en secondes (0s, 1s, 2s, …), un objet se déplace de manière constante.  
Par exemple :  
- À t = 0s → position = 0 m  
- À t = 1s → position = 10 m  
- À t = 2s → position = 20 m  
- À t = 3s → position = 30 m  

La **différence de position par unité de temps** est toujours la même : 10 m/s.  
Ceci est un exemple classique de mouvement à vitesse constante.  

---

## Compréhension de la Position

La position d’un objet se calcule à partir de sa vitesse multipliée par le temps écoulé :  
$$ P = V \times t $$  
Ceci permet de déterminer où se trouvera l’objet à un moment donné sur la timeline.  
C’est la base de l’étude de la physique appliquée aux mouvements linéaires.  

---

## Intuition Graphique

Si nous traçons la position en fonction du temps :  
- Axe horizontal → temps  
- Axe vertical → position  

Pour un mouvement à vitesse constante, la courbe est **une ligne droite**.  
La pente de cette ligne reste constante, représentant la vitesse constante de l’objet.  

---

## Taux de Variation et Pente

Le **taux de variation** entre deux points de la courbe se calcule par la pente :  
$$ m = \frac{\Delta y}{\Delta x} $$  
- Δy → variation de la position  
- Δx → variation du temps  

Cette pente correspond exactement à la vitesse de l’objet.  
Plus la pente est grande, plus la vitesse est élevée ; plus elle est faible, plus la vitesse est réduite.  

---

## Résumé

Pour un mouvement à vitesse constante :  
- La courbe position vs. temps est une **ligne droite**.  
- La **pente** est constante à chaque intervalle de temps.  
- Cette notion relie directement ce que nous avons observé avec nos particules dans l’application : déplacement linéaire, par exemple 100 pixels en x et 30 pixels en y.  

Ainsi, ce graphique illustre parfaitement la **relation entre temps, position et vitesse constante**.  
(voir démo avec graphtoy)
