## 1. Retour au code après la théorie

Après l’étude mathématique complète de la résolution des contraintes (Jacobien, impulsion, multiplicateur de Lagrange), l’objectif est maintenant de **préparer l’architecture logicielle** permettant de les implémenter proprement dans le moteur physique.

On commence par la classe centrale : `Constraint`.

---

## 2. Classe `Constraint` : responsabilités principales

La classe `Constraint` représente une contrainte générique entre deux corps rigides :

- Deux pointeurs vers les corps impliqués :
  - `Body* A`
  - `Body* B`
- Fonctions communes à **toutes** les contraintes :
  - Récupération de la matrice de masse inverse
  - Récupération du vecteur des vitesses
  - Interface de résolution (`solve`)

Cette classe sert de **classe parente** pour tous les types de contraintes.

---

## 3. Matrice de masse inverse

La fonction `getInverseMassMatrix()` :

- Retourne une matrice $6 \times 6$
- Initialise tous les coefficients à zéro
- Remplit uniquement la diagonale avec :
  - $1/m_A$ pour les vitesses linéaires de A
  - $1/I_A$ pour la vitesse angulaire de A
  - $1/m_B$ pour les vitesses linéaires de B
  - $1/I_B$ pour la vitesse angulaire de B

Structure logique de la matrice :

$$
M^{-1} =
\begin{bmatrix}
1/m_A & 0 & 0 & 0 & 0 & 0 \\
0 & 1/m_A & 0 & 0 & 0 & 0 \\
0 & 0 & 1/I_A & 0 & 0 & 0 \\
0 & 0 & 0 & 1/m_B & 0 & 0 \\
0 & 0 & 0 & 0 & 1/m_B & 0 \\
0 & 0 & 0 & 0 & 0 & 1/I_B
\end{bmatrix}
$$

---

## 4. Vecteur des vitesses

La fonction `getVelocities()` :

- Retourne un vecteur de dimension 6
- Ordre des composantes :

$$
\mathbf{v} =
\begin{bmatrix}
v_{Ax} \\
v_{Ay} \\
\omega_A \\
v_{Bx} \\
v_{By} \\
\omega_B
\end{bmatrix}
$$

Ce vecteur regroupe les vitesses linéaires et angulaires des deux corps impliqués dans la contrainte.

---

## 5. Rôle central de la classe parente

La classe `Constraint` conserve :

- Les corps A et B
- La matrice de masse inverse
- Le vecteur des vitesses
- Un destructeur virtuel
- Une méthode virtuelle `solve()`

Ainsi :
- Toute contrainte utilise la même logique de base
- Le comportement spécifique est délégué aux classes filles

---

## 6. Hiérarchie des contraintes

Le moteur physique ne doit pas se limiter à un seul type de contrainte.  
Exemples de contraintes prévues :

- Contrainte de distance (joint)
- Contrainte de non-pénétration (collision)

Chaque contrainte :
- Hérite de `Constraint`
- Possède **son propre Jacobien**
- Implémente **sa propre méthode `solve()`**

Schéma conceptuel :

Constraint  
│  
├── DistanceConstraint  
│ └── Jacobien de distance  
│  
└── PenetrationConstraint  
└── Jacobien de collision


---

## 7. Jacobien spécifique à chaque contrainte

Le Jacobien ne doit **pas** être stocké dans la classe parente :

- Chaque type de contrainte a une géométrie différente
- Chaque contrainte a donc un Jacobien différent

Ainsi :
- `DistanceConstraint` contient son Jacobien de distance
- `PenetrationConstraint` contient son Jacobien de pénétration

---

## 8. Méthode `solve()`

La méthode `solve()` est :

- Déclarée virtuelle dans la classe parente
- Redéfinie dans chaque classe fille

Responsabilités de `solve()` :
1. Construire le Jacobien
2. Calculer la direction de l’impulsion ($J^T$)
3. Calculer la magnitude $\lambda$
4. Appliquer l’impulsion aux corps A et B

---

## 9. Vision globale

Cette architecture permet :

- Une résolution des contraintes unifiée
- Une extensibilité simple (ajout de nouveaux types de contraintes)
- Une séparation claire entre :
  - Données communes (classe parente)
  - Logique spécifique (classes filles)

---

## 10. Étape suivante

La prochaine étape consiste à :

- Étudier en détail la **contrainte de distance**
- Comprendre comment définir ses points d’ancrage
- Dériver mathématiquement son Jacobien
- Implémenter sa méthode `solve()`

La contrainte de pénétration sera ensuite traitée sur la même base.
