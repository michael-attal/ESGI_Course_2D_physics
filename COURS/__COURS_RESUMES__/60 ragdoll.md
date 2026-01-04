**Simuler la physique d’un ragdoll à l’aide de contraintes de joint**


Les _ragdolls_ correctement conçus n’utilisent pas uniquement des contraintes de joint, mais également d’autres types de contraintes, comme les **charnières** (_hinges_).

Si nous décidons d’implémenter un _ragdoll_ en utilisant uniquement des contraintes de joint, nous observerons probablement des comportements non naturels. Cependant, cela ne signifie pas que l’expérience ne soit pas intéressante à tenter.

En tant qu’activité proposée, essayons donc de simuler un _ragdoll_ en utilisant exclusivement des contraintes de joint.

Nous devrions commencer par ajouter les corps rigides qui composeront les différentes parties du _ragdoll_. Un _ragdoll_ simple devrait comporter au minimum une tête, un torse, des bras et des jambes.

![[medias/60 ragdoll-20251226.png]]

Votre première tâche consiste à créer les corps rigides suivants :

- **Tête** : `CircleShape(25)`
    
- **Torse** : `BoxShape(50, 100)`
    
- **Bras gauche** : `BoxShape(15, 70)`
    
- **Bras droit** : `BoxShape(15, 70)`
    
- **Jambe gauche** : `BoxShape(20, 90)`
    
- **Jambe droite** : `BoxShape(20, 90)`
    

Vous pouvez également utiliser la **grille de référence ci-dessous** pour vous aider à définir la position initiale des différentes parties du _ragdoll_.

![[medias/60 ragdoll-20251226-1.png]]

La dernière tâche consiste à ajouter des **contraintes de joint** entre les différentes parties du _ragdoll_. Il s’agit probablement de l’étape la plus délicate, car il est nécessaire d’ajuster finement les **points d’ancrage** afin que le _ragdoll_ se comporte comme attendu. N’oubliez pas également de jouer avec le **facteur de biais** (_bias factor_, compris entre 0 et 1) afin de trouver une valeur correspondant à vos attentes.

Le mouvement de votre _ragdoll_ n’a pas besoin d’être parfait. Essayez différentes valeurs et expérimentez avec les paramètres. 
