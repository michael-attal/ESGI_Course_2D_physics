---
auteur: guillaume cournet
---

# Introduction au cours de Physique 2D pour le Jeu Vidéo  


---

## Objectifs du cours

Ce cours vise à **comprendre et programmer les fondements d’un moteur de physique 2D**.  
Nous aborderons les lois physiques de base, leur traduction en formules mathématiques, puis leur implémentation dans un moteur de jeu simple mais fonctionnel.  
L’objectif est d’apprendre à créer une **intuition entre les mathématiques, la physique et le code**.  

---

## Plan du cours  


Le cours s’organise autour d’une **progression conceptuelle et technique** :

1. Introduction à la simulation physique 2D  
2. Outils mathématiques : vecteurs et opérations  
3. Implémentation en C++  
4. Physique des particules  
5. Corps rigides (*rigid bodies*)  
6. Détection et résolution de collisions  
7. Contraintes et système de contraintes  
8. Stabilité et robustesse d’un moteur de physique  

---

Chaque partie mêlera **notions théoriques**, **visualisations**, et **implémentations progressives**.  

![[01 introduction-20251027.png]]


---

![[intro01.gif]]

---

![[01 introduction-20251102.png]]

---

![[01 introduction-20251102-1.png]]

---

![[01 introduction-20251102-2.png]]

---

### 1. Comprendre la simulation physique 2D  

Nous commencerons par définir ce qu’est une **simulation physique** dans le contexte du jeu vidéo.  

---

Les notions clés incluent :

- le **temps discret** (*time step*),  
- l’**intégration** numérique,  
- la **mécanique du mouvement** (translation, rotation),  
- la différence entre une simulation physique et un rendu graphique.  

---

Ces notions servent à comprendre comment le moteur calcule le mouvement et les interactions entre objets à chaque itération.  


---

### 2. Outils mathématiques : les vecteurs  


Avant toute implémentation, nous ferons un rappel des **vecteurs** et de leurs opérations fondamentales :  
- addition, soustraction,  
- produit scalaire (*dot product*),  
- produit vectoriel (*cross product*).  

---

Nous verrons comment ces opérations permettent de représenter et manipuler des quantités physiques : position, vitesse, accélération, direction, etc.  


Le but est de **développer une intuition géométrique** : comprendre ce que ces calculs signifient visuellement.  

---

### 3. Transition vers le C++  


Une fois les bases mathématiques établies, nous passerons à l’implémentation en **C++**, langage de référence dans le développement de moteurs physiques.  

---

Nous aborderons :
- la structuration du code en classes (vecteur, particule, corps rigide),  
- la surcharge d’opérateurs pour manipuler naturellement les objets physiques,  
- la conception orientée objet d’un moteur minimal.  

---

### 4. Physique des particules  

Nous débuterons l’implémentation avec la **physique des particules** (*point masses*).  
Chaque particule représente un point doté d’une masse, soumis à des forces. 

---

Nous introduirons les concepts de :
- position, vitesse, accélération,  
- intégration du mouvement,  
- forces et impulsions,  
- frottement et résistance de l’air (*drag*).  

Ce modèle simple permet de construire la base du moteur avant d’ajouter la complexité des formes.  


---

### 5. Corps rigides (Rigid Bodies)  

Les **corps rigides** introduisent la notion de **forme** (cercle, polygone, rectangle).  
Nous apprendrons à :
- gérer la rotation et la translation d’un corps,  
- calculer les **moments d’inertie**,  
- appliquer des **torques** (*couples de forces*),  
- représenter les propriétés physiques (masse, centre de gravité, inertie).  

Cette partie relie la physique vectorielle à la géométrie des formes.  


---

### 6. Détection et résolution de collisions  

Les collisions sont un pilier du moteur de physique.  
Deux grandes étapes :  
1. **Détection** — savoir quand et où deux objets entrent en contact. 
2. **Récupération des informations de contact**
3. **Résolution** — calculer les impulsions nécessaires pour les séparer et conserver l’énergie.  

---

Nous aborderons les techniques de :
- détection de collision cercle-cercle et polygone-polygone,  
- réponse physique par **impulsion** et **projection**,  
- gestion des pénétrations et stabilité numérique.  


---

### 7. Stabilité et robustesse du moteur  

Pour terminer, nous étudierons la **stabilité numérique** du moteur :  
- comment éviter les oscillations et les mouvements erratiques,  
- comment gérer les petits chevauchements,  
- comment ajuster le pas de temps et la précision d’intégration.

---

Nous discuterons aussi de l’**architecture générale** d’un petit moteur physique stable, inspiré de solutions comme *Box2D*, *Box2D Lite* ou *Chipmunk2D*, mais à échelle réduite.  


---

## Conclusion  

À la fin du cours, vous serez capables de :
- comprendre les principes fondamentaux de la physique 2D,  
- implémenter un moteur de simulation simple en C++,  
- manipuler les notions de mouvement, force, collision et stabilité.  

Vous aurez ainsi une **base solide pour aborder la simulation 3D**, la conception de gameplay physique et l’optimisation des moteurs temps réel.  

