# Introduction

- Objectif : traduire les concepts de rotation et de mouvement angulaire en code fonctionnel.  
- Approche : implémentation directe dans le moteur physique existant, sans perdre de temps sur la théorie.  
#tags/introduction, #motion/rotation, #implementation/coding

---

# Linear vs Angular Motion

- **Mouvement linéaire** : position, vitesse, accélération → vecteurs  
  $$\vec{p}, \vec{v}, \vec{a}$$
- **Mouvement angulaire** : angle de rotation, vitesse angulaire, accélération angulaire → scalaires  
  $$\theta, \omega, \alpha$$

**Variables en code :**  
- `rotation` → angle de rotation  
- `angularVelocity` → vitesse angulaire  
- `angularAcceleration` → accélération angulaire  

#tags/motion/linear, #motion/angular, #physics/variables

---

# Forces and Torque

- **Forces linéaires** : $$\sum \vec{F}$$  
- **Couples / torque** : $$\sum \tau$$  
- Propriétés nécessaires :  
  - `mass` (m)  
  - `momentOfInertia` (I) et `inverseMomentOfInertia` (1/I)

#tags/physics/forces, #physics/torque, #physics/inertia

---

# Mass and Inertia Management

- Stockage des valeurs :  
  - Mass / Inverse Mass  
  - Moment d’inertie / Inverse moment d’inertie  

- Avantage : accès direct à toutes les valeurs pour les calculs.  
#tags/physics/mass, #physics/inertia, #implementation/decision

---

# Shape Initialization

- Chaque corps rigide possède une **forme** (shape/geometry).  
- Initialisation des pointeurs en C++ :  
```cpp
Shape* shape = nullptr;
```

# Constructor Initialization

Initialisation complète du corps :

- Propriétés linéaires : `position`, `velocity`, `acceleration`
    
- Propriétés angulaires : `rotation`, `angularVelocity`, `angularAcceleration`
    
- Forces : `sumForces`, `sumTorque`  
    #tags/physics/construction, #cpp/constructor, #motion/initialization
    

---

# Integration Functions

- Séparation des intégrations :
    
    - `integrateLinear()` → position et vitesse
        
    - `integrateAngular()` → rotation et vitesse angulaire
        
- Simplifie la logique et reflète la distinction linéaire/rotationnelle.  
    #tags/physics/integration, #motion/linear, #motion/angular
    

---

# Mass and Inverse Initialization

- Moment d’inertie basé sur la forme et la masse :


```cpp
momentOfInertia = shape->getMomentOfInertia() * mass;
inverseMomentOfInertia = (momentOfInertia != 0.0f) ? 1.0f / momentOfInertia : 0.0f;

```

- Calcul de l’accélération angulaire : α=τI\alpha = \frac{\tau}{I}α=Iτ​  
    #tags/physics/mass, #physics/inertia, #cpp/calculation
    

---

# Torque Management and Integration

- Application et réinitialisation du couple :

```cpp
void addTorque(float torque) { sumTorque += torque; }
void clearTorque() { sumTorque = 0.0f; }

```

- Intégration angulaire suit la même logique que l’intégration linéaire mais avec propriétés angulaires.  
    #tags/physics/torque, #physics/integration, #cpp/functions
    

---

# Angular Integration Logic

- Calcul de l’accélération angulaire : α=∑τ⋅inverseMomentOfInertia\alpha = \sum \tau \cdot \text{inverseMomentOfInertia}α=∑τ⋅inverseMomentOfInertia
    
- Intégration :  
    ω+=α⋅Δt\omega \mathrel{+}= \alpha \cdot \Delta tω+=α⋅Δt  
    θ+=ω⋅Δt\theta \mathrel{+}= \omega \cdot \Delta tθ+=ω⋅Δt
    
- Réinitialisation du couple à chaque étape physique.  
    #tags/physics/angular, #math/integration, #cpp/implementation
    

---

# Shape Inertia Implementation

- Méthode virtuelle dans chaque classe de forme :
    
```cpp
virtual float getMomentOfInertia() const = 0;
```

#TODO reecrire les formules
- Formules :
    - Cercle : I=12r2⋅mI = \frac{1}{2} r^2 \cdot mI=21​r2⋅m
    - Rectangle : I=112(w2+h2)⋅mI = \frac{1}{12} (w^2 + h^2) \cdot mI=121​(w2+h2)⋅m
    - Polygone : à implémenter (triangulation et somme des contributions)  
        #tags/physics/shapes, #cpp/virtual-functions, #physics/inertia
        

---

# Testing Angular Rotation

- Test initial avec cercles et rectangles :
    
    - Appliquer un couple constant : `torque = 20.0f`
        
    - Observer l’accélération et la vitesse angulaire
        
    - Mettre à jour la rotation via `integrateAngular()`  
        #tags/testing/angular, #physics/torque, #motion/rotation
        

---

# Verification and Result

- Résultats attendus :
    
    - Accélération angulaire visible
        
    - Vitesse angulaire croissante
        
    - Angle de rotation mis à jour correctement
        
- Validation de l’implémentation de la dynamique angulaire.  
    #tags/verification/testing, #physics/angular, #motion/rotation
    

---

# Conclusion and Next Step

- Réalisations :
    
    - Séparation linéaire vs angulaire
        
    - Gestion correcte du couple et du moment d’inertie
        
    - Intégration de l’accélération angulaire en rotation
        
- Étapes suivantes :
    
    - Rendu de rectangles et polygones en rotation
        
    - Préparation pour la détection et résolution de collisions  
        #tags/conclusion, #physics/angular, #next-steps


