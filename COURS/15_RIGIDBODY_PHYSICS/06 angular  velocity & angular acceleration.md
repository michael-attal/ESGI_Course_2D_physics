# Introduction

Nous abordons désormais la question de la rotation d’un objet.  
Jusqu’ici, nous n’avons traité que le mouvement linéaire : déplacement, vélocité et accélération.  
Il faut maintenant introduire la notion de rotation, c’est-à-dire la mise en mouvement autour du centre de masse de l’objet.  
Il ne s’agit pas d’un mouvement orbital autour d’un point extérieur, mais bien d’une rotation autour du centre de l’objet lui-même.  
Nous avions déjà manipulé un paramètre *angle* lors du dessin des cercles, mais sans qu’il corresponde réellement à l’état interne du corps physique.  
La classe `Body` ne possède aucun angle de rotation propre, et c’est ce que nous allons mettre en place à présent.  
Nous allons donc introduire les notions de vitesse angulaire et d’accélération angulaire.  

# Angular Velocity and Acceleration

Intuitivement, la vitesse angulaire correspond au taux de variation d’un angle au cours du temps.  
Lorsque l’angle évolue, cette variation définit une vitesse, et si cette vitesse elle-même change, cela produit une accélération angulaire.  
Pour représenter l’angle de rotation, on utilise la lettre grecque θ (*theta*).  
Le taux de variation de θ par unité de temps constitue la vitesse angulaire, notée ω (*omega*).  
L’accélération angulaire correspond au taux de variation de cette vitesse, et elle est notée α (*alpha*).  

# Relationship with Linear Motion

En mouvement linéaire, la vitesse est définie comme la variation de la position divisée par le temps.  
Dans le cas angulaire, le principe est strictement analogue :  
la vitesse angulaire est la variation de l’angle divisée par le temps.  
De la même manière, si la vitesse angulaire varie, son taux de variation constitue l’accélération angulaire.  
On retrouve donc la même structure logique que pour le mouvement linéaire :  
vitesse → accélération, mais appliquée à des angles exprimés en radians.  

# Linear and Angular Kinematics

Les grandeurs linéaires et angulaires sont analogues.  
La vitesse linéaire se note $v$, la vitesse angulaire $ω$.  
De même, l’accélération linéaire $a$ correspond à la variation de $v$ divisée par le temps,  
tandis que l’accélération angulaire $α$ correspond à la variation de $ω$ sur le temps.  
On obtient donc deux systèmes parallèles :  
— linéaire : variation de position et variation de vitesse ;  
— angulaire : variation d’angle et variation de vitesse angulaire.  

# Units and Representation

Les angles sont toujours exprimés en radians.  
Les frameworks graphiques et moteurs physiques utilisent systématiquement cette unité,  
et il faut s’y conformer lors de l’écriture du code.  

# Linear and Angular Kinematics Relationship

Les relations entre mouvements linéaires et angulaires suivent un même schéma.  
Pour le mouvement linéaire, les formules classiques sont :  
$v = v_0 + a t$  
et  
$\Delta x = v_0 t + \frac{1}{2} a t^2$.  
Les équations équivalentes existent pour le mouvement angulaire, où il suffit de remplacer $v$ par $ω$ et $a$ par $α$.  
Cette symétrie permet de comprendre facilement les correspondances entre les deux domaines.  

# Angular Kinematics Formulas

Pour le mouvement angulaire :  
— la vitesse angulaire est définie par $\Delta θ / \Delta t$ ;  
— l’accélération angulaire est définie par $\Delta ω / \Delta t$.  
Les équations analogues aux équations linéaires sont :  
$ω = ω_0 + α t$  
et  
$\Delta θ = ω_0 t + \frac{1}{2} α t^2$.  
On retrouve exactement la même structure cinématique que pour le mouvement linéaire.  

# Implementation in the Body Class

Dans la classe `Body`, où se trouvent déjà les grandeurs linéaires (position, vitesse, accélération, masse, inverse de masse),  
il faut ajouter les grandeurs angulaires :  
— l’angle de rotation (en radians) ;  
— la vitesse angulaire ;  
— l’accélération angulaire.  
En 2D, ces valeurs peuvent être représentées par de simples scalaires.  

# Scalar Representation in 2D

En 2D, l’angle se mesure avec un seul nombre,  
et la vitesse angulaire ainsi que l’accélération angulaire sont également des scalaires.  
Contrairement à la 3D, où les rotations impliquent des vecteurs ou des quaternions,  
le mouvement angulaire en 2D se résume à trois flottants :  
angle, vitesse angulaire, accélération angulaire.  

# Integration Function

L’intégration angulaire doit être ajoutée à l’intégration existante du mouvement linéaire.  
On applique le même principe qu’en intégration d’Euler :  
— la vitesse angulaire est mise à jour en ajoutant $α × dt$ ;  
— l’angle de rotation est mis à jour en ajoutant $ω × dt$.  
Ce processus est strictement analogue à l’intégration de la vitesse et de la position en mouvement linéaire.  
On obtient ainsi une fonction `integrateAngular()` exécutée en parallèle de l’intégration linéaire.  

# Conclusion and Next Steps

Nous avons introduit toutes les grandeurs nécessaires pour décrire le mouvement angulaire :  
θ, ω, α, et leur intégration dans le temps.  
Mais pour mettre réellement un objet en rotation, il faut un équivalent angulaire de la force linéaire.  
De même que la force produit une accélération linéaire, il existe une grandeur qui produit une accélération angulaire :  
le *torque*, ou moment de force.  
Dans la suite, nous étudierons en détail le torque et le moment d’inertie, deux concepts fondamentaux pour générer un mouvement de rotation réaliste.  
