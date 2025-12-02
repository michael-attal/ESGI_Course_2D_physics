# Installation et configuration de Visual Studio pour le projet Physics Engine

---

## Introduction

Nous allons apprendre à installer Visual Studio et à configurer un projet pour travailler avec le code source du Physics Engine.  

---

## Préparation des ressources

Téléchargez le dossier fourni **2D Physics-Windows**, qui contient :  
- **assets** : les images  
- **Lib** : fichiers SDL2 GFX nécessaires pour compiler sous Windows  
- **SRC** : code source (physics, application, graphics, main.cpp)  

Assurez-vous de télécharger ce dossier avant d’installer Visual Studio.  

---

## Installation de Visual Studio

Téléchargez et installez **Visual Studio Community Edition** (full IDE, pas VS Code).  
L’installation est simple : double-cliquez sur l’installateur, suivez les étapes et Visual Studio sera prêt avec le compilateur Visual C++.  

---

## Création d’un nouveau projet

Créez un projet vide (**Empty Project**) et renommez-le, par exemple **the physics engine**.  
Activez l’option **Show All Files** pour voir tous les fichiers du système dans Visual Studio.  
Ouvrez le dossier racine du projet via **Open Folder in File Explorer**.  

---

## Ajout des fichiers fournis

Copiez les dossiers **SRC**, **assets** et **Lib** dans le dossier de votre projet Visual Studio.  
Rafraîchissez le projet, sélectionnez tous les fichiers et faites **Include in Project**.  

---

## Vérification du code source

Le fichier **main.cpp** est identique à celui utilisé sous Linux.  
Si la compilation échoue avec "cannot open source file SDL.h", c’est normal : Visual Studio ne sait pas où trouver SDL.  

---

## Téléchargement des bibliothèques SDL

Téléchargez :  
- **SDL2** (libraries de développement pour Visual C++)  
- **SDL2_image** (idem)  

SDL2 GFX est déjà fourni dans **Lib**.  

---

## Installation locale de SDL

Déplacez le dossier SDL2 sur **C:** (par ex. `C:\SDL2`).  
Ce dossier doit contenir :  
- **include** : fichiers header  
- **lib** : DLL et bibliothèques  

Ajoutez les fichiers de SDL2_image dans `C:\SDL2` en remplaçant les existants.  

---

## Configuration des répertoires Include et Library

Dans Visual Studio :  
- **C/C++ → General → Additional Include Directories** : `C:\SDL2\include`  
- **Linker → General → Additional Library Directories** : `C:\SDL2\lib\x86`  

Cela permet à Visual Studio de trouver les headers et bibliothèques.  

---

## Résolution des erreurs de linkage

Si des erreurs de type "unresolved external symbols" apparaissent, ajoutez :  
- **Project Properties → Linker → Input → Additional Dependencies** :  

```bash
SDL2.lib  
SDL2main.lib  
SDL2_image.lib
```

Ces fichiers se trouvent dans `C:\SDL2\lib\x86`.

---

## Gestion des DLL manquantes

Si l’exécution indique "SDL2.dll not found", copiez toutes les DLL de `C:\SDL2\lib\x86` dans le dossier du projet (où se trouve l’exécutable).

---

## Exécution du programme

Vous devriez maintenant voir une fenêtre SDL affichant un cercle avec SDL_gfx.  
SDL2, SDL2_image et SDL2 GFX fonctionnent correctement sous Windows.

---

## Conclusion

Vous pouvez maintenant continuer le cours sous Windows avec Visual Studio.  
Le code reste identique à celui utilisé sous Linux.  
Nous pouvons revenir à la partie physique de notre cours.