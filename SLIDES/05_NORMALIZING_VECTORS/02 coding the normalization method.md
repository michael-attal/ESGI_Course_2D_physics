# Ajout d’une méthode `Normalize()` à `Vector2` et `Vector3`

---

## Objectif

L’objectif est d’ajouter une méthode **normalize()** aux classes `Vector2` et `Vector3`.  
Après avoir implémenté les opérations classiques (addition, soustraction, etc.), il est essentiel d’intégrer cette méthode, car elle est fondamentale pour tous les calculs de direction dans un moteur graphique ou un système de physique.

---

## Implémentation pour Vector2

La méthode `normalize()` va modifier les composantes `x` et `y` **directement dans l’objet** (*in place*).  
Ainsi, on divise chaque composante par la longueur (*length* ou *magnitude*) du vecteur.  

Exemple d’implémentation :

```js
normalize() {
    let length = this.magnitude(); // calcul de la longueur
    if (length === 0) return; // éviter la division par zéro
    this.x /= length;
    this.y /= length;
}
```

Remarquez qu’on calcule la longueur **une seule fois**, afin d’éviter une double opération inutile.  
Cette méthode garantit que le vecteur résultant a une **longueur unitaire**.

---

## Organisation du code

Par souci de clarté, on peut placer la méthode `normalize()` **juste après** la méthode `magnitude()` dans la classe.  
Cela rend la lecture du code plus logique :

1. on calcule la magnitude,
2. puis on normalise le vecteur à partir de cette magnitude.

Ce n’est pas une exigence technique, mais cela améliore la lisibilité et la cohérence du code.

---

## Implémentation pour Vector3

Pour un vecteur à trois composantes, la méthode `normalize()` est très similaire, avec l’ajout du calcul pour `z`.

```js
normalize() {
    let length = this.magnitude();
    if (length === 0) return;
    this.x /= length;
    this.y /= length;
    this.z /= length;
}
```

Encore une fois, on divise chaque composante par la longueur totale du vecteur.  
Le résultat est un **vecteur unitaire en 3D**.

---

## Test de l’implémentation

Pour vérifier le bon fonctionnement, vous pouvez exécuter un test simple :

```js
let position = new Vector2(10, 20);
console.log("Avant normalisation :", position.magnitude());
position.normalize();
console.log("Après normalisation :", position.magnitude());
```

La sortie console devrait afficher une valeur proche de **1.0**.  
En raison des imprécisions des nombres flottants, il est possible d’obtenir quelque chose comme `0.999999`,  
ce qui est mathématiquement équivalent à 1.

---

## Conclusion

Nous avons ajouté la méthode `normalize()` aux classes `Vector2` et `Vector3`.  
Elle permet de transformer n’importe quel vecteur en **vecteur unitaire**, ce qui est essentiel dans de nombreux contextes :

- calculs de direction (caméra, lumière, objets) ;
- simulations physiques (forces, vitesses, frictions) ;
- traitement d’angles et de projections.

La normalisation est donc une étape cruciale et récurrente dans toute application de calcul vectoriel.