# Contrôle du Mouvement des Particules avec un Pas de Temps Fixe

---

Actuellement, notre particule se déplace à l’écran dans la méthode `update` en mettant à jour sa **position** en fonction de sa **vitesse**.  

Le problème est que ce mouvement n’est pas **contrôlé** : sur une machine très rapide, la particule pourrait se déplacer trop vite pour être visible.  
	
Nous avons donc besoin de créer une relation fiable entre **frames** et **temps réel** pour que le mouvement soit identique sur toutes les machines.

---

## Création de Constantes Globales

Pour contrôler notre boucle de jeu, nous allons créer un fichier `constants.h` dans le dossier du moteur physique.  

Ce fichier contiendra des constantes globales comme :  
- **FPS** (frames per second) : nombre de frames par seconde, par exemple 60  
- **MillisecondsPerFrame** : durée d’une frame en millisecondes, calculée comme $$\text{MillisecondsPerFrame} = \frac{1000}{FPS}$$

Ces constantes permettent de limiter la vitesse d’exécution de la boucle de jeu et d’uniformiser le mouvement des particules.

---

## Implémentation du Contrôle des Frames

Dans la fonction `update()`, nous allons mesurer le temps écoulé depuis la dernière frame à l’aide de `SDL_GetTicks()`.  
Nous calculons ensuite le **temps à attendre** pour atteindre la durée cible d’une frame :  

```cpp
int timeToWait = MillisecondsPerFrame - (SDL_GetTicks() - previousFrameTime);
if (timeToWait > 0) {
    SDL_Delay(timeToWait);
}
previousFrameTime = SDL_GetTicks();
```

---

- `SDL_GetTicks()` retourne le nombre de millisecondes écoulées depuis le début de l’application.
- `timeToWait` permet de suspendre l’exécution si la frame est terminée trop rapidement.
- `SDL_Delay()` met en pause l’application pour que chaque frame dure exactement le temps défini par `MillisecondsPerFrame`.
    
Cette méthode simple garantit que **chaque frame dure le même temps**, assurant un mouvement constant et indépendant de la vitesse du processeur.

---

## Résumé

1. Déclarer les constantes globales `FPS` et `MillisecondsPerFrame`.
2. Dans la boucle `update`, calculer le temps écoulé depuis la dernière frame.
3. Suspendre l’exécution si la frame est terminée trop rapidement.
4. Mettre à jour `previousFrameTime` pour la frame suivante.
    

Ainsi, le mouvement de la particule sera **identique sur toutes les machines**, exécuté à **60 frames par seconde**.  
C’est la base d’un **pas de temps fixe** (_fixed time step_) pour la simulation physique.