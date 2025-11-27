# Objets statiques et utilisation de l’inverse de la masse

Lors de la résolution des collisions, l’**inverse de la masse** est souvent utilisé plutôt que la masse directe des objets.  
Ce choix permet de gérer des **objets statiques**—des objets de masse pratiquement infinie qui ne se déplacent pas sous l’effet des forces, impulsions ou gravité.

---

## Pourquoi utiliser l’inverse de la masse ?

- Les moteurs physiques ont besoin d’**objets immobiles**, comme les sols ou les murs.  
- Utiliser la masse directement nécessiterait de gérer des valeurs extrêmement grandes.  
- Avec l’inverse de la masse, un objet statique est représenté par :  

$$
\text{inv\_mass} = 0
$$  

- Cela garantit que les calculs de déplacement ou d’impulsions donnent automatiquement zéro, maintenant l’objet immobile.

---

## Implémentation en code

### Constructeur du corps rigide

```cpp
if (mass != 0.0f)
    invMass = 1.0f / mass;
else
    invMass = 0.0f; // objet statique
```

- Mass = 0 → inverse mass = 0 → objet statique
    
- Mass > 0 → inverse mass = 1 / mass → objet dynamique
    

---

### Méthode de vérification statique

```cpp
bool Body::isStatic() const {
    const float epsilon = 0.0005f; 
    return fabs(invMass - 0.0f) < epsilon;
}
```

- Utilisation d’un **epsilon** pour gérer les erreurs de précision flottante.
    
- Comparaisons directes (`== 0`) peu fiables à cause des arrondis.
    

---

## Intégration et gestion des collisions

- **Objets dynamiques** : répondent aux forces, impulsions et collisions.
    
- **Objets statiques** : ignorent les calculs d’intégration et de déplacement lors des collisions :
    
    - Dans l’intégration : ignorer forces, accélérations et mise à jour de position.
        
    - Dans la résolution des collisions : déplacement (`D_A` ou `D_B`) = 0 si l’objet est statique.
        

---

## Exemple pratique

- Une **grande balle statique** au centre de l’écran (`invMass = 0`).
    
- Des petites balles (`mass = 1`) entrent en collision avec elle.
    
- Avec la méthode de projection, seules les petites balles se déplacent pour résoudre les collisions.
    
- L’objet statique reste en place, insensible à la gravité ou aux forces.
    
- Cette approche s’applique également aux sols, murs ou obstacles immobiles.
    

---

## Synthèse

- L’**inverse de la masse** permet de gérer facilement objets dynamiques et statiques.
    
- Les objets statiques sont représentés par `invMass = 0`, assurant zéro déplacement lors des collisions ou sous l’effet des forces.
    
- Comparaisons flottantes nécessitent un petit epsilon pour détecter correctement les objets statiques.
    
- Cette méthode simplifie la résolution des collisions et l’intégration des forces dans les moteurs physiques.



