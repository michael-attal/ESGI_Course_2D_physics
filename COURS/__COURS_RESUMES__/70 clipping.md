![[medias/70 clipping 2026-01-02 17.45.26.excalidraw]]

# Code

```cpp

// ============================================================================
// Détection de collision entre deux polygones convexes
// Algorithme basé sur le SAT (Separating Axis Theorem) + clipping
// ============================================================================

bool CollisionDetection::IsCollidingPolygonPolygon(
    Body* a,
    Body* b,
    std::vector<Contact>& contacts
) {
    // Cast des formes génériques en formes polygonales
    PolygonShape* aPolygonShape = (PolygonShape*) a->shape;
    PolygonShape* bPolygonShape = (PolygonShape*) b->shape;

    // Indices des arêtes candidates servant d’arêtes de référence
    int aIndexReferenceEdge, bIndexReferenceEdge;

    // Points de support correspondant à la séparation minimale
    Vec2 aSupportPoint, bSupportPoint;

    // ------------------------------------------------------------------------
    // Étape 1 : Test SAT – séparation minimale de A vers B
    // ------------------------------------------------------------------------
    float abSeparation =
        aPolygonShape->FindMinSeparation(
            bPolygonShape,
            aIndexReferenceEdge,
            aSupportPoint
        );

    // Si la séparation est positive ou nulle, il existe un axe séparateur
    // → pas de collision
    if (abSeparation >= 0) {
        return false;
    }

    // ------------------------------------------------------------------------
    // Étape 2 : Test SAT – séparation minimale de B vers A
    // ------------------------------------------------------------------------
    float baSeparation =
        bPolygonShape->FindMinSeparation(
            aPolygonShape,
            bIndexReferenceEdge,
            bSupportPoint
        );

    // Même logique : axe séparateur trouvé → pas de collision
    if (baSeparation >= 0) {
        return false;
    }

    // ------------------------------------------------------------------------
    // Étape 3 : Choix de l’arête de référence
    // On prend celle avec la pénétration la moins profonde
    // (meilleure stabilité numérique)
    // ------------------------------------------------------------------------
    PolygonShape* referenceShape;
    PolygonShape* incidentShape;
    int indexReferenceEdge;

    if (abSeparation > baSeparation) {
        referenceShape = aPolygonShape;
        incidentShape  = bPolygonShape;
        indexReferenceEdge = aIndexReferenceEdge;
    } else {
        referenceShape = bPolygonShape;
        incidentShape  = aPolygonShape;
        indexReferenceEdge = bIndexReferenceEdge;
    }

    // Récupération de l’arête de référence dans l’espace monde
    Vec2 referenceEdge = referenceShape->EdgeAt(indexReferenceEdge);

    // ========================================================================
    // Étape 4 : Clipping (algorithme de Sutherland–Hodgman)
    // Objectif : calculer les points de contact exacts
    // ========================================================================

    // Recherche de l’arête incidente la plus opposée à la normale de référence
    int incidentIndex =
        incidentShape->FindIncidentEdge(referenceEdge.Normal());

    int incidentNextIndex =
        (incidentIndex + 1) % incidentShape->worldVertices.size();

    // Segment incident initial (2 sommets)
    Vec2 v0 = incidentShape->worldVertices[incidentIndex];
    Vec2 v1 = incidentShape->worldVertices[incidentNextIndex];

    std::vector<Vec2> contactPoints = { v0, v1 };
    std::vector<Vec2> clippedPoints = contactPoints;

    // Clipping successif du segment incident contre toutes les arêtes
    // du polygone de référence, sauf l’arête de référence elle-même
    for (int i = 0; i < referenceShape->worldVertices.size(); i++) {

        if (i == indexReferenceEdge)
            continue;

        Vec2 c0 = referenceShape->worldVertices[i];
        Vec2 c1 =
            referenceShape->worldVertices[
                (i + 1) % referenceShape->worldVertices.size()
            ];

        // Découpe du segment contre la demi-droite définie par (c0, c1)
        int numClipped =
            referenceShape->ClipSegmentToLine(
                contactPoints,
                clippedPoints,
                c0,
                c1
            );

        // Si moins de deux points subsistent, il n’y a plus de contact valide
        if (numClipped < 2) {
            break;
        }

        // Mise à jour pour l’itération suivante
        contactPoints = clippedPoints;
    }

    // Sommet de référence servant au calcul de la pénétration
    auto vref = referenceShape->worldVertices[indexReferenceEdge];

    // ------------------------------------------------------------------------
    // Étape 5 : Génération des contacts
    // On ne conserve que les points ayant une pénétration négative
    // ------------------------------------------------------------------------
    for (auto& vclip : clippedPoints) {

        // Calcul de la séparation le long de la normale de l’arête de référence
        float separation =
            (vclip - vref).Dot(referenceEdge.Normal());

        // Si séparation négative → pénétration effective
        if (separation <= 0) {

            Contact contact;
            contact.a = a;
            contact.b = b;
            contact.normal = referenceEdge.Normal();
            contact.start = vclip;
            contact.end   = vclip + contact.normal * -separation;

            // Garantie de cohérence :
            // la normale et le segment vont toujours de A vers B
            if (baSeparation >= abSeparation) {
                std::swap(contact.start, contact.end);
                contact.normal *= -1.0f;
            }

            contacts.push_back(contact);
        }
    }

    return true;
}

// ============================================================================
// Clipping d’un segment par rapport à une droite
// Utilisé pour le calcul précis des points de contact
// ============================================================================

int PolygonShape::ClipSegmentToLine(
    const std::vector<Vec2>& contactsIn,
    std::vector<Vec2>& contactsOut,
    const Vec2& c0,
    const Vec2& c1
) const {
    // Nombre de points conservés après découpe
    int numOut = 0;

    // Normale de la droite de clipping
    Vec2 normal = (c1 - c0).Normalize();

    // Distance signée des deux extrémités du segment à la droite
    float dist0 = (contactsIn[0] - c0).Cross(normal);
    float dist1 = (contactsIn[1] - c0).Cross(normal);

    // Si le point est derrière ou sur la droite → conservé
    if (dist0 <= 0)
        contactsOut[numOut++] = contactsIn[0];

    if (dist1 <= 0)
        contactsOut[numOut++] = contactsIn[1];

    // Si les points sont de part et d’autre de la droite,
    // on calcule le point d’intersection par interpolation linéaire
    if (dist0 * dist1 < 0) {
        float totalDist = dist0 - dist1;

        // Paramètre t de l’intersection
        float t = dist0 / totalDist;

        // Intersection : lerp(p0, p1, t)
        Vec2 contact =
            contactsIn[0] +
            (contactsIn[1] - contactsIn[0]) * t;

        contactsOut[numOut++] = contact;
    }

    return numOut;
}

```


