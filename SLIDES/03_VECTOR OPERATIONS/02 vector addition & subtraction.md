# Introduction

---

Nous commençons doucement en explorant les vecteurs et leurs différentes composantes (2D, 3D).  
L’objectif est de comprendre les **opérations que l’on peut effectuer sur les vecteurs**.

---

## Vue d’Ensemble des Opérations Vectorielles

Pour deux vecteurs (positions, vitesses, forces, friction) :  
- Que signifie additionner ces vecteurs ?  
- Que signifie soustraire ces vecteurs ?  
- Comment les **scaler** ou les multiplier ?  

Ces opérations s’appliquent aux vecteurs 2D ou 3D.

---

## Addition de Vecteurs

L’addition de vecteurs consiste à **combiner les deux flèches** :  
- Chaque vecteur a sa propre direction et magnitude  
- La résultante combine ces deux mouvements

---

## Interprétation Géométrique de l’Addition

Géométriquement :  
- Déplacer selon le vecteur A  
- Puis déplacer selon le vecteur B depuis la fin de A  
- La flèche résultante est la diagonale du parallélogramme formé

---

## Représentation Numérique de l’Addition

Numériquement :  
$$
\vec A + \vec B = (A_x + B_x, A_y + B_y)
$$  
Additionner les composantes `x` et `y` pour obtenir le vecteur final

---

## Compréhension Conceptuelle de l’Addition

L’addition représente la **combinaison des déplacements linéaires** :  
- Déplacer un objet selon $\vec A$ puis selon $\vec B$  
- Résultat : $\vec A + \vec B$

---

## Soustraction de Vecteurs

La soustraction est un peu plus subtile :  
$$
\vec A - \vec B = \vec A + (-\vec B)
$$  
- Inverser $\vec B$ (multiplication par -1) puis additionner à $\vec A$

---

## Décomposition de la Soustraction

Numériquement :  
$$
\vec A - \vec B = (A_x - B_x, A_y - B_y)
$$  
Soustraction composante par composante pour obtenir le vecteur résultant

---

## Compréhension de la Soustraction

Applications pratiques :  
- Moteurs physiques  
- Jeux vidéo  
- Simulation 3D  
- Calcul de distances et directions

---

## Conclusion

- L’addition et la soustraction sont fondamentales pour manipuler des vecteurs  
- Ces concepts seront utilisés pour :  
  - Programmer des mouvements  
  - Simuler des forces  
  - Calculer des positions relatives
