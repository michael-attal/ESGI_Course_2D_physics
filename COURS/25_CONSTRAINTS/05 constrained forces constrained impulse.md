# Introduction aux forces de contrainte et aux impulsions de contrainte

---

## Contexte général

- Les contraintes sont souvent appliquées pour limiter le mouvement d’un objet à un certain chemin ou domaine.
- Exemple classique : un objet (*particle*) contraint à se déplacer sur une trajectoire circulaire.
- Objectif : comprendre les **forces internes** nécessaires pour maintenir la contrainte malgré les forces externes déjà appliquées (gravité, friction, vent, etc.).
- Les moteurs physiques utilisent souvent des **impulsions de contrainte (*constraint impulses*)** plutôt que des forces continues.

---

## Fonction de contrainte et domaine de mouvement

- Fonction de contrainte $C(\vec{p})$ : définit la position de l’objet dans le temps.
- Mouvement souhaité : $\vec{p}(t)$ doit rester sur la trajectoire définie.
- On ne modifie **pas directement la position**, pour éviter les oscillations et comportements non naturels.
- On travaille plutôt sur la **vitesse** ($\dot{\vec{p}}$) ou l’**accélération** ($\ddot{\vec{p}}$).

---

## Notation des dérivées temporelles

- Première dérivée : **vitesse**
  $$
  \dot{\vec{p}} = \frac{d\vec{p}}{dt}
  $$
- Deuxième dérivée : **accélération**
  $$
  \ddot{\vec{p}} = \frac{d^2\vec{p}}{dt^2}
  $$
- Troisième dérivée (optionnelle) : **jerk**, variation de l’accélération.
- Les dérivées permettent de transformer la contrainte de position en **contrainte sur la vitesse ou l’accélération**, garantissant un mouvement plus naturel.

---

## Exemple classique : perle sur un fil

- Fil circulaire avec une perle se déplaçant librement dessus.
- La force de contrainte est :
  - **Toujours perpendiculaire à la vitesse**.
  - Sa **magnitude** et sa **direction** déterminent comment la perle reste sur le fil.
- Calcul de la force de contrainte : nécessite **dérivées et calcul différentiel**, mais la compréhension de l’intuition suffit pour l’implémentation pratique.

---

## Règles générales pour la résolution

1. Identifier la fonction de contrainte $C(\vec{p})$ et la trajectoire cible.
2. Utiliser les dérivées pour travailler sur la vitesse et l’accélération :
   - $\dot{C} = 0$ : première dérivée de la contrainte nulle → vitesse respectant la contrainte.
   - $\ddot{C} = 0$ : deuxième dérivée de la contrainte nulle → accélération respectant la contrainte.
3. Implémenter des **impulsions de contrainte** plutôt que modifier directement la position.

---

## Ressources et recommandations

- La dérivation complète de la magnitude et de la direction de la force de contrainte pour la perle sur un fil existe dans la littérature.
- Pour le moment, **ne pas se concentrer sur la dérivation complète** : l’objectif est d’acquérir l’intuition et comprendre le cadre général.
- Après avoir assimilé le cours, il est possible de revenir sur les détails mathématiques pour approfondir.
