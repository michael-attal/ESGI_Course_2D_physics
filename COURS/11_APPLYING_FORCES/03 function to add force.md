
## Fonction de Mise à Jour et Accélération


Actuellement, dans notre fonction de mise à jour, l'accélération est **constante** : 2.0 pixels/mètre en x et 9.8 pixels/mètre en y. Ensuite, nous intégrons cette accélération pour obtenir une nouvelle vitesse et position.

---

## Rendre l'Accélération Variable

Nous voulons maintenant que l'accélération dépende des **forces appliquées** à notre particule.  
Dans `particle.h`, ajoutons un attribut pour la **somme de toutes les forces** et une méthode `addForce(const Vector& force)`.

---

## Implémentation de `addForce()`

La méthode `addForce` ajoute un vecteur force à l'attribut `sumForces`.  
Le mot-clé `const` garantit que la référence ne sera pas modifiée dans la fonction.

---

## Méthode `clearForces()`

La méthode `clearForces` remet `sumForces` à zéro.  
Cela permet de réinitialiser les forces à chaque frame de simulation.

---

## Implémentation en C++

```cpp
void Particle::addForce(const Vector& force) {
    sumForces += force;
}

void Particle::clearForces() {
    sumForces = Vector(0.0, 0.0, 0.0);
}
```

---

## Compréhension des Attributs d’Objet

`sumForces` est un attribut de l'objet particule qui stocke la **somme des forces** à chaque frame.

---

## Logique d’Intégration

L’accélération est calculée via **F = m * a**, donc `acceleration = sumForces / mass`.  
Ensuite, nous intégrons pour obtenir la vitesse et la position.

---

## Intégration avec Euler

Nous utilisons la **méthode d’Euler** pour intégrer l’accélération et la vitesse.  
Cela peut être remplacé par d’autres intégrateurs si nécessaire.

---

## Réinitialisation des Forces à Chaque Frame

À la fin de chaque frame, il est crucial de **réinitialiser les forces** pour la prochaine étape de simulation.

---

## Application des Forces dans update()

Avant d’intégrer, nous pouvons appliquer une force de vent :

```cpp
Vector wind(0.2, 0.0);
particle.addForce(wind);
```

---

## Workflow d’Intégration

1. Créer la force
2. Ajouter la force à la particule
3. Calculer l’accélération (`a = F / m`)
4. Intégrer pour obtenir vitesse et position
5. Réinitialiser les forces
    

---

## Comparaison avec les Moteurs Physiques

Des moteurs comme **Box2D** ou **Chipmunk2D** utilisent le même principe :  
appliquer une force, calculer l’accélération, mettre à jour la vitesse et la position.

---

## Perspective du Développeur

Pour un développeur, il suffit d’ajouter des forces (`wind`, `friction`, `gravity`),  
le moteur s’occupe du reste.

---

## Test et Ajustement

Vérifier que la particule réagit correctement à la force appliquée  
et ajuster l’intensité si nécessaire.

---

## Affinement

Exemple : ajuster la force du vent à 0.2 m/s pour correspondre au facteur pixels/mètre.

---

## Observation des Effets

Nous observons la variation de la vitesse frame par frame selon la force appliquée.

---

## Conclusion

Nous avons maintenant `addForce` pour appliquer des forces  
et `integrate` pour gérer l’évolution de la particule dans notre moteur physique.

---

## Créativité et Forces

La complexité du mouvement dépend uniquement de **la combinaison des forces** appliquées :  
vent, friction, gravité, poids, résistance des fluides, etc.  
Le moteur se charge de l’intégration.