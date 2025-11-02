# Introduction aux vecteurs  

---

## Objectifs du cours

Ce chapitre a pour objectif de présenter les vecteurs, un outil mathématique essentiel dans la modélisation physique et les simulations numériques.  
Nous introduirons la notion de vecteur, sa représentation géométrique, ses composantes, et son utilisation pour représenter des grandeurs physiques telles que la position, la vitesse, ou la force.

---

## Qu’est-ce qu’un vecteur ?

Un **vecteur** est un objet mathématique qui permet de représenter des **grandeurs possédant une direction et une magnitude (norme)**.  
Les vecteurs sont utilisés pour exprimer des quantités comme la vitesse, l’accélération, la force, ou la position dans l’espace.  
Contrairement à un simple nombre, appelé *scalaire (scalar)*, un vecteur encode une information directionnelle.  


---

## Vecteurs et grandeurs physiques

Les vecteurs sont omniprésents en physique. Ils permettent de représenter des quantités telles que :

- la **vitesse** d’un objet (direction du mouvement et intensité)  
- la **position** dans un espace 2D ou 3D  
- la **force**, la **gravité**, la **portance (lift)**, ou la **traînée (drag)**  
- la **déplacement (displacement)** et l’**accélération**

Ces grandeurs ne peuvent pas être décrites par un seul nombre : elles nécessitent une direction dans l’espace.  


---

## Grandeurs scalaires et grandeurs vectorielles

Les **scalaires (scalars)** sont des quantités décrites par un seul nombre, sans direction.  
Exemples :
- la **température**
- la **masse**
- la **pression**
- l’**aire** ou la **longueur**

Les **vecteurs (vectors)**, eux, nécessitent à la fois :
- une **magnitude (norme)** : la valeur absolue de la grandeur ;
- une **direction** : l’orientation spatiale.  

![[medias/01 vectors & scalar quantities-20251027.png]]

---

## Représentation des vecteurs dans le plan cartésien

En programmation graphique ou en simulation physique, les vecteurs sont souvent représentés dans un **plan cartésien (Cartesian plane)**.  
Un vecteur en 2D est défini par ses deux composantes :  
$$
\vec{v} = (x, y)
$$  
et un vecteur en 3D par trois composantes :  
$$
\vec{v} = (x, y, z)
$$

Ainsi, la **position** d’un point dans un plan ou un espace peut être représentée par un vecteur allant de l’origine $(0, 0)$ vers le point $(x, y)$ ou $(x, y, z)$.  

![[medias/01 vectors & scalar quantities-20251027-1.png]]

---

## Exemple : vecteurs en 2D et 3D

Un vecteur 2D :  
$$
\vec{v_2} = (3, 2)
$$

Un vecteur 3D :  
$$
\vec{v_3} = (3, 0, 3)
$$

Chaque vecteur est composé de **composantes (components)**, correspondant à ses coordonnées sur les axes $x$, $y$, et $z$.  

![[medias/01 vectors & scalar quantities-20251027-2.png]]

---

## Généralisation à plusieurs dimensions

Bien que nous travaillions principalement en 2D et 3D, certains domaines (notamment le rendu 3D et les calculs matriciels) utilisent des **vecteurs à 4 composantes**.  
Ces derniers permettent de manipuler des coordonnées homogènes dans les transformations de projection.  


---

## Implémentation d’un vecteur en C++

En programmation, il est pratique de regrouper les composantes d’un vecteur dans une **structure (struct)** ou une **classe (class)**.  
Voici une implémentation simple d’un vecteur 2D :

```cpp
struct Vector2 {
    float x;
    float y;

    Vector2(float x = 0.0f, float y = 0.0f)
        : x(x), y(y) {}
};
```



On peut ensuite instancier un vecteur de la manière suivante :

```cpp
Vector2 a(3.7f, 25.0f);
Vector2 b(1.0f, -4.5f);

```

---

## Vecteurs 3D en C++

Pour les simulations physiques 3D, nous ajoutons une troisième composante :

```cpp
struct Vector3 {
    float x, y, z;

    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
        : x(x), y(y), z(z) {}
};
```

Exemple d'utilisation:

```cpp
Vector3 position(3.0f, 2.0f, 3.0f);
Vector3 velocity(0.0f, 9.8f, 0.0f);

```

Ces deux objets peuvent représenter respectivement la position et la vitesse d’un objet dans un moteur physique.

---

## Conclusion

Les vecteurs constituent une base incontournable de la physique computationnelle.  
Ils permettent de représenter des positions, des vitesses, des forces et des accélérations de manière cohérente dans l’espace.  
La compréhension intuitive des composantes, de la magnitude et de la direction d’un vecteur est essentielle avant d’aborder les opérations vectorielles (addition, produit scalaire, produit vectoriel).