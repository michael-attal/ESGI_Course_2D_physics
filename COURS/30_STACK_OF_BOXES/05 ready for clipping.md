## Algorithme de clipping : logique complète et génération des contacts multiples

L’objectif de cette étape est de **générer des contacts multiples stables** lorsque deux polygones se recouvrent sur une surface étendue. Contrairement au SAT classique, qui ne retourne qu’un point de pénétration, nous cherchons ici à identifier **un ensemble cohérent de points de contact**, conformément à l’approche proposée par *Erin Catto*.

À ce stade, deux éléments fondamentaux ont déjà été correctement identifiés :
- l’**arête de référence (reference edge)**,
- l’**arête incidente (incident edge)**.

Ces deux entités constituent l’entrée principale de l’algorithme de clipping.

---

## Principe général du clipping (Erin Catto)

Une fois les arêtes identifiées, l’algorithme suit la règle suivante :

> **On clippe l’arête incidente contre les plans latéraux (side planes) de l’arête de référence, mais jamais contre la face de référence elle-même.**

Autrement dit :
- l’arête incidente est progressivement tronquée,
- chaque troncature est effectuée par rapport aux arêtes adjacentes à la référence,
- seuls les points ayant une **pénétration positive** sont conservés.

Ce dernier point est crucial :  
un point issu du clipping mais situé **à l’extérieur du demi-espace pénétrant** doit être ignoré.

---

## Construction du segment incident

### Indices et sommets

À partir de l’arête incidente, nous récupérons :
- `incidentIndex` : indice de l’arête incidente,
- `incidentNextIndex` : `(incidentIndex + 1) % vertexCount`.

Ces deux indices définissent :
- `V0` : premier sommet de l’arête incidente,
- `V1` : second sommet de l’arête incidente.

Ils forment un **segment initial** qui sera successivement clippé.

---

## Initialisation des points de contact

Deux structures sont utilisées :
- `contactPoints` : points courants à clipper,
- `clippedPoints` : points résultants après clipping.

Initialement :
- les deux vecteurs contiennent `{ V0, V1 }`.

Ce choix reflète le fait que l’arête incidente est, au départ, intacte.

---

## Détermination des plans de clipping

Les plans de clipping correspondent aux **arêtes du polygone de référence**, à l’exception de l’arête de référence elle-même.

### Parcours des arêtes de référence

Pour chaque arête `i` du polygone de référence :
- si `i == indexReferenceEdge` → on ignore (règle de Catto),
- sinon :
  - `C0` = sommet `i`,
  - `C1` = sommet `(i + 1) % vertexCount`.

L’arête `(C0, C1)` définit un **plan de clipping**.

---

## Clipping du segment contre un plan

Le cœur de l’algorithme repose sur une fonction dédiée :

```cpp
clipSegmentToLine(contactPoints,clippedPoints,C0,C1)
```


Caractéristiques importantes :
- `contactPoints` : points d’entrée (au maximum 2),
- `clippedPoints` : paramètre de sortie,
- la fonction retourne le **nombre de points conservés**.

Après chaque appel :
- si le nombre de points < 2 → abandon (clipping invalide),
- sinon :
  - `contactPoints` est remplacé par `clippedPoints`,
  - le processus continue avec le plan suivant.

Ainsi, le segment incident est **progressivement tronqué** par tous les plans latéraux de la référence.

---

## Résultat du clipping géométrique

À l’issue de cette boucle :
- on obtient **0, 1 ou 2 points**,
- géométriquement valides,
- mais pas encore filtrés selon la pénétration.

Ces points correspondent aux intersections entre l’arête incidente et le prisme défini par les plans latéraux.

---

## Filtrage par pénétration (séparation négative)

Le clipping géométrique n’est pas suffisant.  
Il faut désormais vérifier que les points sont bien **en pénétration** par rapport à la face de référence.

### Calcul de la séparation

Pour chaque point clippé `Vclip` :

- on récupère un sommet de la référence :

```cpp
Vref = referenceVertices[indexReferenceEdge]
```

- on calcule :

```cpp
separation = dot(Vclip - Vref, referenceNormal)
```


Convention utilisée :
- séparation < 0 → pénétration,
- séparation ≥ 0 → rejet.

---

## Création des contacts physiques

Pour chaque point valide :
- création d’une structure `Contact`,
- chargement :
- des corps A et B,
- de la normale (normale de la référence),
- du point de contact,
- de la profondeur de pénétration (`-separation`).

### Orientation A → B

Si la référence correspond au corps B :
- inversion du point de départ et d’arrivée,
- inversion de la normale.

Cela garantit une convention cohérente :
> **tous les contacts sont orientés de A vers B**.

---

## Résultat final

À la fin de l’algorithme :
- le système peut retourner **un ou deux contacts**,
- parfaitement cohérents,
- exploitables par le solveur d’impulsions.

C’est précisément cette étape qui :
- stabilise les empilements,
- élimine les contacts erratiques,
- permet une résolution réaliste des collisions polygone–polygone.

---

## Prochaine étape : `clipSegmentToLine`

Il reste un élément volontairement traité comme une *boîte noire* :
- la fonction `clipSegmentToLine`.

Elle implémente :
- l’intersection segment–demi-espace,
- via interpolation linéaire,
- exactement comme dans *Box2D*.

La prochaine étape consistera à :
- ouvrir cette boîte noire,
- détailler les équations,
- comprendre comment sont calculés les points interpolés.

C’est la dernière pièce du puzzle pour une implémentation complète du clipping SAT avancé.
