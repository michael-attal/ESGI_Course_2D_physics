# Organisation du moteur physique avec un objet World

---

## Séparation entités, composants et corps rigides

- Les objets du jeu (entities) sont composés de **composants** :
  - **Body component** : contient la masse, le moment d’inertie et toutes les propriétés physiques.
  - **Sprite component** : pour le rendu des textures PNG.
  - **Script component** : pour attacher des scripts aux entités.
- Cette architecture sépare clairement **la physique du rendu graphique**.

---

## Limitation de l’approche initiale

- Actuellement, `Application.cpp` contient un **tableau de pointeurs de corps rigides**.
- Ce n’est pas représentatif des moteurs physiques classiques (Box2D, Chipmunk2D, Bullet Physics) :
  - Ces moteurs utilisent un **objet World** qui centralise :
    - Les corps rigides.
    - Les forces appliquées.
    - La gravité globale.
    - La gestion de la mémoire et de la simulation.
- L’utilisateur n’interagit pas directement avec un tableau de *bodies*.

---

## Création de l’objet World

- **World** : objet responsable de la simulation physique.
  - Contient :
    - Liste de corps rigides (`std::vector<Body*> bodies`).
    - Liste de forces appliquées (`std::vector<Vec2> forces`).
    - Liste de torques appliqués (`std::vector<float> torques`).
  - Gère :
    - Ajout et suppression de corps (`addBody(Body* body)`).
    - Application des forces et torques.
    - Mise à jour de tous les corps (`update(float deltaTime)`).
    - Détection et résolution des collisions (`checkCollisions()`).

---

## Constructeur et attributs

- Constructeur `World(float gravity)` :
  - Initialise la gravité globale `G`.
  - Initialise les listes de corps, forces et torques.
- Destructeur :
  - Libère tous les corps rigides alloués dynamiquement.
  - Assure l’absence de fuite mémoire.

---

## Gestion des forces et torques

- Permet d’appliquer des forces linéaires à tous les corps du monde.
- Permet d’appliquer des torques (forces angulaires) à tous les corps.
- Centralisation de la physique : la mise à jour des positions, rotations et collisions se fait dans le World.

---

## Mise à jour et collision

- La fonction `update(deltaTime)` :
  - Intègre les mouvements des corps.
  - Met à jour les sommets des polygones si nécessaire.
  - Appelle `checkCollisions()` pour gérer les interactions entre corps.
- Séparation nette entre :
  - Logique de physique.
  - Rendu graphique.
  
---

## Résumé

- La création d’un **World** permet de :
  - Centraliser la gestion des corps rigides.
  - Appliquer la gravité et les forces globales.
  - Déléguer la détection et résolution des collisions à un seul objet.
- Cette approche suit les standards des moteurs physiques modernes.
- Prochaine étape : implémenter les fonctions du World (`addBody`, `update`, `checkCollisions`, etc.) en transférant la logique de `Application.cpp` vers `World`.
