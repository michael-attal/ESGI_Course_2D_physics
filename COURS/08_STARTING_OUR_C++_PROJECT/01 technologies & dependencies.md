# Transition de JavaScript vers C++

Nous avons terminé notre prototype en JavaScript.  
Nous allons maintenant passer à C++ pour approfondir la création d’un petit moteur physique et comprendre les concepts de physique.  

---

# Bibliothèques et dépendances

Il est nécessaire d’installer certaines bibliothèques et dépendances pour pouvoir visualiser des éléments à l’écran : rectangles, cercles, et avoir un retour visuel sur le fonctionnement de notre moteur physique.  

---

## Pourquoi le C++ pur n’est pas suffisant

Le langage C++ pur ne sait pas communiquer directement avec le matériel.  
Il ne peut pas afficher un pixel sur l’écran, ni récupérer les entrées clavier, souris ou joystick, sans bibliothèques supplémentaires.  

---

## Protection du système d’exploitation

Les systèmes d’exploitation modernes protègent l’accès direct au matériel.  
Un programme C++ ne peut pas modifier directement la mémoire vidéo ou les périphériques d’entrée sans passer par l’OS.  

---

## Accéder au matériel via les API

Pour afficher des éléments à l’écran ou récupérer les coordonnées de la souris, il est nécessaire de passer par des API spécifiques au système d’exploitation, qui servent d’intermédiaire entre le programme et le matériel.  

---

## API spécifiques à la plateforme

Sur Windows, il faut utiliser l’API Windows.  
Sur Linux, l’API Linux pour créer des fenêtres, dessiner à l’écran et récupérer les événements clavier/souris.  
Chaque OS dispose de ses propres fonctions pour accéder au matériel.  

---

# Problème multi-plateforme

Nous souhaitons écrire un seul code C++ pouvant fonctionner sur Windows, Linux, macOS, ou tout autre OS, sans créer des versions séparées pour chaque plateforme.  

---

# Introduction à SDL

SDL est une bibliothèque facilitant le développement multi-plateforme.  
Elle sert d’intermédiaire entre notre application C++ et le matériel, en traduisant les appels vers les fonctions spécifiques à chaque OS.  

---

## Pourquoi utiliser SDL

SDL permet de dessiner à l’écran : cercles, rectangles, lignes, textures, et d’accéder aux entrées clavier, souris et audio, de manière multi-plateforme.  

---

## Installation de SDL et extensions

Nous devons installer SDL et certaines extensions pour pouvoir développer efficacement : SDL_image pour les textures PNG et SDL_GFX pour les primitives graphiques.  

---

# Installation de SDL sur Linux

Via le terminal Linux et le gestionnaire de paquets :  

```bash
sudo apt install build-essential  
sudo apt install libsdl2-dev  
sudo apt install libsdl2-image-dev  
sudo apt install libsdl2-gfx-dev
```

`build-essential` inclut le compilateur C++ (GCC).  

---

# Installation de SDL sur macOS

Avec un gestionnaire de paquets comme Homebrew :  

```bash
brew install sdl2  
brew install sdl2_image  
brew install sdl2_gfx
```

Après cela, SDL2 est prêt à être utilisé pour programmer en C++.  

---

# Installation de SDL sur Windows

Sous Windows, il faudra configurer Visual Studio pour utiliser SDL2.  
L’installation inclut le téléchargement des fichiers, la configuration des dossiers d’inclusion et des bibliothèques, ainsi que la mise en place des flags du compilateur et du linker.  

---

## Pacte pour les étudiants Windows

Même si vous utilisez Windows, il est conseillé de suivre la partie Linux pour comprendre le fonctionnement du compilateur, des flags et de la compilation.  
Cela facilite ensuite la configuration sous Visual Studio.  

---

## Feuille de route du cours

Nous terminerons la partie Linux et reviendrons sur la configuration de Visual Studio sous Windows.  
Ainsi, le même code C++ pourra fonctionner sur Windows, Linux, macOS, ou toute autre plateforme grâce à SDL2.  
