# Introduction à la Physique des Particules

---

Maintenant que toutes les dépendances sont installées et fonctionnent, nous pouvons compiler notre projet.  
Nous savons même comment afficher quelque chose à l’écran à l’aide de **SDL**, comme un cercle ou un rectangle, voire un petit polygone.  
Toutes ces fonctions sont déjà prêtes à être utilisées pour dessiner à l’écran.  
C’est le point de départ de notre discussion sur la physique proprement dite.  
Comme le titre l’indique, il s’agit ici de **physique des particules**, et nous allons commencer par manipuler des **particules simples**, à la base de notre cours.  

---

## Simplification avec les Particules

Nous allons simplifier notre approche en ne considérant que des **objets particules**.  
L’objectif est de débuter avec la **simulation de particules élémentaires**, ce qui rend l’analyse des propriétés physiques beaucoup plus accessible.  
Nous pourrons ainsi étudier les notions de **mouvement linéaire** : vitesse, accélération, forces appliquées, et déplacement.  

---

Les particules n’ayant **ni forme ni volume**, nous n’avons pas à gérer les rotations ou les corps rigides.  
Elles représentent ce qu’on appelle des **masses ponctuelles**, c’est-à-dire de simples points dans l’espace, dotés d’une masse (1 kg, 2 kg, 100 kg, etc.) mais sans forme géométrique ni sommets.  
Une particule ne peut pas tourner : c’est un point défini par sa position et sa masse.  

---

## Visualisation des Particules

Bien que les particules soient sans forme, nous voulons pouvoir **visualiser** leur position, leur direction et leur vitesse.  
Puisque nous savons déjà dessiner des cercles grâce à notre classe graphique, nous représenterons chaque particule par un **petit cercle** à l’écran.  
Ce cercle symbolisera la position de la masse ponctuelle et permettra de suivre son mouvement.  

---

## Mouvement des Particules

Nous devons maintenant représenter le **mouvement** de ces particules dans notre moteur.  
Chaque particule a une position sur notre canvas 2D, mais nous voulons lui appliquer une **vitesse** et éventuellement une **force**.  
Ces grandeurs permettront de calculer le **déplacement** au cours du temps, simulant ainsi le mouvement.  

---

## Mécanique Newtonienne

Pour modéliser ces mouvements, notre moteur se basera sur la **mécanique newtonienne**.  
Il s’agit du cadre conceptuel introduit par **Isaac Newton**, décrivant le comportement des corps soumis à des forces.  
C’est cette approche dite "classique" qui est enseignée au lycée : on y étudie les grandeurs comme la **vitesse**, l’**accélération**, le **déplacement**, ou la **force** appliquée à un corps.  

---

On ne s’intéresse pas ici au niveau subatomique (atomes, électrons), mais à une description macroscopique et intuitive.  
Ces lois, connues sous le nom de **trois lois du mouvement de Newton**, forment la base de toute notre simulation.  

---

### Première Loi — Loi d’Inertie

Si **aucune force** n’est appliquée à un objet, sa **vitesse ne change pas**.  

Autrement dit :
- un objet immobile reste immobile ;
- un objet en mouvement à vitesse constante continue son mouvement indéfiniment, dans la même direction et à la même vitesse.  

C’est la **loi d’inertie**.  
Dans notre moteur physique, si aucune force n’agit sur la particule, sa vitesse ne doit pas varier.  
Ce principe sera directement intégré dans la logique de notre simulation.  

---

### Deuxième Loi — Relation Force, Masse et Accélération

Cette loi exprime le lien fondamental entre la **force (F)**, la **masse (m)** et l’**accélération (a)** :  
$$
F = m \times a
$$

L’accélération est le **taux de variation de la vitesse** d’un objet.  
Ainsi,  
$$
a = \frac{F}{m}
$$

---

Cette équation nous donne une intuition essentielle :
- plus la masse est **grande**, plus il est **difficile d’accélérer** un objet ;
- plus la masse est **petite**, plus l’objet est **facile à accélérer**.  

L’accélération est **inversement proportionnelle à la masse**.  
Une grande masse diminue l’accélération pour une même force appliquée, tandis qu’une petite masse l’augmente.  
C’est le cœur de la dynamique newtonienne, que nous utiliserons directement dans notre moteur de particules.  

---

### Troisième Loi — Action et Réaction

Pour chaque action, il existe une **réaction égale et opposée**.  
Autrement dit, lorsqu’un corps exerce une force sur un autre, le second exerce une force de **même intensité** mais de **direction opposée**.  
Si j’appuie sur un mur, le mur exerce une force égale sur moi en sens inverse.  
Cette symétrie des interactions est un principe fondamental de la physique newtonienne.  

---

## Application des Lois de Newton dans le Moteur

Ces trois lois sont la **base de notre moteur physique**.  
Elles imposent que :
- sans force, la vitesse reste constante (inertie) ;
- la force détermine l’accélération selon la masse (seconde loi) ;
- toute interaction entre deux objets respecte l’action-réaction (troisième loi).  

Nous modéliserons donc le comportement de nos particules selon ces lois, en vérifiant à chaque étape que la simulation les respecte.  

---

## Aperçu de la Classe Particle

Notre classe `Particle` contiendra les éléments essentiels du mouvement :
- **position** : vecteur (x, y)
- **vitesse** : vecteur (x, y)
- **accélération** : vecteur (x, y)
- **masse** : valeur flottante représentant la masse ponctuelle

Chaque particule sera donc définie par ces grandeurs physiques.  
Le constructeur permettra d’initialiser la position et la masse.  
C’est à partir de ces attributs que nous appliquerons les lois du mouvement pour mettre à jour la position et la vitesse dans le temps.  

---

## Conclusion

Nous avons désormais les bases théoriques nécessaires :  
les trois lois de Newton et la représentation mathématique des particules.  
La prochaine étape consiste à les traduire en code dans notre moteur,  
en commençant par l’implémentation de la classe `Particle` et de ses propriétés dynamiques.  
