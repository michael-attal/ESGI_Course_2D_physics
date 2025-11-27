# Méthode de l'Impulsion — Introduction

- Nous avons parlé du **momentum** et de la conservation du momentum.
- Pour résoudre les collisions, nous utilisons la **méthode de l’impulsion**.
- L’impulsion permet de séparer les objets et de modifier instantanément leur vitesse.

---

# Définition de l'Impulsion

- Une impulsion est un **changement de momentum** via une **modification directe de la vitesse**.
- Dans notre moteur physique, **la masse des objets reste constante**.
- L’impulsion modifie donc uniquement la **vitesse**, pas la masse.

---

# Impulsion comme force appliquée sur un temps

- Relation : $ \text{Impulse} = F \cdot \Delta t $
- Appliquer une force pendant un certain temps équivaut à **changer le momentum**.
- En calcul continu : $ J = \int F(t) dt $

---

# Changement de momentum

- $\Delta p = m \cdot v_\text{nouveau} - m \cdot v_\text{initial}$
- Appliquer une impulsion = **acquisition d’un momentum** pour l’objet.

---

# Réécriture avec masse et vitesse

- $ F \cdot \Delta t = m \cdot a \cdot \Delta t = m \cdot \Delta v $
- On définit l’impulsion par la lettre $ J $ :
  \[
  J = m \cdot \Delta v
  \]
- Comme la masse est constante, $ J $ correspond à **un changement de vitesse**.

---

# Impulsion et changement de vitesse

- Delta V = **impulsion appliquée / masse de l’objet**
- Plus la masse est grande, plus le changement de vitesse est faible.
- Méthode d’impulsion = **changement direct de la vitesse après collision**.

---

# Implémentation dans le moteur physique

- La fonction `Body.applyImpulse` permet d’appliquer une impulsion à un corps.
- Si le corps est statique → **aucun changement**.
- Sinon :  $\text{velocity} += J \times \text{inverseMass}$

---

# Récapitulatif Momentum et Impulsion

- Momentum : $p = m \cdot v$
- Impulsion : $J = \Delta p = m \cdot \Delta v$
- Changement de vitesse dépend de :
  - L’intensité de l’impulsion $ J $
  - Inversement proportionnel à la masse

---

# Objectif : Calculer l’impulsion J

- Pour appliquer la méthode de l’impulsion, nous devons **calculer la valeur de J**.
- Informations disponibles :
  - Masse de chaque corps
  - Inverse de la masse
  - Vitesse actuelle des objets
  - Normale de collision et pénétration
- Étape suivante : **dériver la formule de l’impulsion J** pour résoudre la collision.
