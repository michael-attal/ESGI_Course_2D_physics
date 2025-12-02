
## Introduction

Il ne s’agit pas simplement de comprendre la théorie derrière les vecteurs.  
Nous allons voir comment **implémenter des vecteurs** pour représenter :

- le **mouvement**  
- les **positions**  
- les **forces**  
- l’**accélération**  
- la **vitesse**  

Pour un retour concret, nous utiliserons **JavaScript** pour créer un **proof of concept** (*preuve de concept*).  
L’objectif : comprendre comment utiliser des **objets** pour représenter des vecteurs et manipuler **position**, **vitesse** et **déplacement** sur un écran.

---

## Introduction à p5.js

p5.js est une bibliothèque JavaScript pour programmer rapidement des applications graphiques dans le navigateur.  

- Éditeur de code à gauche  
- **Canvas** à droite affichant les résultats  

> **Illustration à ajouter :** capture d’écran de l’éditeur p5.js avec code et canvas.

p5.js évite la configuration complexe en C++ pour voir les résultats à l’écran.

---

## p5.js et Processing

p5.js est basé sur **Processing**, framework Java pour la programmation créative.  

Deux fonctions clés :  
- `setup()` : exécutée **une seule fois** au lancement  
- `draw()` : exécutée **à chaque frame** d’animation (boucle de jeu)  


---

## Configuration du Canvas

- Dans `setup()` :  
  - Création d’un canvas plein écran (`windowWidth`, `windowHeight`)  

- Chaque frame :  
  1. Définir le fond (`background`) en noir  
  2. Dessiner un cercle aux coordonnées X, Y avec un rayon donné  


---

## Dessin et Système de Coordonnées

- Origine `(0,0)` en haut à gauche  
- Axe X croît vers la droite, axe Y croît vers le bas  
- Exemple : cercle en `(100,200)` de rayon `100px`  

---

## Introduction des Variables

Plutôt que de coder les coordonnées en dur :

```js
var x = 10;
var y = 10;
```

Ces variables servent à positionner le cercle dans `draw()`.  
Pour l’instant, ce **ne sont pas encore des vecteurs**, ce sont des valeurs isolées.


---

## Ajout du Mouvement

Modifier ces variables à chaque frame :

```js
x++;
y++;
```

Résultat attendu : **déplacement diagonal** du cercle vers le bas.


---

## Des Variables aux Vecteurs

- Variables X et Y isolées : limitées
- Créons un **objet vectoriel** regroupant X et Y
- Servira de **blueprint** pour tous les objets nécessitant position, vitesse et direction
    

