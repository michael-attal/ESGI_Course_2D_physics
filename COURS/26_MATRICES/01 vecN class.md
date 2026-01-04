
## 1. Objectif pédagogique  
L’objectif de cette étape est d’introduire une **structure de données vectorielle dynamique** permettant de manipuler des vecteurs à *n* composantes, contrairement aux vecteurs fixes (ex. `VEC2`). Cette abstraction est essentielle pour la résolution de **contraintes physiques** (*constraints solving*), où la taille des vecteurs varie selon le problème.

---

## 2. Motivation : pourquoi un VECN  
Dans un moteur physique, certaines opérations (systèmes de contraintes, solveurs numériques) nécessitent des vecteurs dont la dimension n’est **pas connue à la compilation**.  

Le type `VECN` permet donc de créer dynamiquement des vecteurs de taille arbitraire :  
- 6 composantes  
- 100 composantes  
- 1000 composantes  

Cette flexibilité est indispensable pour généraliser les algorithmes.

---

## 3. Positionnement par rapport à VEC2  
Le type `VEC2` (vecteur 2D) reste **fondamental** dans le moteur (positions, vitesses, forces).  
Il **n’est pas remplacé**.  

`VECN` est un **outil complémentaire**, destiné aux calculs internes des solveurs.

---

## 4. Organisation des fichiers  
Dans le dossier `Physics/` :  
- `VECN2.h / VECN2.cpp` → inchangés  
- **Nouveaux fichiers** :  
  - `VECN.h`  
  - `VECN.cpp`  

(Il est possible de créer un sous-dossier `Math/`, mais pour ce cours nous restons simples.)

---

## 5. Définition conceptuelle de VECN  
Un `VECN` est :  
- un **vecteur colonne** (*column vector*)  
- de taille *n*  
- stocké dynamiquement en mémoire  

Il contient :  
- `int n` → nombre de composantes  
- `float* data` → tableau dynamique de flottants  

C’est une implémentation volontairement **bas niveau**, basée sur l’allocation manuelle.

---

## 6. Attributs internes  
```cpp
class VECN {
private:
    int n;
    float* data;
};
