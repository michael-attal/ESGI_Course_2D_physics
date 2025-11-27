# Introduction

- Objectif : déterminer la **magnitude de l’impulsion $J$** à appliquer aux corps A et B lors d’une collision.
- Données disponibles : vitesse pré-collision $V_A, V_B$, profondeur de pénétration, normale de collision.
- Importance de prendre en compte **la conservation du momentum** et la vitesse post-collision.

---

# Vitesse Relative

- Impulsion générée par la **vitesse relative** des deux corps.
- Vitesse relative : $V_\text{rel} = V_A - V_B$
- Exemple concret : deux voitures à 100 km/h → $V_\text{rel} = 0$. Une à 110 km/h → $V_\text{rel} = 10$ km/h.

---

# Mise en place du problème

- Deux objets légèrement superposés.
- Données : pénétration, normale de collision, vitesses pré-collision $V_A, V_B$.
- Objectif : utiliser ces informations pour calculer l’impulsion.

---

# Projection sur la normale

- On s’intéresse à la **vitesse relative le long de la normale**.
- Formule : $V_\text{rel} \cdot n$
- Seule la composante le long de la normale est utilisée pour calculer l’impulsion.

---

# Coefficient de restitution

- Définit l’**élasticité** de la collision ($0 \leq \varepsilon \leq 1$).
  - 1 : collision parfaitement élastique (ex. ballon de basket)
  - 0 : collision complètement inélastique (ex. boule de terre)
- Formule : $V'_\text{rel} \cdot n = -\varepsilon (V_\text{rel} \cdot n)$

---

# Utilisation du coefficient dans l’équation d’impulsion

- Chaque corps possède un coefficient de restitution propre.
- Permet d’ajuster la **bounciness** de la collision.
- Impulsion finale dépend de : masse, vitesse relative, direction, et coefficient de restitution.

---

# Conservation du momentum

- Impulsion = **changement de momentum**.
- $\Delta p_A = m_A (V'_A - V_A)$
- $\Delta p_B = m_B (V'_B - V_B)$
- La masse reste constante : seul le changement de vitesse est considéré.

---

# Impulsion le long de la normale

- Impulsion vectorielle : $\mathbf{J}_n = j \cdot \mathbf{n}$
  - $j$ : magnitude de l’impulsion
  - $\mathbf{n}$ : direction normalisée de la collision
- Application :
  - Corps A : $+ \mathbf{J}_n$
  - Corps B : $- \mathbf{J}_n$ (conservation du momentum)

---

# Nouvelles vitesses après collision

- $V'_A = V_A + \frac{\mathbf{J}_n}{m_A}$
- $V'_B = V_B - \frac{\mathbf{J}_n}{m_B}$
- Inversement proportionnel à la masse : plus la masse est grande, moins la vitesse change.

---

# Vitesse relative après collision

- Nouvelle vitesse relative : $V'_\text{rel} = V'_A - V'_B$
- On projette cette vitesse relative sur la normale : $V'_\text{rel} \cdot n$

---

# Développement algébrique

- Substitution des vitesses nouvelles dans la formule relative.
- Application du coefficient de restitution : $V'_\text{rel} \cdot n = -\varepsilon (V_\text{rel} \cdot n)$
- Factoring et isolations pour obtenir la **magnitude de l’impulsion $j$**.

---

# Expression finale de l’impulsion

- Formule simplifiée :  
$$
j = \frac{-(1 + \varepsilon) (V_\text{rel} \cdot n)}{\frac{1}{m_A} + \frac{1}{m_B}}
$$
- $j$ : magnitude de l’impulsion à appliquer.
- Direction : le long de la normale $n$.

---

# Simplification finale

- Produit scalaire d’un vecteur unitaire avec lui-même : $n \cdot n = 1$
- Cela simplifie le dénominateur dans le calcul de $j$.
- Exercice proposé : réfléchir pourquoi $n \cdot n = 1$ simplifie le calcul.

---
