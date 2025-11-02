## Introduction

Il s’agit d’aborder certaines forces fondamentales observables dans le monde réel et de comprendre leur transposition dans un moteur physique (*physics engine*). Les coefficients et constantes utilisés dans la réalité (tels que les coefficients de frottement ou la densité d’un fluide) ne produisent pas toujours des résultats cohérents lorsqu’ils sont appliqués directement à une simulation. Il convient donc d’ajuster ces valeurs afin d’obtenir un comportement visuellement cohérent dans le cadre d’un moteur de jeu.

---

## Rappel des forces

Les notions précédemment vues incluent le frottement (*friction*), la traînée (*drag*), et la force de gravité appliquée au poids des particules. Deux autres forces restent à explorer, dont la première est la force d’attraction gravitationnelle.

---

## Concept de gravité

La gravité est perçue, à notre échelle terrestre, comme une force dirigée vers le bas.

Cependant, cette perception simplifie un phénomène bien plus général : tout objet possédant une masse exerce une attraction sur tout autre objet. 

Ainsi, la Terre attire les objets vers son centre, mais ces objets attirent également la Terre en retour — bien que cette dernière attraction soit imperceptible en raison de la différence de masse.

---

## Forces gravitationnelles mutuelles

Chaque paire d’objets possédant une masse s’attire mutuellement avec une force identique en intensité, mais de direction opposée. 

L’exemple classique de la pomme et de la Terre illustre cette réciprocité : la pomme attire la Terre autant que la Terre attire la pomme, mais la masse terrestre rend le déplacement correspondant négligeable.

---

## Contexte historique

L’étude des mouvements planétaires et stellaires a permis de formuler la loi d’attraction universelle de Newton. 

L’observation des orbites et des trajectoires célestes fut essentielle à la compréhension de cette force universelle.

---

## Système à deux corps

Considérons deux objets A et B, de masses respectives $m_a$ et $m_b$, séparés par un vecteur de distance $\vec{d}$. 

Chacun exerce sur l’autre une force gravitationnelle d’intensité identique, mais de sens opposé, alignée sur le vecteur reliant leurs positions.

---

## Symétrie de la force

Ces deux forces, bien que contraires en direction, ont une même magnitude. Dans le cas Terre–pomme, la disproportion des masses rend la réaction imperceptible du côté de la Terre, sans invalider la symétrie du système.

---

## Formule gravitationnelle

La formule générale de la force d’attraction gravitationnelle s’écrit :

$$
F = G \frac{m_a \times m_b}{r^2}
$$

- $G$ la constante gravitationnelle universelle
- $r$ la distance entre les deux objets
- $F$ le module de la force.

---

## Constante universelle et contexte ludique

Dans un moteur de jeu, cette constante $G$ peut être ajustée afin de contrôler visuellement la force d’attraction entre les objets. L’objectif n’est pas la fidélité scientifique, mais l’obtention d’un comportement crédible et plaisant à l’écran.

---

## Relation distance–force

La force est inversement proportionnelle au carré de la distance : plus les objets sont proches, plus la force est importante ; à l’inverse, plus ils s’éloignent, plus elle s’affaiblit.

---

## Direction de la force

La direction de la force est donnée par le vecteur unitaire de la distance. Pour chaque paire d’objets, la force appliquée à A pointe vers B et réciproquement, celle de B pointe vers A.

---

## Récapitulatif de la formule

En résumé :  

$$
\vec{F}_{a \to b} = G \frac{m_a \times m_b}{|\vec{r}|^2} \hat{r}
$$  

et  

$$\vec{F}_{b \to a} = - \vec{F}_{a \to b}$$  

Les deux forces sont opposées et de même intensité.

---

## Vue d’ensemble de l’implémentation

L’implémentation consiste à définir une fonction, par exemple `generateGravitationalForce()`, prenant en paramètre deux particules (A et B) et la constante $G$. 

Cette fonction renverra le vecteur force correspondant.

---

## Paramètres de la fonction

Les paramètres nécessaires sont : les masses des deux particules et la constante $G$, ajustable selon la dynamique souhaitée à l’écran.

---

## Constante G dans la simulation

Dans la réalité, $G \approx 6.67 \times 10^{-11} \, m^3 / (kg \cdot s^2)$.  

Ce niveau de précision est inutile en simulation : dans un moteur de jeu, on choisit une valeur adaptée au système d’unités (souvent basé sur des pixels) et à la perception visuelle.

---

## Perspective de conception

L’important est de choisir une valeur de $G$ qui produise un effet visuel satisfaisant : vitesse d’attraction, stabilité orbitale ou fluidité du mouvement, selon le gameplay recherché.

---

## Application de la force

Une fois la force calculée, elle est appliquée aux deux particules :  
- $A$ reçoit $+\vec{F}$  
- $B$ reçoit $-\vec{F}$  

L’inversion de direction assure la cohérence du système.

---

## Application mutuelle des forces

Ainsi, chaque particule influence l’autre conformément à la loi d’action-réaction. Ce mécanisme permet de reproduire le comportement d’objets s’attirant mutuellement.

---

## Fonction d’implémentation

La fonction `generateGravitationalForce()` doit refléter directement la formule physique.  
Elle calcule :
1. Le vecteur distance $\vec{d} = \vec{p}_B - \vec{p}_A$  
2. Sa magnitude au carré $r^2$  
3. La direction unitaire $\hat{r}$  
4. La force : $\vec{F} = \hat{r} \times G \frac{m_a \times m_b}{r^2}$

---

## Détail du calcul

La force finale est donc un vecteur dirigé selon la ligne reliant les deux corps, dont la magnitude dépend des masses et de la distance.

---

## Direction et magnitude

Le vecteur directionnel est obtenu par normalisation, la magnitude résulte du produit des masses pondéré par $G$ et divisé par $r^2$. La force est ensuite calculée par simple multiplication scalaire.

---

## Calcul final de la force

Le résultat renvoyé est un vecteur contenant la direction et l’intensité de l’attraction.

---

## Conclusion

Toutes les fonctions de génération de force reposent sur des formules physiques établies. Ces équations, validées expérimentalement, permettent une implémentation cohérente et modulable dans le contexte d’un moteur de jeu.

---

## Synthèse d’application

L’objectif est d’utiliser la formule, de l’adapter au moteur, et d’appliquer la force à chaque particule.

---

## Étape finale

Une fois la fonction intégrée dans `force.cpp` et `force.h`, il devient possible d’observer à l’écran le comportement d’attraction entre particules, voire de simuler des orbites planétaires selon les valeurs choisies.
