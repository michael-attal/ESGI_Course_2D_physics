# Introduction

Nous revenons maintenant à l’étape suivante : être capable d’afficher les formes, en commençant par les cercles.  
L’objectif est de dessiner visuellement les différentes géométries associées aux corps rigides.  

# Removing Radius from Body

Première correction nécessaire : le rayon d’un corps n’appartient plus à la classe `Body`.  
Ce rayon provenait de l’ancienne implémentation des particules ; désormais, seule la classe `CircleShape` possède un attribut `radius`.  
Il faut donc :

- supprimer l’attribut `radius` de `Body`,  
- adapter le code de collision qui utilisait `body.radius`,  
- faire en sorte que toutes les informations géométriques proviennent exclusivement de la forme.

La suppression du rayon dans `Body` génère des erreurs, notamment dans le test de collision contre les limites de la fenêtre : ce code utilisait l’ancien `body.radius`. Il faut donc récupérer le rayon directement depuis la forme, lorsqu’elle est de type cercle.

# Collision Check Update

Dans la boucle qui parcourt tous les corps, un test est ajouté :  

- si la forme du corps existe,  
- si son type est `CIRCLE`,  
- alors on récupère un pointeur vers `CircleShape`, en le castant depuis le pointeur de base `Shape*`.

Une fois ce cast effectué, toutes les références à `body.radius` sont remplacées par `circleShape->radius`.  
Un remplacement global est effectué sur la section du code concernée.  
Seuls les corps circulaires sont testés contre les frontières de la fenêtre.

# Replacing Body Radius with Circle Radius

Le code du test de collision est donc entièrement mis à jour pour utiliser le rayon provenant de la forme.  
Cela garantit que la logique repose sur l’architecture polymorphique, et non sur un attribut obsolète dans `Body`.  

# Rendering Shapes

Le même principe s’applique au rendu :  
dans la boucle de dessin, on vérifie si la forme associée au corps est un cercle.  
Si oui :

- on cast la forme vers `CircleShape`,  
- on utilise son rayon,  
- on dessine le cercle avec la méthode adaptée.

Pour l’instant, seuls les cercles sont dessinés. Les autres formes seront ajoutées plus tard.

# Drawing and Rotation

On remplace `drawFilledCircle` par `drawCircle`, car ce dernier accepte un paramètre supplémentaire : l’angle de rotation.  
Ce changement est important, car nous entrons dans le domaine des corps rigides capables de tourner.

La signature de la fonction impose :

- x  
- y  
- radius  
- angle  

On passe pour le moment un angle constant, par exemple `0.0f`, afin de tester le pipeline de rendu.

# Implementing Rotation Test

Pour démontrer visuellement l’effet de l’angle, une variable statique `angle` est ajoutée dans la fonction de rendu.  
À chaque appel de cette fonction :

- `angle` augmente légèrement (par exemple +0.01 radians),  
- l’angle évolue de manière continue et persistante, grâce au mot-clé `static`.

On transmet ensuite cet angle à la fonction qui dessine le cercle.  
Le cercle est alors affiché avec une ligne indiquant son orientation, technique courante dans les moteurs physiques 2D.

# Visualization of Rotation

Le résultat : un cercle tournant lentement grâce à l’incrémentation continue de l’angle.  
Cette rotation n’est pas encore liée aux propriétés physiques du corps :

- pas d’angle intrinsèque du corps,  
- pas de vitesse angulaire réelle,  
- pas d’accélération angulaire,  
- pas de moment d’inertie.

Ceci n’est qu’un test visuel pour valider la chaîne de rendu.

# Angular Motion Preview

La prochaine étape consiste à introduire les notions de mouvement angulaire :

- angle du corps,  
- vitesse angulaire (*angular velocity*),  
- accélération angulaire (*angular acceleration*),  
- influence du moment d’inertie.

Nous construirons progressivement la mécanique complète permettant aux corps rigides de tourner correctement, tout comme ils se déplacent en translation.

