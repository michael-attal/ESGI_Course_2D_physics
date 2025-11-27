# Comparaison de nombres flottants et vérification epsilon

Lors de la dernière séance, nous avons mentionné que la **comparaison de nombres flottants** peut être délicate.  
Nous avons utilisé un contrôle rapide avec un **epsilon** dans la méthode `IsStatic` de la classe `Body` pour tester l’inverse de la masse.

---

## Points importants à retenir

**1) Comparaison générale avec epsilon**

- Dans le test, nous faisons `fabs(invMass - 0.0) < epsilon`.  
- La soustraction de `0.0` montre que la même technique peut être utilisée pour comparer **n’importe quelles deux variables flottantes**.  
- Exemple : pour vérifier si `a` est égal à `b` :  

```cpp
if (fabs(a - b) < epsilon) {
    // a et b sont considérés comme égaux
}
```

- Ici, `b = 0.0` simplement pour le test de masse inverse.
    

---

**2) Limites de cette méthode**

- Ce contrôle epsilon est **naïf** et ne couvre pas tous les cas particuliers rencontrés avec les flottants en C.
    
- Pour des comparaisons plus robustes, l’article [Floating-Point Comparison](https://floating-point-gui.de/errors/comparison/) explique les problèmes potentiels et propose des solutions adaptées.
    

---

**3) Bonnes pratiques en développement professionnel**

- Évitez d’écrire vos propres comparaisons flottantes dans des projets professionnels.
- Préférez toujours une **bibliothèque standard** ou les fonctions natives du langage pour gérer correctement les flottants.
- La plupart des langages modernes (Java, C#, Rust, etc.) offrent des fonctions fiables pour ce type de comparaison.
- L’exemple ici sert surtout à sensibiliser sur la complexité des flottants et à montrer la technique epsilon de base.


