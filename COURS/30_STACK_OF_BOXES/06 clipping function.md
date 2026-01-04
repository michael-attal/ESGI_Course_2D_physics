## Implémentation détaillée de `clipSegmentToLine`

Nous disposons désormais de l’ensemble du pipeline conceptuel :
- arête de référence,
- arête incidente,
- plans latéraux de clipping,
- filtrage par pénétration.

Il reste cependant un élément central à expliciter :  
la fonction **`clipSegmentToLine`**, responsable du **clipping géométrique d’un segment contre un demi-espace**.

---

## Prototype et rôle de la fonction

Dans `shape.h`, la fonction est déclarée comme suit :

- **`contactsIn`** : ensemble de points d’entrée (au maximum deux),
- **`contactsOut`** : paramètre de sortie contenant les points clippés,
- **`C0`, `C1`** : sommets définissant le **plan de clipping**.

La fonction est `const`, car elle ne modifie pas l’état de la forme :  
elle se contente de produire un résultat géométrique à partir de données en entrée.

Son objectif est simple mais fondamental :

> **Clipper un segment contre un plan et retourner les points conservés.**

---

## Initialisation

L’algorithme commence par :
- initialiser un compteur `numOut = 0`,
- qui représentera le nombre de points valides après clipping.

---

## Définition du plan de clipping

Le plan est défini par l’arête `(C0, C1)`.

On calcule :
- le vecteur direction `C1 - C0`,
- puis sa normale (après normalisation).

Cette normale définit l’orientation du demi-espace :
- un point est **accepté** s’il se situe du bon côté du plan,
- rejeté sinon.

---

## Calcul des distances signées

Pour les deux extrémités du segment incident :

- `distance0 = dot(contactsIn[0] - C0, normal)`
- `distance1 = dot(contactsIn[1] - C0, normal)`

Interprétation :
- distance < 0 → point **derrière** le plan (conservé),
- distance ≥ 0 → point **devant** le plan (rejeté).

---

## Conservation des points internes

Si une extrémité est derrière le plan :
- elle est ajoutée à `contactsOut`,
- `numOut` est incrémenté.

Cela correspond au cas où un point du segment est déjà valide sans interpolation.

---

## Détection d’une intersection segment–plan

Si :

```cpp
distance0 * distance1 < 0
```


alors :
- les deux points sont de part et d’autre du plan,
- le segment coupe le plan,
- il existe un **point d’intersection unique**.

Ce test repose sur un principe simple :
> le produit de deux valeurs de signes opposés est négatif.

---

## Calcul de l’intersection par interpolation linéaire

L’intersection est calculée via **interpolation linéaire (LERP)**.

### Rappel : interpolation linéaire

Étant donné deux points `A` et `B`, on définit :

$$
P(t) = A + t · (B − A), \text{ avec t } ∈ [0, 1]
$$

- `t = 0` → point A,
- `t = 1` → point B,
- `t ∈ (0,1)` → point intermédiaire sur le segment.

---

### Calcul du paramètre `t`

Dans le contexte du clipping :

```cpp
t = distance0 / (distance0 - distance1)
```


Ce rapport exprime **la proportion exacte** du segment à laquelle se situe l’intersection avec le plan.

---

### Calcul du point d’intersection

Le point clippé est alors :

```cpp
contact = contactsIn[0] + t · (contactsIn[1] − contactsIn[0])
```


Ce point est :
- ajouté à `contactsOut`,
- `numOut` est incrémenté.

---

## Valeur de retour

La fonction retourne :
- `numOut` : nombre total de points conservés (0, 1 ou 2).

Ce résultat est ensuite utilisé par l’algorithme de collision pour :
- poursuivre le clipping avec d’autres plans,
- ou abandonner si le segment est entièrement rejeté.

---

## Rôle dans la génération des contacts

Il est essentiel de rappeler que :
- `clipSegmentToLine` **ne décide pas** si un point est un contact valide,
- elle effectue uniquement un **traitement géométrique**.

Le filtrage final (pénétration / séparation négative) est effectué **après** le clipping,
dans la phase de génération des contacts physiques.

---

## Résultats observés

Les tests montrent que :

- une collision simple produit un seul contact,
- une collision étendue (faces parallèles) produit **deux contacts**,
- seuls les points réellement pénétrants sont conservés,
- les cas dégénérés (faces parallèles, empilements) sont correctement gérés.

Cette approche :
- corrige les points de contact aberrants,
- stabilise les empilements,
- permet l’application d’impulsions multiples cohérentes.

---

## Impact sur la résolution des contraintes

Lorsque deux points de contact sont générés :
- les impulsions sont appliquées **sur chaque point**,
- la correction de la pénétration est répartie spatialement,
- le système gagne en stabilité numérique.

C’est précisément ce mécanisme qui :
- élimine les oscillations,
- empêche les rotations parasites,
- rend possible des empilements stables.

---

## Conclusion

La fonction `clipSegmentToLine` constitue la **brique géométrique fondamentale**
du système de contacts multiples inspiré de *Box2D*.

Combinée à :
- la sélection SAT de l’arête de référence,
- l’identification de l’arête incidente,
- le filtrage par pénétration,

elle permet de construire un pipeline de collision :
- robuste,
- extensible,
- physiquement cohérent.

La prochaine étape consiste désormais à évaluer si cette génération de contacts,
associée au solveur d’impulsions, suffit à garantir la stabilité globale du système
dans des scénarios complexes (empilements, chaînes de contacts, repos prolongé).



