### Force de friction (frottement)

Le frottement est un phénomène aisément compréhensible, car il intervient dans la vie quotidienne :
- le frottement des pneus sur la route
- la difficulté à marcher sur une surface glacée.  

---

Dans le cas d’un mouvement dirigé selon un vecteur de vitesse, la force de frottement agit en sens opposé, parallèlement à la surface de contact.  
L’intensité de cette force dépend de plusieurs facteurs, notamment d’une constante (le coefficient de frottement) et de la rugosité de la surface, ainsi que de la force normale exercée par le plan sur l’objet.

---

### Définition du frottement

Pour bien saisir la théorie du frottement, il convient de rappeler que celui-ci est une **force de contact qui s’oppose au glissement entre deux surfaces**.  

Dans ce modèle, la particule est en contact avec un plan ; la force de frottement résulte des irrégularités (rugosités) présentes entre les deux surfaces.  

Le degré de résistance dépend du coefficient de frottement (*coefficient of friction*), lequel détermine si la surface est plus ou moins glissante.  
Plus ce coefficient est élevé, plus la force de frottement est importante.

---

### Types de frottement

Deux formes principales de frottement sont à distinguer : 
- le frottement **cinétique** (*kinetic friction*) 
- le frottement **statique** (*static friction*).  

Le frottement **cinétique** se manifeste lorsque l’objet est déjà en mouvement sur la surface. Sa direction est opposée à celle du déplacement et reste parallèle à la surface de contact.  

Autrement dit, si une particule se déplace avec une certaine vitesse, la force de frottement cinétique agit dans la direction inverse du vecteur de vitesse.

---

Le frottement **statique**, quant à lui, est la force qui empêche un objet de se mettre en mouvement.  

Il agit dans la direction opposée à la force qui tenterait d’initier ce mouvement, et reste lui aussi parallèle à la surface de contact.  

En résumé, le frottement cinétique intervient pendant le mouvement, tandis que le frottement statique empêche le mouvement initial.  

Dans le contexte de la simulation physique pour le jeu vidéo (*game physics*), l’intérêt se porte principalement sur le frottement cinétique, car il permet de ralentir et d’arrêter progressivement un objet en mouvement.

---

### Formule du frottement

La force de frottement est proportionnelle au produit du coefficient de frottement μ (*mu*) et de la force normale exercée par la surface sur l’objet :  

$$
\vec{F_f} = \mu \ \times ||\vec{F_n}|| \times -\hat{v}
$$  

où $\hat{v}$ représente le vecteur vitesse unitaire inversé.  

Plus la force normale est importante (par exemple lorsque l’objet est lourd ou pressé fortement contre la surface), plus la force de frottement augmente.  

---

Cette relation explique pourquoi les objets lourds sont plus difficiles à déplacer : la force normale est proportionnelle au poids (et donc à la gravité).  
Ainsi, la force de frottement s’oppose toujours au mouvement et dépend directement de la direction et de la norme du vecteur vitesse normalisé.

---

#### Simplification dans la physique du jeu

Comme pour la force de traînée (*drag force*), il est possible de simplifier la formule du frottement pour des besoins de simulation ludique.  

Plutôt que d’utiliser explicitement les grandeurs physiques réelles ($\mu$, force normale, etc.), celles-ci peuvent être remplacées par une constante unique $k$ représentant la « force de frottement effective ».  

Cette constante peut être ajustée pour rendre la surface plus ou moins glissante.  

$$
\vec{F_f} = k * -\hat{v}
$$

---

## Implémentation

Dans le code, une fonction statique (*helper function*) `generateFrictionForce()` est définie.  
Elle reçoit en paramètre un pointeur vers une particule et la valeur du coefficient $k$.  
La fonction calcule le vecteur de frottement et l’applique à la particule via `particle.addForce(friction)`.  

---

L’implémentation de `generateFrictionForce` est analogue à celle utilisée pour la force de traînée.  

Elle reçoit une référence à la particule et la valeur du coefficient $k$, représentant la combinaison des paramètres physiques (μ et force normale).  

Un vecteur de frottement est initialisé à (0, 0) et sera retourné en fin de fonction.  

La direction de la force de frottement est le vecteur vitesse unitaire inversé (normalisé puis multiplié par -1).  

---

La magnitude de la force est donnée par $k$.  
La force finale est obtenue en multipliant cette direction par $k$, avant d’être renvoyée.  
Cette approche simplifiée suffit pour modéliser le frottement dans la plupart des contextes de jeu.

---

## Conclusion

Une fois la compréhension du modèle acquise, il suffit d’intégrer cette fonction dans les fichiers `force.h` et `force.cpp`.  

Ce module permettra d’ajouter facilement une force de frottement aux particules simulées.  

Le frottement intervient dans une multitude de cas : 
- balle glissant sur une table
- boule de bowling sur une piste
- contact entre des pneus et le bitume.  

Cette force est donc essentielle pour toute simulation réaliste.
