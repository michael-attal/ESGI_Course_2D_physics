# Implémentation de la force de frottement

La fonction `generateFrictionForce` a été ajoutée dans le fichier `force.cpp`.  

Elle reçoit en paramètre une référence constante à une particule et une valeur flottante $k$, conformément à la structure précédemment utilisée pour la force de traînée (*drag force*).  

La différence principale réside dans le fait que la fonction applique ici une force de frottement.

---

### Application du frottement dans le programme

Dans le fichier `application.cpp`, la fonction `update()` est responsable de l’application de la force de frottement.  

La zone du code dédiée aux forces appliquées à la particule a été modifiée : la force de gravité a été retirée pour simuler une vue en plongée, comparable à celle d’une table de billard.  

La particule agit alors comme une bille se déplaçant sur une table sans gravité.  

---

Une force de poussée (*push force*) est appliquée pour permettre un contrôle via les touches du clavier, puis une force de frottement est générée par appel à la fonction `generateFrictionForce`, à laquelle sont passés la particule et un coefficient de $10.0 \times \text{pixels per meter}$. 

Ces unités n’ont pas de valeur physique réelle et servent uniquement à ajuster visuellement la simulation selon l’échelle de l’écran.  

La force de frottement est ensuite ajoutée à la particule via `particle.addForce(frictionForce)`.

---

# Rétroaction visuelle et tests

Après compilation, l’environnement de simulation affiche une vue similaire à celle d’une table de billard : une bille au centre, sur un fond vert.  

Lorsqu’une force de poussée est appliquée, la bille se déplace et finit par s’arrêter grâce à la force de frottement.  

La valeur du coefficient de frottement $k$ détermine la vitesse à laquelle la bille ralentit et s’immobilise.  

---

En ajustant ce paramètre, il est possible de rendre la surface plus ou moins glissante.  

Cette configuration correspond au comportement attendu d’une bille sur une table de billard : une glisse initiale suivie d’un arrêt progressif.

---

### Interaction à la souris et impulsion

Une interaction supplémentaire a été ajoutée : la possibilité de créer un *impulse* à l’aide de la souris.  

L’utilisateur peut cliquer, faire glisser, puis relâcher le bouton de la souris pour appliquer une impulsion à la bille.  

Une ligne rouge indique la direction et l’intensité de cette impulsion.  

Lors du relâchement, une variation instantanée de la vitesse est appliquée à la particule.  

---

Cette impulsion correspond à un changement brusque de vitesse, simulant un impact ou un coup. 

Ce comportement est obtenu en réutilisant les événements de la bibliothèque SDL : clic, glissement, et relâchement de la souris.

---

### Gestion des événements liés à la souris

La fonction de gestion des entrées (*input function*) a été modifiée pour prendre en compte trois événements :  
1. **Mouvement de la souris** (*mouse motion*) — mise à jour de la position du curseur (x, y).  
2. **Clic de souris enfoncé** (*mouse button down*) — début du traçage de la ligne rouge.  
3. **Clic de souris relâché** (*mouse button up*) — création de l’impulsion et application du changement de vitesse.  

---

Dans cette version simplifiée, l’impulsion est interprétée comme un changement instantané de la vitesse de la particule.  

Ce choix permet d’éviter d’attendre la propagation complète d’une force à travers l’accélération et la vitesse, et d’obtenir une réaction immédiate à l’impact.  

**Autrement dit, l’impulsion simule une force très intense appliquée sur un laps de temps extrêmement court.**

---

# Concept physique : l’impulsion

En physique, une impulsion (*impulse*) correspond à la variation de quantité de mouvement résultant de l’application d’une force pendant un court intervalle de temps.  
Dans le cas présent, elle est modélisée par une variation instantanée de la vitesse :  

$$
\vec{J} = \Delta \vec{p} = m \, \Delta \vec{v}
$$  

où $\vec{J}$ est l’impulsion, $m$ la masse, et $\Delta \vec{v}$ le changement de vitesse.  

Cette approximation permet de simuler le comportement attendu d’une bille frappée par une queue de billard, c’est-à-dire une accélération soudaine suivie d’un ralentissement dû au frottement.

---

# Gestion des événements et conclusion

La gestion des événements repose sur trois cas d’utilisation de `SDL_PollEvent` : `SDL_MOUSEMOTION`, `SDL_MOUSEBUTTONDOWN`, et `SDL_MOUSEBUTTONUP`.  
Ces événements suffisent à implémenter le comportement de clic, de glissement et de relâchement, produisant ainsi l’effet de tir d’une bille de billard.  
Le code associé à cette mécanique est volontairement simple, accessible à l’analyse dans le code source fourni.

---

# Remarques finales sur la simulation du frottement

Le système de frottement mis en place permet de contrôler facilement la rugosité perçue de la surface.  
En ajustant la constante $k$, il est possible de simuler différentes natures de surfaces : herbe, glace, ou revêtement poli.  
Il suffit de modifier cette valeur pour obtenir un effet visuel et physique cohérent avec la scène simulée.  
Ce principe illustre l’importance du frottement dans la conception de mécaniques de jeu crédibles et intuitives.
