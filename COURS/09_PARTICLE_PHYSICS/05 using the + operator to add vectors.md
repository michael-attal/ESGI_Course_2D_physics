# Surcharge d’Opérateur pour l’Addition de Vecteurs

Dans l’exercice précédent, nous avons transformé l’appel :  

```cpp
particle.position.add(particle.velocity);
```

en utilisant la **surcharge d’opérateur** (_operator overloading_).

---

Grâce à cela, nous pouvons maintenant écrire :

```cpp
particle.position = particle.position + particle.velocity;
```

Ou encore mieux, en utilisant l’opérateur `+=` :

```cpp
particle.position += particle.velocity;
```

---

Cette syntaxe est plus **lisible** et exprime directement l’idée que nous **ajoutons le vecteur vitesse à la position**.  
Pour que cela fonctionne, nous avons dû **définir dans la classe `Vec2` le comportement des opérateurs `+` et `+=`** pour les vecteurs.

---

À partir de maintenant, nous utiliserons fréquemment la surcharge d’opérateur pour :
- multiplier un vecteur par un scalaire ;
- additionner ou soustraire des vecteurs ;
- utiliser directement les opérateurs `+`, `-`, `*`, `/` au lieu d’appeler des méthodes.

Cette approche rend le code plus naturel et proche de la notation mathématique classique.