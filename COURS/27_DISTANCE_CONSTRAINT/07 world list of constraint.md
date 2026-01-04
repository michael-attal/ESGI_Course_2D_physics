# Intégration des contraintes dans le World et mise en place d’un premier joint  
_Architecture logicielle et préparation de la phase de résolution_

---

## 1. Extension de la classe `World`

À ce stade, le moteur dispose :
- d’un système de corps rigides fonctionnel
- d’une infrastructure de contraintes (classe `Constraint` et dérivées)

Il devient donc nécessaire que la classe `World` :
- ne stocke plus uniquement des corps rigides
- mais également un ensemble de contraintes actives

---

## 2. Ajout d’un conteneur de contraintes dans `world.h`

Dans `world.h`, on introduit :
- un `std::vector<Constraint*>` pour stocker les contraintes
- une méthode pour ajouter une contrainte au monde
- une méthode pour accéder à la liste des contraintes

Les responsabilités du `World` sont ainsi étendues :
- gestion des corps rigides
- gestion des contraintes qui les lient

Cette approche garantit :
- une séparation claire des responsabilités
- un point central de mise à jour de la simulation

---

## 3. Implémentation dans `world.cpp`

Les méthodes ajoutées sont volontairement simples :

### Ajout d’une contrainte
- la contrainte reçue est ajoutée au vecteur interne
- aucune logique supplémentaire n’est appliquée à ce stade

### Accès aux contraintes
- la fonction retourne une référence au vecteur
- ce qui permettra ultérieurement d’itérer dessus lors de la mise à jour du monde

Cette simplicité est intentionnelle :
- la logique complexe interviendra lors de la phase de résolution

---

## 4. Nettoyage de la scène de test (`application.cpp`)

Afin de tester correctement le système de contraintes :
- tous les éléments précédents de la scène sont supprimés
  - sol
  - murs
  - objets de test divers

L’objectif est de :
- réduire la scène à un cas minimal
- observer clairement le comportement d’une contrainte unique

---

## 5. Création des corps rigides de test

Deux corps rigides sont créés :

### Corps A
- forme : cercle
- rayon : 30
- position : centre exact de l’écran
- masse : 0.0  
  → corps **statique**, immobile

### Corps B
- forme : cercle
- rayon : 20
- position : 100 pixels à gauche de A
- masse : 1.0  
  → corps **dynamique**, soumis aux forces et contraintes

Ce choix permet :
- d’avoir un point d’ancrage fixe
- et un corps libre dont le mouvement sera contraint

---

## 6. Création du joint (distance constraint)

Un objet `JointConstraint` est ensuite instancié :

Paramètres transmis :
- pointeur vers le corps A
- pointeur vers le corps B
- point d’ancrage exprimé en espace monde

Pour simplifier l’observation :
- le point d’ancrage est choisi comme étant la position du corps A

Interprétation physique :
- le corps B est contraint à rester à une distance fixe du centre de A
- il peut se déplacer, mais uniquement sur un cercle de rayon constant
- le comportement est équivalent à un pendule rigide sans tige visible

---

## 7. Ajout explicite de la contrainte au monde

Une étape cruciale est mise en évidence par un avertissement du compilateur :
- la contrainte est créée
- mais pas encore ajoutée au monde

La correction consiste à :
- appeler explicitement `world.addConstraint(joint)`

Cela rappelle un principe fondamental :
- créer un objet ne suffit pas
- il doit être enregistré auprès du système qui l’utilise

---

## 8. Gestion des erreurs de linkage

Un problème de linkage apparaît ensuite :
- méthode virtuelle `solve()` non définie

Cause :
- la classe dérivée (`JointConstraint`) hérite d’une méthode virtuelle pure
- mais ne fournit pas encore d’implémentation

Solution temporaire :
- fournir une implémentation vide de `solve()`

Cela permet :
- de compiler et linker correctement
- tout en reportant la logique réelle à l’étape suivante

---

## 9. État actuel du système

À ce stade :
- le moteur compile sans erreur
- le monde contient :
  - deux corps rigides
  - une contrainte de type joint
- l’architecture est prête pour la résolution des contraintes

Cependant :
- la contrainte n’est pas encore appliquée
- aucune correction des vitesses ou positions n’est effectuée

---

## 10. Prochaine étape : la résolution des contraintes

Le cœur du système reste à implémenter :
- la méthode `solve()` de la `JointConstraint`

C’est dans cette fonction que :
- la Jacobienne est utilisée
- la matrice de masse inverse intervient
- le multiplicateur de Lagrange (λ) est calculé
- les impulsions correctives sont appliquées aux corps rigides

Toute la théorie abordée précédemment :
- Jacobiennes
- contraintes de vitesse
- impulsions
- résolution numérique

converge directement vers cette fonction.

---

## 11. Conclusion

Cette étape marque une transition importante :
- de l’architecture logicielle
- vers la résolution physique effective

Le moteur est désormais structurellement prêt :
- à évaluer les violations de contraintes
- et à les corriger dynamiquement lors de chaque mise à jour du monde

La prochaine phase consistera à transformer cette infrastructure
en un système de contraintes pleinement fonctionnel.
