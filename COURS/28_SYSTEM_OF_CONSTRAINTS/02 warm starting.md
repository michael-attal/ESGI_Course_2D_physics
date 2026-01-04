# Warm Starting et Optimisation des Solveurs de Contraintes

## Introduction
Lorsqu’on résout un système de contraintes dans un moteur physique, chaque contrainte produit des **impulsions λ (lambda)** pour maintenir les corps liés selon les règles définies. Pour un système simple, itérer 50 fois la résolution de toutes les contraintes peut donner un résultat proche de la solution idéale.  
Cependant, 50 itérations par étape de simulation sont **inacceptables en temps réel**. Il faut donc chercher une approche plus intelligente pour optimiser la convergence.

## Cohérence des objets dans la simulation
Dans un moteur physique, les objets ne se déplacent généralement pas beaucoup d’une étape de simulation à l’autre. Cette propriété est appelée **cohérence temporelle**.  
- Si un objet est à une position X à l’étape n, il sera très proche de X à l’étape n+1.  
- On peut exploiter cette cohérence pour optimiser la résolution des contraintes.

### Idée principale
Si l’impulsion calculée à l’étape précédente était proche de la bonne valeur, on peut **réutiliser cette impulsion comme estimation initiale** pour la nouvelle étape.  
Cette technique s’appelle le **warm starting**.

## Mise en œuvre du warm starting
1. Dans chaque contrainte, on conserve la dernière valeur de λ calculée dans un vecteur appelé **cached lambda**.  
2. Au début de la nouvelle étape de simulation (**pre-solve**), on applique cette impulsion précédente aux corps concernés.  
3. Ensuite, on effectue un nombre réduit d’itérations pour ajuster λ aux conditions actuelles.  

### Étapes détaillées
1. **Pré-calcul (pre-solve)**  
   - Calculer la **Jacobian matrix** une seule fois (elle ne change pas pendant les itérations).  
   - Appliquer la **cached lambda** des itérations précédentes aux corps A et B.  

2. **Résolution (solve)**  
   - Itérer plusieurs fois pour appliquer les impulsions nécessaires.  
   - Après chaque itération, accumuler λ dans **cached lambda** pour la prochaine étape.

3. **Optionnel : post-solve**  
   - Vérifications et corrections supplémentaires (clamping, sanity checks).  
   - Permet de stabiliser davantage le système si nécessaire.

## Avantages
- Réduction significative du nombre d’itérations nécessaires par étape de simulation.  
- Amélioration de la stabilité de la simulation.  
- Les chaînes de corps rigides restent plus cohérentes, avec moins d’étirement.

## Exemple d’implémentation
```cpp
// Dans constraint.h
Vector cachedLambda; // Impulsions sauvegardées pour le warm starting

// Dans pre-solve()
applyCachedLambda(cachedLambda); // Applique les impulsions sauvegardées aux corps

// Dans solve()
for (int i = 0; i < iterationCount; ++i) {
    calculateImpulse();       // Calcul de la nouvelle lambda
    applyImpulse();           // Applique les impulsions aux corps
    accumulateCachedLambda(); // Sauvegarde pour la prochaine étape
}
```

### Points importants

- **Jacobian matrix** : calculée une seule fois dans pre-solve pour améliorer les performances.
- **Cached lambda** : vecteur d’impulsions accumulées pour réutilisation.
- **Iterative solve** : itérations réduites, souvent 2 à 5 suffisent grâce au warm starting.
- **Bias vector** (future amélioration) : permet de corriger les contraintes pour obtenir une solution visuellement plus stable.
    

## Résultat

Avec le warm starting, on obtient :
- Une chaîne de corps interconnectés qui réagit correctement à la gravité.
- Moins d’itérations par étape de simulation, donc meilleure performance.
- Une simulation plus stable et plus réaliste visuellement.
    

### Conclusion

Le **warm starting** est une technique standard dans les moteurs physiques modernes pour optimiser la résolution des contraintes.  
En combinant :

- la pré-calculation des Jacobians,
- l’accumulation des λ,
- et un nombre réduit d’itérations,

on obtient une solution efficace et suffisamment précise pour la plupart des simulations temps réel.
