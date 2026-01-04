# Ajout de textures dans le moteur physique

---

## Contexte et motivation

- Les polygones fonctionnent correctement avec collisions et résolution grâce à l’algorithme SAT pour polygones convexes.
- Problème actuel : le moteur physique n’est pas stable à 100 % et le rendu est limité à des formes fil de fer (wireframe).
- Objectif : afficher des textures sur les corps rigides pour un rendu visuel plus attrayant (ex. basketball, bowling ball, tennis ball).

---

## Modification de la structure `Body`

- Ajout d’un **pointeur vers SDL_Texture** dans la structure `Body` :
  ```cpp
  SDL_Texture* texture = nullptr;
```

- Inclusion des headers SDL nécessaires :

```cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
```

- Création d’une fonction membre `setTexture` pour charger la texture depuis le système de fichiers :

```cpp
void setTexture(const char* textureFileName);
```


## Chargement de la texture

- Étapes dans `Body.cpp` :
    
    1. Créer une surface SDL à partir du fichier PNG :

```cpp
SDL_Surface* surface = IMG_Load(textureFileName);
```

1.  Vérifier que la surface est valide.
    
2. Créer la texture à partir de la surface et du renderer SDL :
```cpp
texture = SDL_CreateTextureFromSurface(Graphics::renderer, surface);
```

4. Libérer la surface après création de la texture :
```cpp
SDL_FreeSurface(surface);
```

## Application des textures dans le rendu

- Dans la fonction `render`, tester si le mode debug est actif :
    
    - **Si debug** : afficher le wireframe du polygone.
        
    - **Sinon** : afficher la texture si elle est disponible :

```cpp
if (!debug && body.texture) {
    Graphics::drawTexture(body.position.x, body.position.y,
                          body.shape->width, body.shape->height,
                          body.rotation, body.texture);
} else {
    // Rendu wireframe classique
}

```

- Cette approche permet de garder le moteur physique indépendant du rendu tout en affichant des textures à l’écran.
    

---

## Résultat attendu

- Les boîtes affichent correctement `crate.png` ou d’autres textures PNG.
    
- Étendre la même logique pour les cercles avec textures comme `basketball.png` ou `bowling.png`.
    
- La rotation, la collision et la gravité continuent de fonctionner correctement avec les textures.
    

---

## Conclusion

- Chargement et affichage des textures dans le moteur physique est simple avec SDL et SDL_image.
    
- Cette étape améliore significativement l’aspect visuel tout en conservant la logique de physique intacte.
    
- Exercices proposés : appliquer les textures aux cercles et vérifier l’interaction dynamique sur l’écran.