## Refactor du SAT : indices, référence, incident et préparation au clipping

Dans cette étape, l’objectif n’est pas d’introduire un nouvel algorithme, mais de **refactoriser proprement l’implémentation actuelle du SAT** afin de préparer le terrain pour la gestion correcte des contacts multiples et l’algorithme de clipping.

L’idée générale est de :
- clarifier les responsabilités des variables,
- adopter une terminologie standard utilisée en physique du jeu,
- remplacer certaines données géométriques par des **indices**, plus exploitables pour la suite.

---

## Clarification sémantique : renommer pour mieux raisonner

Jusqu’ici, le code manipulait des notions comme :
- `aAxis`, `bAxis`,
- `aPoint`, `bPoint`.

Ces noms sont fonctionnels mais insuffisamment explicites pour la logique que nous voulons mettre en place.

### Référence et support

Nous adoptons désormais les conventions suivantes :

- **Reference edge**  
  → l’arête associée à l’axe de pénétration minimale retourné par le SAT.

- **Support point**  
  → le point de pénétration maximale associé à cet axe.  
  C’est une terminologie standard dans la littérature et dans les moteurs physiques (support point).

Ainsi :
- `aAxis` / `bAxis` deviennent des **indices de référence**,
- `aPoint` / `bPoint` deviennent des **support points**.

---

## Changement fondamental : retourner un index, pas un vecteur

Un point clé du refactor est le suivant :

> **On ne retourne plus directement l’axe (vecteur), mais l’index de l’arête correspondante.**

Pourquoi ?
- l’axe est dérivé d’une arête,
- pour le clipping, nous avons besoin de connaître **quelle arête exacte** est impliquée,
- l’index permet de retrouver l’arête, ses sommets et sa normale de manière cohérente.

### Nouveau contrat de `findMinSeparation`

Dans la classe `PolygonShape` :

- au lieu de retourner un `Vector2 axis`,
- la fonction remplit :
  - un `int indexReferenceEdge`,
  - un `Vector2 supportPoint`.

Cela implique :
- modification de la signature dans `shape.h`,
- modification correspondante dans `shape.cpp`.

Le cœur de l’algorithme reste identique :
- on parcourt les arêtes,
- on calcule les projections,
- on conserve la séparation minimale,
- **mais on stocke l’indice de l’arête gagnante**, pas son vecteur.

---

## Séparation AB / BA et choix de la référence

Dans la détection polygone–polygone, nous calculons toujours :
- la séparation de A vers B (AB),
- la séparation de B vers A (BA).

Selon laquelle est la plus critique :
- **le polygone correspondant devient la référence**,
- l’autre devient l’incident.

Il y a donc deux cas symétriques à gérer.

### Abstraction essentielle : referenceShape et incidentShape

Pour éviter une logique conditionnelle omniprésente, on introduit :

- `PolygonShape* referenceShape`
- `PolygonShape* incidentShape`
- `int indexReferenceEdge`

Une fois ces pointeurs initialisés :
- le reste du code **ne raisonne plus en termes de A ou B**,
- il ne manipule que **référence** et **incident**.

Cela simplifie considérablement la suite du traitement.

---

## Récupération de l’arête de référence

À partir de :
- `referenceShape`,
- `indexReferenceEdge`,

on peut reconstruire l’arête de référence via une méthode du type :
- `edgeAt(indexReferenceEdge)`.

Cette arête fournit :
- ses sommets,
- sa normale,
- les informations nécessaires au clipping.

---

## Recherche de l’arête incidente

L’étape suivante consiste à trouver **l’arête incidente**, c’est-à-dire :
- l’arête du polygone incident
- dont la normale est **la moins alignée** avec la normale de l’arête de référence.

### Principe algorithmique

1. On prend la **normale de l’arête de référence**.
2. On parcourt toutes les arêtes du polygone incident.
3. Pour chacune :
   - on calcule sa normale,
   - on calcule le produit scalaire avec la normale de référence.
4. On conserve l’arête ayant :
   - la **projection minimale** (le pire alignement).

Cette arête est l’**incident edge**.

---

## Implémentation : `findIncidentEdge`

Dans `PolygonShape` :
- la fonction retourne un `int`,
- correspondant à l’indice de l’arête incidente.

Caractéristiques :
- initialisation avec une projection minimale à `+∞`,
- boucle sur toutes les arêtes,
- calcul du produit scalaire normal–normal,
- conservation de l’indice associé à la plus mauvaise projection.

Conceptuellement :
> on cherche l’arête qui “fait face” à la référence.

---

## État du système après cette étape

À la fin de ce refactor, nous disposons de :

- une **arête de référence** clairement identifiée,
- une **arête incidente** correspondante,
- des indices exploitables,
- une logique indépendante de l’ordre A/B,
- une structure prête pour l’étape suivante.

---

## Prochaine étape : le clipping

Avec :
- l’arête de référence,
- l’arête incidente,

nous pouvons désormais appliquer l’algorithme de **clipping** (tel que décrit par Erin Catto) afin de :
- tronquer correctement le segment incident,
- générer un ou plusieurs points de contact valides,
- fournir au solveur des données stables et cohérentes.

Cette étape est décisive pour :
- éliminer les points de contact aberrants,
- stabiliser les empilements,
- résoudre correctement les contacts multiples.

Comme toujours en moteur physique :  
**le diable est dans les détails**.
