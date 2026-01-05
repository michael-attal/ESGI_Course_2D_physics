# Contact Caching / Manifold Caching  
## Notes de cours – ESGI (Physique pour moteurs de jeu)

### 1. Contexte général et objectifs pédagogiques
Dans cette séquence du cours, l’objectif n’est pas d’implémenter immédiatement de nouvelles fonctionnalités complexes, mais **de comprendre les techniques utilisées dans les moteurs physiques professionnels** (*professional physics engines*).  
Ces techniques visent principalement :
- l’amélioration de la **stabilité numérique** (*stability*),
- l’optimisation de la **détection et résolution des collisions** (*collision detection / resolution*),
- le **contrôle des performances** (*performance awareness*).

L’un des concepts fondamentaux abordés ici est celui de **contact caching**, aussi appelé **manifold caching**.

![[medias/01 contact caching 2026-01-03 13.18.03.excalidraw|800]]
---

### 2. Limites de l’implémentation actuelle
Dans l’implémentation actuelle du moteur physique étudié en cours :
- Les **contraintes de pénétration** (*penetration constraints*) sont stockées dans un simple vecteur.
- Ce vecteur est **reconstruit à chaque frame** (à chaque appel de `update`).
- Une fois la frame terminée, **toutes les informations sont perdues**.

Conséquence majeure :
- Le moteur **ne bénéficie pas réellement du warm starting** (*warm starting*), c’est-à-dire la réutilisation des impulsions (*impulses*) calculées lors de la frame précédente.
- Chaque itération repart de zéro, ce qui nuit à la **stabilité des contacts persistants** (objets posés, empilés, glissants).

---

### 3. Principe du Contact Caching
Le **contact caching** consiste à :
- **Conserver les contacts entre deux corps rigides d’une frame à l’autre**,
- Permettre la **persistance des contraintes de pénétration** et de leurs impulsions associées.

Autrement dit, au lieu de recalculer intégralement les contacts à chaque frame :
- On les **met en cache**,
- On les **met à jour uniquement si nécessaire**.

Ce mécanisme est une condition essentielle pour exploiter pleinement le *warm starting*.

---

### 4. Notion de Manifold
Dans le contexte des moteurs physiques :
- Un **manifold** est défini comme un **ensemble de contacts** (*set of contacts*) entre **une paire de corps rigides**.

Exemples :
- Corps A ↔ Corps B → 1 manifold
- Corps A ↔ Corps C → 1 manifold distinct
- Corps C ↔ Sol → 1 autre manifold

⚠️ À ne pas confondre avec la notion mathématique formelle de *manifold* : ici, le terme est employé de manière pragmatique et simplifiée.

👉 **Manifold caching** et **contact caching** désignent donc essentiellement la même idée.

---

### 5. Avantages majeurs du Manifold Caching

#### 5.1 Warm Starting effectif
- Les impulsions précédemment calculées (*cached lambdas / impulses*) peuvent être réutilisées.
- Résultat : meilleure convergence du solveur et **stabilité accrue** des objets au repos.

#### 5.2 Réduction des mises à jour inutiles
Avant d’ajouter un nouveau contact à un manifold :
- On vérifie s’il est **suffisamment éloigné** d’un contact existant.
- Si la distance est inférieure à un **seuil ε (epsilon threshold)** :
  - Le contact est considéré comme déjà existant.
  - Le manifold **n’est pas modifié**.

Effets positifs :
- Évite les oscillations numériques.
- Améliore le comportement des objets en glissement (*slipping*).
- Réduit le bruit dans la résolution des contraintes.

---

### 6. Structure de données : la classe `Manifold`

Un **manifold** contient typiquement :

#### 6.1 Données principales
- Références vers les deux corps rigides concernés :
  - `RigidBody* A`
  - `RigidBody* B`
- Nombre courant de contacts.
- Un **tableau de contacts** (*array of contacts*).
- Un **tableau de contraintes de pénétration** associées aux contacts.

Chaque contact contient généralement :
- Points de contact,
- Normale de collision,
- Profondeur de pénétration,
- Impulsion accumulée (*cached impulse*).

Un nombre maximal de contacts peut être imposé (ex. 4 ou 5).

---

### 7. Gestion du cycle de vie des contacts

Le manifold doit fournir des mécanismes pour :
- Ajouter un contact,
- Supprimer les contacts expirés (*expired contacts*),
- Vérifier les seuils de distance.

Logique typique :
- Si deux contacts sont trop proches → conserver l’ancien.
- Si un contact dépasse le seuil de séparation → le supprimer.
- Libérer ainsi de l’espace pour de nouveaux contacts pertinents.

---

### 8. Intégration dans le pipeline de résolution

Chaque manifold possède ses propres méthodes :
- `preSolve()`
- `solve()`
- `postSolve()`

Rôle :
- Parcourir les contraintes de pénétration internes,
- Appeler les méthodes correspondantes sur chaque contrainte.

Le manifold agit donc comme un **conteneur logique et temporel** pour les contraintes de collision.

---

### 9. Gestion des manifolds au niveau du monde (World)
Le moteur physique doit maintenir :
- Un **vecteur de manifolds persistants** dans la structure `World`.

Points importants :
- Les contraintes globales restantes (ex. joints) sont gérées séparément.
- Les manifolds concernent exclusivement les **contacts de collision**.

Lors de la détection de collision :
1. Vérifier si un manifold existe déjà pour la paire (A, B).
2. Si oui → ajouter ou mettre à jour le contact.
3. Sinon → créer un nouveau manifold et l’initialiser.

---

### 10. Choix des seuils (distance threshold)
Un point délicat de l’implémentation :
- Déterminer quand deux contacts sont « trop proches ».
- Déterminer quand un contact doit être supprimé.

Ces seuils sont :
- Empiriques,
- Dépendants de l’échelle de la simulation,
- Ajustés expérimentalement.

---

### 11. Référence aux moteurs existants : Box2D
Dans Box2D :
- Le concept équivalent au manifold est appelé **Arbiter**.
- Un *arbiter* agit comme un **juge** (*judge*) des interactions entre deux corps rigides.
- Il décide de la gestion et de la résolution des contacts persistants.

Bien que l’implémentation diffère, le **principe conceptuel est identique**.

---

### 12. Conclusion pédagogique
Le **contact / manifold caching** est une technique clé pour :
- Améliorer la stabilité des contraintes de pénétration,
- Réduire les recalculs inutiles,
- Approcher le fonctionnement des moteurs physiques professionnels.

Même si cette technique n’est pas implémentée dans le cadre du cours :
- Elle constitue une **extension naturelle** du moteur existant,
- Elle représente une **excellente piste de travail avancé** pour les étudiants souhaitant aller plus loin.

Implémenter le manifold caching est souvent **la prochaine étape logique** après un moteur de collision fonctionnel.
