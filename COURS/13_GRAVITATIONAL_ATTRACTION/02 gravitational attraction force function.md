## Implémentation de la Génération de la Force Gravitationnelle

Nous allons implémenter la fonction `GenerateGravitationalForce` en C++. 

Le prototype est défini dans `Force.h` et prend en paramètres deux références de particules (A et B) et un flottant $g$ représentant la constante gravitationnelle. 
Cette constante permet d’ajuster la force gravitationnelle pour la rendre visible dans le jeu, et pourra être modifiée pour obtenir l’effet souhaité.

---

## Revue du Code dans Force.cpp

Dans `Force.cpp`, la fonction crée un vecteur distance $\vec{d} = \vec{p}_B - \vec{p}_A$, calcule sa longueur au carré, sépare direction et magnitude de l’attraction, puis retourne la force gravitationnelle finale. 

Cela suit exactement la formule théorique vue dans les slides.

---

## Préparation de l’Application

Dans `application.cpp`, nous modifions la scène pour passer d’une particule unique à deux planètes. La première, « small planet », a une masse de 1.0, et la seconde, « big planet », une masse de 20.0. 

Les deux sont ajoutées au vecteur de particules pour simuler l’attraction mutuelle.

---

## Rendu des Planètes

Chaque planète est dessinée avec un cercle rempli : bleu pour la petite planète et jaune pour la grande.

Le rendu individuel de chaque planète permet de visualiser clairement leur position et leur interaction.

---

## Ajout de l’Attraction Gravitationnelle

Il est possible de donner une petite impulsion à la petite planète et de conserver la friction pour ralentir les particules. 

L’objectif est de faire s’attirer les deux planètes en utilisant la formule gravitationnelle que nous avons définie, avec des forces de même magnitude mais directions opposées.

---

## Implémentation dans la Fonction Update

L’application des forces se fait dans la fonction `update`. 

Nous conservons la force de poussée (flèches du clavier) et la friction, puis nous ajoutons la force gravitationnelle avant l’intégration des positions et vitesses.

---

## Création de la Force d’Attraction

Pour créer la force d’attraction, nous utilisons la fonction `force::generateGravitationalForce` avec en paramètres les deux particules et la constante gravitationnelle $G$. 

Il faudra éventuellement utiliser les pointeurs vers les particules pour passer correctement les références.

---

## Ajustement de la Constante Gravitationnelle

La valeur de $G$ doit être ajustée pour rendre l’attraction visible à l’écran. Commencer avec 1.0 est possible, mais il faudra souvent augmenter cette valeur pour obtenir un mouvement perceptible dans le jeu.

---

## Application des Forces aux Particules

La force d’attraction est appliquée aux deux planètes : positive pour la petite planète et négative pour la grande, respectant ainsi la troisième loi de Newton (action-réaction).

---

## Observation des Résultats et Ajustements

Si le déplacement est trop faible, il faut augmenter $G$ ou réduire l’effet de friction pour visualiser correctement l’attraction. Il est important de vérifier les valeurs et d’ajuster les paramètres pour que la simulation soit intéressante visuellement.

---

### Compréhension de la Force Faible

La division par la distance au carré peut rendre la force très faible pour des objets éloignés. Pour les jeux, il est conseillé d’exagérer l’effet en limitant la distance minimale et maximale pour la force.

---

### Introduction du Clamping de la Distance

On peut contraindre la distance au carré entre un minimum et un maximum pour éviter que la force devienne trop faible ou trop grande, améliorant ainsi la visualisation dans le jeu.

---

### Implémentation du Clamping dans le Code

On peut passer les bornes minimale et maximale en paramètres supplémentaires de la fonction et utiliser `std::clamp` pour limiter la distance au carré dans le calcul de la force gravitationnelle.

---

## Utilisation de std::clamp

`std::clamp` permet de garantir que la distance au carré reste comprise entre les bornes définies, assurant une force gravitationnelle stable et visible dans le jeu.

---

## Observation des Effets Visuels

Le *clamping* permet d’avoir une attraction suffisante pour que les planètes se déplacent de façon visible et, si besoin, orbitent autour de la planète de plus grande masse.

---

## Affinage des Paramètres

On peut ajuster les valeurs de $G$, la friction et les limites de distance pour obtenir des orbites correctes et un mouvement réaliste mais exagéré, adapté au jeu.

---

## Observation de l’Effet d’Orbite

La petite planète se déplace plus rapidement autour de la grande car la masse de la grande planète est plus importante, rendant son accélération moindre, conformément à la physique.

---

### Ajustement de la Friction et Comportement Final

L’ajout de friction permet de stabiliser le mouvement des planètes après un certain temps et rend l’expérience plus agréable visuellement.

---

## Conclusion

La simulation montre une orbite réaliste adaptée à un contexte de jeu. 

On peut expérimenter avec plusieurs planètes et ajuster les constantes pour visualiser différentes interactions gravitationnelles. 

La fonction et les paramètres sont prêts à être utilisés et adaptés à différents scénarios de jeu.
