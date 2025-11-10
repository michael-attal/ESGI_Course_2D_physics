# Exercice Final sur les Particules

Cet exercice conclut la partie sur les particules avant de passer aux corps rigides (*rigid bodies*).  

L'objectif est de combiner les particules avec les forces étudiées : ressorts (*spring force*), gravité (*weight force*), et autres interactions, pour explorer les effets collectifs et émergents.

Deux options de projet sont proposées.

---

## Option 1 : Chaîne de Particules

Créer une chaîne de particules connectées par des ressorts :  

- Un ancrage fixe en haut peut être conservé  
- Tableau de particules connectées entre elles par des ressorts  
- Paramètres ajustables : distance des ressorts, constante de raideur, masse des particules  
- Exemple : 10 à 15 particules reliées en chaîne, chaque nœud étant une particule reliée aux suivantes par un ressort  

---

Cette configuration permet d'observer l'effet d'une chaîne de particules soumise à des forces et contraintes multiples.

---

## Option 2 : Structure de Soft Body

Créer une structure de type corps souple (*soft body*) :  
- Plusieurs particules (ex. 4 à 5) reliées par des ressorts formant un squelette triangulaire  
- Chaque ressort maintient les particules à distance, simulant la cohésion d'un corps souple  
- Possibilité d'interaction via la souris ou le clavier pour appliquer des forces et déplacer le corps  

Cette option explore la dynamique d’un réseau de particules interconnectées, avec conservation approximative de la forme grâce aux ressorts.

---

## Modification de l’Implémentation de la Force de Ressort

La fonction `generateSpringForce` initiale reliait une particule à un ancrage fixe.  
Pour ces exercices, il faut créer une surcharge de la fonction permettant de relier deux particules :  
- Paramètres : particule A, particule B  
- La distance utilisée pour calculer la force est maintenant $$\vec{d} = \text{position}_A - \text{position}_B$$  
- Le calcul de la direction, magnitude et force finale reste identique à l’implémentation précédente  

---

Cette approche orientée objet permet d’utiliser la même fonction sous différents paramètres pour gérer plusieurs types de connexions entre particules.

---

## Application de la Fonction

Cette nouvelle fonction sert à générer les forces de ressort entre :  
- Les particules de la chaîne (*chain of particles*)  
- Les particules formant le corps souple (*soft body vertices*)  

Le ressort peut étendre ou comprimer, appliquant des forces attractives ou répulsives selon la position relative des particules.

---

## Choix et Mise en Œuvre de l’Exercice

- Option 1 : implémenter une chaîne de particules attachée à un ancrage fixe, interconnectée par des ressorts  
- Option 2 : créer un *soft body* avec plusieurs particules reliées par un réseau de ressorts triangulaires  

L’exercice permet de mettre en pratique les concepts de particules, de ressorts et de forces, et d’explorer les interactions dynamiques entre plusieurs éléments connectés.
