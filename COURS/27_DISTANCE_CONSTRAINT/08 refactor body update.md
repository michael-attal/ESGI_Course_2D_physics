## 1. Rôle central de la méthode `solve()`

La méthode `solve()` d’une contrainte est le point de convergence de toute la théorie précédente.

Son rôle est strictement défini :
1. charger la Jacobienne avec les coefficients corrects
2. récupérer le vecteur des vitesses courantes
3. récupérer la matrice de masse inverse $M^{-1}$
4. calculer le multiplicateur de Lagrange $\lambda$
5. appliquer les impulsions (linéaires et angulaires) aux corps A et B

Tout le travail théorique sur :
- Jacobiennes
- matrices
- impulsions
- contraintes de vitesse  

aboutit exclusivement à cette fonction.

---

## 2. Rappel du pipeline théorique de résolution

Le schéma logique est le suivant :

- $J$ : Jacobienne de la contrainte
- $V$ : vecteur des vitesses
- $M^{-1}$ : matrice de masse inverse
- $\lambda$ : amplitude de l’impulsion correctrice

Une fois $\lambda$ calculé :
- on applique les impulsions à A et B
- à la fois sur les vitesses linéaires et angulaires

---

## 3. Problème architectural identifié dans `World::update`

Le design initial posait un problème fondamental :
- toutes les étapes (forces, intégration, collisions, contraintes)
- étaient regroupées dans une seule fonction `Body::update`

Ce modèle empêche toute résolution correcte des contraintes, car :
- les contraintes doivent être résolues **après** le calcul des accélérations
- mais **avant** l’intégration des vitesses vers les positions

Il est donc nécessaire de **refactoriser entièrement le cycle de simulation**.

---

## 4. Nouveau découpage du cycle de simulation

Le pipeline correct devient :

1. **Intégration des forces**
2. **Résolution des contraintes**
3. **Intégration des vitesses**

Schématiquement :

Forces → Accélérations → Vitesses  
↓  
Résolution des contraintes  
↓  
Positions & rotations


Ce point est fondamental :  
la résolution des contraintes agit directement sur les vitesses.

---

## 5. Refactorisation de la classe `Body`

### Suppression de `update()`

La méthode monolithique `update()` est supprimée.

Elle est remplacée par deux méthodes distinctes :

- `integrateForces(dt)`
- `integrateVelocities(dt)`

---

## 6. `integrateForces(dt)`

Responsabilités :
- ignorer les corps statiques
- calculer les accélérations linéaires :
  $$
  a = \frac{F}{m}
  $$
- intégrer les accélérations pour obtenir les vitesses
- intégrer également les accélérations angulaires
- vider les forces et torques accumulés

Cette étape met à jour :
- vitesse linéaire
- vitesse angulaire

Mais **ne modifie pas encore la position**.

---

## 7. `integrateVelocities(dt)`

Responsabilités :
- ignorer les corps statiques
- intégrer les vitesses pour prédire :
  - la position
  - la rotation
- mettre à jour les sommets (vertices) de la forme associée

Cette étape :
- transforme les objets dans l’espace monde
- applique effectivement le mouvement visible

---

## 8. Mise à jour du `World::update`

La fonction `World::update` est désormais structurée ainsi :

1. boucle sur les corps → `integrateForces(dt)`
2. boucle sur les contraintes → `constraint.solve()`
3. boucle sur les corps → `integrateVelocities(dt)`
4. vérification des collisions (temporaire)

Ce découpage rend explicite :
- le moment exact où les contraintes interviennent
- leur rôle correctif sur les vitesses

---

## 9. Importance de la résolution entre deux intégrations

La contrainte ne peut pas être résolue :
- ni avant les forces (les vitesses seraient incorrectes)
- ni après l’intégration des positions (trop tard)

Elle doit impérativement se situer :
- **entre** intégration des forces
- **et** intégration des vitesses

C’est la clé de toute simulation physique contrainte.

---

## 10. Mise à jour des vertices

Après chaque intégration des vitesses :
- la position et la rotation changent
- les sommets doivent être reconvertis en espace monde

Cela est assuré par :
- `shape.updateVertices(position, rotation)`

Cette étape garantit :
- une cohérence géométrique
- un rendu correct

---

## 11. Conséquences conceptuelles

Cette refactorisation implique :
- une architecture plus modulaire
- un moteur prêt pour des contraintes complexes
- une transition vers un solveur de contraintes général

À terme :
- les collisions elles-mêmes deviendront des contraintes
- la résolution sera unifiée

---

## 12. État actuel et suite

À présent :
- le moteur est correctement structuré
- le pipeline physique est valide
- les contraintes sont intégrées au bon endroit

Il reste une étape cruciale :
- implémenter concrètement `JointConstraint::solve()`

C’est à ce moment précis que :
- la Jacobienne sera calculée
- $\lambda$ sera déterminé
- la contrainte de distance sera effectivement respectée

Cette étape constitue l’un des points les plus importants du moteur physique.
