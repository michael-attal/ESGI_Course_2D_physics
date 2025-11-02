# Introduction aux Méthodes Statiques dans les Vecteurs


Jusqu'à présent, pour additionner deux vecteurs, nous avons utilisé une méthode d'instance, par exemple `position.add(velocity)`, où nous passons le vecteur à ajouter en paramètre.

---

## Concept des Méthodes Statiques

Une **méthode statique** est une méthode de la classe elle-même et non d’un objet spécifique.  
Elle permet d’effectuer des opérations sur des vecteurs et de **retourner un nouveau vecteur** sans modifier les vecteurs originaux.

---

## Création d'une Méthode Statique

Pour créer une méthode statique `add`, on définit dans la classe : `static add(a, b)`.  
Elle reçoit deux vecteurs en paramètre, crée un nouveau vecteur résultat, additionne les composantes x et y, puis retourne ce vecteur résultat.

---

## Exemple d'Implémentation

- Créer un nouveau vecteur `result` initialisé à $(0, 0)$  
- Additionner les composantes x : `result.x = a.x + b.x`  
- Additionner les composantes y : `result.y = a.y + b.y`  
- Retourner `result`  

Cette approche permet d’obtenir un nouveau vecteur sans modifier les vecteurs originaux.

---

## Extension aux Autres Opérations

On peut de la même manière créer une méthode statique pour la **soustraction** :  
- Passer deux vecteurs en paramètre  
- Soustraire leurs composantes  
- Retourner le vecteur résultat

Cela offre une alternative aux méthodes d'instance pour manipuler des vecteurs.

---

## Résumé

Nous avons maintenant deux façons de manipuler des vecteurs :  
1. **Méthode d'instance** : `position.add(velocity)` modifie directement l’objet.  
2. **Méthode statique** : `Vector2.add(a, b)` retourne un nouveau vecteur résultat.  

Les méthodes statiques ajoutent de la flexibilité pour les opérations sur les vecteurs et peuvent être utiles selon les besoins de votre programme.
