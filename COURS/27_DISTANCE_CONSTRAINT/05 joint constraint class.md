## 1. Renommage et clarification conceptuelle

Nous avions initialement deux classes squelettes :
- `DistanceConstraint`
- `PenetrationConstraint`

Pour plus de clarté conceptuelle, **DistanceConstraint est renommée en `JointConstraint`**.

Justification :
- Il s’agit d’un **joint** reliant deux corps rigides
- Le comportement recherché est celui d’une **contrainte de distance via un point d’ancrage**

---

## 2. Hiérarchie des contraintes

Toutes les contraintes :
- héritent de la classe parente `Constraint`
- partagent une interface commune (`solve()`)
- possèdent des données spécifiques (Jacobien, points d’ancrage, etc.)

Chaque type de contrainte aura :
- **son propre Jacobien**
- une logique de résolution différente

---

## 3. Rôle du Jacobien dans une contrainte

Pour une `JointConstraint` :
- le Jacobien est une **matrice ligne**
- il encode la relation linéaire entre :
  - vitesses linéaires
  - vitesses angulaires
  - contrainte de distance

Le contenu du Jacobien :
- détermine entièrement le comportement physique de la contrainte
- sera dérivé mathématiquement plus tard

---

## 4. Interface de la classe `JointConstraint`

Organisation de la classe :

- **Attributs privés**
  - matrice Jacobienne

- **Méthodes publiques**
  - constructeurs
  - méthode `solve()` (override)

Cette séparation garantit :
- encapsulation des données
- cohérence avec le polymorphisme des contraintes

---

## 5. Constructeurs de `JointConstraint`

Deux constructeurs sont définis :

1. **Constructeur par défaut**
   - appelle le constructeur de la classe parente `Constraint`
   - initialise le Jacobien

2. **Constructeur paramétré**
   - reçoit :
     - un pointeur vers le corps A
     - un pointeur vers le corps B
     - un point d’ancrage en espace monde

---

## 6. Initialisation du Jacobien

Le Jacobien d’une contrainte reliant deux corps 2D contient :
- 6 composantes (3 par corps : $v_x$, $v_y$, $\omega$)

Il est donc initialisé comme :
- une matrice **1 × 6**
- une matrice ligne

Cette initialisation est faite dans la liste d’initialisation du constructeur.

---

## 7. Initialisation des corps impliqués

Dans le constructeur paramétré :
- `this->A = A`
- `this->B = B`

Ces pointeurs sont stockés dans la classe parente `Constraint`, car :
- toutes les contraintes manipulent des corps rigides
- cette information est commune à tous les types de contraintes

---

## 8. Stockage du point d’ancrage : choix architectural

Décision importante :
- les points d’ancrage **ne sont pas stockés dans `JointConstraint`**
- ils sont stockés dans la classe parente `Constraint`

Raison :
- toutes les contraintes futures utiliseront des points de référence
- centraliser cette logique évite la duplication

---

## 9. Points d’ancrage en espace local

Deux vecteurs sont ajoutés dans `Constraint` :
- `aPoint` : ancrage en espace local du corps A
- `bPoint` : ancrage en espace local du corps B

Ces points représentent :
- le **même point physique**
- exprimé dans deux repères différents

---

## 10. Conversion monde → local dans le constructeur

Dans le constructeur de `JointConstraint` :

- le point d’ancrage est fourni en **espace monde**
- il est converti en :
  - espace local de A
  - espace local de B

Conceptuellement :
- `aPoint = A.worldSpaceToLocalSpace(anchorPoint)`
- `bPoint = B.worldSpaceToLocalSpace(anchorPoint)`

---

## 11. Dépendance fonctionnelle

À ce stade :
- la fonction `worldSpaceToLocalSpace()` n’existe pas encore
- le compilateur signale une erreur attendue

Cela définit clairement la **prochaine étape** :
- implémenter les conversions espace monde ↔ espace local dans la classe `Body`

---

## 12. Transition vers la suite

Nous avons maintenant :
- une architecture de contraintes cohérente
- une `JointConstraint` correctement initialisée
- les données nécessaires stockées en espace local

Prochaine étape :
- implémenter la conversion monde → local
- dériver mathématiquement le Jacobien de la contrainte de distance
- écrire la méthode `solve()` de la `JointConstraint`
