# ESGI — Physique 2D  
## Stabilité des piles : limites du SAT et gestion des contacts multiples

Nous arrivons à la phase finale de notre moteur de physique 2D. Avant de conclure, il est essentiel d’aborder un **détail fondamental**, souvent sous-estimé, mais central dans les moteurs physiques : **la stabilité des empilements**, en particulier la différence de comportement entre **cercles** et **boîtes (rectangles)**.

---

## 1. Rappel : contraintes de pénétration et stabilité

Dans notre moteur, les collisions sont résolues via des **contraintes de pénétration** :
- lorsqu’un chevauchement est détecté,
- on applique une résolution itérative,
- après plusieurs itérations, la pénétration disparaît.

Avec cette approche :
- un empilement de **cercles** est parfaitement stable,
- un empilement de **boîtes** devient instable (jitter, oscillations, chute).

Ce constat est **normal** et met en évidence une limite structurelle de notre modèle actuel.

---

## 2. Pourquoi les cercles sont stables

Pour les cercles :
- le point de contact est **unique et bien défini**,
- la normale de collision est claire,
- l’impulsion est appliquée de manière cohérente.

Résultat :
- la gravité est compensée correctement,
- aucune rotation parasite,
- empilement stable.

---

## 3. Le problème des boîtes : jitter et déséquilibre

Pour les boîtes :
- les faces peuvent être **parallèles**,
- la zone de contact est **étendue**, pas ponctuelle,
- pourtant, notre moteur **choisit un seul point de collision**.

Conséquence :
- l’impulsion est appliquée **sur un seul côté**,
- cela crée un **couple de rotation artificiel**,
- les boîtes oscillent,
- la pile devient instable.

Ce phénomène est particulièrement visible :
- lorsque deux boîtes sont **parfaitement alignées**,
- ou lorsqu’une boîte repose sur le sol.

---

## 4. Origine du problème : implémentation du SAT

Notre algorithme de collision repose sur le **SAT (Separating Axis Theorem)**.

Rappel du fonctionnement :
- on teste les axes issus des arêtes,
- on projette les sommets,
- on cherche l’axe avec la **pénétration maximale**,
- on retourne **un seul axe + un seul point de contact**.

Cela fonctionne bien quand :
- les objets sont inclinés,
- un point de pénétration est clairement identifiable.

Mais cela échoue quand :
- les arêtes sont parallèles,
- plusieurs sommets ont une pénétration équivalente.

Dans ce cas, le SAT retourne :
- un **sommet extrême arbitraire**,
- qui ne représente pas la réalité physique du contact.

---

## 5. Cas critique : contacts multiples

Considérons deux boîtes alignées :
- la face inférieure de la boîte du haut
- repose entièrement sur la face supérieure de la boîte du bas.

Physiquement :
- il existe **deux points de contact** (ou une ligne de contact),
- l’impulsion devrait être répartie **équitablement**.

Dans notre moteur actuel :
- un seul point est retourné,
- l’autre reste non corrigé,
- les corrections alternent,
- d’où l’instabilité.

---

## 6. Principe fondamental à retenir

> **Un empilement stable nécessite des impulsions équilibrées.**

Cela implique :
- détecter **tous les points de contact pertinents**,
- appliquer l’impulsion **sur chacun d’eux**,
- éviter toute correction asymétrique.

---

## 7. Changement de modèle : contacts multiples

Nous devons modifier notre architecture :

### Avant
- 1 collision → 1 contact → 1 impulsion

### Après
- 1 collision → **N contacts** → **N impulsions réparties**

Concrètement :
- la détection de collision retourne une **liste de contacts**,
- chaque contact représente un point réel de collision,
- les impulsions sont appliquées sur **tous les contacts**.

---

## 8. Rôle du `Contact`

Le `Contact` (struct) devient :
- un **conteneur de données**, uniquement,
- il ne résout plus la collision.

Chaque contact contient :
- `bodyA`, `bodyB`
- `start` et `end` (points de pénétration)
- `normal` (toujours orientée de A vers B)

La résolution est déplacée :
- dans le **solveur global**,
- qui traite une **liste de contacts**.

---

## 9. Conséquences architecturales

Ce changement implique :
- une détection de collision capable de retourner **0, 1 ou plusieurs contacts**,
- un solveur qui répartit les impulsions,
- une meilleure stabilité des piles de boîtes.

C’est une évolution **indispensable** pour :
- moteurs physiques réalistes,
- empilements stables,
- comportement cohérent à long terme.

---

## 10. Prochaine étape

Nous allons maintenant :
1. préparer le code pour gérer des **vecteurs de contacts**,
2. adapter la détection SAT pour identifier **plusieurs points de contact**,
3. implémenter des algorithmes capables d’extraire ces contacts dans les cas dégénérés (faces parallèles).

C’est cette transition qui transforme un moteur « fonctionnel » en un moteur **physiquement crédible**.
