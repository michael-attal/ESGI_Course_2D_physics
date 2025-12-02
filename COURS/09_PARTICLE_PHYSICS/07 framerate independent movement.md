# Gestion du Temps et du FPS

---

Dans le développement de simulations et de jeux, nous avons souvent tendance à **prendre les frames par seconde (FPS) pour acquises**.  
Les moteurs de jeu gèrent ces détails en interne, mais il est crucial de comprendre comment contrôler le temps et le mouvement **frame par frame** à bas niveau.  
Nous construisons ainsi une base solide pour tous les calculs de physique et de rendu.  

---

## Importance de la Persistance des Variables

Pour gérer correctement le temps entre les frames, nous déclarons la variable `previousFrameTime` **static** dans la fonction `update`.  
Cela permet de **conserver la valeur** d’une frame à l’autre sans la réinitialiser à chaque appel.  

---

Ensuite, nous calculons le temps à attendre avant de traiter la frame suivante :  

```cpp
int timeToWait = MillisecondsPerFrame - (SDL_GetTicks() - previousFrameTime);
if (timeToWait > 0) {
    SDL_Delay(timeToWait);
}
previousFrameTime = SDL_GetTicks();
```

- `timeToWait` : durée restante pour atteindre la durée cible d’une frame.
- `SDL_Delay()` : suspend l’exécution pour que la frame dure exactement le temps défini.
    
Cette approche garantit un **contrôle précis du FPS**.  

---

## De Pixels par Frame à Pixels par Seconde

Penser en **pixels par frame** est limité et dépend du FPS.  
Il est préférable de penser en **pixels par seconde**, ce qui nécessite d’introduire un facteur **delta time** (`Δt`) : le temps écoulé depuis la dernière frame.  

---

## Calcul du Delta Time et Mouvement Indépendant du FPS

`deltaTime` se calcule ainsi :

```cpp
float deltaTime = (SDL_GetTicks() - previousFrameTime) / 1000.0f;
```

- Conversion en secondes en divisant par 1000.
- Utilisation de `deltaTime` pour ajuster tout mouvement afin qu’il soit **indépendant du FPS**.
    
---

Exemple de mouvement d’une particule :

```cpp
float velocityX = 100.0f; // pixels par seconde
float velocityY = 30.0f;  // pixels par seconde
particle.position.x += velocityX * deltaTime;
particle.position.y += velocityY * deltaTime;
```

Ainsi, la particule se déplacera correctement même si le FPS varie : 60, 30 ou 5 frames par seconde, le mouvement reste constant.  

---

## Règle d’Or pour le Mouvement

- Tout **déplacement**, **rotation** ou transformation doit être multiplié par `deltaTime`.
- Cela assure une **simulation cohérente et indépendante du FPS**.

---

- Exemple : pour une rotation de 90° par seconde :

```cpp
angle += 90.0f * deltaTime;
```
- Pour un déplacement de 10 pixels par seconde :

```cpp
position += 10.0f * deltaTime;
```

Cette pratique sera systématiquement appliquée pour tous les mouvements et transformations.