## Inverse de la masse

Nous avons vu que la masse influence la force appliquée et l’accélération des particules.  
Nous entrons maintenant dans le domaine des forces appliquées dynamiquement, pour changer le comportement des particules.  
Un détail important, présent dans presque tous les moteurs physiques, est l’utilisation de l’inverse de la masse.

---

## De la masse à l’inverse de la masse

Dans `particle.h`, nous stockons actuellement le rayon de la particule, sa position, sa vitesse, son accélération et la somme des forces appliquées, ainsi que la masse.  
La plupart des moteurs physiques stockent plutôt **l’inverse de la masse**.  
Certains moteurs ne stockent même pas la masse, uniquement son inverse, soit $\frac{1}{m}$, l’*inverse* de la masse.

---

## Pourquoi utiliser l’inverse de la masse

La raison est simple : la majorité des calculs nécessitent l’inverse de la masse.  
Au lieu de diviser à chaque calcul par la masse (opération coûteuse), on stocke directement l’inverse pour gagner en performance.

---

## Conserver les deux valeurs

On peut stocker seulement l’inverse, mais ici, nous conservons les deux pour des raisons pédagogiques.  
Dans `particle.cpp`, lors de l’initialisation :  

```cpp
if (mass != 0.0) inverseMass = 1.0 / mass; else inverseMass = 0.0;
```

Cela permet d’éviter une division par zéro si la masse est nulle.

---

## Intégration et accélération

Lors de l’intégration pour calculer l’accélération à partir des forces, on peut remplacer la division par la masse par une multiplication par l’inverse de la masse :  
$F \times \frac{1}{m} = a$  
Ceci est totalement équivalent à la méthode précédente.

---

## Pratique dans les moteurs physiques

L’inverse de la masse est utilisé dans quasiment tous les moteurs physiques : Box2D, Chipmunk, Bullet, etc.  
Dans notre cas, chaque particule stocke également l’inverse de sa masse.

---

## Validation

Pour vérifier, on exécute le programme et le comportement reste identique à avant.  
Ainsi, l’**inverse de la masse** est prêt à être utilisé dans toutes les opérations futures.