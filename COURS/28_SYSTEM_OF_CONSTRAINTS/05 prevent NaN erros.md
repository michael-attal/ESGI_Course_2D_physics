# Gestion des NaN dans la résolution des contraintes

## Contexte
Lors des tests de simulation du rag doll, certains points d’ancrage ont provoqué des **segmentation faults** et des contraintes ont été violées.  
Le problème venait de la résolution du système linéaire dans la méthode **Gauss-Seidel**, utilisée pour calculer les mises à jour de position `x`.  

### Problème rencontré
- Lors de la division ou des calculs sur les valeurs flottantes, certaines opérations produisaient des **NaN** (*Not a Number*).  
- La vérification classique `if(value != 0)` ne suffisait pas à protéger le moteur physique contre ces erreurs flottantes.  
- Ces NaN entraînaient la corruption de la simulation et des comportements instables des rag dolls.

---

## Solution proposée
1. Extraire la mise à jour de `x` dans une variable intermédiaire :

```cpp
float dx = computeDeltaX(); // calcul de l’incrément
```

2. Tester si `dx` est un nombre valide (non NaN) :
```cpp
if(dx == dx) {
    x += dx; // appliquer l’incrément seulement si dx est valide
}
```

**Explication :**  
En C++, une valeur NaN n’est jamais égale à elle-même (`NaN != NaN` retourne vrai). Ainsi, le test `dx == dx` garantit que l’incrément est valide avant de modifier `x`.

---

## Résultat

- Après cette modification, les **segmentation faults** disparaissent.
- Les contraintes sont désormais respectées et la simulation reste stable même avec plusieurs points d’ancrage.
- La structure du rag doll fonctionne correctement et les corps rigides restent attachés conformément aux joint constraints.
    

---

## Recommandations

- Toujours protéger les valeurs flottantes critiques dans les moteurs physiques contre les NaN.
- Utiliser des tests simples comme `dx == dx` pour vérifier la validité avant d’appliquer des incréments.
- Cette technique améliore la robustesse de la simulation, notamment pour des systèmes complexes comme des rag dolls.