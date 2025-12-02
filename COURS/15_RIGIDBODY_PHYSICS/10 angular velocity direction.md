# Angular Velocity Direction

- L’angular velocity est stockée comme un scalaire (`float`) dans notre moteur physique.  
- Cette décision simplifie le calcul en 2D tout en respectant la direction de rotation.

---

## 3D Perspective

- Dans un espace **3D**, l’angular velocity est un **vecteur 3D** :  
  - Perpendiculaire au vecteur de vitesse linéaire.  
  - Représente la rotation autour d’un axe.  

![[medias/angular3d.png]]  

---

## 2D Implementation

- Pour un moteur 2D :  
  - Vitesse linéaire : vecteur 2D sur le plan _x-y_.  
  - Angular velocity : vecteur en direction **z**, rotation autour du centre de masse.  

- On peut imaginer la direction comme **entrant dans l’écran**.  

![[medias/angular2d.png]]  

---

## Simplification

- Au lieu de manipuler un vecteur complet, on stocke simplement la **magnitude du composant z** :  
```cpp
float angularVelocity; // magnitude du vecteur en z
```
- Cela suffit pour gérer la rotation des objets en 2D tout en respectant la physique angulaire.
    

#tags/physics/angular, #motion/angular, #implementation/2d

