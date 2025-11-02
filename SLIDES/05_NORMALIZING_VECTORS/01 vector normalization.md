# Normaliser un vecteur

---

## Introduction

Nous arrivons presque à la fin des opérations que nous souhaitions voir entre vecteurs — addition, produit vectoriel, produit scalaire, magnitude, etc.  
Il reste une dernière opération, que j’ai volontairement repoussée : **la normalisation d’un vecteur** (*vector normalization*).  
C’est une notion essentielle, très utilisée en infographie, en physique, et dans tout moteur 3D ou moteur de jeu.

---

## Définition et objectif

Lorsqu’on parle de « normaliser » un vecteur, cela signifie **le transformer en vecteur unitaire** (*unit vector*), c’est-à-dire un vecteur dont la longueur vaut 1.  

Si l’on note notre vecteur $\vec{A}$, la version normalisée sera notée $\hat{A}$, ce symbole (le petit chapeau) indiquant que sa norme est égale à 1 :  
$|\hat{A}| = 1.0$  

---

### Mais pourquoi faire cela ? 

Dans de nombreux problèmes, **la direction** d’un vecteur est plus importante que sa **magnitude** (*length*).  
Par exemple, lorsque nous voulons indiquer une direction de déplacement, d’éclairage ou de vue, la distance n’a pas d’importance.  
On cherche uniquement à conserver **l’orientation**.  

Ainsi, lorsqu’un vecteur ne sert qu’à indiquer une direction, il est logique de le normaliser.

---

## Exemple : le vecteur normal

Rappelons la notion de **vecteur normal** (*normal vector*) :  
Pour chaque face d’une surface 3D (par exemple un triangle d’un maillage), on définit un vecteur perpendiculaire à cette face.  

Ce vecteur normal n’a pas besoin de longueur particulière — seule **sa direction** est significative.  
C’est pourquoi, **par convention**, les vecteurs normaux d’un modèle 3D sont **normalisés**.  

---

Formellement, un vecteur normal est défini comme étant :  
1. perpendiculaire à la face correspondante 
2. de longueur 1.  

Ainsi, dans toute géométrie 3D, les normales sont **des vecteurs unitaires**.

---

## Autres exemples d’utilisation

De nombreux cas nécessitent la normalisation :  
- En physique, pour indiquer une direction de force sans tenir compte de l’intensité.  
- Pour calculer la **friction** (*friction*) opposée à la **vitesse** (*velocity*) d’un objet.  

Par exemple, si un objet se déplace avec une vitesse représentée par $\vec{v}$, le frottement est souvent dans la direction opposée.  
On peut alors exprimer la direction du frottement par :  
$-\hat{v} = -\frac{\vec{v}}{|\vec{v}|}$  

Ce vecteur unitaire négatif indique que la force de friction agit **dans la direction inverse** du mouvement.  
C’est un usage typique des vecteurs unitaires en simulation physique.

---

## Comment normaliser un vecteur

Si l’on dispose d’un vecteur $\vec{a} = (x, y, z)$,  
la version normalisée $\hat{a}$ se calcule de la manière suivante :  

$\hat{a} = \frac{\vec{a}}{|\vec{a}|} = \left(\frac{x}{|\vec{a}|}, \frac{y}{|\vec{a}|}, \frac{z}{|\vec{a}|}\right)$  

où $|\vec{a}|$ est la **magnitude** (*length*) du vecteur :  

$|\vec{a}| = \sqrt{x^{2} + y^{2} + z^{2}}$  

Ainsi, chaque composante est divisée par la longueur totale, garantissant que le vecteur résultant ait une norme de 1.

---

## Implémentation

En pratique, dans un moteur 3D ou un prototype JavaScript,  
on définit une fonction `normalize()` dans la classe `Vector2` ou `Vector3`.  

Exemple en pseudo-code :

```js
normalize() {
    let length = Math.sqrt(this.x*this.x + this.y*this.y + this.z*this.z);
    if (length === 0) return new Vector3(0, 0, 0);
    return new Vector3(this.x / length, this.y / length, this.z / length);
}
```

Cette fonction retourne un **nouveau vecteur unitaire**, conservant la direction, mais supprimant la magnitude d’origine.

---

## Conclusion

La **normalisation** est omniprésente en programmation graphique :

- Pour calculer les **normales** d’un modèle 3D,
- Pour déterminer la **direction de la lumière**,
- Pour orienter la **caméra** ou les **objets ennemis**,
- Pour gérer des forces physiques ou des directions de mouvement.
    

Chaque fois qu’un calcul ne dépend que de la **direction**, on utilise un vecteur **normalisé**.