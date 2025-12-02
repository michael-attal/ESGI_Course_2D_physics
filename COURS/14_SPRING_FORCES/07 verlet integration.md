# Intégration de Verlet

Nous venons d’évoquer une méthode d’intégration numérique différente : l’intégration de Verlet (*Verlet integration*).

Nous continuerons à utiliser l’intégration d’Euler dans notre code, mais il est important de présenter quelques éléments supplémentaires à propos de Verlet avant de poursuivre.

---

L’intégration de Verlet est particulièrement adaptée aux problèmes impliquant des particules et des contraintes entre celles-ci. 

Des exemples typiques incluent des masses reliées par des ressorts ou des points connectés par des segments rigides (*sticks*).

---

L’exemple ci-dessous illustre une simulation de tissu 2D (*cloth simulation*) reposant sur cette méthode : la surface du tissu est représentée par un ensemble de points reliés entre eux par des contraintes fortes.

![[medias/cloth-verlet-integration.gif]]

---

L’intégration de Verlet est remarquablement stable dans ce type de scénario. 

Elle est idéale pour les simulations comportant des éléments mobiles possédant une certaine liberté de mouvement tout en restant liés les uns aux autres. 

Cette interconnexion implique que le mouvement d’une particule influence directement ou indirectement les autres — comme dans les systèmes de masses et ressorts, ou de points et segments rigides.

---

Il convient également de souligner que l’intégration de Verlet **n’est pas limitée** à ces systèmes de particules et de contraintes. 

Si elle est souvent choisie pour sa stabilité dans ce contexte, elle reste avant tout une méthode d’intégration numérique pouvant être appliquée à d’autres types de problèmes.

---

Il est recommandé de lire l’article rédigé par Marian Pekár intitulé [_Verlet Integration 2D Cloth Physics Simulation_](https://pikuma.com/blog/verlet-integration-2d-cloth-physics-simulation). 

Marian, développeur de jeux originaire de République tchèque, y présente une implémentation complète en C++ d’une simulation de tissu 2D utilisant Verlet. 
