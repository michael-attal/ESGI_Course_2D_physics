# Impulsions de contrainte vs forces de contrainte

---

## Contexte

- Objectif : maintenir un objet contraint sur une trajectoire (ex. chemin circulaire) sans modifier directement sa position.
- Méthodes possibles :
  1. **Basée sur la vitesse (*velocity-based*)** : on agit sur la première dérivée de la contrainte ($\dot{C}=0$).
  2. **Basée sur l'accélération ou la force (*acceleration/force-based*)** : on agit sur la deuxième dérivée de la contrainte ($\ddot{C}=0$).

---

## Approche basée sur la vitesse

- On modifie la **vitesse** de l'objet pour que la première dérivée de la contrainte soit nulle.
- Les vitesses des corps impliqués sont ajustées via des **impulsions de contrainte (*constraint impulses*)**.
- Une impulsion $\vec{J}$ est liée à une force $\vec{F}$ appliquée sur un intervalle de temps $\Delta t$ :
  $$
  \vec{J} = \vec{F} \Delta t
  $$
- Une impulsion change directement la vitesse :
  $$
  \Delta \vec{v} = \mathbf{M}^{-1} \vec{J}
  $$
  où $\mathbf{M}^{-1}$ est la matrice contenant les inverses des masses et moments d’inertie des corps.

---

## Conversion forces ↔ impulsions

- Force : $\vec{F} = m \vec{a}$
- Accélération : $\vec{a} = \mathbf{M}^{-1} \vec{F}$
- Impulsion : $\vec{J} = \vec{F} \Delta t \implies \Delta \vec{v} = \mathbf{M}^{-1} \vec{J}$
- Idéal pour passer d’une approche force-based à velocity-based dans un moteur physique.

---

## Matrice des masses inverses

- Pour un corps seul (2D) :
  $$
  \mathbf{M}^{-1} =
  \begin{bmatrix}
  m^{-1} & 0 & 0 \\
  0 & m^{-1} & 0 \\
  0 & 0 & I^{-1}
  \end{bmatrix}
  $$
  avec $m$ la masse et $I$ le moment d’inertie.
- Pour deux corps A et B (ex. joint ou contrainte entre deux corps) : matrice $6 \times 6$ diagonale
  - Bloc A : inverse masse + inverse moment d’inertie
  - Bloc B : inverse masse + inverse moment d’inertie
- Multiplication par le vecteur des impulsions (linéaires et angulaires) fournit le changement de vitesse $\Delta \vec{v}$ pour les deux corps.

---

## Classe Constraint (pseudo-code)

```cpp
class Constraint {
public:
    RigidBody* bodyA;
    RigidBody* bodyB;

    // Retourne la matrice 6x6 des masses inverses
    Matrix6x6 getInverseM() const {
        Matrix6x6 M;
        M.setZero();
        M(0,0) = bodyA->inverseMass;
        M(1,1) = bodyA->inverseMass;
        M(2,2) = bodyA->inverseInertia;
        M(3,3) = bodyB->inverseMass;
        M(4,4) = bodyB->inverseMass;
        M(5,5) = bodyB->inverseInertia;
        return M;
    }

    // Résout la contrainte et applique les impulsions aux corps
    void solve();
};
```
- `getInverseM()` : construit et retourne la matrice des masses inverses et des moments d’inertie pour les corps impliqués.
    
- `solve()` : calcule les impulsions de contrainte et applique les changements de vitesse correspondants.
    

---

## Résumé conceptuel

- Une impulsion de contrainte est un moyen de **modifier la vitesse** pour satisfaire la contrainte.
    
- La conversion force ↔ impulsion repose sur la multiplication par $\Delta t$.
    
- Les matrices de masses inverses sont essentielles pour considérer correctement l’inertie des corps et appliquer les bonnes impulsions.
    
- L’approche velocity-based est largement utilisée dans les moteurs physiques modernes.

