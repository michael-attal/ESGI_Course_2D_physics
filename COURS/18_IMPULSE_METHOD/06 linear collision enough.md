# Introduction

- Analyse des applications des **impulsions linéaires** dans les jeux vidéo.  
- Exemples historiques : *The Incredible Machine* montre que des collisions et réponses simples entre objets circulaires peuvent suffire à créer des interactions intéressantes.  
- Même avec des collisions simples, on peut simuler un comportement crédible de chute et rebond sans gérer la rotation des sprites.  
- Prototype JavaScript illustrant l’application d’impulsions linéaires entre sphères : conservation du momentum et impulsions le long de la normale.  

---

# Linear Responses

- Pour certains types de jeux, **les réponses linéaires suffisent**.  
- Collisions cercle sur cercle en vue 2D (top view) permettent une résolution uniquement par déplacement linéaire, sans rotation.  
- En contexte ludique, il est souvent inutile de reproduire parfaitement les lois physiques : « reality is overrated ».  
- Ajustement des constantes physiques (gravité, restitution) pour rendre le gameplay plus agréable et dynamique.  
- Utilisation d’impulsions linéaires simples peut suffire à créer des interactions amusantes et convaincantes pour le joueur.  
