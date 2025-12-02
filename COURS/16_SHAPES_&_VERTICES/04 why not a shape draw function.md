# Quick Question

- Objectif : proposer un exercice rapide pour réfléchir à la conception du rendu.  
- Situation : dans la fonction `render()`, on effectue des tests pour chaque type de body (circle, box, polygon) et on dessine chaque forme manuellement.  

---

## Render Function Logic

- Actuellement :  
  - Si `body.shape.type == circle` → dessiner un cercle  
  - Si `body.shape.type == box` → dessiner un polygone  
  - Si `body.shape.type == polygon` → dessiner un polygone  
- Plusieurs conditions dispersées dans le code.  

---

## The Question

- Pourquoi ne pas utiliser le polymorphisme et déléguer la responsabilité du dessin à chaque shape ?  
  - Exemple : `circle.draw()`, `polygon.draw()`  
- L’idée : chaque objet connaît sa propre manière de se dessiner, ce qui rend le code plus propre et orienté objet.  
- Question posée : pourquoi cette logique est-elle centralisée dans `render()` au lieu d’être dans chaque shape ?  

---

## Object-Oriented Design Reflection

- Encouragement à réfléchir sur la responsabilité du dessin : la shape devrait gérer son propre rendu.  
- Question à résoudre : pourquoi cette approche n’a pas été utilisée ici ?  

---

## Exercise

- Pourquoi le code actuel effectue ces vérifications dans la fonction `render()` plutôt que de déléguer le dessin aux classes de shapes ?  
- Objectif : comprendre la décision de conception derrière cette approche dans la fonction de rendu.
