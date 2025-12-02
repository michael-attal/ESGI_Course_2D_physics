## Commande de compilation longue en C++

La commande de compilation avec g++ peut devenir très longue, avec de nombreuses options, fichiers source et flags du linker.  
Recompiler manuellement à chaque modification serait fastidieux.  

---

## Introduction au Makefile

Le makefile est un fichier d’aide contenant des règles pour construire notre projet.  
Il permet de compiler simplement en tapant `make` au lieu de répéter la commande g++ complète.  

---

## Structure d’un Makefile

Un makefile contient des règles avec un nom suivi de deux-points et d’une commande indentée par une tabulation.  
La commande inclut le compilateur, les fichiers source et les flags du linker pour générer l’exécutable.  
Exemple : compilation de tous les `.cpp` de **src** et **src/physics**, avec liens vers SDL et `-lm`, générant l’exécutable `app`.  

---

## Règles additionnelles : run et clean

Le makefile peut inclure :  
- `run` : exécute l’exécutable généré (`make run`)  
- `clean` : supprime l’exécutable (`make clean`)  

---

## Utilisation des règles du Makefile

Avec les règles `build`, `run` et `clean`, il suffit de :  
- `make` ou `make build` pour compiler  
- `make run` pour exécuter  
- `make clean` pour supprimer l’exécutable  
Cela simplifie la gestion du projet.  

---

## Bonnes pratiques pour les Makefile

Avoir des règles distinctes pour compiler, exécuter et nettoyer est pratique.  
Pour des projets professionnels, un makefile peut inclure plusieurs cibles pour différents systèmes et configurations.  

---

## Makefile dans le contexte du cours

Dans ce cours, le makefile simplifie notre travail et évite de taper des commandes longues.  
Il suffit de `make` pour compiler tout le projet automatiquement.  

---

## Compilation sur macOS

La procédure de compilation sur macOS est identique à celle sur Linux.  
Il suffit d’utiliser le terminal et les mêmes commandes ou makefile.  

---

## Compilation sur Windows

Sur Windows, il faudra configurer Visual Studio, le linker et les DLL.  
Une fois la configuration terminée, la compilation et l’exécution deviennent simples, comme sur Linux et macOS.  
