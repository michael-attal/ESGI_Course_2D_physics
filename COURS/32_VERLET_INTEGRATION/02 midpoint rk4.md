## Méthodes d’intégration améliorées  
### Cours ESGI – Complément / Bonus

Après avoir étudié l’**intégration d’Euler explicite** (explicit Euler), il est utile de présenter des variantes et méthodes plus précises pour améliorer la **stabilité** et la **précision** des simulations physiques.

---

## Euler semi-implicite (Semi-Implicit Euler)

L’**Euler semi-implicite** (semi-implicit Euler method) est une simple **modification de l’ordre de calcul** :

1. On **met à jour la vitesse** en premier, à partir de l’accélération calculée :  
   $v_{n+1} = v_n + a_n \cdot \Delta t$

2. On utilise cette **vitesse mise à jour** pour calculer la position suivante :  
   $x_{n+1} = x_n + v_{n+1} \cdot \Delta t$

Cette inversion permet de :
- rester **plus proche de la solution exacte** pour un mouvement à accélération constante,
- éviter le **gain artificiel d’énergie** observé avec l’Euler explicite,
- conserver une **stabilité numérique** meilleure, avec une légère perte d’énergie progressive.

**Résumé :** la semi-implicite Euler est recommandée pour les simulations où l’Euler explicite est insuffisamment stable.

---

## Méthode du point milieu (Midpoint Method)

Pour augmenter la précision, on peut utiliser la **méthode du point milieu** (midpoint method). L’idée est simple :

1. On divise le pas de temps en deux : $\Delta t / 2$.
2. On évalue la **pente** (vitesse) à ce **mi-point**.
3. On utilise cette pente intermédiaire pour prédire la valeur finale :  
   $x_{n+1} = x_n + f(x_n + \frac{\Delta t}{2} f(x_n)) \cdot \Delta t$

Cette approche réduit l’erreur d’approximation par rapport à l’Euler simple en **échantillonnant plus finement la dérivée** au sein du pas de temps.

---

## Méthode de Runge–Kutta d’ordre 4 (RK4)

La **méthode de Runge–Kutta d’ordre 4** (RK4) est une généralisation de la méthode du point milieu qui prend **quatre échantillons** pour chaque pas de temps :

1. Calculer $K_1$ à partir de l’état initial.
2. Calculer $K_2$ au point milieu en utilisant $K_1$.
3. Calculer $K_3$ au point milieu en utilisant $K_2$.
4. Calculer $K_4$ à la fin du pas en utilisant $K_3$.
5. Combiner ces quatre valeurs avec une moyenne pondérée :  
   $x_{n+1} = x_n + \frac{1}{6} (K_1 + 2K_2 + 2K_3 + K_4) \cdot \Delta t$

**Avantages :**
- Très **précise** et stable,
- Approche très proche de la solution continue réelle.

**Inconvénients :**
- Coût computationnel élevé,
- Rarement utilisée en **temps réel** (jeux vidéo, simulations interactives) car il faut effectuer **quatre évaluations par pas de temps**.

---

## Comparaison pratique pour le développement de jeux

| Méthode | Précision | Coût | Usage typique |
|---------|-----------|------|---------------|
| Euler explicite | Faible | Très faible | Prototypage, jeux simples |
| Euler semi-implicite | Moyenne | Très faible | Jeux 2D/3D avec forces constantes |
| Point milieu | Moyenne à haute | Moyen | Simulations plus précises |
| RK4 | Très haute | Élevé | Simulations scientifiques ou hors temps réel |

**Conclusion :**  
Pour la majorité des **moteurs physiques en jeux vidéo**, l’Euler semi-implicite constitue un **bon compromis** entre **vitesse** et **stabilité**. Les méthodes plus précises comme RK4 sont réservées aux contextes où la précision est critique et le temps de calcul moins contraint.