# Analyse détaillée de `ClipSegmentToLine`

## 1. Rôle général de la fonction

La fonction `ClipSegmentToLine` implémente une opération de **clipping géométrique** :  
elle découpe un **segment** par rapport à une **droite orientée**, afin de ne conserver que la partie du segment située **dans un demi-plan donné**.

Dans un moteur physique, cette opération est essentielle lors de la détection de collision **polygone–polygone**, plus précisément dans la phase de **génération des contacts** après le test SAT (Separating Axis Theorem).

Objectifs principaux :
- déterminer **des points de contact précis**
- éliminer les points situés à l’extérieur de la zone de collision
- garantir la **stabilité numérique** du solveur de contraintes

---

## 2. Signature et données manipulées

```cpp
int PolygonShape::ClipSegmentToLine(
    const std::vector<Vec2>& contactsIn,
    std::vector<Vec2>& contactsOut,
    const Vec2& c0,
    const Vec2& c1
) const
```

### Signification des paramètres

- `contactsIn`  
    Contient **exactement deux points** :  
    les extrémités du **segment incident** à découper.
    
- `contactsOut`  
    Tableau de sortie, pouvant contenir **0, 1 ou 2 points**, correspondant aux points du segment **à l’intérieur du demi-plan**.
    
- `c0`, `c1`  
    Deux points définissant une **arête du polygone de référence**.  
    Cette arête définit une **droite orientée** servant de frontière de clipping.

