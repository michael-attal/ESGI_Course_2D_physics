## Aperçu de la Solution Proposée

Cet exemple illustre la solution pour la chaîne de particules connectées par des ressorts.  

Chaque particule est reliée à la précédente, et la première est reliée à un ancrage fixe en haut. 

Le système permet d’observer l’extension, la compression et le mouvement global de la chaîne.

---

## Fonction de Force

La fonction principale est `generateSpringForce` pour relier deux particules : A et B.  

---

Dans `application.h`, les variables globales incluent :  
- Vecteur de particules (*vector of particle objects*)  
- Force de poussée (*push force*) contrôlée par les touches fléchées  
- Curseur de souris et état du bouton gauche (*left mouse button down*)  
- Ancrage (*anchor*)  
- Constante de ressort K et longueur au repos (*rest length*)  
- Nombre de particules du système  

La stabilité de la simulation dépend des valeurs choisies pour $k$ et la longueur au repos.

---

## Configuration de l’Application

Dans `application.cpp`, la fonction `setup` initialise :  
- L’ancrage fixe  
- Les particules dans une boucle `for` de 0 à `num_particles`  
- Chaque particule reçoit une position initiale échelonnée selon la longueur au repos, une masse de 2.0, et un rayon (ex. 6 pixels)  
- Les particules sont ajoutées dans le vecteur global  

Cette configuration prépare la chaîne à être soumise aux forces.

---

## Gestion des Entrées

Lors d’un clic souris, l’impulsion est appliquée à la dernière particule de la chaîne.  
Les touches du clavier continuent de générer la force de poussée sur toutes les particules.

---

## Fonction Update

Pour chaque particule :  
- Application de la force de poussée (*push force*)  
- Application de la force de frottement (*drag force*) pour limiter le mouvement  
- Application de la force de gravité (*weight force*)  

Les interactions dynamiques sont ainsi simulées pour l’ensemble de la chaîne.

---

## Connexions par Ressort

Implémentation :  
1. La première particule est reliée à l’ancrage fixe  
2. Chaque particule suivante est reliée à la précédente via un ressort  
3. La force de ressort est ajoutée aux deux particules concernées, positive pour la particule actuelle, négative pour la précédente  

Cette étape est cruciale pour simuler la cohésion et la dynamique de la chaîne.

---

## Intégration et Limites

- Intégration des équations de mouvement avec la méthode d’Euler  
- Vérification des collisions et ajustement de la vélocité aux limites  

Ces étapes assurent la mise à jour correcte de la position et de la vitesse de chaque particule.

---

## Rendu

- Dessin de l’ancrage et de la ligne reliant le premier ressort  
- Boucle sur les particules pour dessiner les ressorts entre particules consécutives  
- Dessin de chaque particule (*bob*)  

Le rendu reflète visuellement la structure de la chaîne et la dynamique des forces appliquées.

---

## Observations

- La chaîne de 15 particules montre l’effet de la gravité et des ressorts : la première particule supporte le poids des suivantes  
- Les forces clavier et souris permettent d’interagir avec la dernière particule  

Les paramètres $k$ et la longueur au repos peuvent être ajustés pour modifier la rigidité et l’espacement de la chaîne.

---

## Conclusion

Cette solution démontre l’application de ressorts et de forces sur une chaîne de particules.  
Il est possible d’étendre le système ou de modifier les constantes pour expérimenter différentes configurations.  
La prochaine étape consiste à implémenter un corps souple (*soft body*) avec des sommets connectés par des ressorts.
