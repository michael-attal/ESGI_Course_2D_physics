# Accélération constante

Nous venons d’introduire la notion d’accélération : une variation de la vitesse par unité de temps.  
Par exemple, une chute verticale soumise à la gravité entraîne une accélération constante d’environ $$9.8 \, m/s^2$$.  
Que signifie ce concept dans la simulation logicielle du mouvement ?  
Observons cela plus rigoureusement.

---

## Accélération constante en code

Lorsque nous programmons une accélération constante, nous reproduisons précisément cette évolution de la vitesse au fil du temps.  
À chaque itération de la boucle de simulation (game loop), la vitesse augmente, et cette variation se répercute directement sur la position de l’objet.

---

# Chronologie du mouvement

Partons d’une position initiale nulle au temps $$t = 0$$.  
Après une seconde, l’objet aura acquis une certaine vitesse, ce qui crée un premier déplacement.  
Au fil des secondes, cet écart grandit : la vitesse augmentant, le déplacement cumulé sur la position devient de plus en plus important.  
On observe donc un mouvement qui s’accélère.

---

## Comprendre la variation de position

L’objet démarre lentement, puis son déplacement par unité de temps croît progressivement.  
Visuellement, la courbe représentant la position augmente de manière non linéaire.

---

## Représentation graphique

Sur un graphique où l’axe des abscisses représente le temps et l’axe des ordonnées la position, la trajectoire n’est pas une ligne droite mais une courbe.  
Cette courbure provient de l’accélération constante.

---

## Rappel de physique

Pour tout mouvement rectiligne uniformément accéléré, la relation suivante relie position, vitesse et accélération :

$$
x(t) = x_0 + v_0 t + \frac{1}{2} a t^{2}
$$

Elle exprime que la position dépend à la fois de la vitesse **et** de l’accélération appliquée au système.

---

## Objectif en simulation

Dans un moteur de jeu ou un simulateur physique, nous devons déterminer la nouvelle position à chaque frame.  
Or, la fonction précédente n’est pas linéaire : la pente (la vitesse) évolue continuellement.  
Nous devons donc **prédire** la prochaine position à partir d’un temps discret, de la vitesse courante et de l’accélération du système.

---

## Une non-linéarité fondamentale

La variation de vitesse (pente de la courbe de position) est différente à chaque instant.  
La simulation doit ainsi approcher une mécanique continue avec des mises à jour discrètes : un défi numérique essentiel.

---

## Introduction au calcul différentiel et intégral

Puisque la vitesse est le **taux de variation** de la position, et que l’accélération est le **taux de variation** de la vitesse, nous entrons naturellement dans le domaine du calcul différentiel.  

Inversement :  
* intégrer l’accélération → obtenir la vitesse  
* intégrer la vitesse → obtenir la position  

C’est précisément cette intégration numérique que nos simulateurs réalisent à chaque frame.

---

## Conclusion

Nous pouvons exécuter du code qui « fonctionne ».  
Mais comprendre les principes mathématiques et physiques sous-jacents rend la simulation bien plus riche : nous faisons le lien direct entre théorie (calcul différentiel) et pratique (animation en temps réel).  
Poursuivons donc notre exploration du mouvement, de l’accélération et des fondements du calcul appliqués à la physique du jeu vidéo.
