# Introduction

- Implémentation de la **méthode d’impulsion** dans le code source pour les corps.  
- Ajout d’un attribut `float restitution` dans la classe `Body` pour représenter le **coefficient de restitution** (elasticité) du corps.  
- Valeur par défaut : `1.0` (parfaitement élastique), modifiable manuellement pour chaque corps.  

---

# Resolve Penetration et Resolve Collision

- Création de la fonction `ResolveCollision` qui combine :  
  1. **Resolve Penetration** : séparer les objets pour qu’ils ne se chevauchent plus.  
  2. **Apply Impulse** : appliquer l’impulsion pour modifier la vitesse des corps.  
- Résolution de la collision gère maintenant à la fois la pénétration et l’impulsion.  

---

# Implémentation de applyImpulse

- Ajout de la méthode `applyImpulse(Vector J)` dans la classe `Body` :  
$$
\Delta V = J \cdot \text{inverseMass}
$$  
- Vérification : si le corps est **statique** (masse inverse = 0), ne rien appliquer.  
- Applique l’impulsion instantanément en changeant la vitesse linéaire du corps.  

---

# Calcul de la vitesse relative et de l’impulsion

- Calcul du coefficient de restitution \(\varepsilon = \min(\text{restitution}_A, \text{restitution}_B)\).  
- Vitesse relative :  
$$
V_\text{rel} = V_A - V_B
$$  
- Vitesse relative projetée sur la normale :  
$$
V_\text{rel,n} = V_\text{rel} \cdot n
$$  
- Magnitude de l’impulsion :  
$$
j = \frac{-(1+\varepsilon) V_\text{rel,n}}{\frac{1}{m_A} + \frac{1}{m_B}}
$$  
- Impulsion vectorielle finale :  
$$
J_n = j \cdot n
$$  
- Application : \(+J_n\) à A, \(-J_n\) à B.  

---

# Mise à jour dans application.cpp

- Boucle sur tous les corps pour détecter les collisions.  
- Appel de `ResolveCollision` pour appliquer la pénétration et l’impulsion.  
- Corps statiques restent immobiles (masse inverse = 0).  

---

# Ajustements visuels et tests

- Création de petits corps dynamiques avec masse 1 et restitution 0.9.  
- Application de la force de gravité et optionnellement du vent.  
- Rendu simple de cercles sans rotation pour visualiser le comportement.  

---

# Comportement à l’exécution

- Les corps dynamiques rebondissent correctement selon leur restitution.  
- La restitution faible (ex : 0.2) produit des collisions plus **inelastiques**, les corps restent ensemble.  
- La simulation est stable, les corps au repos ne jitter pas grâce à une intégration linéaire correcte.  

---

# Conclusion

- Collisions entre corps résolues avec la **méthode d’impulsion**.  
- Conservation du momentum respectée.  
- Formules mathématiques traduites directement en code C++ fonctionnel.  
