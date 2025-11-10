# Force de poids

Rappelons rapidement que nous pouvons appliquer des forces à nos particules, comme la force du vent qui pousse vers la droite.  
La **masse** de la particule influence la facilité avec laquelle elle peut être accélérée : plus la masse est grande, plus l’accélération est difficile ; plus la masse est petite, plus elle est facile à accélérer.

---

# Problème avec la force de poids et l’accélération

Si nous appliquons une force de poids vers le bas, une petite particule tombe beaucoup plus vite qu’une grosse.  
Or, dans le monde réel, deux objets de masses différentes tombent **à la même vitesse**, atteignant le sol en même temps.

---

# Poids vs Gravité

La force que nous appelons **poids** est due à l’accélération de la gravité.  
La gravité est une **accélération** $g$ (environ 9.81 m/s² à la surface de la Terre), et la force qui en découle est le poids : $F_{\text{poids}} = m \times g$.

---

# Formule de la force de poids

La force de poids est donc calculée en multipliant la **masse** par l’accélération de la gravité :  $F = m \times a$.  
C’est la masse de l’objet qui détermine l’intensité de la force appliquée vers le bas.

---

# Masse vs Poids

La **masse** se mesure en kilogrammes (kg) et représente la quantité de matière.  
Le **poids** est une force (en newtons) : $F = m \times g$.  
Ainsi, la masse détermine la force appliquée par la gravité.

---

# Annulation du terme de masse

Lorsque nous calculons l’accélération d’un objet, nous divisons la force par la masse :  
$a = \frac{F}{m} = \frac{m \times g}{m} = g$.  
La masse s’annule, et toutes les particules tombent **à la même accélération**, indépendamment de leur masse.

---

# Implémentation et exemple

Pour chaque particule, la force de poids est calculée ainsi :  

```cpp
Vector weight = particle.mass * Vector(0, 9.81);
particle.addForce(weight);
```

Le résultat est que les particules, quelle que soit leur masse, suivent la même accélération verticale.

---

# Exemple de code et observation

Dans `application.cpp` : une petite particule (masse = 1.0) et une grosse particule (masse = 3.0) commencent à la même hauteur.  
La force de poids appliquée est : `poids = masse * 9.8`.  
À l’exécution, les deux particules atteignent le sol **au même moment**, démontrant l’annulation de la masse.

---

# Vérification

Nous plaçons les particules à des positions initiales différentes horizontalement pour observer la chute : la masse influence le vent mais **pas la gravité**.

---

# Observation et conclusion

L’accélération verticale due à la gravité est indépendante de la masse.  
Seule la force du vent continue d’être influencée par la masse.

---

# Résumé

La **force de poids** dépend de la masse, mais comme l’accélération est calculée par $a=F/m$, la masse s’annule.  
Ainsi, toutes les particules tombent à la même vitesse, peu importe leur masse, et atteignent le sol simultanément.