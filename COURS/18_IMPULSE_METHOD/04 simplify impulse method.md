# Dot Product d’un Vecteur Unitaire avec Lui-Même

- Si un vecteur est un **vecteur unitaire** (longueur = 1), alors :  
$$
\mathbf{n} \cdot \mathbf{n} = 1
$$
- Permet de simplifier le dénominateur dans le calcul de l’impulsion :  
$$
j = \frac{-(1+\varepsilon)(V_\text{rel} \cdot n)}{\frac{1}{m_A} + \frac{1}{m_B}}
$$
- Cette simplification est possible car la normale est toujours normalisée avant le calcul.  

---

# Formule Finale et Implémentation

- La formule finale de l’impulsion $J_n$ :  
$$
J_n = j \cdot n
$$
- Application : $+J_n$ à A, $-J_n$ à B pour respecter la **conservation du momentum**.
- Dans le code source, cette formule est traduite directement en C++ pour la fonction `resolveCollision`.

---

# Implémentation C++

- Récupération des corps A et B depuis l’objet de contact.
- Définition du coefficient de restitution $\varepsilon$ :  
$$
\varepsilon = \min(\text{restitution}_A, \text{restitution}_B)
$$
- Calcul de la **vitesse relative** :  
$$
V_\text{rel} = V_A - V_B
$$
- Calcul de la **magnitude de l’impulsion** :  
$$
j = \frac{-(1+\varepsilon) (V_\text{rel} \cdot n)}{\frac{1}{m_A} + \frac{1}{m_B}}
$$
- Direction de l’impulsion : vecteur normalisé de contact $n$.
- Impulsion vectorielle finale :  
$$
J_n = j \cdot n
$$

---

# Application de l’Impulsion

- Appliquer l’impulsion aux corps :  
  - Corps A : $+J_n$  
  - Corps B : $-J_n$
- Résultat : **changement instantané de la vitesse**, corps se séparent selon la direction de la normale.

---

# Conclusion

- Impulsion linéaire $J_n$ résout la collision entre A et B.
- Formule finale simple et directe à implémenter en C++.
- Effet visible : objets A et B se séparent immédiatement après collision.

---
