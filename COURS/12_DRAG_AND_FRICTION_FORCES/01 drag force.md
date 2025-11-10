## Application des forces aux particules

Nous arrivons à un point essentiel du cours : l’application des forces à nos particules.  
Nous avons appliqué plusieurs types de forces — le **poids**, la **force du vent**, ou encore une **force de poussée**.  

---


L’application de ces forces dans notre moteur est simple : il suffit d’appeler `particle.addForce()` avec le vecteur représentant la force à appliquer.  
La vraie question est : quelles forces peut-on générer ?  
En réalité, tout dépend de ce que l’on souhaite simuler. Certaines forces proviennent directement du monde réel — comme la **friction**, la **traînée** (*drag*) ou les **forces de ressort** — et peuvent être modélisées numériquement dans notre simulation physique.

---

## Introduction à la force de traînée

Commençons par une force très courante : la **force de traînée** (*drag force*).  
Lorsqu’un objet se déplace dans un fluide (air, eau, huile, etc.), il subit une résistance qui s’oppose à son mouvement.  

---

Cette force agit **dans la direction opposée à la vitesse** et dépend toujours du fluide environnant.  
Ainsi, que l’objet se déplace dans l’air ou dans l’eau, il subira une résistance liée aux propriétés du fluide dans lequel il se trouve.

---

## Dépendance à la vitesse

Contrairement à la friction, la traînée dépend directement de la **vitesse** de l’objet.  
Plus l’objet se déplace rapidement, plus la force de traînée augmente.  
À faible vitesse, la traînée est presque négligeable, mais à grande vitesse, elle devient une composante majeure du mouvement.

---

### Formule de la force de traînée

La force de traînée dépend du carré de la vitesse.  
Sa formule générale est :  

$$
\vec{F_d} = \frac{1}{2} \times \rho \times C_d \times A \times ||v||^{2} \times -\hat{v}
$$

---

où :  
- $\rho$ est la densité du fluide,  
- $C_d$ est le coefficient de traînée du fluide,  
- $A$ est l’aire de section transversale (*cross-sectional area*),  
- $v$ est la vitesse de la particule.  

Cette force agit toujours **dans le sens opposé à la vitesse**.

---

## Les constantes de la formule

Bien que cette formule puisse sembler complexe, la plupart des termes sont des **constantes** :  
- $\frac{1}{2}$ est un facteur fixe,  
- $\rho$ dépend du fluide (air, eau, huile, etc.),  
- $C_d$ dépend de la forme de l’objet et du fluide,  
- $A$ dépend de la surface exposée au flux.  

---

En simulation, nous ajustons ces constantes empiriquement pour obtenir un comportement visuel cohérent.

---

## Aire de section transversale

L’aire de section transversale $A$ représente la surface de contact entre l’objet et le fluide pendant le déplacement.  
Un objet profilé (comme une aile d’avion) a une petite surface exposée, donc une faible traînée.  
Au contraire, un objet volumineux ou non aérodynamique subira une traînée importante.  
La force de traînée est donc **proportionnelle** à cette surface.

---

## Simplification pour les particules

Dans notre cas, les particules sont assimilées à des **points de masse**.  
Elles n’ont pas réellement de surface.  
Nous pouvons donc simplifier notre formule en supposant :  $A = 1.0$

Cette simplification nous permet d’alléger les calculs sans affecter la cohérence du comportement visuel.

---

## Formule finale simplifiée

En regroupant toutes les constantes dans un seul coefficient $k$, la formule devient :  
$\vec{F}_d = -k \times \|\vec{v}\|^2 \times \hat{v}$

---

où :  
- $k$ regroupe $\frac{1}{2} \rho C_d A$,  
- $\|\vec{v}\|$ est la norme de la vitesse,  
- $\hat{v}$ est le vecteur vitesse normalisé,  
- Le signe négatif indique que la force agit **dans le sens opposé au mouvement**.  
- Dans notre moteur, $k$ représente la résistance du fluide : plus $k$ est grand, plus la traînée est forte.

---

## Génération de la force de traînée en code

Nous allons créer une fonction utilitaire dans un module `force.h` / `force.cpp`.  
Ce module contiendra plusieurs fonctions statiques pour générer les forces classiques : friction, traînée, ressort, etc.  
L’objectif est de pouvoir écrire simplement :  

```cpp
particle.addForce(drag);
```

---



## Implémentation de generateDragForce

La fonction `generateDragForce()` procède ainsi :

1. Vérifie si la particule a une vitesse non nulle.
2. Calcule la direction de la traînée : le vecteur vitesse normalisé, inversé.
3. Calcule la magnitude : $k \times ||\vec{v}||^{2}$.
4. Combine direction et magnitude pour obtenir la force finale.
5. Retourne la force de traînée à appliquer à la particule.

---

Cette méthode évite le calcul coûteux de la racine carrée en utilisant la norme au carré de la vitesse.

---

## Application dans la simulation

Une fois la force de traînée générée :

- Elle est appliquée dès que la particule entre dans un fluide.
- Le coefficient $k$ ajuste la résistance du fluide.
- La direction est automatiquement calculée à partir de la vitesse.

---

Un $k$ élevé simulera un fluide visqueux (boue, huile), tandis qu’un $k$ faible représentera un fluide léger (air).