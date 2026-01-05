## Intégration de Verlet

![[medias/03 verlet integration-20260105-2.png]]

![[medias/03 verlet integration-20260105-1.png]]

![[medias/03 verlet integration-20260105.png]]



L’**intégration de Verlet** (Verlet integration) est très populaire en développement de jeux pour plusieurs raisons :  
- **Précision suffisante** pour la plupart des applications.  
- **Rapidité** d’exécution, comparable à l’Euler semi-implicite.  
- **Stabilité numérique** exceptionnelle, surtout pour des systèmes de particules connectées par des contraintes.  
- **Réversibilité temporelle**, utile pour certaines simulations.

---

### Principe

Contrairement à Euler, Verlet **ne stocke plus la vitesse**.  
On ne conserve que :
- la **position actuelle** $x_n$, $y_n$,  
- et la **position précédente** $x_{n-1}$, $y_{n-1}$.  

La vitesse est implicite, donnée par la différence entre la position actuelle et la précédente :  
$v_n = \frac{x_n - x_{n-1}}{\Delta t}$  

La nouvelle position est alors calculée par la formule de Verlet :  
$x_{n+1} = x_n + (x_n - x_{n-1}) + a_n \cdot \Delta t^2$  
$y_{n+1} = y_n + (y_n - y_{n-1}) + a_n \cdot \Delta t^2$  

Ici, $a_n$ est l’accélération due aux forces appliquées sur la particule.

---

### Implémentation

1. **Stockage des positions** : chaque particule conserve sa position actuelle et précédente.  
   À l’initiation, la position précédente peut être initialisée égale à la position actuelle.  

2. **Calcul de l’accélération** :  
   $a = F / m$, où $F$ est la force appliquée et $m$ la masse de la particule.  

3. **Application de la formule de Verlet** :  
   - Calcul de la "vitesse implicite" : différence entre position actuelle et précédente.  
   - Mise à jour de la position suivante avec la formule ci-dessus.  

4. **Gestion des contraintes / collisions** :  
   - La position est ajustée si une particule dépasse les limites (murs, surfaces).  
   - Pour conserver la cohérence de la vitesse implicite, la **position précédente** est ajustée en conséquence :  
     $x_{n-1} = x_n + v_x$, $y_{n-1} = y_n + v_y$  
   Cela permet de maintenir la bonne vitesse lors de la projection sur la contrainte.

---

### Avantages

- **Précision suffisante** : comparable aux méthodes d’ordre supérieur pour de nombreuses simulations.  
- **Stabilité pour les systèmes contraints** : idéal pour les particules reliées par des ressorts, sticks ou contraintes multiples.  
- **Pas de stockage explicite de la vitesse** : simplifie le calcul et évite les erreurs de synchronisation entre position et vitesse.

---

### Conclusion

L’intégration de Verlet est particulièrement adaptée aux simulations temps réel impliquant plusieurs particules et contraintes.  
Elle combine **simplicité**, **rapidité**, et **stabilité numérique**, ce qui en fait un standard dans les moteurs physiques de jeux vidéo.
