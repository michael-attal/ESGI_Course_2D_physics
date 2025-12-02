# Transition to Angular Motion and Shapes

Nous avons désormais migré toute la logique depuis la classe *particle* vers une classe plus générale nommée **body**.  
Cette classe continue d’inclure les notions de mouvement linéaire :  
- position,  
- vélocité,  
- accélération,  
- somme des forces.  

Cependant, avec un **rigid body**, nous devons introduire de nouveaux éléments liés au **mouvement angulaire**.  
En plus du mouvement linéaire, nous étudierons :  
- l’angle,  
- la vélocité angulaire,  
- l’accélération angulaire,  
- le couple (torque).  

Ces notions seront détaillées très bientôt.

En plus de la masse et de son inverse, un *body* doit désormais posséder un **pointeur vers une forme géométrique**.  
Ce pointeur référence un objet dérivé d’une classe `Shape`.

Lors de la création d’un *body*, nous pouvons directement lui associer :  
- une forme *circle*,  
- une forme *polygon*,  
- une forme *box*.  

Le constructeur de `Body` accepte ainsi un paramètre `ShapeType` afin de créer un corps rigide avec la forme appropriée.  
Les méthodes classiques (`AddForce`, `ClearForces`, `Integrate`) restent identiques et gèrent toujours la dynamique linéaire.

---

# Shape Class Overview

La classe `Shape` constitue une **classe parent** générique pour toutes les formes géométriques.  
Elle propose :  
- une structure commune,  
- une méthode `GetType()` pour récupérer le type de forme (circle, polygon, box),  
- une méthode `GetMomentOfInertia()` que chaque forme doit surcharger.

Le **moment d’inertie** dépend de la géométrie et de la masse.  
Chaque forme fournit sa propre implémentation.  
Nous étudierons son calcul en détail dans la suite du cours.

L’héritage permet donc à chaque forme de redéfinir :  
- son type,  
- son moment d’inertie,  
- ses propriétés géométriques internes.

---

# Circle Shape

La structure `CircleShape` dérive de `Shape`.  
Elle contient :  
- un rayon (`float radius`).

Elle surcharge :  
- `GetType()` pour retourner `CIRCLE`,  
- `GetMomentOfInertia()` pour fournir le moment d’inertie spécifique aux cercles.

C'est la forme la plus simple à mettre en œuvre, tant en dessin qu'en détection de collisions.

---

# Polygon Shape

La structure `PolygonShape` dérive elle aussi de `Shape`.  
Elle contient :  
- un vecteur de sommets (`std::vector<Vec2> vertices`).

Elle propose :  
- un constructeur par défaut,  
- un constructeur acceptant directement une liste de sommets,  
- une implémentation personnalisée du moment d’inertie.

Elle permet de représenter :  
- triangles,  
- quadrilatères,  
- pentagones,  
- polygones convexes à *N* sommets.

L’ensemble des polygones gérés doit être **convexe**.  
Nous verrons plus tard la distinction entre convexité et concavité.

---

# Box Shape

La structure `BoxShape` représente un **polygone particulier**, dérivé de `PolygonShape`.  
Un *box* est un polygone à **quatre sommets** défini par :  
- une largeur,  
- une hauteur.

Le constructeur `BoxShape(width, height)` se charge d’initialiser automatiquement les quatre sommets du rectangle.  
Elle surcharge également `GetMomentOfInertia()`.

Ainsi, une *box* n'est qu'un polygone spécialisé.

---

# Implementation Plan

Le diagramme de classes utilisé repose sur :  
- une classe `Shape`,  
- trois classes dérivées : `CircleShape`, `PolygonShape`, `BoxShape`,  
- une classe `Body` contenant un pointeur vers une `Shape`.

Chaque *body* peut donc recevoir la géométrie de son choix, être déplacé, tourner, entrer en collision, rebondir, etc.

La mise en œuvre suivra cet ordre :  
1. Implémentation de `Shape`.  
2. Implémentation de `CircleShape`.  
3. Tests avec un moteur basé uniquement sur les cercles (collisions simples).  
4. Implémentation de `PolygonShape`.  
5. Implémentation de `BoxShape`.  
6. Intégration des rotations et des moments d’inertie.  

Les **cercles** seront les premiers objets testés, car ils sont simples à manipuler et constituent une excellente entrée vers les collisions rigides.  
Ensuite viendront les polygones, puis enfin la *box*, forme rectangulaire particulièrement utilisée en simulation.

Ce plan structure la transition vers un moteur physique 2D complet :  
- gestion de formes,  
- mouvements linéaires et angulaires,  
- rigidité,  
- collisions étendues.

