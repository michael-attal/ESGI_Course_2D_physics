# Résolution de collision entre polygones — Impulsions linéaires et angulaires

---

## Contexte général

Nous avons détecté une collision entre deux polygones rigides à l’aide de l’algorithme SAT (*Separating Axis Theorem*).  
Les informations de collision ont été calculées : normale de collision (*collision normal*), profondeur de pénétration (*penetration depth*) et point de contact (*contact point*).  
Il s’agit maintenant de **résoudre cette collision** de manière physiquement réaliste.  

---

## Méthode de résolution : méthode des impulsions

Pour résoudre la collision, nous utilisons la **méthode des impulsions** (*impulse method*), déjà employée pour les collisions cercle–cercle.  
Cette méthode consiste à appliquer une impulsion instantanée aux corps rigides afin de les séparer et de modifier leurs vitesses.  

---

## Nouveauté par rapport aux cercles : la rotation

Dans le cas des cercles, une impulsion **linéaire** (*linear impulse*) suffisait.  
Pour les polygones, ce n’est plus le cas : la collision peut induire une **rotation**.  
Il faut donc désormais prendre en compte :
- une impulsion linéaire (changement de vitesse linéaire),
- une impulsion angulaire (*angular impulse*) provoquant un changement de vitesse angulaire (*angular velocity*).  

---

## Impulsion linéaire et impulsion angulaire

La résolution complète d’une collision entre deux polygones nécessite l’application simultanée de :
- une **impulsion linéaire**, qui modifie la vitesse du centre de masse,
- une **impulsion angulaire**, qui modifie la rotation du corps rigide.  

Ces deux effets sont indispensables pour obtenir un comportement réaliste, par exemple lorsqu’un objet commence à tourner après l’impact.  
#linear-impulse #angular-velocity #physics-simulation

---

## Rôle de la masse et du moment d’inertie

Pour calculer correctement ces impulsions, il est nécessaire de prendre en compte :
- la masse (*mass*) des objets,
- le moment d’inertie (*moment of inertia* ou *inertia tensor*).  

Ces grandeurs déterminent la manière dont un corps réagit à une impulsion, notamment en rotation.  
#moment-of-inertia #mass-properties #rotational-dynamics

---

## Rappel : vitesse linéaire sans rotation

Sans rotation, tous les points d’un corps rigide possèdent la **même vitesse linéaire** (*linear velocity*).  
La vitesse d’un point quelconque du corps est identique à celle du centre de masse (*center of mass*).  
La position du point n’a alors aucune influence sur la vitesse.  
#linear-velocity #center-of-mass #rigid-body-motion

---

## Cas avec rotation : vitesses différentes selon les points

Lorsqu’un corps rigide est en rotation, la situation change.  
La vitesse linéaire d’un point dépend alors de sa position par rapport au centre de masse.  
Un point situé sur le bord du corps se déplace plus rapidement qu’un point proche du centre.  
#rotation-effects #point-velocity #angular-motion

---

## Vitesse linéaire en un point P

Pour un corps rigide en rotation, la vitesse linéaire en un point P est différente de celle du centre de masse.  
Cette vitesse dépend :
- de la vitesse angulaire (*angular velocity*),
- du vecteur position **r** reliant le centre de masse au point P.  
#point-p #local-velocity #rigid-body-rotation

---

## Direction de la vitesse angulaire

Le vecteur vitesse angulaire **ω** (*angular velocity vector*) est perpendiculaire au plan de rotation.  
Il pointe selon la normale à la surface du disque ou du polygone en rotation, conformément à la règle de la main droite.  
#angular-velocity-vector #right-hand-rule #vector-physics

---

## Calcul de la vitesse linéaire au point P

La vitesse linéaire **v** au point P est donnée par le **produit vectoriel** (*cross product*) entre :
- la vitesse angulaire **ω**,
- le vecteur position **r**.  

Formule fondamentale :
  
**v = ω × r**

Cette vitesse est perpendiculaire à la fois à **ω** et à **r**.  
#cross-product #vector-math #linear-velocity

---

## Interprétation physique

La vitesse linéaire en un point d’un corps en rotation est tangentielle.  
Elle dépend de la distance du point au centre de masse et de la vitesse angulaire.  
Chaque point du corps possède donc une vitesse propre lorsqu’il y a rotation.  
#tangential-velocity #physical-interpretation #rotational-motion

---

## Lien avec la collision

Lors d’une collision entre polygones, le contact se fait en un point précis de la surface.  
Il est donc indispensable de calculer la **vitesse linéaire au point de contact**, et non uniquement celle du centre de masse.  
Cette vitesse intervient directement dans le calcul des impulsions de collision.  
#contact-point #collision-physics #impulse-calculation

---

## Transition vers le calcul des impulsions

Maintenant que la vitesse au point de contact est définie, nous pouvons passer à l’étape suivante.  
La prochaine étape consistera à calculer l’impulsion **j** (*impulse magnitude*), en tenant compte :
- des vitesses linéaires et angulaires,
- des masses et moments d’inertie,
- de la normale de collision.  

C’est cette impulsion qui permettra de résoudre la collision de manière réaliste.  
#impulse-magnitude #collision-response #next-lecture
