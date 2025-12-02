# Implémentation des Méthodes de Vector3

Tout ce que nous avions à faire était de regarder toutes les méthodes de notre classe `Vector2` : addition, addition statique, soustraction, soustraction statique, mise à l’échelle (scaling), produit scalaire (dot product), rendu, etc., puis de les reproduire pour notre classe `Vector3`.

---

## Aperçu de la Classe Vector3

Nous avons déplacé la classe vector vers le haut et ajouté la classe `Vector3` un peu plus tard.  
La classe `Vector3` est le modèle (blueprint) pour tous nos vecteurs 3D dans l’application.  
Le constructeur prend maintenant en compte le composant `z` : `this.z = z`.

---

## Méthode Add

La méthode `add` reçoit un vecteur 3 en paramètre et additionne les composantes `x`, `y` et `z`.  
Nous avons également une version statique de `add` qui reçoit deux vecteurs 3, crée un nouveau vecteur 3 `(0,0,0)`, additionne les composantes correspondantes et retourne le résultat.

---

## Méthode Subtract

Pour la soustraction, c’est similaire : soustraire chaque composante, version statique pour deux vecteurs, retour du nouveau vecteur 3.  
Toujours en vérifiant qu’il n’y ait pas de faute de frappe.

---

## Méthode Scale

La méthode `scale` reçoit un nombre et multiplie chaque composante du vecteur, y compris `z`, par ce nombre.

---

## Produit Scalaire (Dot Product)

Le produit scalaire entre vecteurs 3D :  
`x*x + y*y + z*z`, en n’oubliant pas la composante `z`.

---

## Magnitude

La magnitude (longueur) du vecteur 3D :  
$$\sqrt{x^{2} + y^{2} + z^{2}}$$

---

## Produit Vectoriel (Cross Product)

Produit vectoriel déjà défini précédemment. Rien de nouveau à ajouter ici.

---

## Méthode Draw

Pas de méthode de dessin pour `Vector3` sur un canvas 2D.  
Implémentation future possible avec OpenGL ou Vulkan pour travailler en 3D.

---

## Objets Vector3

Création des objets `Vector3` pour position et vélocité avec 3 composantes :  
- position : `(10, 20, -2)`  
- velocity : `(1, 2, 0)`

---

## Fonction Setup

Mise à jour de la position via la vélocité.  
Contrôle dans la console pour la position (pas de rendu 3D ici).

---

## Debugging

Correction d’une erreur : `position.add` ne doit pas créer un nouveau vecteur pour l’opération.

---

## Résumé

Toutes les méthodes de `Vector2` ont été implémentées pour `Vector3`.  
L’important : considérer toutes les composantes `x`, `y`, et `z` pour les opérations : addition, soustraction, produit scalaire, cross product, etc.
