# Question

- Pourquoi ai-je choisi de placer toutes ces instructions de dessin dans la fonction `render()` plutôt que de déléguer à une méthode `draw()` dans chaque classe de shape ?  
- Pourquoi cette logique est-elle centralisée ici et non dans les classes `circle` ou `polygon` ?

---

# Reasoning

- Principalement pour éviter d’introduire des instructions de rendu dans notre moteur physique.  
- Le moteur physique doit rester agnostique au rendu et indépendant de SDL ou de toute autre bibliothèque graphique.  

---

# Separation of Concerns

- Toute logique de dessin doit se situer en dehors du moteur physique.  
- Le dossier `physics` contient uniquement la physique : shapes, rigid bodies, particules, collisions.  
- Aucun code de rendu ne doit se trouver dans ce dossier.  

---

# Design Decision

- Les classes de shapes ne contiennent pas de méthodes de dessin.  
- Si un utilisateur veut dessiner une shape, il doit appeler explicitement `drawCircle()`, `drawPolygon()`, `drawHexagon()`, etc., depuis l’extérieur du moteur physique.  

---

# Conclusion

- La décision de conception vise à maintenir le moteur physique indépendant du rendu graphique.  
- Pas d’instructions de rendu dans le dossier physics, c’est tout.
