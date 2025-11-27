---
# Points de Support (Support Points) dans SAT

Nous venons de mettre en œuvre un code SAT qui se base sur la **recherche de l’axe de séparation minimale** entre deux polygones et le test de cette séparation pour détecter une collision.

Avant d’aller plus loin, il est important de comprendre la notion de **"support points"**. Vous pouvez rencontrer cette expression dans des livres ou articles sur le SAT, et il est essentiel de savoir ce que cela signifie.

---
# Définition

Un **point de support (support point)** est le sommet du **second polygone** qui se situe **le plus en retrait** par rapport à un certain **bord du premier polygone**.

---
# Exemple

Si l’on considère l’arête avec normale **n₁** du premier polygone, le support point du second polygone sera le sommet **le plus éloigné derrière cette arête**.

![[medias/support-point2.jpg]]

On répète cette opération pour toutes les arêtes, par exemple pour l’arête avec normale **n₂**, on obtient un autre support point.

![[medias/support-point1.jpg]]

Le support point final est celui qui **donne la plus petite valeur de séparation** parmi tous les support points précédents.

---
# Comparaison avec l’implémentation SAT

Cette notion est très proche de ce que nous avons déjà fait dans notre implémentation SAT :  
- Projection des sommets sur les axes définis par les normales des arêtes.  
- Recherche de la **séparation minimale** pour détecter la collision.

Ainsi, chaque support point correspond à un **sommet critique** qui permet de déterminer **le meilleur point de collision SAT** entre deux polygones convexes.

---
# Conclusion

Si vous lisez un livre ou un article qui parle de "support points", il s’agit **exactement** de cela : un sommet le plus en retrait derrière une arête, utilisé pour calculer la **meilleure collision SAT** entre deux polygones convexes.

#tags
#collision-detection/sat, #polygon/collision, #support-points, #convex-polygons, #game-physics
