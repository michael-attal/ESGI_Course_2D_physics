
---

# Introduction

Nous avons jusqu’ici travaillé avec des cercles et détecté leurs collisions, que nous résolvions ensuite via la méthode de l’impulsion. Les balles rebondissent correctement et tout fonctionne. Nous allons maintenant nous arrêter un instant pour examiner des formes différentes.

---
# Axis-Aligned Bounding Boxes (AABB)

Une des formes les plus utilisées dans les moteurs physiques, et en développement de jeux, est ce que l’on appelle **AABB** (*Axis-Aligned Bounding Box*). Il s’agit de boîtes dont les arêtes sont alignées avec les axes du système de coordonnées. Si l’on a un axe X et un axe Y, les sommets et les arêtes de la boîte suivent ces axes. Ces boîtes **ne sont pas tournées**, ce qui simplifie beaucoup les calculs de collision.

---
# Popularité et cas d’usage

Les AABB sont populaires car elles permettent d’encapsuler facilement des éléments de l’UI, comme des champs de texte ou des boutons. L’algorithme de détection de collision pour les AABB est **peu coûteux et rapide** en termes de complexité algorithmique et de cycles processeur.

Elles sont idéales pour le **broad-phase testing**. Dans cette phase, on détecte rapidement si deux objets *potentiellement* en collision se chevauchent. Si la détection broad-phase signale une collision possible, on passe à la **narrow-phase**, où l’on teste les arêtes et sommets précisément. Les AABB sont souvent utilisées pour encapsuler des formes plus complexes, de la même manière que l’on pourrait utiliser des cercles.

---
# Détection de collision

Supposons que nous ayons deux objets A et B, chacun représenté par une AABB. Pour détecter la collision, nous devons projeter les boîtes sur les axes X et Y. 

## Projection sur l’axe X

Pour chaque objet, calculons :

- `A.left` et `A.right` à partir de la position X et de la largeur de A.
- `B.left` et `B.right` à partir de la position X et de la largeur de B.

La condition de chevauchement horizontal est :

```cpp
isOverlappingX = (A.left <= B.right) && (B.left <= A.right)
```


Si cette condition est vraie, les boîtes se chevauchent horizontalement.

---
## Projection sur l’axe Y

De même, projetons sur l’axe Y :

- `A.top` et `A.bottom` à partir de la position Y et de la hauteur de A.
- `B.top` et `B.bottom` à partir de la position Y et de la hauteur de B.

La condition verticale est :

```cpp
isOverlappingY = (A.bottom <= B.top) && (B.bottom <= A.top)
```

---
# Test final de collision

Pour conclure que A et B se chevauchent :


```cpp
isColliding = isOverlappingX && isOverlappingY
```


Si une seule des projections ne se chevauche pas, il n’y a **pas de collision**.  
> Principe clé : *S’il existe au moins un axe avec un écart entre deux corps rigides, ils ne se touchent pas.*

---
# Separating Axis Theorem (SAT)

Ce principe est à la base du **Separating Axis Theorem** (*Théorème de l’Axe Séparateur*). Il fonctionne pour :

- Les AABB
- Les boîtes orientées (avec rotation)
- Les polygones quelconques

L’idée : si au moins un axe montre une séparation entre les deux objets, ils ne sont pas en collision. C’est la même logique que pour les AABB, mais étendue aux objets plus complexes.

---
# Conclusion

La détection de collision entre AABB est omniprésente dans les jeux vidéo. Elle est rapide, simple et efficace pour la broad-phase. Mais le principe fondamental que nous venons de voir sert également de base pour la détection de collision entre **boîtes orientées et polygones** via le SAT.  
Ceci sera la prochaine étape de notre cours pour gérer les collisions entre formes plus complexes et avec rotation.





