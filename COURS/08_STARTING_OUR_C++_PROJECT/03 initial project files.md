# Introduction

Abordons maintenant le système de fichiers, les fichiers et leur contenu.  
 
À l’intérieur, nous trouvons le `makefile`, ainsi que deux dossiers : **assets** et **src**.  

---

## Dossier Assets

Dans le dossier **assets**, nous avons plusieurs fichiers PNG :  
`Basketball.png`, `Bowling_ball.png`, `Crate.png` (une boîte en bois) et `Metal.png` (texture métallique).  
Ces images serviront plus tard pour afficher des textures, mais pour l’instant, elles ne sont pas utilisées.  

---

## Aperçu du dossier Source

Dans le sous-dossier **src**, nous avons :  
application.cpp, application.h, graphics.cpp, graphics.h, main.cpp et un sous-dossier **physics** contenant quelques fichiers.  
C’est typique des projets C++ : séparation entre les fichiers d’application, de moteur physique et de rendu.  

---

## Fichiers Header et Source

Les déclarations et définitions de classes sont séparées :  
- Fichier `.h` : déclaration des classes et prototypes  
- Fichier `.cpp` : implémentation réelle des fonctions et méthodes  

---

## Aperçu de main.cpp

Le fichier **main.cpp** est la porte d’entrée du programme.  
Pour visualiser le contenu, nous utilisons un éditeur de texte : Vim, VSCode, Sublime ou Emacs.  

---

## Contenu de main.cpp

La fonction principale `main` reçoit éventuellement des paramètres depuis la ligne de commande, mais elle sert surtout à démarrer l’application et la boucle de jeu.  

---

## Inclusion de Application.h

Le premier `#include` dans main.cpp est **application.h**, qui contient la classe Application.  
Nous créons un objet Application et appelons `setup()` pour initialiser la simulation et les objets dans le monde physique.  

---

## Boucle de jeu

Après l’initialisation, nous entrons dans la boucle de jeu :  
- `input` : lecture des événements clavier/souris  
- `update` : calcul des positions, vitesses et interactions des objets  
- `render` : dessin des objets à l’écran  
La boucle continue tant que `running` est vrai.  

---

## Rendu et nettoyage

La fonction `render` dessine les objets selon leurs nouvelles positions.  
La fonction `destroy` (ou `~Application`) libère la mémoire et ferme la fenêtre SDL.  

---

## Logique de l’application et du moteur physique

Tout le code de calcul physique et de gestion de l’application se trouve dans **application.h**, **application.cpp** et le dossier **physics**.  
main.cpp ne change pas pendant le cours.  

---

## Aperçu de Application.h

Le fichier **application.h** déclare la classe Application :  
- Protection contre l’inclusion multiple (`#ifndef` / `#define`)  
- Membres privés : `bool running`  
- Membres publics : constructeur, destructeur, prototypes des méthodes `setup`, `input`, `update`, `render`, `destroy`, `isRunning()`  

---

## Protection des headers

Les guards empêchent l’inclusion multiple du fichier header.  
Cette structure est présente dans tous les fichiers `.h`.  

---

## Inclusion de graphics.h

Nous incluons **graphics.h** pour accéder aux fonctions SDL utiles : ouverture de fenêtre, rendu, dessin de primitives, etc.  

---

## Déclaration de la classe

La classe Application contient des membres privés (`running`) et publics (constructeur, destructeur, méthodes).  
`isRunning()` est un getter pour accéder au flag `running`.  

---

## Constructeurs et méthodes

Constructeur et destructeur par défaut (`= default`) ; méthodes prototypes exposées au main.cpp :  
`setup()`, `input()`, `update()`, `render()`, `destroy()`.  

---

## Déclaration vs Implémentation

Les prototypes sont déclarés dans **application.h**, et l’implémentation réelle se trouve dans **application.cpp**.  

---

## `application.cpp` : implémentation

Fichier d’implémentation : contient le code réel des fonctions déclarées dans `application.h`.  
Première ligne : `#include "application.h"`.  

---

## Getter isRunning()

Renvoie la valeur du flag privé `running`.  
Pratique pour vérifier si l’application est en cours d’exécution.  

---

## Méthode `setup()`

`running = graphics::openWindow()` : ouvre une fenêtre SDL et retourne true/false selon le succès.  
Ensuite, nous ajouterons les objets et éléments de la scène dans cette méthode.  

---

## Méthode `input()`

Lit les événements clavier et souris via SDL.  
- `SDL_QUIT` : fenêtre fermée → `running = false`  
- `SDL_KEYDOWN` avec `SDLK_ESCAPE` : touche Escape → `running = false`  

---

## Méthode `update()`

Mettra à jour tous les objets, calcule la physique, résout les collisions.  
Actuellement vide, à compléter ultérieurement.  

---

## Méthode `render()`

Dessine les objets avec la classe **graphics** :  
- `graphics::clearScreen(color)`  
- `graphics::drawFilledCircle(x, y, radius, color)`  
- `graphics::renderFrame()`  

---

## Méthode `destroy()`

Libère les ressources : `graphics::closeWindow()`.  

---

## Aperçu de graphics.h

Variables membres statiques : largeur et hauteur de la fenêtre, pointeurs SDL_Window et SDL_Renderer.  
Fonctions disponibles : getters, ouverture/fermeture de fenêtre, clear, renderFrame, dessin de primitives (ligne, cercle, rectangle, polygone, texture).  

---

## Fonctions de la classe Graphics

- `width()`, `height()` : getters  
- `openWindow()`, `closeWindow()`  
- `clearScreen(color)`  
- `renderFrame()`  
- `drawLine(x0, y0, x1, y1, color)`  
- `drawCircle(x, y, radius, color)`  
- `drawFilledCircle(...)`  
- `drawRectangle(...)`, `drawFilledRectangle(...)`  
- `drawPolygon(...)`, `drawFilledPolygon(...)`  
- `drawTexture(...)`  

---

# Conclusion

`graphics.h/cpp` fournit toutes les fonctions SDL nécessaires pour le rendu.  
L’objectif du cours est la physique et les calculs, pas SDL.  
Nous pouvons utiliser ces fonctions librement pour dessiner lignes, cercles, rectangles, polygones ou textures.  

---

# Compilation et exécution

Retour au terminal Linux : nous pouvons compiler le projet et exécuter l’application pour observer le moteur physique en action.  
