# Résolution de collision avec rotation — Vitesse au point de contact et impulsions

---

## Rappel : vitesse dépendante du point de contact

Lorsqu’un corps rigide est en rotation, la **vitesse linéaire dépend du point considéré**.  
Dans une collision, ce point est le **point de contact** (*contact point*), noté $P$.  
La résolution doit donc s’appuyer sur la vitesse **au point $$P$$**, et non uniquement sur celle du centre de masse.

---

## Collision entre deux corps rigides en rotation

Deux corps rigides, notés $A$ et $B$, évoluent librement jusqu’à la collision détectée par le SAT (*Separating Axis Theorem*).  
Le point de contact $P$ est identifié sur leurs surfaces.

On définit :
- $\mathbf{R}_A$ : vecteur du centre de masse de $A$ vers $P$  
- $\mathbf{R}_B$ : vecteur du centre de masse de $B$ vers $P$  

Ces vecteurs sont essentiels pour le calcul des vitesses locales.

---

## Définition de la vitesse au point $P$

La **vitesse au point $P$** (*point velocity*) est la somme :
- de la vitesse linéaire du centre de masse,
- de la contribution due à la rotation.

On la note $\mathbf{V}$ pour la distinguer de la vitesse linéaire $\mathbf{v}$.

---

## Vitesse au point $P$ pour le corps $A$

La vitesse au point de contact pour le corps $A$ est :

$$
\mathbf{V}_A = \mathbf{v}_A + \boldsymbol{\omega}_A \times \mathbf{R}_A
$$

où :
- $\mathbf{v}_A$ est la vitesse du centre de masse,
- $\boldsymbol{\omega}_A$ est la vitesse angulaire (*angular velocity*),
- $\times$ est le produit vectoriel (*cross product*).

---

## Vitesse au point $P$ pour le corps $B$

De façon analogue, pour le corps $B$ :

$$
\mathbf{V}_B = \mathbf{v}_B + \boldsymbol{\omega}_B \times \mathbf{R}_B
$$

Ces expressions fournissent les vitesses exactes au point d’impact.

---

## Objectif : vitesse après collision

Nous cherchons maintenant les **vitesses après collision** (*post-collision velocities*), qui dépendent :
- du changement de vitesse linéaire,
- du changement de vitesse angulaire.

Ces variations sont induites par une **impulsion** $$\mathbf{J}$$ appliquée selon la normale de collision $$\mathbf{n}$$.

---

## Mise à jour des vitesses linéaires

Les vitesses linéaires après collision sont données par :

Pour le corps $A$ :
$$
\mathbf{v}_A' = \mathbf{v}_A - \frac{\mathbf{J}}{m_A}
$$

Pour le corps $B$ :
$$
\mathbf{v}_B' = \mathbf{v}_B + \frac{\mathbf{J}}{m_B}
$$

où $m_A$ et $m_B$ sont les masses.

---

## Mise à jour des vitesses angulaires

Les vitesses angulaires après collision deviennent :

Pour le corps $A$ :
$$
\boldsymbol{\omega}_A' = \boldsymbol{\omega}_A - \frac{\mathbf{R}_A \times \mathbf{J}}{I_A}
$$

Pour le corps $B$ :
$$
\boldsymbol{\omega}_B' = \boldsymbol{\omega}_B + \frac{\mathbf{R}_B \times \mathbf{J}}{I_B}
$$

où $I_A$ et $I_B$ sont les moments d’inertie (*moment of inertia*).

---

## Vitesse au point $P$ après collision

La vitesse finale au point de contact combine à nouveau translation et rotation :

Pour le corps $A$ :
$$
\mathbf{V}_A' = \mathbf{v}_A' + \boldsymbol{\omega}_A' \times \mathbf{R}_A
$$

Pour le corps $B$ :
$$
\mathbf{V}_B' = \mathbf{v}_B' + \boldsymbol{\omega}_B' \times \mathbf{R}_B
$$

---

## Développement pour le corps $A$

En remplaçant $\mathbf{v}_A'$ et $\boldsymbol{\omega}_A'$ :

$$
\mathbf{V}_A' =
\left( \mathbf{v}_A - \frac{\mathbf{J}}{m_A} \right)
+
\left( \boldsymbol{\omega}_A - \frac{\mathbf{R}_A \times \mathbf{J}}{I_A} \right)
\times \mathbf{R}_A
$$

---

## Regroupement des termes

Après développement et regroupement :

$$
\mathbf{V}_A' =
\underbrace{\left( \mathbf{v}_A + \boldsymbol{\omega}_A \times \mathbf{R}_A \right)}_{\mathbf{V}_A}
-
\frac{\mathbf{J}}{m_A}
-
\frac{(\mathbf{R}_A \times \mathbf{J}) \times \mathbf{R}_A}{I_A}
$$

Cette expression relie directement la vitesse au point avant et après collision.

---

## Forme finale pour le corps $B$

De manière symétrique :

$$
\mathbf{V}_B' =
\mathbf{V}_B
+
\frac{\mathbf{J}}{m_B}
+
\frac{(\mathbf{R}_B \times \mathbf{J}) \times \mathbf{R}_B}{I_B}
$$

---

## Transition vers le calcul de l’impulsion

Ces deux équations constituent la base du calcul de l’impulsion $\mathbf{J}$.  
La prochaine étape consistera à déterminer explicitement $\mathbf{J}$ en fonction :
- des vitesses relatives au point de contact,
- de la restitution,
- des propriétés de masse et d’inertie.

C’est cette étape qui permettra de résoudre complètement la collision entre corps rigides en rotation.
