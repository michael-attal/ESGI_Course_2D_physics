# Introduction  

Nous venons de discuter de l’intégration et de son rôle dans la simulation physique.  
Maintenant, nous allons effectuer un petit ajustement dans notre code pour mieux organiser l’intégration des particules.  

---

## Mise en place du problème  

Nous avons un ensemble de particules soumises à une **accélération constante**.  
Pour prédire la nouvelle position, nous intégrons la vitesse issue de cette accélération.  

---

## Refactorisation du code  

Nous allons déplacer les lignes de code correspondant à l’intégration directement **dans la classe Particle**.  
Cela permet à chaque particule de gérer elle-même son intégration.  

---

## Création de la méthode `integrate`  

Nous créons une nouvelle méthode `integrate` dans la classe `Particle`.  
Il suffit ensuite d’appeler `particle.integrate(dt)` pour que la particule mette à jour sa vitesse et sa position en fonction de l’accélération.  

---

## Programmation orientée objet  

Chaque particule devient responsable de son propre calcul d’intégration,  
ce qui respecte le principe de **responsabilité unique** en POO.  

---

## Implémentation de la méthode  

Dans `particle.cpp`, nous implémentons :  

```cpp
void Particle::integrate(float dt)
{
    velocity += acceleration * dt;
    position += velocity * dt;
}
```

On remplace les références directes à la vitesse et à l’accélération de l’extérieur  
par les attributs de l’objet, et on multiplie par le paramètre `dt`.

---

## Passage de paramètres

Le **delta time** (`dt`) est passé en paramètre afin de rester flexible et réutilisable  
pour chaque particule et chaque pas de temps.

---

## Modification des fichiers d’en-tête

Dans `particle.h`, on déclare la méthode :

```cpp
void integrate(float dt);
```

Ce qui permet d’utiliser `dt` comme paramètre lors de l’appel de la méthode.

---

## Résultat

L’intégration Euler est désormais **encapsulée dans la particule**,  
tout en conservant le même comportement : la particule se déplace correctement selon l’accélération constante.

---

## Découplage des responsabilités

Cette approche permet de **découpler la logique d’intégration** du reste du moteur physique.  
Si nous souhaitons remplacer Euler par Verlet ou Runge-Kutta,  
il suffit de modifier la méthode `integrate` sans toucher au reste du code.

---

## Flexibilité et améliorations futures

Chaque particule sait comment s’intégrer elle-même.  
Dans le code principal, il suffit de faire :

```cpp
particle.integrate(dt);
```

La technique d’intégration peut ainsi être changée facilement,  
offrant **modularité** et **extensibilité** pour le moteur physique.

---

## Conclusion

L’intégration Euler pour une accélération constante est maintenant proprement implémentée et encapsulée.  
La prochaine étape sera d’introduire le concept de **forces** dans notre simulation.