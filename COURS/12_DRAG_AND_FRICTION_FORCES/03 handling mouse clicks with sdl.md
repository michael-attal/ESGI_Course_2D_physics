### Capture de la souris SDL et génération de particules

Il est possible de faire en sorte que SDL capture les clics de souris et récupère les coordonnées *X* et *Y* du curseur. L’exécution du programme montre que, lorsque la souris se déplace, des particules peuvent être générées à chaque clic. Il est ainsi possible d’en créer un grand nombre, et dès qu’elles atteignent la zone inférieure, elles subissent la force de traînée (*drag force*).  

---

Si les particules se déplacent vers la droite, c’est parce que la force du vent (*wind force*) reste appliquée. Ce comportement est incorrect, car il ne devrait pas y avoir de vent à l’intérieur du fluide. Il convient donc de supprimer cette force dans cette zone.

---

## Suppression de la force du vent

Avant d’aborder la capture de la souris, il est nécessaire de retirer la force du vent. 

Cette force peut être conditionnée de manière à ne s’appliquer que si la particule se trouve dans la partie supérieure de l’écran (hors du fluide). Toutefois, dans un premier temps, il est préférable de la supprimer complètement afin de ne pas fausser les résultats.  

La force du vent n’est donc plus appliquée dans la simulation.

---

## Capture du clic de souris avec SDL

La détection du clic de souris s’effectue dans la fonction de gestion des entrées (*input function*), en ajoutant un cas spécifique :  

```cpp
case SDL_MOUSEBUTTONDOWN:
```


---

Lorsqu’un bouton de la souris est enfoncé, SDL permet de vérifier s’il s’agit du bouton gauche (`SDL_BUTTON_LEFT`). Dans ce cas, deux variables locales `x` et `y` sont créées.

La fonction `SDL_GetMouseState(&x, &y)` renseigne ces variables avec les coordonnées exactes du curseur au moment du clic.

---

## Création des particules

Une fois les coordonnées _X_ et _Y_ obtenues, une nouvelle particule est instanciée à cette position avec une masse de `1.0` et un rayon de `5` pixels :

```cpp
Particle p(Vector2(x, y), 1.0f, 5.0f);
particles.push_back(p);
```

---

Cette particule est ensuite ajoutée au tableau `particles`.

Ce mécanisme permet de générer dynamiquement des particules à chaque clic. Celles-ci sont correctement construites et détruites lors de la fermeture de l’application. Il est possible d’en créer plusieurs simultanément : elles se déplacent de manière fluide et subissent la force de traînée (_drag force_).

---

## Vérification de la force de traînée

La simulation confirme le bon fonctionnement de la force de traînée. La force du vent ayant été supprimée, seule la traînée agit sur les particules.

Les fichiers `physics/force.h` et `force.cpp` contiennent la fonction `generateDragForce()`, qui calcule une force proportionnelle à la vitesse de la particule et à une constante _k_.

---

Ce système peut être étendu à d’autres types de forces physiques :

- **Force de frottement** (_friction force_)
- **Force de ressort** (_spring force_)
    
---

Ces forces peuvent être implémentées de manière similaire dans `force.cpp`. Chaque fonction renvoie un vecteur représentant la force calculée, prêt à être appliqué à une particule :

```cpp
particle.addForce(friction);
particle.addForce(drag);
particle.addForce(spring);
```

L’ensemble du modèle de simulation repose ainsi sur des générateurs de forces indépendants, permettant de reproduire différents comportements physiques de manière modulaire et extensible.

