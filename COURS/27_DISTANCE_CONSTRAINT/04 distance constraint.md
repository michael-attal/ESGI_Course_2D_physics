## 1. Du cadre général à une contrainte spécifique

Jusqu’à présent, nous avons étudié une **méthode générale** pour résoudre les contraintes :
- Calcul de la direction de l’impulsion via le Jacobien transposé
- Calcul de la magnitude de l’impulsion via $\lambda$
- Application de l’impulsion pour satisfaire une contrainte de vitesse d’égalité

Nous allons maintenant nous concentrer sur une **contrainte concrète** : la contrainte de distance.

---

## 2. Intuition de la contrainte de distance

Une contrainte de distance impose que **deux points**, chacun appartenant à un corps rigide différent, restent à une distance constante.

Cas typique :
- Un **joint** (revolute joint)
- Deux corps A et B
- Un point d’ancrage commun
- Les corps peuvent **tourner autour du point**, mais **ne peuvent pas s’en éloigner**

Autrement dit :
- La position relative est contrainte
- La rotation reste libre

---

## 3. Architecture côté moteur : le rôle du `World`

Le moteur physique contient un objet central : `World`.

Avant :
- `World` stockait uniquement une liste de corps rigides

Maintenant :
- `World` stocke :
  - une liste de corps (`bodies`)
  - une liste de contraintes (`constraints`)

Conceptuellement :
- Les corps décrivent l’état dynamique
- Les contraintes décrivent les relations géométriques à maintenir

---

## 4. Création d’une contrainte dans l’application

Dans le code applicatif (par exemple `application.cpp`) :

1. Création de deux corps rigides
2. Ajout de ces corps au monde
3. Définition d’un **point d’ancrage** en espace monde
4. Création d’une contrainte de type joint (distance constraint)
5. Ajout de la contrainte au monde

Le point d’ancrage est défini **en espace monde**, par exemple :
- position de A moins un vecteur $(100, 0)$
- ancrage situé à gauche du corps A

---

## 5. Boucle de simulation et résolution des contraintes

À chaque étape de simulation :

- `World::update()` :
  - met à jour les corps
  - **parcourt toutes les contraintes**
  - appelle `solve()` sur chacune d’elles

Pour une contrainte de distance :
- `solve()` calcule le Jacobien
- calcule $\lambda$
- applique les impulsions
- garantit que la distance reste constante

---

## 6. Classe `JointConstraint`

La contrainte de distance est implémentée sous forme de classe fille :

- `JointConstraint` hérite de `Constraint`
- Elle possède ses **données spécifiques**

Données essentielles :
- Un Jacobien (propre à cette contrainte)
- Deux points d’ancrage :
  - un dans l’espace local de A
  - un dans l’espace local de B

---

## 7. Pourquoi stocker l’ancrage en espace local ?

C’est un point fondamental.

Un point d’ancrage :
- Est défini initialement en **espace monde**
- Mais doit être stocké en **espace local** des corps

Rappel des espaces :
- **Espace monde** : coordonnées globales de la scène
- **Espace local** : coordonnées relatives au corps rigide

Chaque corps rigide possède son propre repère :
- Origine = centre de masse
- Orientation = rotation du corps

---

## 8. Exemple conceptuel

Supposons :
- Le centre de A est à $(0,0)$
- L’ancrage est à $(-100,0)$ en espace monde

Alors :
- En espace local de A :
  - ancrage = $(-100,0)$
- En espace local de B :
  - ancrage = $(+100,0)$ (selon la position relative)

Chaque corps stocke **sa propre version locale** du même point d’ancrage.

---

## 9. Conversion monde → local

Lors de la construction de `JointConstraint` :

1. On reçoit :
   - `Body* A`
   - `Body* B`
   - `Vec2 anchorWorld`

2. On convertit :
   - `anchorWorld` → `anchorA_local`
   - `anchorWorld` → `anchorB_local`

Cette conversion est faite via une fonction :
- `worldSpaceToLocalSpace()`

---

## 10. Principe mathématique de la conversion inverse

Pour passer de l’espace monde à l’espace local :

1. **Annuler la translation** :
   $$
   p' = p_{world} - position_{body}
   $$

2. **Annuler la rotation** :
   $$
   p_{local} = R(-\theta) \cdot p'
   $$

On applique donc :
- une translation inverse
- une rotation inverse

C’est exactement l’inverse de la transformation local → monde.

---

## 11. Fonctions de transformation dans `Body`

Chaque corps rigide fournit deux fonctions fondamentales :

- `localSpaceToWorldSpace(point)`
  - rotation
  - translation

- `worldSpaceToLocalSpace(point)`
  - translation inverse
  - rotation inverse

Ces conversions sont omniprésentes dans les moteurs physiques.

---

## 12. Résultat final

Dans `JointConstraint` :

- Les points d’ancrage sont stockés :
  - **en espace local de A**
  - **en espace local de B**

Avantages :
- Les ancrages suivent naturellement les rotations
- Le calcul du Jacobien devient cohérent
- La contrainte reste stable quelle que soit l’orientation des corps

---

## 13. Suite du cours

Prochaine étape :
- Utiliser ces points d’ancrage locaux
- Dériver la **formule mathématique de la contrainte de distance**
- Construire explicitement le **Jacobien de la contrainte**
- Implémenter la méthode `solve()` du `JointConstraint`
