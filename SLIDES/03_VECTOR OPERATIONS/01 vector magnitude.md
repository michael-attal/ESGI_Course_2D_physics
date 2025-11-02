# Comprendre les Vecteurs

---

Nous prenons notre temps pour bien saisir ce qu’est un vecteur.  
Nous avons créé un **blueprint** pour un vecteur avec les composantes x et y, utilisé pour représenter une position 2D dans notre canvas JavaScript p5.js.

---

# Opérations sur les Vecteurs

Les vecteurs permettent de réaliser plusieurs opérations importantes :  
- Addition de vecteurs (positions, vitesses, forces)  
- Soustraction de vecteurs  
- Multiplication et division (scaling)  
- Calcul de la magnitude

---

# Magnitude d’un Vecteur

La **magnitude** correspond à la longueur de la flèche représentant le vecteur :  
- Force, vitesse ou accélération  
- Notation mathématique : $||\vec v||$

---

# Calcul de la Magnitude

Pour un vecteur avec composantes `x` et `y` :  
- Base = `x`  
- Hauteur = `y`  
- Hypoténuse = magnitude

---

## Théorème de Pythagore et Longueur du Vecteur

La magnitude se calcule avec le **théorème de Pythagore** :  
$$
||v|| = \sqrt{x^{2} + y^{2}}
$$  
On élève au carré chaque composante, on fait la somme et on prend la racine carrée.

---

## Implémentation de la Fonction Magnitude

Dans notre classe `Vec2` :  
- Méthode `magnitude()` qui retourne la longueur du vecteur :  

```js
magnitude() {
    return Math.sqrt(this.x * this.x + this.y * this.y);
}
```

---

## Visualiser la Magnitude avec p5.js

- Déplacer le vecteur en fonction de la position de la souris :

```js
position.x = mouseX;
position.y = mouseY;
```

- Dessiner le vecteur avec `draw()`
- Afficher la magnitude dans la console :

```js
console.log(position.magnitude());
```

---

## Interprétation des Valeurs de Magnitude

- La magnitude varie selon la distance par rapport à l’origine :
    - Proche de zéro à proximité de l’origine
    - Augmente à mesure qu’on s’éloigne
- Correspond à l’hypoténuse du triangle formé par `x` et `y`
    

---

## Magnitude Toujours Positive

- La magnitude est **toujours positive**
- Mettre au carré une composante négative donne un résultat positif
- Racine carrée d’un nombre positif reste positive
    

---

## Magnitude dans la Programmation et les Moteurs Physiques

- La magnitude est utilisée pour :
    - La vitesse d’un objet (joueur ou ennemi)
    - La distance entre deux objets
    - Le calcul de forces dans un moteur physique
        
- C’est une opération centrale en programmation graphique et en développement de jeux