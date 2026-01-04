# Contraintes de position et de vitesse : approche intuitive

---

## Introduction

- L’objectif est de comprendre les **contraintes** de manière progressive et intuitive.
- On commence par des exemples simples avant d’ajouter le **rigueur mathématique** complète (mécanique lagrangienne, intégrales, dérivées, etc.).
- On se concentre d’abord sur **les contraintes d’égalité** (*equality constraints*) et leur résolution pas à pas.

---

## Exemple : contrainte de position (position constraint)

- Scénario : une balle tombe sous gravité et doit s’arrêter au sol (\(y = 0\)).
- Fonction de contrainte : 
  $$
  C(y) = y_\text{ball} - y_\text{floor}
  $$
  avec \(C = 0\) quand la balle touche le sol.
- Résolution naïve en code :
```cpp
  if(ball.y < floor.y) ball.y = floor.y;
```
- Limite : déplacer directement la position peut causer des **instabilités**, surtout si plusieurs contraintes interagissent.
    

---

## Contrainte de vitesse (velocity constraint)

- Idée : au lieu de corriger directement la position, corriger la **vitesse** pour une approche plus **lisse**.
    
- Première dérivée de la position :
    
    $$\dot{y} = v_y$$​
- Objectif : limiter la vitesse de la balle pour qu’elle **revienne progressivement à la position voulue**.
    

### Feedback sur la position

- Définir l’erreur de position :
    
    $$e= y_\text{ball} - y_\text{floor}$$​
- Mettre à jour la vitesse en fonction de cette erreur :
    
    $$vy←−β e$$
    
    où $\beta \in [0,1]$ est le **facteur de biais** (_bias factor_).
    
    - $\beta=1$ : correction rapide, solution immédiate.
        
    - $\beta≪1$: correction progressive, mouvement plus doux.
        

---

## Stabilisation par boucle de rétroaction

- La **boucle de rétroaction** applique la correction sur plusieurs étapes de simulation.
    
- À chaque itération :
    
    1. Calculer l’erreur de position $e$.
        
    2. Ajuster la vitesse selon $vy←−βe$.
        
    3. Intégrer la vitesse pour obtenir la nouvelle position.
        
- Résultat : la balle s’approche progressivement de la position cible sans créer d’instabilités.
    

---

## Résumé

- **Position constraint** : corrige directement la position (peut provoquer des instabilités).
    
- **Velocity constraint** : corrige la vitesse pour une transition plus douce.
    
- **Facteur de biais $\beta$** : contrôle la rapidité de la correction.
    
- Cette approche est à la base des méthodes utilisées dans les moteurs physiques modernes pour **résoudre les collisions** et garantir la stabilité.