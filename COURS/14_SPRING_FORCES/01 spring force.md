## Rappel

Une particule est un objet ponctuel possédant une masse, sans forme, incapable de rotation. Les forces appliquées modifient son accélération, sa vitesse et sa position.

---

## Récapitulatif des Forces Abordées

Les forces abordées incluent : la traînée (*drag*), la friction, l'attraction gravitationnelle.  
La force étudiée ici sera la force de ressort (*spring force*), applicable entre deux objets ou entre un objet et un point d’ancrage.

---

## Motivation

L'objectif est de simuler l'effet des ressorts : attraction, compression et extension.  
Les forces principales à implémenter sont : traînée, friction, attraction gravitationnelle, poids et ressorts, avec des fonctions auxiliaires pour les générer.

---

### Transition vers la Force de Ressort

La force de ressort sera analysée à travers sa formule, permettant de simuler un ressort qui se contracte et s’étend.  

Dans le fichier `force.cpp`, une fonction statique sera implémentée pour calculer le vecteur force et l’appliquer aux particules.

---

## Loi de Hooke

La force du ressort est régie par la loi de Hooke (*Hooke’s law*).  

Elle stipule que la force est proportionnelle au déplacement du ressort par rapport à sa longueur au repos.

---

## Expériences et Observations de Hooke

Hooke a expérimenté avec des ressorts afin de déterminer la relation entre le déplacement et la force exercée.  
La formule obtenue régit le mouvement des objets soumis à un ressort, qu’il s’agisse de particules ou de poids attachés.

---

## Longueur au Repos et Déplacement

La longueur au repos (*rest length*), notée $L_0$, correspond à l’état d’équilibre du ressort sans force appliquée.  

Tout déplacement par rapport à cette longueur génère une force proportionnelle.

---

## Extension et Compression du Ressort

L’extension du ressort produit une force qui attire l’objet vers l’équilibre.  

La compression du ressort accumule une énergie potentielle qui pousse l’objet vers l’équilibre.  

La direction de la force est toujours opposée au déplacement.

---

## Direction de la Force

La direction de la force est définie par le vecteur allant du point d’ancrage à la particule.  

Elle est normalisée pour obtenir uniquement la direction et multipliée par la magnitude de la force.

---

## Formule de la Loi de Hooke

La force du ressort est définie par :  

$$
\vec{F} = -k \Delta L
$$  

avec :  
- $k$ : constante de raideur (*spring constant*)  
- $\Delta L$ : déplacement par rapport à la longueur au repos  
Le signe négatif indique que la force s’oppose au déplacement.

---

## Concept d'Implémentation

$\Delta L$ représente la différence entre la longueur actuelle du ressort et la longueur au repos.  
Certains ouvrages utilisent $x$ à la place de $\Delta L$, mais il est préférable de conserver $\Delta L$ pour illustrer le déplacement réel.

---

## Implémentation en Code

Paramètres requis :  
- particule (*particle*)  
- point d’ancrage (*anchor*)  
- longueur au repos (*rest length*)  
- constante de raideur $k$  

---

Exemple :  
```cpp
Vector2 generateSpringForce(Particle particle, Vector2 anchor, float restLength, float k) {
    Vector2 distance = particle.position - anchor;
    float displacement = distance.magnitude() - restLength;
    Vector2 direction = distance.normalized();
    float magnitude = -k * displacement;
    return direction * magnitude;
}
```

- `particle` : particule soumise à la force
- `anchor` : point fixe du ressort
- `restLength` : longueur au repos du ressort
- `k` : constante de raideur
    

---

## Étapes de Calcul

1. Calculer le vecteur distance entre l’ancre et la particule
2. Obtenir le déplacement $\Delta L$
3. Normaliser le vecteur distance pour obtenir la direction de la force
4. Calculer la magnitude de la force : $|\vec{F}| = k \times \Delta L$
5. Appliquer le signe négatif pour opposer la force au déplacement
6. Retourner le vecteur force final
    

---

## Application de la Fonction

Exemple d’application :

```cpp
Vector2 springForce = generateSpringForce(particle, Vector2(100,100), 300.0f, 20.0f);
particle.addForce(springForce);
```

- `Vector2(100,100)` : position de l’ancrage
- `300.0f` : longueur au repos en pixels
- `20.0f` : constante de raideur
    

---

## Intégration Finale

L’application répétée de cette fonction aux particules simule le comportement d’un ressort : compression, extension et retour vers l’équilibre.

---

## Étape d’Implémentation

La fonction peut être copiée dans le code source pour tester la simulation de la force de ressort et ajuster la constante $k$ pour obtenir l’effet visuel désiré.
