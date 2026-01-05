# Tunneling et Continuous Collision Detection (CCD)  
## Notes de cours – ESGI (Physique pour moteurs de jeu)

### 1. Continuité avec le Contact Caching
Le **contact caching / manifold caching** apporte déjà une amélioration notable de la stabilité du moteur physique, en particulier :
- la réduction des **micro-tremblements** (*small jitters*, souvent de l’ordre du pixel),
- la possibilité pour les objets de **passer en sommeil** (*sleeping objects*),
- l’évitement de mises à jour inutiles lorsque les contacts restent stables et sous un **seuil de distance** (*distance threshold*).

Cependant, même avec ces optimisations, certaines **limitations fondamentales** subsistent. L’une des plus importantes est le phénomène appelé **tunneling**.

![[medias/02 tunnelling - continuous detection collision 2026-01-03 13.26.09.excalidraw]]
---

### 2. Définition du tunneling
Le **tunneling** désigne une situation où :
- deux corps rigides se déplacent **très rapidement**,
- leur trajectoire devrait théoriquement mener à une collision,
- mais, en raison de la **nature discrète** de la simulation, les formes **ne se chevauchent jamais** (*no overlap*).

Dans une simulation discrète :
- on connaît la position à l’instant `t`,
- on intègre les vitesses,
- on prédit directement la position à `t + Δt`.

Si la distance parcourue pendant `Δt` est trop grande :
- l’objet peut « sauter » d’un côté à l’autre de l’obstacle,
- sans jamais générer d’état intermédiaire où une collision est détectable.

👉 Le moteur **ne peut pas détecter une collision qui n’existe pas géométriquement** dans un état discret.

---

### 3. Illustration conceptuelle
Considérons deux objets rapides :
- À l’instant `t`, ils sont séparés.
- À `t + Δt`, ils ont déjà dépassé la zone de collision.
- À aucun moment discret ils ne se chevauchent.

Résultat :
- le moteur ne déclenche **aucune collision**,
- les objets se traversent : c’est le **tunneling**.

Ce problème apparaît aussi bien en **2D qu’en 3D**.

---

### 4. Lien avec la Continuous Collision Detection (CCD)
Le tunneling est intimement lié à la notion de **Continuous Collision Detection (CCD)**.

Contrairement à la **discrete collision detection** :
- la CCD cherche à détecter les collisions **entre** deux états,
- et non uniquement **aux instants discrets**.

---

### 5. Principe général de la CCD
L’idée centrale est la suivante :
- considérer le déplacement d’un objet entre `t` et `t + Δt` comme un **segment** ou une **trajectoire continue**,
- effectuer un **ray casting** (*ray casting test*) ou un test de segment.

Procédure conceptuelle :
1. Construire un segment entre la position actuelle et la position prédite.
2. Tester l’intersection entre les trajectoires des objets.
3. Si une intersection est détectée :
   - calculer le **temps d’impact** (*time of impact*, TOI).

---

### 6. Temps d’impact (Time of Impact)
Le **time of impact** correspond à :
- la fraction de `Δt` à laquelle la collision se produit réellement.

Utilisation :
- « Revenir en arrière » dans la simulation jusqu’à ce temps précis,
- Positionner les objets à l’instant exact de la collision,
- Effectuer la détection et la résolution de collision à cet instant.

Cela revient à :
- **adapter dynamiquement le pas de temps**,
- pour ne pas manquer l’événement de collision.

---

### 7. Exemples concrets d’usage
La CCD est particulièrement indispensable dans les cas suivants :

- **Jeux de billard / pool**
  - Une boule rapide peut traverser une autre sans CCD.
- **Projectiles**
  - Balles, missiles, obus, rayons.
- **Objets à très grande vitesse**
  - Tous les cas où la vitesse est élevée par rapport à la taille des formes.

Dans ces situations :
- le ray casting entre les positions successives est souvent la seule solution fiable.

---

### 8. Coût et complexité
Bien que conceptuellement simple, la CCD :
- ajoute de la **complexité algorithmique**,
- augmente le **coût de calcul**,
- complique le pipeline du moteur physique.

C’est pourquoi :
- elle n’est **pas toujours activée globalement**,
- elle est souvent réservée à certains objets critiques (*bullets*, *fast bodies*).

---

### 9. Choix pédagogique du cours
Dans le cadre de ce moteur physique :
- la **CCD ne sera pas implémentée**,
- afin de préserver la lisibilité et la cohérence du code,
- et d’éviter un excès de complexité prématuré.

Néanmoins, il est **essentiel d’en comprendre l’existence et le rôle** :
- la quasi-totalité des moteurs physiques professionnels intègrent une forme de CCD,
- souvent combinée à la détection discrète classique.

---

### 10. Conclusion
- Le **tunneling** est une limitation structurelle des simulations discrètes.
- La **continuous collision detection** est la réponse standard à ce problème.
- Elle repose sur le calcul d’intersections continues et du **temps d’impact**.
- Même si elle n’est pas implémentée ici, elle constitue :
  - un **concept fondamental**,
  - une **extension naturelle** pour un moteur physique plus avancé.

Pour les étudiants souhaitant aller plus loin :
- de nombreuses implémentations existent (articles, dépôts GitHub),
- la CCD est souvent moins complexe à implémenter qu’elle n’y paraît,
- mais son intégration demande des choix clairs en termes de performances et de design.
