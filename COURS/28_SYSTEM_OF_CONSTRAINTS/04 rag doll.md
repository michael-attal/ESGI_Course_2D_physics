# Création d’un Rag Doll avec des Joint Constraints

## Introduction
Dans cette activité, nous allons implémenter un **rag doll** (poupée articulée) en utilisant uniquement des **joint constraints**.  
Dans les moteurs physiques professionnels, les rag dolls combinent souvent **joint constraints** et **hinge constraints** pour contrôler les angles.  
Ici, nous allons expérimenter avec des joints simples pour relier toutes les parties du corps.

---

## Configuration des corps rigides
Chaque partie du rag doll est un corps rigide (`RigidBody`) avec un **shape** et une **masse** définis.  
Exemple :

- **Bob** : petit cercle (5 px), masse = 0 → statique, utilisé comme point d’ancrage pour la tête et contrôlé par la souris.  
- **Tête** : cercle (25 px), masse = 5 → suit le Bob pour rester attachée.  
- **Torso** : rectangle, masse = 1, positionné sous la tête.  
- **Bras et jambes** : rectangles, positionnés par rapport au torse, masses = 1.

Positions relatives :

```cpp
head.position = bob.position + Vector2(0, 70);
torso.position = head.position + Vector2(0, 80);
leftArm.position = torso.position + Vector2(-32, -10);
rightArm.position = torso.position + Vector2(32, -10);
leftLeg.position = torso.position + Vector2(-20, 97);
rightLeg.position = torso.position + Vector2(20, 97);
```

Chaque corps reçoit également une **texture** pour représenter visuellement les différentes parties.

---

## Création des joints

Chaque corps est relié aux autres par un **joint constraint** avec un **anchor point** précis :

- **String** : relie le Bob à la tête, permet de contrôler la tête via la souris.
    
- **Neck** : relie la tête au torse, anchor = tête + 25 px en y.
    
- **Shoulders** : relient le torse aux bras gauche et droit.
    
- **Hips** : relient le torse aux jambes gauche et droite.
    

Tous les joints sont ajoutés au **world**, ce qui permet leur résolution automatique à chaque étape de simulation.

---

## Contrôle par la souris

Le mouvement de la souris contrôle directement le **Bob**, ce qui entraîne un mouvement de la tête et du rag doll :

```cpp
Vector2 dir = normalize(mouse.position - bob.position);
float speed = 1.0f;
bob.position += dir * speed;

```
- La tête et le corps suivent grâce aux contraintes.
    
- Ce mécanisme simple permet de tester les contraintes tout en interagissant avec le rag doll.
    

---

## Visualisation

Pour le debug et la compréhension :

- Une ligne est tracée entre le **Bob** et la tête.
- Tous les **anchor points** des joints sont dessinés en rouge pour vérifier leur position dans l’espace du monde.
- Les textures des différentes parties du rag doll sont affichées.
    

---

## Remarques et conseils

- La **masse des corps** influence fortement la stabilité.
- Les positions des **anchor points** doivent être soigneusement choisies pour éviter les collisions ou comportements instables.
- Les contraintes peuvent encore être améliorées avec :
    - **Warm starting** (réutilisation des impulsions précédentes),
    - **Bias factor** pour la stabilisation (Baumgarte),
    - Résolution des collisions basée sur les contraintes.
        
Cette configuration permet d’obtenir un rag doll fonctionnel, stable et interactif, bien que quelques ajustements restent nécessaires pour un comportement parfaitement réaliste.