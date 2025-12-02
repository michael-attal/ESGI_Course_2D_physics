## Aperçu du dossier 2D Physics

Nous avons déjà peuplé le dossier 2D physics avec les fichiers graphiques, main.cpp et l’application.  
L’objectif de ce cours est la physique : collisions, friction, pertes d’énergie, accélération et mouvement.  

---

## Compilation sur Linux

Voyons comment compiler le projet sur Linux.  
Nous pourrons plus tard adapter ces commandes pour macOS et Windows.  

---

## Makefile et fichiers source

Dans le dossier racine, nous avons : makefile, assets et src.  
Tous les fichiers `.cpp` de **src** doivent être compilés avec un compilateur C++ comme g++.  

---

## Compilation de tous les fichiers source

Nous compilons tous les fichiers `.cpp` du dossier **src** et du sous-dossier **physics**.  
Nous générons un exécutable avec l’option `-o app`.  
Sous Windows, cela pourrait être `app.exe`.  

---

## Première tentative de compilation

La compilation initiale peut produire des erreurs et avertissements.  

---

## Compréhension des erreurs

Exemple : avertissement sur `= default`, qui est une extension C++11.  
Il faut spécifier le standard C++ lors de la compilation avec g++ (`-std=c++17`) pour utiliser les fonctionnalités modernes du langage.  

---

## Ajout du flag C++17

Après avoir ajouté `-std=c++17`, nous pouvons réduire les avertissements.  
Une erreur fréquente suivante est un **linker error**, pas une erreur de compilation.  
Les fonctions SDL ne sont pas trouvées car il faut lier les bibliothèques SDL au linker.  

---

## Lien avec les bibliothèques SDL

Nous ajoutons les flags pour le linker :  
- `-lSDL2`  
- `-lSDL2_image`  
- `-lSDL2_gfx`  
- `-lm` (bibliothèque mathématique)  
Cela permet au linker de trouver les implémentations SDL nécessaires.  

---

## Compilation réussie

Sous Linux, aucune sortie signifie que tout s’est bien passé.  
Un exécutable `app` est créé et prêt à être exécuté.  

---

## Exécution de l’exécutable

L’exécution ouvre une fenêtre pleine écran, efface l’écran et peint le fond en vert.  
Le cercle blanc est dessiné grâce à `graphics::drawFilledCircle` dans la fonction `render`.  
La boucle de jeu (`input`, `update`, `render`) tourne plusieurs fois par seconde.  

---

## Étapes suivantes

Nous avons compilé correctement et configuré toutes les bibliothèques SDL.  
Nous pouvons maintenant nous concentrer uniquement sur la physique de la simulation.  
