# Implementation

- Objectif : simplifier le code en centralisant l’intégration linéaire, l’intégration angulaire et la mise à jour des vertices dans une méthode `update()` du corps (Body).  
- On enlève toutes les parties dispersées de l’intégration et de la mise à jour des vertices.  
- La méthode `update()` recevra très probablement le delta time (`dt`).

---

## Creating the Update Method

- Créer la méthode `Body::update(float dt)`.  
- Prototype à déclarer dans la classe Body.  
- Dans l’implémentation : tout le code précédemment dispersé est transféré ici.  

---

## Integrations

- Intégration linéaire : `integrateLinear(dt)`  
- Intégration angulaire : `integrateAngular(dt)`  
- Mise à jour des vertices :  
  - Vérifier si le shape est polygon ou box  
  - Récupérer le `PolygonShape*` correspondant  
  - Appeler `updateVertices(rotation, position)` avec les attributs du Body  

---

## Updating and Testing

- Chaque frame : `body.update(dt)` est appelé pour tous les bodies.  
- Résultat : intégration linéaire et angulaire + vertices mises à jour de l’espace local vers le world space.  
- Vérification : box rotative correctement affichée dans le canvas.  

---

## Next Steps: Collisions

- Prochaine étape : gérer les collisions.  
- Commencer avec les cercles :  
  - Vérifier le chevauchement (overlap)  
  - Résoudre les collisions  
  - Appliquer impulsions et momentum  
- Sujet détaillé et complexe : cercles, boxes et interactions physiques.  
