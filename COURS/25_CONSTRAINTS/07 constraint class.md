# Préparation du code pour les contraintes

---

## Contexte

- Objectif : remplacer la résolution de collisions directe par des contraintes (*constraints*), en particulier la contrainte de non-pénétration.
- Étapes principales :
  1. Supprimer les boucles d’itération pour la projection partielle des collisions.
  2. Créer une nouvelle structure pour gérer les contraintes de manière systématique.
  3. Préparer des classes génériques pour les matrices et vecteurs de taille variable.

---

## Classe `Constraint`

- **Responsabilité** : représenter une contrainte entre un ou plusieurs corps rigides.
- **Attributs principaux** :
  - `RigidBody* bodyA` : pointeur vers le premier corps impliqué.
  - `RigidBody* bodyB` : pointeur vers le second corps impliqué.
- **Méthodes principales** :
  - `Matrix getInverseM()` : retourne la matrice des masses inverses et moments d’inertie des corps impliqués.
  - `void solve()` : résout la contrainte et applique les impulsions correspondantes aux corps.

---

## Structures de données dynamiques

### Matrice dynamique `MatrixMN`

- Objectif : ne pas se limiter à des tailles fixes (ex. 3x3, 6x6, 12x12).
- Attributs :
  - `int M` : nombre de lignes.
  - `int N` : nombre de colonnes.
  - `std::vector<std::vector<float>> data` : stockage des valeurs.
- Méthodes :
  - Constructeur dynamique : `MatrixMN(int rows, int cols)`.

### Vecteur dynamique `VectorN`

- Objectif : manipuler des vecteurs avec un nombre quelconque de composants.
- Attributs :
  - `int N` : nombre de composantes.
  - `std::vector<float> elements` : stockage des valeurs.
- Méthodes :
  - Constructeur dynamique : `VectorN(int size)`.

---

## Avantages de cette approche

- **Généralisation** : la même classe `MatrixMN` peut servir pour des matrices 3x3, 6x6 ou autres selon le nombre de corps impliqués.
- **Flexibilité** : les vecteurs `VectorN` permettent de représenter des vecteurs linéaires et angulaires de différentes dimensions.
- **Préparation à la résolution des contraintes** : ces structures facilitent les opérations de multiplication de matrices et vecteurs nécessaires pour appliquer les impulsions et respecter les contraintes.

---

## Étapes suivantes

1. Implémenter `VectorN` et `MatrixMN`.
2. Préparer les méthodes de multiplication et manipulation pour ces classes.
3. Intégrer ces classes dans `Constraint` pour gérer les contraintes entre corps.
4. Commencer à résoudre les contraintes avec la méthode `solve()`.
