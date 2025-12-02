# Vue d’ensemble de l’implémentation

Abordons maintenant l’implémentation.  
Regardons la structure du dossier de notre projet pour le moteur physique.  
Regardons les fichiers et sous-dossiers présents dans le dossier racine du projet.  

---

## Structure du dossier racine

Le dossier racine est le dossier principal du projet nommé **physics**.  
Il contient plusieurs sous-dossiers et fichiers.  
Expliquons le rôle de chacun.  

---

# Makefile

Le premier fichier est le `makefile`.  
Il contient des configurations et des règles pour les outils de compilation.  
Lors de l’utilisation du compilateur **GCC**, ce `makefile` facilite la compilation du projet.  
Nous verrons bientôt le contenu précis de ce `makefile`.  

---

# Dossier Assets

Le sous-dossier **assets** contient les images utilisées par le moteur, comme des PNG représentant un ballon de basket, une boule de bowling ou une boîte.  
C’est le dossier dédié aux ressources visuelles du projet.  

---

# Dossier SRC

Le dossier **SRC** contient le code source de l’application.  
L’entrée principale est **main.cpp**, et nous avons également :  

- **application.h**  
- **application.cpp**  
- **graphics.h**  
- **graphics.cpp**  

Ces fichiers gèrent la création de la fenêtre, les objets et l’état général de l’application.  

---

# Fichiers de l’application

**main.cpp** reste minimal et appelle la **classe Application** définie dans **application.h** et **application.cpp**.  
La classe Application contient toute la logique de l’application : ouverture de la fenêtre, gestion des objets, des entrées clavier et souris, activation de la gravité, etc.  

---

# Fichiers graphiques

**graphics.h** et **graphics.cpp** contiennent des fonctions SDL prêtes à l’emploi pour dessiner : lignes, rectangles, cercles, textures PNG, ouvrir et fermer la fenêtre.  
Ces fichiers sont fournis, et il n’est pas nécessaire de s’inquiéter des détails de SDL.  

---

# Dossier Physics

Le sous-dossier **physics** contient tout le code lié au moteur physique :  
- Implémentation de **Vector2**  
- Particules  
- Corps rigides  (*rigid bodies*)
- Collisions et résolution  
- Forces  
- Intégration  
- Vitesse  

Tout ce qui concerne les lois physiques, la simulation, les calculs de force et d’accélération se trouve ici.  

---

# Séparation des responsabilités

Le moteur physique est indépendant du rendu.  
Il prend des nombres en entrée, effectue les calculs physiques, et renvoie des nombres.  
Le rendu, via **graphics.h** et **graphics.cpp**, utilise ces résultats pour afficher la simulation.  
Cette séparation permet de réutiliser le moteur physique avec n’importe quel moteur de rendu : SDL, OpenGL, Vulkan, Metal, etc.  

---

# Résumé de la structure des dossiers

La structure finale est la suivante :  
- **assets** : ressources visuelles  
- **SRC** : code de l’application (main, application, graphics)  
- **physics** : code du moteur physique (Vector2, particules, rigid bodies, collisions, forces, intégration, vélocité)  

Cette structure reste identique quel que soit le système d’exploitation : Windows, Linux, macOS, FreeBSD, OpenBSD, etc.  

---

# Étapes suivantes

Nous allons maintenant ouvrir le terminal Linux et naviguer dans cette structure.  
Nous observerons les fichiers, puis compilerons le projet pour générer un exécutable et voir le moteur physique en action.  

---

# Parcours d’apprentissage

Même si vous utilisez Windows, il est conseillé de suivre la compilation sous Linux pour comprendre le fonctionnement des dépendances et des flags du compilateur.  
Une fois cette étape comprise, configurer Visual Studio pour Windows sera beaucoup plus simple.  
Nous commencerons donc par Linux, puis adapterons ensuite la procédure à Windows.  
