## Contraintes et "sticks"

Lorsqu’on parle de systèmes de particules avec **intégration de Verlet**, les contraintes entre les points sont essentielles pour maintenir la cohérence du système. Ces contraintes peuvent être modélisées comme des **sticks** : des segments qui relient deux points et dont la longueur doit rester constante, indépendamment des forces extérieures comme la gravité ou le vent.

---

### Définition d’un stick

Un stick relie deux points, P0 et P1, avec une **longueur fixe** $L$.  
Chaque stick est initialisé avec ses deux points et la longueur à maintenir.  
Dans le code, on peut avoir un tableau de sticks pour gérer plusieurs contraintes simultanément.

La distance initiale entre deux points peut être calculée dynamiquement avec le théorème de Pythagore :  
$d = \sqrt{(x_1 - x_0)^2 + (y_1 - y_0)^2}$  

---

### Mise à jour des sticks

Pour appliquer la contrainte :
1. Calculer la différence entre les positions :  
   $dx = x_1 - x_0$, $dy = y_1 - y_0$  
2. Calculer la distance actuelle :  
   $distance = \sqrt{dx^2 + dy^2}$  
3. Calculer l’écart par rapport à la longueur désirée :  
   $difference = L - distance$  
4. Appliquer un **offset proportionnel** à chaque point :  
   - Si P0 et P1 sont libres de mouvement :  
     $offset = difference / 2$  
     $x_0 -= dx \cdot offset / distance$, $y_0 -= dy \cdot offset / distance$  
     $x_1 += dx \cdot offset / distance$, $y_1 += dy \cdot offset / distance$  
   - Si un point est **pinned** (fixe), seul l’autre point est déplacé.

Cette approche garantit que la distance entre les deux points reste constante, créant une contrainte **rigide**.

---

### Organisation du système

- Chaque point peut avoir un attribut `pinned` pour indiquer s’il est fixe ou mobile.  
- Les sticks sont mis à jour à chaque itération après la mise à jour des positions par Verlet.  
- L’ordre de rendu : les sticks sont dessinés avant les points pour que les points apparaissent au-dessus.

---

### Exemples de configuration

- On peut créer des formes rigides comme des carrés ou des triangles en reliant les points par plusieurs sticks, y compris les diagonales pour renforcer la structure.  
- L’ajout de points fixes (anchors) permet de maintenir certaines parties du système immobiles tout en laissant les autres se déplacer.  
- Les sticks peuvent être utilisés pour créer des simulations 2D complexes, comme des roues, des ponts ou des structures suspendues.

---

### Conclusion

L’utilisation de sticks avec **Verlet integration** permet de créer des systèmes de particules contraints stables et facilement extensibles.  
Cette combinaison est à la base de nombreux simulateurs physiques en 2D et 3D, offrant **stabilité numérique**, simplicité et flexibilité pour des interactions complexes entre particules.
