# Conversion entre espace local et espace monde dans la classe Body  
_Implémentation des transformations géométriques_

---

## 1. Objectif général

L’objectif est de pouvoir :
- convertir un **point d’ancrage exprimé en espace monde**
- vers l’**espace local** du corps rigide A
- et vers l’**espace local** du corps rigide B

Ces conversions sont indispensables pour :
- stocker les points d’ancrage de manière stable
- indépendamment des mouvements ultérieurs des corps rigides

---

## 2. Ajout des prototypes dans `body.h`

Deux fonctions sont ajoutées à l’API publique de la classe `Body` :

1. **Local space → World space**
2. **World space → Local space**

Ces fonctions :
- prennent un point 2D en paramètre
- retournent un point 2D transformé
- sont déclarées `const`, car elles ne modifient pas l’état du corps

---

## 3. Rôle de chaque transformation

### Local space → World space
Permet de :
- prendre un point défini dans le repère du corps
- le placer correctement dans le monde
- en tenant compte de la rotation et de la translation du corps

### World space → Local space
Permet de :
- prendre un point exprimé dans le monde
- le ramener dans le repère local d’un corps rigide
- en annulant les effets de la translation et de la rotation

---

## 4. Implémentation dans `body.cpp`

Les deux fonctions sont implémentées directement dans le fichier source `body.cpp`.

Plutôt que de les écrire pas à pas, leur implémentation est reprise telle qu’elle a été présentée précédemment.

---

## 5. Détail : Local space → World space

La transformation se fait en deux étapes :

1. **Rotation**
   - le point local est d’abord tourné
   - l’angle utilisé est l’angle de rotation du corps rigide (en radians)

2. **Translation**
   - le point tourné est ensuite translaté
   - en ajoutant la position du corps rigide dans le monde

Formellement :
- rotation du point autour de l’origine locale
- puis translation vers la position globale du corps

Cette opération place correctement le point dans l’espace monde.

---

## 6. Détail : World space → Local space

Cette fonction réalise exactement l’opération inverse.

Elle se décompose également en deux étapes, dans l’ordre inverse :

1. **Inverse de la translation**
   - on soustrait la position du corps rigide au point monde
   - cela ramène le point dans le repère centré sur le corps

2. **Inverse de la rotation**
   - on applique une rotation avec l’angle opposé
   - c’est-à-dire `-rotation`

Mathématiquement :
- cette opération correspond à la multiplication par l’**inverse de la matrice de rotation**
- ce qui annule la rotation appliquée précédemment

---

## 7. Interprétation matricielle

La rotation directe correspond à la matrice :

$$
\begin{pmatrix}
\cos \theta & -\sin \theta \\
\sin \theta & \cos \theta
\end{pmatrix}
$$

L’opération inverse consiste à :
- utiliser l’angle opposé
- ce qui revient à multiplier par l’inverse de cette matrice

L’implémentation explicite avec cosinus et sinus :
- est équivalente à une approche matricielle
- mais plus simple à coder et plus légère

---

## 8. Importance pour le système de contraintes

Ces fonctions sont fondamentales car :
- les contraintes stockent leurs points d’ancrage en **espace local**
- les calculs physiques ultérieurs utilisent ces points transformés en espace monde
- chaque corps rigide possède son propre repère local

Ainsi :
- le même point d’ancrage physique
- est stocké différemment pour A et pour B
- selon leur position et leur orientation respectives

---

## 9. Utilisation dans les contraintes

Grâce à ces fonctions :
- le constructeur d’une contrainte peut recevoir un point en espace monde
- le convertir immédiatement en espace local pour chaque corps
- garantir une stabilité numérique et conceptuelle du système

---

## 10. Conclusion

Avec l’ajout de :
- `localSpaceToWorldSpace`
- `worldSpaceToLocalSpace`

la classe `Body` dispose désormais :
- des outils nécessaires pour gérer correctement les transformations géométriques
- d’une base solide pour l’implémentation des contraintes articulaires et de collision

Cette étape complète l’infrastructure indispensable avant :
- le calcul des Jacobiennes
- l’implémentation des méthodes `solve()` des contraintes
