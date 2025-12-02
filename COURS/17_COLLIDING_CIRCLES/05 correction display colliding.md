# Gestion du drapeau de collision

Nous avons ajouté une petite variable booléenne appelée **isColliding** dans chaque `Body`.  
Cette variable est mise à **true** dès qu’une collision est détectée entre deux corps rigides.

---

# Utilité du drapeau

Le but principal de ce drapeau est de permettre de **rendre visuellement les corps en collision** différemment, par exemple en rouge.

---

# Problème d’initialisation

Parfois, les corps en collision n’étaient pas affichés en rouge.  
Le problème venait de la manière dont le drapeau était initialisé.

Dans la leçon précédente, je mettais `isColliding` à **false** **à l’intérieur de la boucle de détection**.  
Cela signifie que si un corps avait déjà été marqué comme `true`, il pouvait être réinitialisé à `false` au cours du même passage.

---

# Correction de l’ordre des opérations

La bonne pratique est de **parcourir tous les corps et de mettre leur drapeau à false avant de commencer les boucles de détection de collision**.  

```cpp
// Avant la détection de collision
for (auto& body : bodies) {
    body.isColliding = false;
}

// Boucles de détection de collision
for (int i = 0; i < bodies.size() - 1; i++) {
    for (int j = i + 1; j < bodies.size(); j++) {
        if (CollisionDetection::isColliding(&bodies[i], &bodies[j])) {
            bodies[i].isColliding = true;
            bodies[j].isColliding = true;
        }
    }
}
```


# Résultat attendu

En procédant ainsi, les corps en collision seront correctement affichés en rouge, et les corps non en collision resteront dans leur couleur normale.

![[medias/collision.png]]

Cette modification garantit que le rendu visuel correspond toujours à l’état réel des collisions dans la simulation.