```cpp
int numOut = 0;
```

- Compteur du nombre de points valides après clipping.
- La fonction retourne ce nombre à la fin.
## 4. Construction de la droite de clipping



```cpp
Vec2 normal = (c1 - c0).Normalize();
```

### Interprétation géométrique

- `(c1 - c0)` est le **vecteur directeur** de l’arête.
    
- Après normalisation, on obtient un vecteur unitaire servant d’axe de référence.
    
- Malgré son nom, ce vecteur n’est pas une normale perpendiculaire classique :  
    il est utilisé comme **vecteur de test** dans le produit vectoriel 2D.

## 5. Calcul des distances signées via le produit vectoriel (cross)

```cpp
float dist0 = (contactsIn[0] - c0).Cross(normal);
float dist1 = (contactsIn[1] - c0).Cross(normal);
```

### 5.1 Définition du produit vectoriel 2D

Pour deux vecteurs 2D `a` et `b` :

$a \times b = ax​by​−ay​bx$​

Le résultat est un **scalaire**.

---

### 5.2 Sens géométrique du `Cross`

Le produit vectoriel 2D permet de déterminer :

- **le côté d’une droite sur lequel se situe un point**
    
- une **distance signée** par rapport à cette droite (à un facteur près)
    

Dans ce contexte :

- `(contactsIn[i] - c0)` est le vecteur allant de la droite vers le point testé
    
- `normal` définit l’orientation de la droite
    

Interprétation du signe :

- `dist < 0` → point **à l’intérieur du demi-plan**
    
- `dist > 0` → point **à l’extérieur**
    
- `dist = 0` → point **exactement sur la droite**
    

👉 Le `cross` remplace ici un test d’équation de plan.

## 6. Conservation des points valides

```cpp
if (dist0 <= 0)
    contactsOut[numOut++] = contactsIn[0];

if (dist1 <= 0)
    contactsOut[numOut++] = contactsIn[1];
```

- Si la distance est négative ou nulle, le point est conservé.
    
- Trois cas possibles après cette étape :
    - `0 point` → segment entièrement rejeté
    - `1 point` → segment partiellement valide
    - `2 points` → segment entièrement valide

## 7. Cas critique : segment traversant la droite

```cpp
if (dist0 * dist1 < 0)
```

### Interprétation

- Les distances ont des signes opposés
- Un point est à l’intérieur, l’autre à l’extérieur
- Le segment **coupe la droite**
- Il faut calculer le **point d’intersection**

## 8. Calcul du point d’intersection (interpolation linéaire)

```cpp
float totalDist = dist0 - dist1;
float t = dist0 / totalDist;
```
- `t` est un paramètre compris entre 0 et 1
    
- Il indique **où se situe l’intersection sur le segment**
    

Formule utilisée :

$P(t) = P_0 + t (P_1 - P_0)$

```cpp
Vec2 contact =
    contactsIn[0] +
    (contactsIn[1] - contactsIn[0]) * t;

```

- Le point obtenu est **exactement sur la frontière du demi-plan**
- Il est ajouté à la liste des points valides

## 9. Valeur de retour

```cpp
return numOut;
```

- Indique combien de points subsistent après clipping
- Utilisé par l’algorithme de clipping global pour décider :
    - si un contact existe
    - combien de points de contact doivent être générés

## 10. Importance dans un moteur physique

Cette fonction permet :

- un **contact précis géométriquement**
- une meilleure stabilité du solveur
- une réduction significative du **tremblement (jitter)**
- des empilements plus stables
- une cohérence avec les moteurs professionnels (Box2D, Chipmunk, Bullet)
    

---

## 11. Résumé conceptuel

- Le produit vectoriel 2D sert à tester l’appartenance à un demi-plan
- Le clipping découpe un segment contre une arête
- Cette opération est fondamentale pour produire des **contacts réalistes**
- C’est un pilier de la détection de collision polygone–polygone

👉 Sans ce type de clipping précis, un moteur physique devient rapidement instable.
