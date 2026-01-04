# Détection de collision Cercle ↔ Polygone : Gestion des régions et contact

---

## Contexte

Cette étape consiste à déterminer **la région du centre du cercle** par rapport à l’arête la plus proche et à calculer les informations de collision. Les régions sont :

1. **Région A** : Coin supérieur gauche de l’arête
2. **Région B** : Coin inférieur droit de l’arête
3. **Région C** : Zone centrale le long de l’arête
4. **Intérieur du polygone** : Centre du cercle à l’intérieur du polygone

L’algorithme calcule le **contact**, le **profondeur de pénétration** et le **vecteur normal** pour chacune de ces situations.

---

## Étapes de l’implémentation

### 1. Initialisation

- Récupérer les **formes** : polygone et cercle
- Récupérer les **vertices du polygone** en coordonnées mondiales
- Déclarer un booléen `isOutside` pour savoir si le centre du cercle est à l’intérieur ou à l’extérieur du polygone
- Déclarer `minCurrentVertex` et `minNextVertex` pour stocker l’arête la plus proche
- Déclarer `distanceCircleEdge` pour suivre la distance minimale entre le centre du cercle et l’arête

---

### 2. Recherche de l’arête la plus proche

- Boucler sur toutes les **vertices** du polygone
- Calculer chaque **arête** et son **vecteur normal**
- Calculer la **projection** du vecteur `centre du cercle - vertex` sur le normal
- Si la projection est **positive**, le centre est **à l’extérieur**
- Sinon, le centre est à l’intérieur, et on cherche la projection la moins négative pour identifier l’arête la plus proche
- Stocker les vertices correspondantes et la distance minimale dans `distanceCircleEdge`

---

### 3. Détection de la région

#### Région A

- Vecteur `V1` : du **vertex courant** vers le centre du cercle
- Vecteur `V2` : du **vertex courant** vers le **vertex suivant** de l’arête
- Si le **dot product** `V1·V2 < 0` → centre dans région A
- Distance `|V1|` < rayon → collision détectée
- Calculer le **contact** :
  - `contactA = polygone`, `contactB = cercle`
  - `penetrationDepth = rayon - |V1|`
  - `normal = V1.normalized`
  - `start = centreCercle - normal*rayon`
  - `end = start + normal*penetrationDepth`

#### Région B

- Vecteur `V1` : du **vertex suivant** vers le centre du cercle
- Vecteur `V2` : du **vertex suivant** vers le **vertex courant**
- Si `V1·V2 < 0` → centre dans région B
- Distance `|V1|` < rayon → collision détectée
- Calculer le **contact** comme pour la région A

#### Région C (zone centrale)

- Distance perpendiculaire du centre du cercle à l’arête
- Si distance < rayon → collision détectée
- Calculer le **contact** :
  - `penetrationDepth = rayon - distance`
  - `normal = edge.normal`
  - `start = centreCercle - normal*rayon`
  - `end = start + normal*penetrationDepth`

---

### 4. Cas intérieur du polygone

- Si le **centre du cercle est à l’intérieur** :
  - Collision assurée
  - `penetrationDepth = rayon - distanceCircleEdge`
  - `normal = edge.normal`
  - `start = centreCercle - normal*rayon`
  - `end = start + normal*penetrationDepth`

---

### 5. Conclusion

- Chaque région nécessite un calcul spécifique pour **contact**, **normal** et **penetrationDepth**
- Gestion de cas **extérieur/extérieur**, **intérieur/intérieur** et **zones régionales** pour robustesse
- Permet d’avoir des informations fiables même si le cercle traverse rapidement le polygone

#tags: physics-engine/collision, physics-engine/polygon, physics-engine/circle, physics-engine/2d, physics-engine/contact, physics-engine/penetration, physics-engine/vector-operations
