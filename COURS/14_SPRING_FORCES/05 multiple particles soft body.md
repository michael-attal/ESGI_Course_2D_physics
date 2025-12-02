# Soft Body

Cette section traite de l’implémentation d’un *soft body* (corps souple) formé d’un carré de particules interconnectées par des ressorts.  
Contrairement à la chaîne de particules, ce système ne comporte aucun ancrage fixe, et les ressorts présentent une rigidité accrue afin de préserver la forme.  

---

## Configuration de l’Application

Dans `application.h` :  
- Absence d’ancrage fixe (*anchor*) : les particules sont libres dans l’espace  
- Valeur élevée de la constante de ressort (*spring constant*) pour accroître la rigidité  
- Longueur au repos (*rest length*) fixée à 200 pixels  
- Définition de quatre particules correspondant aux sommets du carré  

Ces paramètres déterminent la configuration structurelle initiale du corps souple.  

---

## Initialisation des Particules

Dans `application.cpp` :  
- Création de quatre particules nommées A, B, C et D  
- Positionnement des particules dans un ordre horaire afin de définir les coins du carré  
- Attribution d’un rayon uniforme de 6 pixels à chaque particule  
- Insertion des particules dans le vecteur global gérant la simulation  

Cette phase prépare la structure à la réception des forces et à la dynamique simulée.  

---

## Application des Forces

Pour chaque particule :  
- Application d’une force de frottement (*drag force*) afin de stabiliser le mouvement  
- Application d’une force gravitationnelle (*weight force*) uniforme  
- Création des connexions par ressorts :  
  - Arêtes extérieures : 
    - A ↔ B, B ↔ C, C ↔ D, D ↔ A  
  - Diagonales internes : A ↔ C et B ↔ D pour renforcer la cohésion  
- Ajout des forces opposées sur les particules connectées pour respecter la troisième loi de Newton  

Ces interactions permettent de simuler la déformation élastique du carré et la propagation des tensions internes.  

---

## Intégration et Rendu

- Intégration temporelle des équations du mouvement via la méthode d’Euler  
- Vérification des collisions avec les limites de la scène  
- Tracé des ressorts reliant les paires de particules connectées  
- Dessin individuel des particules pour visualiser les sommets  

Le rendu permet d’observer en temps réel la réponse physique du corps souple face à la gravité et aux forces internes.  

---

## Observations

- Les ressorts conservent globalement la géométrie du carré mais autorisent de légères déformations  
- L’absence d’ancrage permet une liberté de mouvement accrue  
- Les interactions dynamiques révèlent un comportement souple et fluide du système  

Cette simulation illustre efficacement les principes fondamentaux d’un corps déformable simple.  

---

## Conclusion et Étapes Suivantes

- Le système de particules et de corps souples est complet  
- L’intégration de Verlet (*Verlet integration*) est recommandée pour accroître la stabilité numérique des simulations de ce type  
- La prochaine étape consiste à explorer les *rigid bodies* (corps rigides), où les rotations et les collisions jouent un rôle déterminant  

Cette transition marque le passage vers une modélisation plus avancée de la dynamique physique.  
