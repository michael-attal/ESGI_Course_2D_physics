## Premiers Pas

---

Nous commençons très lentement pour que tout le monde soit sur la même longueur d’onde.  

Nous avons l’éditeur p5.js ouvert, nous pouvons appuyer sur **Play** et voir le résultat à droite.  

J’ai créé deux variables globales, `x` et `y`, qui représentent les coordonnées où nous allons dessiner notre cercle.

---

## Comprendre l’Abstraction

Même si nous dessinons un cercle, nous pourrions dessiner **n’importe quel objet** à cette position :  
- Un joueur principal  
- Un ennemi  
- Un rectangle  
- Un objet 3D  

Le fait de dessiner un cercle est un **détail**.  

L’important est de comprendre **le système de coordonnées et la notion de vecteur**.

---

## Le Système de Coordonnées et le Rendu

Nous utilisons un système 2D pour l’écran, mais le concept est le même pour :  
- Une image PNG (sprite)  
- Des projectiles ou des balles  
- Tout objet à positionner dans votre application  

Nous devons **abstraire le rendu**, ce cercle pourrait représenter n’importe quel élément dans votre programme.

---

## Le Rendu comme Détail

Le rendu est simplement un détail de notre prototype ou preuve de concept.  
L’idée principale : la **position du cercle** sera représentée par un **vecteur**.

---

## Création de la Classe Vector

Nous allons créer une **classe** pour remplacer nos variables globales.  
- Cette classe servira de **blueprint** pour tous les vecteurs  
- Nom proposé : `Vec2` (Vector of Two Components)

---

## Le Constructeur

La classe `Vec2` possède un **constructeur** qui reçoit les paramètres X et Y :  
- `this.x` reçoit la valeur X  
- `this.y` reçoit la valeur Y  

`this.x` et `this.y` représentent les **attributs internes de l’objet**.

---

## La Méthode Draw

La classe `Vec2` inclut une méthode `draw()` qui permet au vecteur de se dessiner lui-même :  
- Couleur : blanc  
- Position : `this.x`, `this.y`  
- Rayon : fixe ou paramétrable

---

## Instanciation du Vecteur

Création d’un objet vecteur :  
```js
let position = new Vec2(10, 20)
```

- `position` est un objet de type `Vec2`
- Il encapsule X et Y et sait se dessiner
    

---

## Regrouper les Coordonnées dans un Vecteur

Nous avons maintenant `x` et `y` **liés entre eux** via la classe `Vec2`.  
Appel de la méthode draw :

```js
position.draw()
```

Chaque vecteur connaît sa position et sait se dessiner lui-même.

---

## Application des Principes Objet

- Encapsulation des coordonnées X et Y dans un objet
- Méthodes de la classe responsables des actions (dessiner le vecteur)
- Exemple classique de **programmation orientée objet (OOP)**
    

---

## Premier Résultat

Nous devrions voir le vecteur à la position `(10, 20)`.  
Le cercle initial est remplacé par l’objet vecteur, simplifiant la gestion des coordonnées et du rendu.

---

## Conclusion et Étapes Suivantes

- Première étape : abstraction d’un vecteur à deux composantes
- Pour un canvas 2D, cela suffit pour commencer
- Étapes suivantes : opérations vectorielles :
    - Addition et soustraction de vecteurs
    - Magnitude
    - Scaling et division