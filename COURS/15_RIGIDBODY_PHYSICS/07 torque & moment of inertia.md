# Introduction  
Nous venons d’introduire les notions de vitesse angulaire (*angular velocity*) et d’accélération angulaire (*angular acceleration*), qui correspondent directement aux concepts déjà vus en mouvement linéaire — vitesse (*velocity*) et accélération (*acceleration*) — mais appliqués cette fois à une rotation autour d’un axe donné.  
#physics/rotation, #physics/torque

# Comment initier une accélération angulaire  
La question suivante est : comment initier une accélération angulaire ? Pour modifier l’accélération angulaire d’un objet, on applique un *torque* (couple). Le *torque* représente la capacité d’une force à faire tourner un objet autour d’un axe. On le note généralement avec la lettre grecque τ (*tau*).  
#physics/torque, #physics/forces

# Définition formelle du torque  
La définition formelle du torque en mécanique repose sur la formule :  
$$\tau = F \cdot d \cdot \sin(\theta)$$  
où $F$ est la force appliquée, $d$ la distance au point d’application, et $\theta$ l’angle entre la direction de la force et le bras de levier.  
#physics/torque, #maths/formulas

# Force, distance et angle  
Considérons un objet et son centre de masse servant d’axe de rotation. En appliquant une force à une certaine distance du centre, la direction de cette force influence le torque produit. L’angle $\theta$ représente précisément cet écart entre la direction de la force et le bras de levier.  
#physics/torque, #physics/rotation

# Effet de l’angle sur le torque  
Le torque est maximal lorsque $\theta = 90^\circ$, car $\sin(\theta)$ est alors maximal. Si la force est appliquée parallèlement au bras de levier ($\theta = 0$), le torque devient nul : aucune rotation ne peut être induite.  
#physics/torque, #maths/trigonometry

# Maximum de torque et fonction sinus  
Ainsi, l’application d’une force perpendiculaire génère le torque maximal. La présence du terme $\sin(\theta)$ reflète cette relation géométrique essentielle.  
#physics/torque, #maths/trigonometry

# Rôle de la distance (d)  
La distance $d$ entre le point d’application de la force et l’axe de rotation influence grandement le torque. Comme pour une porte : il est bien plus facile de l’ouvrir en poussant près de la poignée qu’au niveau des charnières.  
#physics/torque, #physics/levers

# Composantes du torque  
Le torque résulte donc de trois éléments :  
— la force appliquée ;  
— la distance au centre de rotation ;  
— l’angle de la force.  
Ces trois composantes déterminent l’intensité de la rotation induite.  
#physics/torque, #physics/rotation

# Simplification du torque pour un moteur physique  
Dans un moteur physique, ce formalisme peut être simplifié. Le torque y est traité de manière analogue à la force en mouvement linéaire.  
#physics/engines, #physics/torque

# Analogie torque / accélération angulaire  
L’équation fondamentale devient :  
$$\tau = I \alpha$$  
où $I$ est le *moment d’inertie* (*moment of inertia*) et $\alpha$ l’accélération angulaire (*angular acceleration*). Cette équation est l’équivalent rotationnel de $$F = m a$$.  
#physics/rotation, #maths/formulas

# Comprendre le moment d’inertie  
Le *moment d’inertie* mesure la résistance d’un objet à l’accélération angulaire. Plus $I$ est grand, plus il est difficile de modifier sa vitesse angulaire.  
#physics/inertia, #physics/rotation

# Relation entre torque, force et inertie  
Ainsi, l’accélération angulaire s’obtient par :  
$$\alpha = \frac{\tau}{I}$$  
Le moment d’inertie joue donc exactement le rôle de la masse en mouvement linéaire.  
#physics/inertia, #maths/formulas

# Moment d’inertie et forme  
Comme la masse influence le mouvement linéaire, la distribution de masse d’un objet influence son moment d’inertie. Il dépend de la géométrie de l’objet.  
#physics/shapes, #physics/inertia

# Calcul du moment d’inertie  
Chaque forme géométrique possède une formule spécifique de moment d’inertie. Deux exemples :  
— disque plein : $$I = \frac{1}{2} m r^2$$  
— rectangle plein : $$I = \frac{1}{12} m (w^2 + h^2)$$  
#physics/inertia, #maths/formulas

# Exemples selon différentes formes  
Un cercle ne résiste pas à la rotation de la même manière qu’un rectangle. Les formules tiennent compte de ces variations géométriques.  
#physics/shapes, #physics/inertia

# Influence de la masse  
La masse intervient naturellement : un objet plus massif est plus difficile à mettre en rotation.  
#physics/inertia, #physics/mass

# Moment d’inertie du rectangle  
Pour un rectangle :  
$$I = \frac{1}{12} m (w^2 + h^2)$$  
comme dans la définition standard.  
#physics/inertia, #maths/formulas

# Référence Wikipédia  
La page Wikipédia sur le moment d’inertie recense de nombreuses formules et noms alternatifs comme *angular mass* (masse angulaire), terme très explicite.  
#physics/inertia, #references/wikipedia

# Masse angulaire  
Le moment d’inertie détermine le torque nécessaire pour produire une accélération angulaire donnée.  
#physics/inertia, #physics/torque

# Comparaison avec l’accélération linéaire  
Comme la masse détermine la force requise pour accélérer linéairement, le moment d’inertie détermine le torque nécessaire pour accélérer en rotation.  
#physics/rotation, #physics/inertia

# Exemples supplémentaires  
La page rassemble de nombreux cas : masse ponctuelle, anneau, tige, disque plein, etc.  
#physics/shapes, #physics/inertia

# Exemple du disque  
Pour un disque plein :  
$$I = \frac{1}{2} m r^2$$  
identique à la formule précédente.  
#physics/disc, #physics/inertia

# Implémentation en code  
Dans le cas d’un moteur physique, on utilise ces formules pour initialiser le moment d’inertie des formes définies (cercle, rectangle, etc.).  
#physics/engines, #coding/physics

# Passage en 3D  
En 3D, le moment d’inertie devient un *tenseur d’inertie* (*inertia tensor*), représenté par une matrice.  
#physics/3d, #physics/inertia

# Retour au cas 2D  
En 2D, un simple scalaire suffit, d’où la simplicité de nos formules.  
#physics/2d, #physics/inertia

# Récapitulatif 2D  
Pour un rectangle ou un cercle, les formules du moment d’inertie correspondent exactement aux modèles physiques standard.  
#physics/2d, #physics/shapes

# Mise en œuvre dans le code  
Chaque forme possède une méthode interne `getMomentOfInertia()` renvoyant la partie géométrique de la formule.  
#coding/physics, #physics/inertia

# Ajout de la masse  
Le moment d’inertie final du *rigid body* est obtenu en multipliant cette valeur par la masse du corps.  
#physics/mass, #coding/physics

# Masse dans le corps rigide  
La masse appartient au *body* et non à la forme. Le calcul final du moment d’inertie doit donc être fait dans le constructeur du corps rigide.  
#coding/architecture, #physics/inertia

# Structure du constructeur  
Le constructeur crée la forme, la position, l’accélération, puis calcule le moment d’inertie complet via :  
shape.getMomentOfInertia() × mass.  
#coding/physics, #oop/design

# Exemple pour le rectangle  
La forme rectangle renvoie uniquement $\frac{1}{12} (w^2 + h^2)$, puis le corps rigide multiplie par la masse.  
#physics/shapes, #coding/physics

# Séparation des responsabilités  
La forme gère la géométrie, le corps gère les propriétés physiques globales.  
#co
