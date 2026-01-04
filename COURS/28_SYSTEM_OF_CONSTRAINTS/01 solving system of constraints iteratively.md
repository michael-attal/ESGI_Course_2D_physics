# Joint Constraints and Iterative Solvers in Physics Engines

## Introduction
Pour commencer, nous avons travaillé avec une seule contrainte entre deux corps. Le moteur de physique calcule les **impulsions λ (lambda)** nécessaires pour maintenir cette contrainte, puis applique ces impulsions aux corps A et B. 

Ce processus modifie la vitesse de chaque corps dans le domaine des vitesses afin de maintenir la contrainte valide. Par exemple, si nous considérons un pendule, la contrainte garantit que la distance entre le point d’ancrage et le corps reste constante. Cette mécanique est fondamentale pour comprendre le rôle des **joint constraints** dans la simulation physique.

## Extension à plusieurs corps
Une fois la contrainte simple maîtrisée, l’étape suivante consiste à connecter plusieurs corps entre eux pour former une chaîne ou un pont. Cela implique de créer plusieurs corps et de les connecter avec des joints.  

Dans `application.cpp`, la configuration de la scène se fait ainsi :  
1. Définir la gravité du monde.  
2. Ajouter plusieurs corps à la scène :  
   - Chaque corps reçoit une forme (par exemple un box shape de dimensions 30×30×height).  
   - Le premier corps a une masse de 0, ce qui le rend **statique**, tandis que les corps suivants ont une masse de 1 et sont dynamiques.  
   - La position X de chaque corps dépend de son index, de manière à les espacer correctement.  
   - Un texture peut être ajoutée pour visualisation, mais n’influence pas la physique.  
3. Connecter les corps par des contraintes :  
   - Créer une joint constraint entre chaque corps et le suivant (body1 ↔ body2, body2 ↔ body3…).  
   - Le point d’ancrage du joint correspond à la position du corps courant.  
4. Ajouter ces contraintes au monde pour qu’elles soient prises en compte lors de la simulation.

## Rendu et visualisation
Pour visualiser les joints :  
- On parcourt toutes les contraintes ajoutées au monde.  
- Les points locaux A et B de chaque joint sont convertis en coordonnées mondiales.  
- Une ligne est tracée entre ces points pour représenter la contrainte.  
- Ensuite, tous les corps sont dessinés normalement.  

Cela permet de vérifier visuellement que les corps sont bien connectés et que les contraintes sont appliquées correctement.

## Problèmes rencontrés
Lorsque l’on simule une chaîne de corps :  
- Les objets statiques (masse = 0) peuvent être initialement mal positionnés, car leurs vertices ne sont pas mis à jour lors de la création. Il faut donc **forcer une mise à jour initiale** pour ces corps.  
- Les impulsions appliquées peuvent être insuffisantes pour compenser la gravité, entraînant un **étirement progressif de la chaîne**.  

Ce problème est dû au fait que les solveurs locaux traitent chaque contrainte indépendamment. Résoudre une contrainte peut invalider la précédente, surtout dans un système où plusieurs corps sont liés par des joints.

## Approche itérative
La solution consiste à utiliser une **approche itérative** :  
- Au lieu de résoudre chaque contrainte une seule fois, on boucle plusieurs fois sur toutes les contraintes du monde à chaque étape de simulation.  
- Chaque itération affine l’approximation de la magnitude d’impulsion nécessaire pour que les contraintes soient respectées.  
- Par exemple, 50 itérations peuvent suffire pour qu’une chaîne de corps réagisse correctement à la gravité et aux forces appliquées.  

Cette méthode est une approximation numérique. Elle ne garantit pas une solution parfaite, mais permet de stabiliser le système de contraintes.  

### Limites et optimisations
- Trop d’itérations ralentissent la simulation. Dans un moteur de physique temps réel, il est préférable de limiter à 10–20 itérations.  
- Des techniques supplémentaires peuvent améliorer la précision :  
  - Priorisation des contraintes les plus importantes.  
  - Ajustement adaptatif du nombre d’itérations selon la stabilité du système.  
  - Combinaison de solveurs locaux et globaux pour mieux gérer les systèmes complexes.  

## Résumé
- Les **joint constraints** permettent de lier des corps rigides avec des relations fixes.  
- Les solveurs locaux fonctionnent pour des contraintes simples, mais échouent sur des chaînes ou systèmes complexes.  
- Une approche itérative permet de résoudre plusieurs contraintes simultanément et d’améliorer la stabilité.  
- L’optimisation du solveur est essentielle pour rendre la simulation à la fois précise et performante.  

Cette compréhension est la base pour travailler avec les moteurs physiques modernes et construire des systèmes complexes de corps interconnectés.
